#pragma once

namespace DG {
	namespace math {
		struct float2;
		struct float3;
		struct float4;
		struct float4x4;

		struct float2
		{
			float x, y;

			float2();
			float2(float x, float y);
			float2(const float2 &other);
			float2(const float3 &other);
			float2(const float4 &other);

			float2 &operator=(const float2& other);
			float2 &operator=(const float3& other);
			float2 &operator=(const float4& other);

			static float length(const float2& v);
			static float2 normalize(const float2 &v);
			static float dotProduct(const float2& lhs, const float2 &rhs);
		};

		struct float3
		{
			float x, y, z;

			float3();
			float3(float x, float y);
			float3(float x, float y, float z);
			float3(const float2 &other);
			float3(const float3 &other);
			float3(const float4 &other);

			float3 &operator=(const float2& other);
			float3 &operator=(const float3& other);
			float3 &operator=(const float4& other);

			inline static float length(const float3& v);
			inline static float3 normalize(const float3 &v);
			inline static float dotProduct(const float3& lhs, const float3 &rhs);
			inline static float3 projectOn(const float3 &lhs, const float3 &rhs);
			inline static float3 cross(const float3 &lhs, const float3 &rhs);
		};

		struct float4
		{
			float x, y, z, w;

			float4();
			float4(float x, float y);
			float4(float x, float y, float z);
			float4(float x, float y, float z, float w);
			float4(const float2 &other);
			float4(const float3 &other);
			float4(const float4 &other);

			float4 &operator=(const float2& other);
			float4 &operator=(const float3& other);
			float4 &operator=(const float4& other);

			static float length(const float4& v);

			static float4 normalize(const float4 &v);

			static float dotProduct(const float4& lhs, const float4 &rhs);
		};

		struct float4x4
		{
			float m11, m12, m13, m14;
			float m21, m22, m23, m24;
			float m31, m32, m33, m34;
			float m41, m42, m43, m44;

			float4x4();
			float4x4(float value);
			float4x4(float m11, float m12, float m13, float m14,
				float m21, float m22, float m23, float m24,
				float m31, float m32, float m33, float m34,
				float m41, float m42, float m43, float m44);
			float4x4(const float4 &v1, const float4 &v2, const float4 &v3, const float4 &v4);
			float4x4(const float4x4 &other);

			float4x4 &operator=(const float4x4 &other);

			static float determinant(const float4x4 &mat);
			static float4x4 transpose(const float4x4 &mat);
			static float4x4 inverse(const float4x4 &mat);
			static float4x4 translate(const float4x4 &mat, const float3 &v);
			static float4x4 scale(const float4x4 &mat, const float3 &s);
			static float4x4 rotationX(const float4x4 &mat, const float theta);
			static float4x4 rotationY(const float4x4 &mat, const float theta);
			static float4x4 rotationZ(const float4x4 &mat, const float theta);
			static float4x4 lookAt(const float3 &eye, const float3 &target, const float3 &up);
			static float4x4 createOrthographic(float left, float right, float top, float bottom, float nearPlane, float farPlane);
			static float4x4 createPerspective(float fov, float aspectRatio, float nearPlane, float farPlane);
		};

		bool operator==(const float2 &lhs, const float2 &rhs);
		float2 operator+(const float2 &lhs, const float2 &rhs);
		float2 operator+=(float2 &lhs, const float2 &rhs);
		float2 operator-(const float2 &lhs, const float2 &rhs);
		float2 operator-=(float2 &lhs, const float2 &rhs);
		float2 operator+(const float2 &v, const float value);
		float2 operator+=(float2 &v, const float value);
		float2 operator-(const float2 &v, const float value);
		float2 operator-=(float2 &v, const float value);
		float2 operator*(const float2 &v, const float value);
		float2 operator*=(float2 &v, const float value);
		float2 operator/(const float2 &v, const float value);
		float2 operator/=(float2 &v, const float value);

		bool operator==(const float3 &lhs, const float3 &rhs);
		float3 operator+(const float3 &lhs, const float3 &rhs);
		float3 operator+=(float3 &lhs, const float3 &rhs);
		float3 operator-(const float3 &lhs, const float3 &rhs);
		float3 operator-=(float3 &lhs, const float3 &rhs);
		float3 operator+(const float3 &v, const float value);
		float3 operator+=(float3 &v, const float value);
		float3 operator-(const float3 &v, const float value);
		float3 operator-=(float3 &v, const float value);
		float3 operator*(const float3 &v, const float value);
		float3 operator*=(float3 &v, const float value);
		float3 operator/(const float3 &v, const float value);
		float3 operator/=(float3 &v, const float value);

		bool operator==(const float4 &lhs, const float4 &rhs);
		float4 operator+(const float4 &lhs, const float4 &rhs);
		float4 operator+=(float4 &lhs, const float4 &rhs);
		float4 operator-(const float4 &lhs, const float4 &rhs);
		float4 operator-=(float4 &lhs, const float4 &rhs);
		float4 operator+(const float4 &v, const float value);
		float4 operator+=(float4 &v, const float value);
		float4 operator-(const float4 &v, const float value);
		float4 operator-=(float4 &v, const float value);
		float4 operator*(const float4 &v, const float value);
		float4 operator*=(float4 &v, const float value);
		float4 operator/(const float4 &v, const float value);
		float4 operator/=(float4 &v, const float value);

		bool operator==(const float4x4 &lhs, const float4x4 &rhs);
		float4x4 operator+(const float4x4 &lhs, const float4x4 &rhs);
		float4x4 operator+=(float4x4 &lhs, const float4x4 &rhs);
		float4x4 operator-(const float4x4 &lhs, const float4x4 &rhs);
		float4x4 operator-=(float4x4 &lhs, const float4x4 &rhs);

		float4x4 operator*(const float4x4 &lhs, const float4x4 &rhs);
		float4x4 operator*(const float4x4 &v, const float value);
		float4x4 operator*=(float4x4 &lhs, const float4x4 &rhs);
		float4x4 operator*=(float4x4 &v, const float value);
	}
}