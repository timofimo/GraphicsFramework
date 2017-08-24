#pragma once

namespace GFW
{
	/**
	 * \brief Enum of commonly used shader attribute types.
	 */
	enum class ShaderAttributeType
	{
		BOOL, INT, UNSIGNED_INT, FLOAT, DOUBLE,
		BVEC2, IVEC2, UVEC2, VEC2, DVEC2,
		BVEC3, IVEC3, UVEC3, VEC3, DVEC3,
		BVEC4, IVEC4, UVEC4, VEC4, DVEC4,
		MAT2, MAT3, MAT4
	};

	/**
	 * \brief Struct that stores information about a shader attribute.
	 */
	struct ShaderAttribute
	{
		ShaderAttributeType type;	// The type of the attribute
		int location;				// The location of the attribute
	};
}