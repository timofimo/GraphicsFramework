#pragma once
#include <glm\glm.hpp>
#include <glm\gtx\norm.hpp>
#include <glm\gtx\transform.hpp>

#define TMPL_TYPE template <typename type>

namespace GFW
{
	/**
	 * \brief Small wrapper around some of the most basic math functions.
	 */
	namespace Math
	{
		typedef glm::vec2 Vec2;
		typedef glm::vec3 Vec3;
		typedef glm::vec4 Vec4;
		typedef glm::bvec2 BVec2;
		typedef glm::bvec3 BVec3;
		typedef glm::bvec4 BVec4;
		typedef glm::ivec2 IVec2;
		typedef glm::ivec3 IVec3;
		typedef glm::ivec4 IVec4;
		typedef glm::uvec2 UVec2;
		typedef glm::uvec3 UVec3;
		typedef glm::uvec4 UVec4;
		typedef glm::dvec2 DVec2;
		typedef glm::dvec3 DVec3;
		typedef glm::dvec4 DVec4;
		typedef glm::mat2 Mat2;
		typedef glm::mat3 Mat3;
		typedef glm::mat4 Mat4;
		typedef glm::quat Quaternion;

		TMPL_TYPE auto Sin(const type& x) { return glm::sin(x); }
		TMPL_TYPE auto Cos(const type& x) { return glm::cos(x); }
		TMPL_TYPE auto Tan(const type& x) { return glm::tan(x); }
		TMPL_TYPE auto ASin(const type& x) { return glm::asin(x); }
		TMPL_TYPE auto ACos(const type& x) { return glm::acos(x); }
		TMPL_TYPE auto ATan(const type& x) { return glm::atan(x); }
		TMPL_TYPE auto SinH(const type& x) { return glm::sinh(x); }
		TMPL_TYPE auto CosH(const type& x) { return glm::cosh(x); }
		TMPL_TYPE auto TanH(const type& x) { return glm::tanh(x); }
		TMPL_TYPE auto Abs(const type& x) { return glm::abs(x); }
		TMPL_TYPE auto Sign(const type& x) { return glm::sign(x); }
		TMPL_TYPE auto Floor(const type& x) { return glm::floor(x); }
		TMPL_TYPE auto Ceil(const type& x) { return glm::ceil(x); }
		TMPL_TYPE auto ToDegrees(const type& x) { return glm::degrees(x); }
		TMPL_TYPE auto ToRadians(const type& x) { return glm::radians(x); }

		TMPL_TYPE auto Min(const type& x, const type& y) { return glm::min(x, y); }
		TMPL_TYPE auto Max(const type& x, const type& y) { return glm::max(x, y); }
		TMPL_TYPE auto Lerp(const type& x, const type& y, const type& a) { return glm::lerp(x, y, a); }
		TMPL_TYPE auto Slerp(const type& x, const type& y, const type& a) { return glm::slerp(x, y, a); }
		TMPL_TYPE auto Clamp(const type& x, const type& min, const type& max) { return glm::clamp(x, min, max); }

		TMPL_TYPE type Normalize(const type& vec) { return glm::normalize(vec); }
		TMPL_TYPE auto Length(const type& vec) { return glm::length(vec); }
		TMPL_TYPE auto Length2(const type& vec) { return glm::length2(vec); }
		TMPL_TYPE auto Distance(const type& vec1, const type& vec2) { return glm::distance(vec1, vec2); }
		TMPL_TYPE auto Distance2(const type& vec1, const type& vec2) { return glm::distance2(vec1, vec2); }
		TMPL_TYPE auto Dot(const type& vec1, const type& vec2) { return glm::dot(vec1, vec2); }
		TMPL_TYPE type Cross(const type& vec1, const type& vec2) { return glm::cross(vec1, vec2); }

		inline Vec3 EulerAngles(const Quaternion& quat) { return glm::eulerAngles(quat); }
		inline Quaternion EulerAngles(const Vec3& rotation) { return glm::quat(rotation); }
		inline Quaternion ToQuaternion(const Mat3& mat) { return glm::toQuat(mat); }
		inline Quaternion ToQuaternion(const Mat4& mat) { return glm::toQuat(mat); }
		inline Mat3 ToMat3(const Quaternion& quat) { return glm::toMat3(quat); }
		inline Mat4 ToMat4(const Quaternion& quat) { return glm::toMat4(quat); }
		inline Mat4 Translate(const Vec3& translation) { return glm::translate(translation); }
		inline Mat4 Scale(const Vec3& scale) { return glm::scale(scale); }
		inline Mat4 Rotate(const Vec3& rotation) { return glm::rotate(rotation.z, Vec3(0, 0, 1)) * glm::rotate(rotation.x, Vec3(1, 0, 0)) * glm::rotate(rotation.y, Vec3(0, 1, 0)); }
		inline Mat4 Rotate(const Quaternion& rotation) { return ToMat4(rotation); }

		inline Mat4 LookAt(const Vec3& position, const Vec3& direction, const Vec3& up) { return glm::lookAt(position, position + direction, up); }
		inline Mat4 Perspective(float fovy, float aspect, float zNear, float zFar) { return glm::perspective(fovy, aspect, zNear, zFar); }
		inline Mat4 InfinitePerspective(float fovy, float aspect, float zNear) { return glm::infinitePerspective(fovy, aspect, zNear); }
		inline Mat4 Orthographic(float left, float right, float bottom, float top) { return glm::ortho(left, right, bottom, top); }
	}
}