#pragma once
#include "Math.h"
#include <string>
#include "Interfaces/ITexture.h"
#include "Interfaces/IBuffer.h"

namespace GFW
{
	using namespace Math;
	using namespace std;

	/**
	 * \brief Enum of common types of shader parameters
	 */
	enum class ShaderParameterType
	{
		BOOL, INT, UNSIGNED_INT, FLOAT, DOUBLE,
		BVEC2, IVEC2, UVEC2, VEC2, DVEC2,
		BVEC3, IVEC3, UVEC3, VEC3, DVEC3,
		BVEC4, IVEC4, UVEC4, VEC4, DVEC4,
		MAT2, MAT3, MAT4,
		SAMPLER1D, SAMPLER1DARRAY, SAMPLER2D, SAMPLER2DARRAY,
		SAMPLER3D, SAMPLER2DMS, SAMPLER2DMSARRAY, SAMPLERCUBE,
		UNIFORM_BUFFER, SHADER_STORAGE_BUFFER
	};

	/**
	 * \brief Struct that stores information about a shader parameter.
	 */
	struct ShaderParameter
	{
		string name;				// The name of the shader parameter
		ShaderParameterType type;	// The type of the shader parameter
		union
		{
			int location;			// The location of the shader parameter
			int binding;			// The binding point of a texture sampler or buffer
		};
		union
		{
			bool b;					// Current value of bool shader parameter
			int i;					// Current value of int shader parameter
			unsigned ui;			// Current value of unsigned int shader parameter
			float f;				// Current value of float shader parameter
			double d;				// Current value of double shader parameter
			BVec2 bvec2;			// Current value of bvec2 shader parameter
			IVec2 ivec2;			// Current value of ivec2 shader parameter
			UVec2 uvec2;			// Current value of uvec2 shader parameter
			Vec2 vec2;				// Current value of vec2 shader parameter
			DVec2 dvec2;			// Current value of dvec2 shader parameter
			BVec3 bvec3;			// Current value of bvec3 shader parameter
			IVec3 ivec3;			// Current value of ivec3 shader parameter
			UVec3 uvec3;			// Current value of uvec3 shader parameter
			Vec3 vec3;				// Current value of vec3 shader parameter
			DVec3 dvec3;			// Current value of dvec3 shader parameter
			BVec4 bvec4;			// Current value of bvec4 shader parameter
			IVec4 ivec4;			// Current value of ivec4 shader parameter
			UVec4 uvec4;			// Current value of uvec4 shader parameter
			Vec4 vec4;				// Current value of vec4 shader parameter
			DVec4 dvec4;			// Current value of dvec4 shader parameter
			Mat2 mat2;				// Current value of mat2 shader parameter
			Mat3 mat3;				// Current value of mat3 shader parameter
			Mat4 mat4;				// Current value of mat4 shader parameter
			ITexture* texture;		// Current texture bound to sampler shader parameter
			IBuffer* buffer;		// Current buffer bound to buffer binding point
		};
	};
}
