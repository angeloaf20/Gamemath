#include "stdafx.h"
#include "Gamemath.h"
#include <iostream>
#include <numbers>

inline float det3x3(
	float a11, float a12, float a13, 
	float a21, float a22, float a23, 
	float a31, float a32, float a33
)
{
	return (a11 * (a22 * a33 - a23 * a32)) - (a12 * (a21 * a33 - a23 * a31)) + (a13 * (a21 * a32 - a22 * a31));
}

namespace DG 
{
	namespace math 
	{
		float2::float2() :
			x{},
			y{}
		{
		}

		float2::float2(float x, float y): 
			x{ x },
			y{ y }
		{
		}

		float2::float2(const float2 &other): 
			x{ other.x },
			y{ other.y }
		{
		}

		float2::float2(const float3 & other):
			x{ other.x },
			y{ other.y }
		{
		}

		float2::float2(const float4 & other):
			x{ other.x },
			y{ other.y }
		{
		}

		float2 &float2::operator=(const float2 & other)
		{
			x = other.x;
			y = other.y;
			return *this;
		}

		float2 &float2::operator=(const float3 & other)
		{
			x = other.x;
			y = other.y;
			return *this;
		}

		float2 &float2::operator=(const float4 & other)
		{
			x = other.x;
			y = other.y;
			return *this;
		}

		bool operator==(const float2 & lhs, const float2 &rhs)
		{
			return lhs.x == rhs.x && lhs.y == rhs.y;
		}

		float2 operator+(const float2 & lhs, const float2 &rhs)
		{
			return float2(lhs.x + rhs.x, lhs.y + rhs.y);
		}

		float2 operator+=(float2 &lhs, const float2 &rhs)
		{
			lhs.x += rhs.x;
			lhs.y += rhs.y;

			return lhs;
		}

		float2 operator-(const float2 &lhs, const float2 &rhs)
		{
			return float2(lhs.x - rhs.x, lhs.y - rhs.y);
		}

		float2 operator-=(float2 &lhs, const float2 &rhs)
		{
			lhs.x -= rhs.x;
			lhs.y -= rhs.y;

			return lhs;
		}

		float2 operator+(const float2 & lhs, const float value)
		{
			return float2(lhs.x + value, lhs.y + value);
		}

		float2 operator+=(float2 & lhs, const float value)
		{
			lhs.x += value;
			lhs.y += value;
			return lhs;
		}

		float2 operator-(const float2 &v, const float value)
		{
			return float2(v.x - value, v.y - value);
		}

		float2 operator-=(float2 &v, const float value)
		{
			v.x -= value;
			v.y -= value;
			return v;
		}

		float2 operator*(const float2 &v, const float value)
		{
			return float2(v.x * value, v.y * value);
		}

		float2 operator*=(float2 &v, const float value)
		{
			v.x *= value;
			v.y *= value;

			return v;
		}

		float2 operator/(const float2 &v, const float value)
		{
			return float2(v.x/value, v.y/value);
		}

		float2 operator/=(float2 &v, const float value)
		{
			v.x /= value;
			v.y /= value;

			return v;
		}

		float float2::length(const float2 & v)
		{
			float len = sqrtf(v.x * v.x + v.y * v.y);
			return len;
		}

		float2 float2::normalize(const float2 & v)
		{
			float len = length(v);

			return float2{ v.x / len, v.y / len };
		}

		float float2::dotProduct(const float2 & lhs, const float2 & rhs)
		{
			return lhs.x * rhs.x + lhs.y * rhs.y;
		}

		float3::float3() :
			x{},
			y{},
			z{}
		{
		}

		float3::float3(float x, float y):
			x{ x },
			y{ y },
			z{}
		{
		}

		float3::float3(float x, float y, float z):
			x{ x },
			y{ y },
			z{ z }
		{
		}

		float3::float3(const float2 &other):
			x{ other.x },
			y{ other.y },
			z{}
		{
		}

		float3::float3(const float3 & other):
			x{ other.x },
			y{ other.y },
			z{ other.z }
		{
		}

		float3::float3(const float4 & other):
			x{ other.x },
			y{ other.y },
			z{ other.z }
		{
		}

		float3 &float3::operator=(const float2 & other)
		{
			x = other.x;
			y = other.y;
			z = 0.0f;
			return *this;
		}

		float3 &float3::operator=(const float3 & other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
			return *this;
		}

		float3 &float3::operator=(const float4 & other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
			return *this;
		}

		bool operator==(const float3 & lhs, const float3 & rhs)
		{
			return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
		}

		float3 operator+(const float3 & lhs, const float3 &rhs)
		{
			return float3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
		}

		float3 operator+=(float3 &lhs, const float3 &rhs)
		{
			lhs.x += rhs.x;
			lhs.y += rhs.y;
			lhs.z += rhs.z;

			return lhs;
		}

		float3 operator-(const float3 &lhs, const float3 &rhs)
		{
			return float3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
		}

		float3 operator-=(float3 &lhs, const float3 &rhs)
		{
			lhs.x -= rhs.x;
			lhs.y -= rhs.y;
			lhs.z -= rhs.z;

			return lhs;
		}

		float3 operator+(const float3 & lhs, const float value)
		{
			return float3(lhs.x + value, lhs.y + value, lhs.z + value);
		}

		float3 operator+=(float3 & lhs, const float value)
		{
			lhs.x += value;
			lhs.y += value;
			lhs.z += value;

			return lhs;
		}

		float3 operator-(const float3 &v, const float value)
		{
			return float3(v.x - value, v.y - value, v.z - value);
		}

		float3 operator-=(float3 &v, const float value)
		{
			v.x -= value;
			v.y -= value;
			v.z -= value;

			return v;
		}

		float3 operator*(const float3 &v, const float value)
		{
			return float3(v.x * value, v.y * value, v.z * value);
		}

		float3 operator*=(float3 &v, const float value)
		{
			v.x *= value;
			v.y *= value;
			v.z *= value;

			return v;
		}

		float3 operator/(const float3 &v, const float value)
		{
			return float3(v.x / value, v.y / value, v.z / value);
		}

		float3 operator/=(float3 &v, const float value)
		{
			v.x /= value;
			v.y /= value;
			v.z /= value;

			return v;
		}

		float float3::length(const float3 & v)
		{
			return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
		}

		float3 float3::normalize(const float3 & v)
		{
			float len = length(v);

			return float3(v.x / len, v.y / len, v.z / len);
		}

		float float3::dotProduct(const float3 & lhs, const float3 & rhs)
		{
			return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
		}

		float3 float3::projectOn(const float3 & lhs, const float3 & rhs)
		{
			float3 thisNormalized = float3::normalize(lhs);
			float dot = float3::dotProduct(thisNormalized, rhs);

			return thisNormalized * dot;
		}

		float3 float3::cross(const float3 & lhs, const float3 & rhs)
		{
			return float3(
				lhs.y * rhs.z - lhs.z * rhs.y,
				lhs.z * rhs.x - lhs.x * rhs.z,
				lhs.x * rhs.y - lhs.y * rhs.x
			);
		}

		float4::float4() :
			x{},
			y{},
			z{},
			w{}
		{
		}

		float4::float4(float x, float y):
			x{ x },
			y{ y },
			z{},
			w{}
		{
		}

		float4::float4(float x, float y, float z):
			x{ x },
			y{ y },
			z{ z },
			w{}
		{
		}

		float4::float4(float x, float y, float z, float w):
			x{ x },
			y{ y },
			z{ z },
			w{ w }
		{
		}

		float4::float4(const float2 & other) :
			x{ other.x },
			y{ other.y },
			z{ },
			w{ }
		{
		}

		float4::float4(const float3 & other) :
			x{ other.x },
			y{ other.y },
			z{ other.z },
			w{ }
		{
		}

		float4::float4(const float4 & other):
			x{ other.x },
			y{ other.y },
			z{ other.z },
			w{ other.w }
		{
		}

		float4 &float4::operator=(const float2 & other)
		{
			x = other.x;
			y = other.y;
			z = 0.0f;
			return *this;
		}

		float4 &float4::operator=(const float3 & other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
			w = 0.0f;
			return *this;
		}

		float4 &float4::operator=(const float4 & other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
			w = other.w;
			return *this;
		}

		float float4::length(const float4 &v)
		{
			return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
		}

		float4 float4::normalize(const float4 & v)
		{
			float len = float4::length(v);

			return float4(v.x / len, v.y / len, v.z / len, v.w / len);
		}

		float float4::dotProduct(const float4 & lhs, const float4 & rhs)
		{
			return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
		}

		bool operator==(const float4 & lhs, const float4 & rhs)
		{
			return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
		}

		float4 operator+(const float4 & lhs, const float4 &rhs)
		{
			return float4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
		}

		float4 operator+=(float4 &lhs, const float4 &rhs)
		{
			lhs.x += rhs.x;
			lhs.y += rhs.y;
			lhs.z += rhs.z;
			lhs.w += rhs.w;

			return lhs;
		}

		float4 operator-(float4 &lhs, const float4 &rhs)
		{
			return float4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
		}

		float4 operator-=(float4 &lhs, const float4 &rhs)
		{
			lhs.x -= rhs.x;
			lhs.y -= rhs.y;
			lhs.z -= rhs.z;
			lhs.w -= rhs.w;

			return lhs;
		}

		float4 operator+(const float4 & lhs, const float value)
		{
			return float4(lhs.x + value, lhs.y + value, lhs.z + value, lhs.w + value);
		}

		float4 operator+=(float4 & lhs, const float value)
		{
			lhs.x += value;
			lhs.y += value;
			lhs.z += value;
			lhs.w += value;

			return lhs;
		}

		float4 operator-(const float4 &v, const float value)
		{
			return float4(v.x - value, v.y - value, v.z - value, v.w - value);
		}

		float4 operator-=(float4 &v, const float value)
		{
			v.x -= value;
			v.y -= value;
			v.z -= value;
			v.w -= value;

			return v;
		}

		float4 operator*(const float4 &v, const float value)
		{
			return float4(v.x * value, v.y * value, v.z * value, v.w * value);
		}

		float4 operator*=(float4 &v, const float value)
		{
			v.x *= value;
			v.y *= value;
			v.z *= value;
			v.w *= value;

			return v;
		}

		float4 operator/(const float4 &v, const float value)
		{
			return float4(v.x / value, v.y / value, v.z / value, v.w / value);
		}

		float4 operator/=(float4 &v, const float value)
		{
			v.x /= value;
			v.y /= value;
			v.z /= value;
			v.w /= value;

			return v;
		}

		float4x4::float4x4()
		{
			m11 = 0.0f; m12 = 0.0f; m13 = 0.0f; m14 = 0.0f;
			m21 = 0.0f; m22 = 0.0f; m23 = 0.0f; m24 = 0.0f;
			m31 = 0.0f; m32 = 0.0f; m33 = 0.0f; m34 = 0.0f;
			m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 = 0.0f;
		}

		float4x4::float4x4(float value)
		{
			m11 = value; m12 = 0.0f; m13 = 0.0f; m14 = 0.0f;
			m21 = 0.0f; m22 = value; m23 = 0.0f; m24 = 0.0f;
			m31 = 0.0f; m32 = 0.0f; m33 = value; m34 = 0.0f;
			m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 = value;
		}

		float4x4::float4x4(float m11_, float m12_, float m13_, float m14_, float m21_, float m22_, float m23_, float m24_, float m31_, float m32_, float m33_, float m34_, float m41_, float m42_, float m43_, float m44_)
		{
			m11 = m11_; m12 = m12_; m13 = m13_; m14 = m14_;
			m21 = m21_; m22 = m22_; m23 = m23_; m24 = m24_;
			m31 = m31_; m32 = m32_; m33 = m33_; m34 = m34_;
			m41 = m41_; m42 = m42_; m43 = m43_; m44 = m44_;
		}

		float4x4::float4x4(const float4 & v1, const float4 & v2, const float4 & v3, const float4 & v4)
		{
			m11 = v1.x; m12 = v1.y; m13 = v1.z; m14 = v1.w;
			m21 = v2.x; m22 = v2.y; m23 = v2.z; m24 = v2.w;
			m31 = v3.x; m32 = v3.y; m33 = v3.z; m34 = v3.w;
			m41 = v4.x; m42 = v4.y; m43 = v4.z; m44 = v4.w;
		}

		float4x4::float4x4(const float4x4 & other)
		{
			m11 = other.m11; m12 = other.m12; m13 = other.m13; m14 = other.m14;
			m21 = other.m21; m22 = other.m22; m23 = other.m23; m24 = other.m24;
			m31 = other.m31; m32 = other.m32; m33 = other.m33; m34 = other.m34;
			m41 = other.m41; m42 = other.m42; m43 = other.m43; m44 = other.m44;
		}

		float4x4 & float4x4::operator=(const float4x4 & other)
		{
			m11 = other.m11; m12 = other.m12; m13 = other.m13; m14 = other.m14;
			m21 = other.m21; m22 = other.m22; m23 = other.m23; m24 = other.m24;
			m31 = other.m31; m32 = other.m32; m33 = other.m33; m34 = other.m34;
			m41 = other.m41; m42 = other.m42; m43 = other.m43; m44 = other.m44;

			return *this;
		}

		bool operator==(const float4x4 &lhs, const float4x4 &rhs)
		{
			return lhs.m11 == rhs.m11 && lhs.m12 == rhs.m12 && lhs.m13 == rhs.m13 && lhs.m14 == rhs.m14
				&& lhs.m21 == rhs.m21 && lhs.m22 == rhs.m22 && lhs.m23 == rhs.m23 && lhs.m24 == rhs.m24
				&& lhs.m31 == rhs.m31 && lhs.m32 == rhs.m32 && lhs.m33 == rhs.m33 && lhs.m34 == rhs.m34
				&& lhs.m41 == rhs.m41 && lhs.m42 == rhs.m42 && lhs.m43 == rhs.m43 && lhs.m44 == rhs.m44;
		}

		float4x4 operator*(const float4x4 &lhs, const float4x4 &rhs)
		{
			float4x4 result = float4x4();

			result.m11 = lhs.m11 * rhs.m11 + lhs.m12 * rhs.m21 + lhs.m13 * rhs.m31 + lhs.m14 * rhs.m41;
			result.m12 = lhs.m11 * rhs.m12 + lhs.m12 * rhs.m22 + lhs.m13 * rhs.m32 + lhs.m14 * rhs.m42;
			result.m13 = lhs.m11 * rhs.m13 + lhs.m12 * rhs.m23 + lhs.m13 * rhs.m33 + lhs.m14 * rhs.m43;
			result.m14 = lhs.m11 * rhs.m14 + lhs.m12 * rhs.m24 + lhs.m13 * rhs.m34 + lhs.m14 * rhs.m44;

			result.m21 = lhs.m21 * rhs.m11 + lhs.m22 * rhs.m21 + lhs.m23 * rhs.m31 + lhs.m24 * rhs.m41;
			result.m22 = lhs.m21 * rhs.m12 + lhs.m22 * rhs.m22 + lhs.m23 * rhs.m32 + lhs.m24 * rhs.m42;
			result.m23 = lhs.m21 * rhs.m13 + lhs.m22 * rhs.m23 + lhs.m23 * rhs.m33 + lhs.m24 * rhs.m43;
			result.m24 = lhs.m21 * rhs.m14 + lhs.m22 * rhs.m24 + lhs.m23 * rhs.m34 + lhs.m24 * rhs.m44;

			result.m31 = lhs.m31 * rhs.m11 + lhs.m32 * rhs.m21 + lhs.m33 * rhs.m31 + lhs.m34 * rhs.m41;
			result.m32 = lhs.m31 * rhs.m12 + lhs.m32 * rhs.m22 + lhs.m33 * rhs.m32 + lhs.m34 * rhs.m42;
			result.m33 = lhs.m31 * rhs.m13 + lhs.m32 * rhs.m23 + lhs.m33 * rhs.m33 + lhs.m34 * rhs.m43;
			result.m34 = lhs.m31 * rhs.m14 + lhs.m32 * rhs.m23 + lhs.m33 * rhs.m34 + lhs.m34 * rhs.m44;

			result.m41 = lhs.m41 * rhs.m11 + lhs.m42 * rhs.m21 + lhs.m43 * rhs.m31 + lhs.m44 * rhs.m41;
			result.m42 = lhs.m41 * rhs.m12 + lhs.m42 * rhs.m22 + lhs.m43 * rhs.m32 + lhs.m44 * rhs.m42;
			result.m43 = lhs.m41 * rhs.m13 + lhs.m42 * rhs.m23 + lhs.m43 * rhs.m33 + lhs.m44 * rhs.m43;
			result.m44 = lhs.m41 * rhs.m14 + lhs.m42 * rhs.m23 + lhs.m43 * rhs.m34 + lhs.m44 * rhs.m44;

			return result;
		}

		float4x4 operator*=(float4x4 &lhs, const float4x4 &rhs)
		{
			lhs.m11 = lhs.m11 * rhs.m11 + lhs.m12 * rhs.m21 + lhs.m13 * rhs.m31 + lhs.m14 * rhs.m41;
			lhs.m12 = lhs.m11 * rhs.m12 + lhs.m12 * rhs.m22 + lhs.m13 * rhs.m32 + lhs.m14 * rhs.m42;
			lhs.m13 = lhs.m11 * rhs.m13 + lhs.m12 * rhs.m23 + lhs.m13 * rhs.m33 + lhs.m14 * rhs.m43;
			lhs.m14 = lhs.m11 * rhs.m14 + lhs.m12 * rhs.m24 + lhs.m13 * rhs.m34 + lhs.m14 * rhs.m44;

			lhs.m21 = lhs.m21 * rhs.m11 + lhs.m22 * rhs.m21 + lhs.m23 * rhs.m31 + lhs.m24 * rhs.m41;
			lhs.m22 = lhs.m21 * rhs.m12 + lhs.m22 * rhs.m22 + lhs.m23 * rhs.m32 + lhs.m24 * rhs.m42;
			lhs.m23 = lhs.m21 * rhs.m13 + lhs.m22 * rhs.m23 + lhs.m23 * rhs.m33 + lhs.m24 * rhs.m43;
			lhs.m24 = lhs.m21 * rhs.m14 + lhs.m22 * rhs.m24 + lhs.m23 * rhs.m34 + lhs.m24 * rhs.m44;

			lhs.m31 = lhs.m31 * rhs.m11 + lhs.m32 * rhs.m21 + lhs.m33 * rhs.m31 + lhs.m34 * rhs.m41;
			lhs.m32 = lhs.m31 * rhs.m12 + lhs.m32 * rhs.m22 + lhs.m33 * rhs.m32 + lhs.m34 * rhs.m42;
			lhs.m33 = lhs.m31 * rhs.m13 + lhs.m32 * rhs.m23 + lhs.m33 * rhs.m33 + lhs.m34 * rhs.m43;
			lhs.m34 = lhs.m31 * rhs.m14 + lhs.m32 * rhs.m23 + lhs.m33 * rhs.m34 + lhs.m34 * rhs.m44;

			lhs.m41 = lhs.m41 * rhs.m11 + lhs.m42 * rhs.m21 + lhs.m43 * rhs.m31 + lhs.m44 * rhs.m41;
			lhs.m42 = lhs.m41 * rhs.m12 + lhs.m42 * rhs.m22 + lhs.m43 * rhs.m32 + lhs.m44 * rhs.m42;
			lhs.m43 = lhs.m41 * rhs.m13 + lhs.m42 * rhs.m23 + lhs.m43 * rhs.m33 + lhs.m44 * rhs.m43;
			lhs.m44 = lhs.m41 * rhs.m14 + lhs.m42 * rhs.m23 + lhs.m43 * rhs.m34 + lhs.m44 * rhs.m44;

			return lhs;
		}

		float4x4 operator*(const float4x4 &lhs, const float value)
		{
			return {
				lhs.m11 * value,
				lhs.m12 * value,
				lhs.m13 * value,
				lhs.m14 * value,
				lhs.m21 * value,
				lhs.m22 * value,
				lhs.m23 * value,
				lhs.m24 * value,
				lhs.m31 * value,
				lhs.m32 * value,
				lhs.m33 * value,
				lhs.m34 * value,
				lhs.m41 * value,
				lhs.m42 * value,
				lhs.m43 * value,
				lhs.m44 * value,
			};
		}

		float4x4 operator*=(float4x4 &lhs, const float value)
		{
			lhs.m11 *= value;
			lhs.m12 *= value;
			lhs.m13 *= value;
			lhs.m14 *= value;
			lhs.m21 *= value;
			lhs.m22 *= value;
			lhs.m23 *= value;
			lhs.m24 *= value;
			lhs.m31 *= value;
			lhs.m32 *= value;
			lhs.m33 *= value;
			lhs.m34 *= value;
			lhs.m41 *= value;
			lhs.m42 *= value;
			lhs.m43 *= value;
			lhs.m44 *= value;

			return lhs;
		}

		float4x4 operator+(const float4x4 &lhs, const float4x4 &rhs)
		{
			return float4x4(
				lhs.m11 + rhs.m11, lhs.m12 + rhs.m12, lhs.m13 + rhs.m13, lhs.m14 + rhs.m14,
				lhs.m21 + rhs.m21, lhs.m22 + rhs.m22, lhs.m23 + rhs.m23, lhs.m24 + rhs.m24,
				lhs.m31 + rhs.m31, lhs.m32 + rhs.m32, lhs.m33 + rhs.m33, lhs.m34 + rhs.m34,
				lhs.m41 + rhs.m41, lhs.m42 + rhs.m42, lhs.m43 + rhs.m43, lhs.m44 + rhs.m44
			);
		}

		float4x4 operator+=(float4x4 &lhs, const float4x4 &rhs)
		{
			lhs.m11 += rhs.m11; lhs.m12 += rhs.m12; lhs.m13 += rhs.m13; lhs.m14 += rhs.m14;
			lhs.m21 += rhs.m21; lhs.m22 += rhs.m22; lhs.m23 += rhs.m23; lhs.m24 += rhs.m24;
			lhs.m31 += rhs.m31; lhs.m32 += rhs.m32; lhs.m33 += rhs.m33; lhs.m34 += rhs.m34;
			lhs.m41 += rhs.m41; lhs.m42 += rhs.m42; lhs.m43 += rhs.m43; lhs.m44 += rhs.m44;

			return lhs;
		}

		float4x4 operator-(const float4x4 &lhs, const float4x4 &rhs)
		{
			return float4x4(
				lhs.m11 - rhs.m11, lhs.m12 - rhs.m12, lhs.m13 - rhs.m13, lhs.m14 - rhs.m14,
				lhs.m21 - rhs.m21, lhs.m22 - rhs.m22, lhs.m23 - rhs.m23, lhs.m24 - rhs.m24,
				lhs.m31 - rhs.m31, lhs.m32 - rhs.m32, lhs.m33 - rhs.m33, lhs.m34 - rhs.m34,
				lhs.m41 - rhs.m41, lhs.m42 - rhs.m42, lhs.m43 - rhs.m43, lhs.m44 - rhs.m44
			);
		}

		float4x4 operator-=(float4x4 &lhs, const float4x4 &rhs)
		{
			lhs.m11 -= rhs.m11; lhs.m12 -= rhs.m12; lhs.m13 -= rhs.m13; lhs.m14 -= rhs.m14;
			lhs.m21 -= rhs.m21; lhs.m22 -= rhs.m22; lhs.m23 -= rhs.m23; lhs.m24 -= rhs.m24;
			lhs.m31 -= rhs.m31; lhs.m32 -= rhs.m32; lhs.m33 -= rhs.m33; lhs.m34 -= rhs.m34;
			lhs.m41 -= rhs.m41; lhs.m42 -= rhs.m42; lhs.m43 -= rhs.m43; lhs.m44 -= rhs.m44;

			return lhs;
		}

		float float4x4::determinant(const float4x4 & mat)
		{
			float a11 = mat.m11; float a12 = mat.m12; float a13 = mat.m13; float a14 = mat.m14;
			float a21 = mat.m21; float a22 = mat.m22; float a23 = mat.m23; float a24 = mat.m24;
			float a31 = mat.m31; float a32 = mat.m32; float a33 = mat.m33; float a34 = mat.m34;
			float a41 = mat.m41; float a42 = mat.m42; float a43 = mat.m43; float a44 = mat.m44;

			float detMatA = det3x3(a22, a23, a24, a32, a33, a34, a42, a43, a44); 

			float detMatB = det3x3(a21, a23, a24, a31, a33, a34, a41, a43, a44);

			float detMatC = det3x3(a21, a22, a24, a31, a32, a34, a41, a42, a44);

			float detMatD = det3x3(a21, a22, a23, a31, a32, a33, a41, a42, a43);
			
			return (a11 * detMatA) - (a12 * detMatB) + (a13 * detMatC)- (a14 * detMatD);
		}

		float4x4 float4x4::transpose(const float4x4 & mat)
		{
			float4x4 result = mat;

			std::swap(result.m12, result.m21);
			std::swap(result.m13, result.m31);
			std::swap(result.m14, result.m41);
			std::swap(result.m24, result.m42);
			std::swap(result.m34, result.m43);
			std::swap(result.m32, result.m23);

			return result;
		}

		float4x4 float4x4::inverse(const float4x4 & mat)
		{
			float4x4 result = float4x4{};

			float a00 = mat.m11, a01 = mat.m12, a02 = mat.m13, a03 = mat.m14;
			float a10 = mat.m21, a11 = mat.m22, a12 = mat.m23, a13 = mat.m24;
			float a20 = mat.m31, a21 = mat.m32, a22 = mat.m33, a23 = mat.m34;
			float a30 = mat.m41, a31 = mat.m42, a32 = mat.m43, a33 = mat.m44;

			float b00 = a00 * a11 - a01 * a10;
			float b01 = a00 * a12 - a02 * a10;
			float b02 = a00 * a13 - a03 * a10;
			float b03 = a01 * a12 - a02 * a11;
			float b04 = a01 * a13 - a03 * a11;
			float b05 = a02 * a13 - a03 * a12;
			float b06 = a20 * a31 - a21 * a30;
			float b07 = a20 * a32 - a22 * a30;
			float b08 = a20 * a33 - a23 * a30;
			float b09 = a21 * a32 - a22 * a31;
			float b10 = a21 * a33 - a23 * a31;
			float b11 = a22 * a33 - a23 * a32;

			float invDet = 1.0f / (b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06);

			result.m11 = (a11 * b11 - a12 * b10 + a13 * b09) * invDet;
			result.m21 = (-a01 * b11 + a02 * b10 - a03 * b09) * invDet;
			result.m31 = (a31 * b05 - a32 * b04 + a33 * b03) * invDet;
			result.m41 = (-a21 * b05 + a22 * b04 - a23 * b03) * invDet;
			result.m12 = (-a10 * b11 + a12 * b08 - a13 * b07) * invDet;
			result.m22 = (a00 * b11 - a02 * b08 + a03 * b07) * invDet;
			result.m32 = (-a30 * b05 + a32 * b02 - a33 * b01) * invDet;
			result.m42 = (a20 * b05 - a22 * b02 + a23 * b01) * invDet;
			result.m13 = (a10 * b10 - a11 * b08 + a13 * b06) * invDet;
			result.m23 = (-a00 * b10 + a01 * b08 - a03 * b06) * invDet;
			result.m33 = (a30 * b04 - a31 * b02 + a33 * b00) * invDet;
			result.m43 = (-a20 * b04 + a21 * b02 - a23 * b00) * invDet;
			result.m14 = (-a10 * b09 + a11 * b07 - a12 * b06) * invDet;
			result.m24 = (a00 * b09 - a01 * b07 + a02 * b06) * invDet;
			result.m34 = (-a30 * b03 + a31 * b01 - a32 * b00) * invDet;
			result.m44 = (a20 * b03 - a21 * b01 + a22 * b00) * invDet;

			return result;
		}

		float4x4 float4x4::translate(const float4x4 & mat, const float3 & v)
		{
			return {
				1.0f, 0.0f, 0.0f, v.x,
				0.0f, 1.0f, 0.0f, v.y,
				0.0f, 0.0f, 1.0f, v.z,
				0.0f, 0.0f, 0.0f, 1.0f
			};
		}

		float4x4 float4x4::scale(const float4x4 & mat, const float3 & s)
		{
			return {
				s.x, 0.0f, 0.0f, 0.0f,
				0.0f, s.y, 0.0f, 0.0f,
				0.0f, 0.0f, s.z, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			};
		}

		float4x4 float4x4::rotationX(const float4x4 & mat, const float theta)
		{
			float4x4 result(1.0f);
			
			result.m22 = cosf(theta);
			result.m23 = -sinf(theta);
			result.m32 = sinf(theta);
			result.m33 = cosf(theta);

			return result;
		}

		float4x4 float4x4::rotationY(const float4x4 & mat, const float theta)
		{
			float4x4 result(1.0f);

			result.m11 = cosf(theta);
			result.m13 = sinf(theta);
			result.m31 = -sinf(theta);
			result.m33 = cosf(theta);

			return result;
		}

		float4x4 float4x4::rotationZ(const float4x4 & mat, const float theta)
		{
			float4x4 result(1.0f);

			result.m11 = cosf(theta);
			result.m12 = -sinf(theta);
			result.m21 = sinf(theta);
			result.m22 = cosf(theta);

			return result;
		}

		float4x4 float4x4::lookAt(const float3 &eye, const float3 &target, const float3 &upDir)
		{
			float3 forward = float3::normalize(eye - target);
			float3 right = float3::normalize(float3::cross(upDir, forward));
			float3 up = float3::cross(right, forward);

			return float4x4(
				right.x, up.x, forward.x, 0.0f,
				right.y, up.y, forward.y, 0.0f,
				right.z, up.z, forward.z, 0.0f,
				float3::dotProduct(right, eye), float3::dotProduct(up, eye), float3::dotProduct(forward, eye), 1.0f
			);
		}

		float4x4 float4x4::createOrthographic(float left, float right, float top, float bottom, float nearPlane, float farPlane)
		{
			float a = 2.0 / ((double)right - (double)left);
			float b = 2.0 / ((double)top - (double)bottom);
			float c = 2.0 / ((double)nearPlane - (double)farPlane);

			float d, e, f;

			d = (((double)left + (double)right) / ((double)left - (double)right));
			e = (float)(((double)top + (double)bottom) / ((double)bottom - (double)top));
			f = (float)((double)nearPlane / ((double)nearPlane - (double)farPlane));

			return float4x4(
				a, 0.0f, 0.0f, 0.0f,
				0.0f, b, 0.0f, 0.0f,
				0.0f, 0.0f, c, 0.0f,
				d, e, f, 1.0f
			);
		}

		float4x4 float4x4::createPerspective(float fov, float aspectRatio, float nearPlane, float farPlane)
		{
			constexpr float pi = std::numbers::pi;
			float yScale = tanf(0.5f * (pi - fov));
			float xScale = yScale / aspectRatio;
			float zRangeInverse = 1.0f / (nearPlane - farPlane);
			float zScale = farPlane * zRangeInverse;
			float zTranslation = nearPlane * farPlane * zRangeInverse;


			return float4x4(
				xScale, 0.0f, 0.0f, 0.0f,
				0.0f, yScale, 0.0f, 0.0f, 
				0.0f, 0.0f, zScale, zTranslation,
				0.0f, 0.0f, -1.0f, 1.0f
			);
		}

}
}