#pragma once
#include <vector>
#include "Math.h"
#include "Structures/ShaderAttribute.h"
#include "Structures/ShaderParameter.h"

namespace GFW
{
	class ISampler;
	class IBuffer;
	class ITexture;
	using namespace std;
	using namespace Math;

	/**
	 * \brief Interface for API specific shader class
	 */
	class IShader
	{
	public:
		virtual ~IShader() = default;

		/**
		 * \brief Interface to initialize a shader from the source code.
		 * \param shaderSource The shaders source code.
		 */
		virtual void Create(const char* shaderSource) = 0;

		/**
		 * \brief Interface to initialize a shader from the source code loaded directly from a file.
		 * \param file The file with the shaders source code.
		 */
		virtual void CreateFromFile(const char* file) = 0;

		/**
		 * \brief Interface for requesting the shader attributes of this shader program.
		 * \return A vector with information about all shader attributes for this shader program.
		 */
		virtual vector<ShaderAttribute> GetShaderAttributes() = 0;

		/**
		 * \brief Interface for requesting information about all shader parameters in this shader program.
		 * \return A vector with information about all shader parameters for this shader program.
		 */
		virtual vector<ShaderParameter> GetShaderParameters() = 0;

		/**
		 * \brief Interface to request information about a specific shader parameter in this shader program by name.
		 * \param name The name of the shader parameter.
		 * \return Information about the shader parameters with name @name.
		 */
		virtual ShaderParameter GetShaderParameter(const string& name) = 0;

		/**
		 * \brief Interface to set bool shader parameter.
		 * \param name The name of the shader parameter.
		 * \param x The value to set the shader parameter to.
		 */
		virtual void SetShaderParameter(const string& name, bool x) = 0;

		/**
		* \brief Interface to set int shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, int x) = 0;

		/**
		* \brief Interface to set unsigned int shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, unsigned x) = 0;

		/**
		* \brief Interface to set float shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, float x) = 0;

		/**
		* \brief Interface to set double shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, double x) = 0;

		/**
		* \brief Interface to set 2 component bool vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const BVec2& x) = 0;

		/**
		* \brief Interface to set 2 component int vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const IVec2& x) = 0;

		/**
		* \brief Interface to set 2 component unsigned int vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const UVec2& x) = 0;

		/**
		* \brief Interface to set 2 component float vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const Vec2& x) = 0;

		/**
		* \brief Interface to set 2 component double vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const DVec2& x) = 0;

		/**
		* \brief Interface to set 3 component bool vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const BVec3& x) = 0;

		/**
		* \brief Interface to set 3 component int vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const IVec3& x) = 0;

		/**
		* \brief Interface to set 3 component unsigned int vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const UVec3& x) = 0;

		/**
		* \brief Interface to set 3 component float vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const Vec3& x) = 0;

		/**
		* \brief Interface to set 3 component double vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const DVec3& x) = 0;

		/**
		* \brief Interface to set 4 component bool vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const BVec4& x) = 0;

		/**
		* \brief Interface to set 4 component int vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const IVec4& x) = 0;

		/**
		* \brief Interface to set 4 component unsigned int vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const UVec4& x) = 0;

		/**
		* \brief Interface to set 4 component float vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const Vec4& x) = 0;

		/**
		* \brief Interface to set 4 component double vector shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const DVec4& x) = 0;

		/**
		* \brief Interface to set 2x2 matrix shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const Mat2& x) = 0;

		/**
		* \brief Interface to set 3x3 matrix shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const Mat3& x) = 0;

		/**
		* \brief Interface to set 4x4 matrix shader parameter.
		* \param name The name of the shader parameter.
		* \param x The value to set the shader parameter to.
		*/
		virtual void SetShaderParameter(const string& name, const Mat4& x) = 0;

		/**
		* \brief Interface to set texture shader parameter.
		* \param name The name of the shader parameter.
		* \param x The texture to bind to the sampler location.
		*/
		virtual void SetShaderParameter(const string& name, const ITexture* x) = 0;

		/**
		* \brief Interface to set sampler shader parameter.
		* \param name The name of the shader parameter.
		* \param x The sampler to bind to the sampler location.
		*/
		virtual void SetShaderParameter(const string& name, const ISampler* x) = 0;

		/**
		* \brief Interface to set buffer shader parameter.
		* \param name The name of the shader parameter.
		* \param x The buffer to bind to the buffer binding.
		*/
		virtual void SetShaderParameter(const string& name, const IBuffer* x) = 0;
	};
}
