#pragma once
#include <memory>

namespace GFW
{
	/**
	 * \brief Enum with texture formats common to most graphics APIs.
	 * R = red channel : G = green channel : B = blue channel : A = alpha channel
	 * SNORM = value between -1 and 1 : F = floating point, value range dependent on the amount of bits : Otherwise value is UNORM = value between 0 and 1
	 * DEPTH and STENCIL formats are meant for depth and stencil framebuffers.
	 * COMPRESSED are compressed texture formats to save memory in return for a slight loss of quality.
	 */
	enum class TextureFormat
	{
		R8,
		R8_SNORM,
		R16,
		R16_SNORM,
		RG8,
		RG8_SNORM,
		RG16,
		RG16_SNORM,
		RGB16_SNORM,
		RGBA8,
		RGBA8_SNORM,
		RGBA16,
		R16F,
		RG16F,
		RGBA16F,
		R32F,
		RG32F,
		RGB32F,
		RGBA32F,
		R8I,
		R8UI,
		R16I,
		R16UI,
		R32I,
		R32UI,
		RG8I,
		RG8UI,
		RG16I,
		RG16UI,
		RG32I,
		RG32UI,
		RGB32I,
		RGB32UI,
		RGBA8I,
		RGBA8UI,
		RGBA16I,
		RGBA16UI,
		RGBA32I,
		RGBA32UI,
		DEPTH_COMPONENT16,
		DEPTH_COMPONENT24,
		DEPTH_COMPONENT32,
		DEPTH_COMPONENT32F,
		DEPTH24_STENCIL8,
		DEPTH32F_STENCIL8,
		STENCIL_INDEX8,
		COMPRESSED_RGB_S3TC_DXT1,
		COMPRESSED_SRGB_S3TC_DXT1,
		COMPRESSED_RGBA_S3TC_DXT1,
		COMPRESSED_SRGB_ALPHA_S3TC_DXT1,
		COMPRESSED_RGBA_S3TC_DXT3,
		COMPRESSED_SRGB_ALPHA_S3TC_DXT3,
		COMPRESSED_RGBA_S3TC_DXT5,
		COMPRESSED_SRGB_ALPHA_S3TC_DXT5,
	};

	/**
	 * \brief Enum for data type commonly used for pixel data.
	 */
	enum class TextureDataType
	{
		GL_UNSIGNED_BYTE, 
		GL_BYTE, 
		GL_UNSIGNED_SHORT, 
		GL_SHORT, 
		GL_UNSIGNED_INT, 
		GL_INT, 
		GL_FLOAT
	};

	enum class TextureMultisampleCount
	{
		NO_MULTISAMPLING/*1 sample per pixel.*/,
		MULTISAMPLE_2X/*Maximum of 2 samples per pixel.*/,
		MULTISAMPLE_4X/*Maximum of 4 samples per pixel.*/,
		MULTISAMPLE_8X/*Maximum of 8 samples per pixel.*/
	};

	/**
	 * \brief Interface for API specific texture class.
	 */
	class ITexture
	{
	public:
		virtual ~ITexture() = default;

		/**
		 * \brief Interface to initialize the texture as either a 1D or 2D texture.
		 * \param width The width of the texture.
		 * \param height The height of the texture. Setting this to 1 will create a 1D texture.
		 * \param generateMipmaps If mipmaps should be generated for this texture.
		 * \param format The format of the texture.
		 * \param type The type of @pixelData.
		 * \param pixelData The pixel data to initialize the texture to. nullptr to only create the storage.
		 */
		virtual void Create(int width, int height, bool generateMipmaps, TextureFormat format, TextureDataType type, unsigned char* pixelData) = 0;

		/**
		 * \brief Interface to initialize the texture as a multisampled 2D texture.
		 * \param width The width of the texture.
		 * \param height The height of the texture.
		 * \param sampleCount The sample count of the texture.
		 * \param format The format of the texture.
		 */
		virtual void Create(int width, int height, TextureMultisampleCount sampleCount, TextureFormat format) = 0;

		/**
		 * \brief Interface to initialize the texture as a 3D texture.
		 * \param width The width of the texture.
		 * \param height The height of the texture.
		 * \param depth The depth of the texture.
		 * \param generateMipmaps If mipmaps should be generated for this texture.
		 * \param format The format of the texture.
		 * \param type The type of @pixelData.
		 * \param pixelData The pixel data to initialize the texture to. nullptr to only create the storage.
		 */
		virtual void Create(int width, int height, int depth, bool generateMipmaps, TextureFormat format, TextureDataType type, unsigned char* pixelData) = 0;

		/**
		 * \brief Interface to initialize the texture as a 1D or 2D texture array.
		 * \param width The width of the texture.
		 * \param height The height of the texture. Setting this to 1 will create a 1D texture.
		 * \param layers The number of textures in the array.
		 * \param generateMipmaps If mipmaps should be generated for each of the textures in the array.
		 * \param format The format of the texture.
		 * \param type The type of @pixelData.
		 * \param pixelData The pixel data to initialize the textures to. nullptr to only create the storage.
		 */
		virtual void CreateArray(int width, int height, int layers, bool generateMipmaps, TextureFormat format, TextureDataType type, unsigned char** pixelData) = 0;

		/**
		 * \brief Interface to initialize the texture as a cubemap.
		 * \param width The width of all faces on the cubemap.
		 * \param height The height of all faces on the cubemap.
		 * \param generateMipmaps If mipmaps should be generated for each of the textures in the array.
		 * \param format The format of the texture.
		 * \param type The type of @pixelData.
		 * \param pixelData The pixel data to initialize each of the six faces of the cubemap to.
		 */
		virtual void CreateCube(int width, int height, bool generateMipmaps, TextureFormat format, TextureDataType type, unsigned char* pixelData[6]) = 0;

		/**
		 * \brief Interface to load a texture from a file. Common file types like PNG, JPG and BMP should be supported. Textures exported from this framework should also be supported.
		 * \param file The texture file to load.
		 * \param mipmaps When set to true mipmaps should get loaded from the file if present and should otherwise be generated. When set to false no mipmaps will be generated but mipmaps present in the file also won't be used.
		 */
		virtual void CreateFromFile(const char* file, bool mipmaps) = 0;

		/**
		 * \brief Interface for updating the contents of a 1D texture.
		 * \param x The offset to start writing at in the texture.
		 * \param width The width in pixels to write to the texture.
		 * \param level The mipmap level to write to.
		 * \param format The format of the texture.
		 * \param type The type of @pixelData.
		 * \param pixelData The pixel data to write to the texture.
		 */
		virtual void UpdateTexture(int x, int width, int level, TextureFormat format, TextureDataType type, unsigned char* pixelData) = 0;

		/**
		 * \brief Interface for updating the contents of a 2D texture of a 1D texture array.
		 * \param x The offset to start writing at in the width of the texture.
		 * \param y The offset to start writing at in the height of the texture or in the case of a 1D texture array the layer to write to.
		 * \param width The width in pixels to write to the texture.
		 * \param height The height in pixels to write to the texture. Should be 1 when updating a 1D texture array.
		 * \param level The mipmap level to write to.
		 * \param format The format of the texture.
		 * \param type The type of @pixelData.
		 * \param pixelData The pixel data to write to the texture.
		 */
		virtual void UpdateTexture(int x, int y, int width, int height, int level, TextureFormat format, TextureDataType type, unsigned char* pixelData) = 0;

		/**
		 * \brief Interface for updating the contents of a 3D texture of a 2D texture array.
		 * \param x The offset to start writing at in the width of the texture.
		 * \param y The offset to start writing at in the height of the texture.
		 * \param z The offset to start writing at in the depth of the texture or in the case of a 2D texture array the layer to write to.
		 * \param width The width in pixels to write to the texture.
		 * \param height The height in pixels to write to the texture.
		 * \param depth The depth in pixels to write to the texture. Should be 1 when updating a 2D texture array.
		 * \param level The mipmap level to write to.
		 * \param format The format of the texture.
		 * \param type The type of @pixelData.
		 * \param pixelData The pixel data to write to the texture.
		 */
		virtual void UpdateTexture(int x, int y, int z, int width, int height, int depth, int level, TextureFormat format, TextureDataType type, unsigned char* pixelData) = 0;
		
		/**
		 * \brief Interface for exporting the texture data directly from the API to a buffer. Usefull for exporting compressed textures.
		 * \param size The size of the exported data.
		 * \return Shared pointer to the exported data.
		 */
		virtual std::shared_ptr<char> Export(int& size) = 0;
	};
}
