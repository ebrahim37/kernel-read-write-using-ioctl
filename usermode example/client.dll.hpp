// Generated using https://github.com/a2x/cs2-dumper
// 2025-08-01 22:47:35.099029800 UTC
// Truncated for this project

#pragma once

#include <cstddef>

namespace cs2_dumper {
    namespace schemas {
        namespace client_dll {
            // Parent: None
            // Field count: 33
            namespace CGameSceneNode {
                constexpr std::ptrdiff_t m_nodeToWorld = 0x10; // CTransform
                constexpr std::ptrdiff_t m_pOwner = 0x30; // CEntityInstance*
                constexpr std::ptrdiff_t m_pParent = 0x38; // CGameSceneNode*
                constexpr std::ptrdiff_t m_pChild = 0x40; // CGameSceneNode*
                constexpr std::ptrdiff_t m_pNextSibling = 0x48; // CGameSceneNode*
                constexpr std::ptrdiff_t m_hParent = 0x78; // CGameSceneNodeHandle
                constexpr std::ptrdiff_t m_vecOrigin = 0x88; // CNetworkOriginCellCoordQuantizedVector
                constexpr std::ptrdiff_t m_angRotation = 0xC0; // QAngle
                constexpr std::ptrdiff_t m_flScale = 0xCC; // float32
                constexpr std::ptrdiff_t m_vecAbsOrigin = 0xD0; // Vector
                constexpr std::ptrdiff_t m_angAbsRotation = 0xDC; // QAngle
                constexpr std::ptrdiff_t m_flAbsScale = 0xE8; // float32
                constexpr std::ptrdiff_t m_nParentAttachmentOrBone = 0xEC; // int16
                constexpr std::ptrdiff_t m_bDebugAbsOriginChanges = 0xEE; // bool
                constexpr std::ptrdiff_t m_bDormant = 0xEF; // bool
                constexpr std::ptrdiff_t m_bForceParentToBeNetworked = 0xF0; // bool
                constexpr std::ptrdiff_t m_bDirtyHierarchy = 0x0; // bitfield:1
                constexpr std::ptrdiff_t m_bDirtyBoneMergeInfo = 0x0; // bitfield:1
                constexpr std::ptrdiff_t m_bNetworkedPositionChanged = 0x0; // bitfield:1
                constexpr std::ptrdiff_t m_bNetworkedAnglesChanged = 0x0; // bitfield:1
                constexpr std::ptrdiff_t m_bNetworkedScaleChanged = 0x0; // bitfield:1
                constexpr std::ptrdiff_t m_bWillBeCallingPostDataUpdate = 0x0; // bitfield:1
                constexpr std::ptrdiff_t m_bBoneMergeFlex = 0x0; // bitfield:1
                constexpr std::ptrdiff_t m_nLatchAbsOrigin = 0x0; // bitfield:2
                constexpr std::ptrdiff_t m_bDirtyBoneMergeBoneToRoot = 0x0; // bitfield:1
                constexpr std::ptrdiff_t m_nHierarchicalDepth = 0xF3; // uint8
                constexpr std::ptrdiff_t m_nHierarchyType = 0xF4; // uint8
                constexpr std::ptrdiff_t m_nDoNotSetAnimTimeInInvalidatePhysicsCount = 0xF5; // uint8
                constexpr std::ptrdiff_t m_name = 0xF8; // CUtlStringToken
                constexpr std::ptrdiff_t m_hierarchyAttachName = 0x138; // CUtlStringToken
                constexpr std::ptrdiff_t m_flZOffset = 0x13C; // float32
                constexpr std::ptrdiff_t m_flClientLocalScale = 0x140; // float32
                constexpr std::ptrdiff_t m_vRenderOrigin = 0x144; // Vector
            }

            // Parent: None
            // Field count: 82
            namespace C_BaseEntity {
                constexpr std::ptrdiff_t m_CBodyComponent = 0x38; // CBodyComponent*
                constexpr std::ptrdiff_t m_NetworkTransmitComponent = 0x40; // CNetworkTransmitComponent
                constexpr std::ptrdiff_t m_nLastThinkTick = 0x328; // GameTick_t
                constexpr std::ptrdiff_t m_pGameSceneNode = 0x330; // CGameSceneNode*
                constexpr std::ptrdiff_t m_pRenderComponent = 0x338; // CRenderComponent*
                constexpr std::ptrdiff_t m_pCollision = 0x340; // CCollisionProperty*
                constexpr std::ptrdiff_t m_iMaxHealth = 0x348; // int32
                constexpr std::ptrdiff_t m_iHealth = 0x34C; // int32
                constexpr std::ptrdiff_t m_lifeState = 0x350; // uint8
                constexpr std::ptrdiff_t m_bTakesDamage = 0x351; // bool
                constexpr std::ptrdiff_t m_nTakeDamageFlags = 0x358; // TakeDamageFlags_t
                constexpr std::ptrdiff_t m_nPlatformType = 0x360; // EntityPlatformTypes_t
                constexpr std::ptrdiff_t m_ubInterpolationFrame = 0x361; // uint8
                constexpr std::ptrdiff_t m_hSceneObjectController = 0x364; // CHandle<C_BaseEntity>
                constexpr std::ptrdiff_t m_nNoInterpolationTick = 0x368; // int32
                constexpr std::ptrdiff_t m_nVisibilityNoInterpolationTick = 0x36C; // int32
                constexpr std::ptrdiff_t m_flProxyRandomValue = 0x370; // float32
                constexpr std::ptrdiff_t m_iEFlags = 0x374; // int32
                constexpr std::ptrdiff_t m_nWaterType = 0x378; // uint8
                constexpr std::ptrdiff_t m_bInterpolateEvenWithNoModel = 0x379; // bool
                constexpr std::ptrdiff_t m_bPredictionEligible = 0x37A; // bool
                constexpr std::ptrdiff_t m_bApplyLayerMatchIDToModel = 0x37B; // bool
                constexpr std::ptrdiff_t m_tokLayerMatchID = 0x37C; // CUtlStringToken
                constexpr std::ptrdiff_t m_nSubclassID = 0x380; // CUtlStringToken
                constexpr std::ptrdiff_t m_nSimulationTick = 0x390; // int32
                constexpr std::ptrdiff_t m_iCurrentThinkContext = 0x394; // int32
                constexpr std::ptrdiff_t m_aThinkFunctions = 0x398; // CUtlVector<thinkfunc_t>
                constexpr std::ptrdiff_t m_bDisabledContextThinks = 0x3B0; // bool
                constexpr std::ptrdiff_t m_flAnimTime = 0x3B4; // float32
                constexpr std::ptrdiff_t m_flSimulationTime = 0x3B8; // float32
                constexpr std::ptrdiff_t m_nSceneObjectOverrideFlags = 0x3BC; // uint8
                constexpr std::ptrdiff_t m_bHasSuccessfullyInterpolated = 0x3BD; // bool
                constexpr std::ptrdiff_t m_bHasAddedVarsToInterpolation = 0x3BE; // bool
                constexpr std::ptrdiff_t m_bRenderEvenWhenNotSuccessfullyInterpolated = 0x3BF; // bool
                constexpr std::ptrdiff_t m_nInterpolationLatchDirtyFlags = 0x3C0; // int32[2]
                constexpr std::ptrdiff_t m_ListEntry = 0x3C8; // uint16[11]
                constexpr std::ptrdiff_t m_flCreateTime = 0x3E0; // GameTime_t
                constexpr std::ptrdiff_t m_flSpeed = 0x3E4; // float32
                constexpr std::ptrdiff_t m_EntClientFlags = 0x3E8; // uint16
                constexpr std::ptrdiff_t m_bClientSideRagdoll = 0x3EA; // bool
                constexpr std::ptrdiff_t m_iTeamNum = 0x3EB; // uint8
                constexpr std::ptrdiff_t m_spawnflags = 0x3EC; // uint32
                constexpr std::ptrdiff_t m_nNextThinkTick = 0x3F0; // GameTick_t
                constexpr std::ptrdiff_t m_fFlags = 0x3F8; // uint32
                constexpr std::ptrdiff_t m_vecAbsVelocity = 0x3FC; // Vector
                constexpr std::ptrdiff_t m_vecServerVelocity = 0x408; // CNetworkVelocityVector
                constexpr std::ptrdiff_t m_vecVelocity = 0x430; // CNetworkVelocityVector
                constexpr std::ptrdiff_t m_vecBaseVelocity = 0x510; // Vector
                constexpr std::ptrdiff_t m_hEffectEntity = 0x51C; // CHandle<C_BaseEntity>
                constexpr std::ptrdiff_t m_hOwnerEntity = 0x520; // CHandle<C_BaseEntity>
                constexpr std::ptrdiff_t m_MoveCollide = 0x524; // MoveCollide_t
                constexpr std::ptrdiff_t m_MoveType = 0x525; // MoveType_t
                constexpr std::ptrdiff_t m_nActualMoveType = 0x526; // MoveType_t
                constexpr std::ptrdiff_t m_flWaterLevel = 0x528; // float32
                constexpr std::ptrdiff_t m_fEffects = 0x52C; // uint32
                constexpr std::ptrdiff_t m_hGroundEntity = 0x530; // CHandle<C_BaseEntity>
                constexpr std::ptrdiff_t m_nGroundBodyIndex = 0x534; // int32
                constexpr std::ptrdiff_t m_flFriction = 0x538; // float32
                constexpr std::ptrdiff_t m_flElasticity = 0x53C; // float32
                constexpr std::ptrdiff_t m_flGravityScale = 0x540; // float32
                constexpr std::ptrdiff_t m_flTimeScale = 0x544; // float32
                constexpr std::ptrdiff_t m_bAnimatedEveryTick = 0x548; // bool
                constexpr std::ptrdiff_t m_bGravityDisabled = 0x549; // bool
                constexpr std::ptrdiff_t m_flNavIgnoreUntilTime = 0x54C; // GameTime_t
                constexpr std::ptrdiff_t m_hThink = 0x550; // uint16
                constexpr std::ptrdiff_t m_fBBoxVisFlags = 0x560; // uint8
                constexpr std::ptrdiff_t m_flActualGravityScale = 0x564; // float32
                constexpr std::ptrdiff_t m_bGravityActuallyDisabled = 0x568; // bool
                constexpr std::ptrdiff_t m_bPredictable = 0x569; // bool
                constexpr std::ptrdiff_t m_bRenderWithViewModels = 0x56A; // bool
                constexpr std::ptrdiff_t m_nFirstPredictableCommand = 0x56C; // int32
                constexpr std::ptrdiff_t m_nLastPredictableCommand = 0x570; // int32
                constexpr std::ptrdiff_t m_hOldMoveParent = 0x574; // CHandle<C_BaseEntity>
                constexpr std::ptrdiff_t m_Particles = 0x578; // CParticleProperty
                constexpr std::ptrdiff_t m_vecAngVelocity = 0x5A8; // QAngle
                constexpr std::ptrdiff_t m_DataChangeEventRef = 0x5B4; // int32
                constexpr std::ptrdiff_t m_dependencies = 0x5B8; // CUtlVector<CEntityHandle>
                constexpr std::ptrdiff_t m_nCreationTick = 0x5D0; // int32
                constexpr std::ptrdiff_t m_bAnimTimeChanged = 0x5DD; // bool
                constexpr std::ptrdiff_t m_bSimulationTimeChanged = 0x5DE; // bool
                constexpr std::ptrdiff_t m_sUniqueHammerID = 0x5E8; // CUtlString
                constexpr std::ptrdiff_t m_nBloodType = 0x5F0; // BloodType
            }

            // Parent: C_BaseEntity
            // Field count: 68
            namespace CCSPlayerController {
                constexpr std::ptrdiff_t m_hPlayerPawn = 0x8FC; // CHandle<C_CSPlayerPawn>
            }

            // Parent: C_BasePlayerPawn
            // Field count: 56
            namespace C_CSPlayerPawnBase {
                // ... inherits from C_BasePlayerPawn
            }

            // Parent: C_CSPlayerPawnBase
            // Field count: 110
            namespace C_CSPlayerPawn {
                constexpr std::ptrdiff_t m_pBulletServices = 0x17F0; // CCSPlayer_BulletServices*
                constexpr std::ptrdiff_t m_pHostageServices = 0x17F8; // CCSPlayer_HostageServices*
                constexpr std::ptrdiff_t m_pBuyServices = 0x1800; // CCSPlayer_BuyServices*
                constexpr std::ptrdiff_t m_pGlowServices = 0x1808; // CCSPlayer_GlowServices*
                constexpr std::ptrdiff_t m_pActionTrackingServices = 0x1810; // CCSPlayer_ActionTrackingServices*
            }
        }
    }
}
