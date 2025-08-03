#pragma once
#include <cmath>

struct Vector3 {
    float x, y, z;

    Vector3 operator+(const Vector3& other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vector3 operator-(const Vector3& other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vector3 operator*(float scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }
};

struct ViewMatrix {
    float matrix[4][4];

    Vector3 WorldToScreen(const Vector3& pos, int width, int height) const {
        float _x = matrix[0][0] * pos.x + matrix[0][1] * pos.y + matrix[0][2] * pos.z + matrix[0][3];
        float _y = matrix[1][0] * pos.x + matrix[1][1] * pos.y + matrix[1][2] * pos.z + matrix[1][3];
        float w = matrix[3][0] * pos.x + matrix[3][1] * pos.y + matrix[3][2] * pos.z + matrix[3][3];

        if (w < 0.01f) {
            return { -1, -1, -1 };
        }

        float inv_w = 1.f / w;
        _x *= inv_w;
        _y *= inv_w;

        float x = width / 2.f;
        float y = height / 2.f;

        x += 0.5f * _x * width + 0.5f;
        y -= 0.5f * _y * height + 0.5f;

        return {x, y, w};
    }
};
