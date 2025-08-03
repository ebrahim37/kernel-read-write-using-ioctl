#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include "driver.hpp"
#include "offsets.hpp"
#include "client.dll.hpp"
#include "vector.hpp"

uintptr_t get_process_id(const char* process_name) {
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (Process32First(snapshot, &entry) == TRUE) {
        while (Process32Next(snapshot, &entry) == TRUE) {
            if (_stricmp(entry.szExeFile, process_name) == 0) {
                CloseHandle(snapshot);
                return entry.th32ProcessID;
            }
        }
    }

    CloseHandle(snapshot);
    return 0;
}

uintptr_t get_module_base(uintptr_t process_id, const char* module_name) {
    MODULEENTRY32 entry;
    entry.dwSize = sizeof(MODULEENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, process_id);

    if (Module32First(snapshot, &entry) == TRUE) {
        do {
            if (!strcmp(entry.szModule, module_name)) {
                CloseHandle(snapshot);
                return (uintptr_t)entry.modBaseAddr;
            }
        } while (Module32Next(snapshot, &entry));
    }

    CloseHandle(snapshot);
    return 0;
}

int main() {
    uintptr_t process_id = get_process_id("cs2.exe");
    if (!process_id) {
        std::cout << "Failed to find process: cs2.exe" << std::endl;
        return 1;
    }

    uintptr_t client_dll = get_module_base(process_id, "client.dll");
    if (!client_dll) {
        std::cout << "Failed to find module: client.dll" << std::endl;
        return 1;
    }

    driver_manager driver("\\\\.\\cartidriver", process_id);
    std::cout << "Driver loaded" << std::endl;

    while (true) {
        system("cls"); // Clear console

        ViewMatrix view_matrix = driver.RPM<ViewMatrix>(client_dll + cs2_dumper::offsets::client_dll::dwViewMatrix);

        uintptr_t local_player_controller = driver.RPM<uintptr_t>(client_dll + cs2_dumper::offsets::client_dll::dwLocalPlayerController);
        if (!local_player_controller) continue;

        uintptr_t local_player_pawn = driver.RPM<uintptr_t>(local_player_controller + cs2_dumper::schemas::client_dll::CCSPlayerController::m_hPlayerPawn);
        if (!local_player_pawn) continue;

        int local_team = driver.RPM<int>(local_player_pawn + cs2_dumper::schemas::client_dll::C_BaseEntity::m_iTeamNum);

        uintptr_t entity_list = driver.RPM<uintptr_t>(client_dll + cs2_dumper::offsets::client_dll::dwEntityList);
        if (!entity_list) continue;

        for (int i = 0; i < 64; ++i) {
            uintptr_t list_entry = driver.RPM<uintptr_t>(entity_list + (8 * (i & 0x7FFF) >> 9) + 16);
            if (!list_entry) continue;

            uintptr_t player_controller = driver.RPM<uintptr_t>(list_entry + 120 * (i & 0x1FF));
            if (!player_controller) continue;

            uintptr_t player_pawn = driver.RPM<uintptr_t>(player_controller + cs2_dumper::schemas::client_dll::CCSPlayerController::m_hPlayerPawn);
            if (!player_pawn || player_pawn == local_player_pawn) continue;

            int health = driver.RPM<int>(player_pawn + cs2_dumper::schemas::client_dll::C_BaseEntity::m_iHealth);
            if (health <= 0 || health > 100) continue;

            int team = driver.RPM<int>(player_pawn + cs2_dumper::schemas::client_dll::C_BaseEntity::m_iTeamNum);
            if (team == local_team) continue;

            uintptr_t scene_node = driver.RPM<uintptr_t>(player_pawn + cs2_dumper::schemas::client_dll::C_BaseEntity::m_pGameSceneNode);
            if (!scene_node) continue;

            Vector3 position = driver.RPM<Vector3>(scene_node + cs2_dumper::schemas::client_dll::CGameSceneNode::m_vecAbsOrigin);

            Vector3 screen_pos = view_matrix.WorldToScreen(position, 1920, 1080); // Assuming 1920x1080 resolution

            if (screen_pos.z > 0.0f) { // If player is on screen
                std::cout << "Enemy at: " << screen_pos.x << ", " << screen_pos.y << " | Health: " << health << std::endl;
            }
        }
        Sleep(100); // Sleep to reduce CPU usage
    }

    return 0;
}
