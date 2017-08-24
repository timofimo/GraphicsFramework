#pragma once
#include "Math.h"

namespace GFW
{
	using namespace Math;

	/**
	 * \brief Enum for commonly used texture filters.
	 */
	enum class SamplerFilter
	{
		NEAREST/*No filtering is applied to the texture. Mipmaps won't be used.*/,
		LINEAR/*Linear filtering is applied to the texture. Mipmaps won't be used.*/,
		NEAREST_MIPMAP_NEAREST/*No filtering is applied to the texture. The nearest mipmap level will be used.*/,
		LINEAR_MIPMAP_NEAREST/*Linear filtering is applied to the texture. The nearest mipmap level will be used.*/,
		NEAREST_MIPMAP_LINEAR/*No filtering is applied to the texture. A linear filter will be applied to the closest two mipmap levels.*/,
		LINEAR_MIPMAP_LINEAR/*Linear filtering is applied to the texture. A linear filter will be applied to the closest two mipmap levels.*/
	};

	/**
	 * \brief Enum for commonly used anisotropic filters.
	 */
	enum class AnisotropicFilter
	{
		FILTER_NONE/*One sample is taken from the texture when filtering.*/,
		FILTER_2X/*A maximum of 2 samples is taken from the texture when filtering.*/,
		FILTER_4X/*A maximum of 4 samples is taken from the texture when filtering.*/,
		FILTER_8X/*A maximum of 8 samples is taken from the texture when filtering.*/,
		FILTER_16X/*A maximum of 16 samples is taken from the texture when filtering.*/
	};

	/**
	 * \brief Enum for commonly used edge sampling operations.
	 */
	enum class EdgeSampling
	{
		REPEAT/*The texture coordinates wrap around the texture.*/,
		MIRRORED_REPEAT/*The texture coordinates wrap around the texture. Mirroring the texture every time it wraps around.*/,
		CLAMP_TO_EDGE/*The texture coordinates are clamped in between 0 and 1.*/,
		CLAMP_TO_BORDER/*Samples taken with texture coordinates outside the 0 to 1 range will equal the border color.*/,
	};

	/**
	 * \brief Interface for API specific sampler class
	 */
	class ISampler
	{
	public:
		virtual ~ISampler() = default;

		/**
		 * \brief Interface to initialize a sampler object.
		 * \param minFilter The type of texture filtering to apply when sampling a texture. Minification filter.
		 * \param magFilter The type of texture filtering to apply when sampling a texture. Magnification filter.
		 * \param anisotropy The maximum amount of anisotropic samples to use when filtering.
		 * \param edgeSampling The type of edge sampling operation to use when sampling a texture.
		 * \param borderColor The border color to use when sampling outside the texture.
		 */
		virtual void Create(SamplerFilter minFilter, SamplerFilter magFilter, AnisotropicFilter anisotropy, EdgeSampling edgeSampling, const Vec4& borderColor) = 0;

		/**
		 * \brief Interface to set the minifaction filter of this sampler.
		 * \param filter The new filter.
		 */
		virtual void SetMinifactionFilter(SamplerFilter filter) = 0;

		/**
		 * \brief Interface to get the current minification filter of this sampler.
		 * \return The current minification filter.
		 */
		virtual SamplerFilter GetMinifactionFilter() = 0;

		/**
		 * \brief Interface to set the magnification filter of this sampler.
		 * \param filter Then new filter.
		 */
		virtual void SetMagnificationFilter(SamplerFilter filter) = 0;

		/**
		 * \brief Interface to get the current magnification filter of this sampler.
		 * \return The current magnification filter.
		 */
		virtual SamplerFilter GetMagnificationFilter() = 0;

		/**
		 * \brief Interface to set the anisotropy to the when filtering a texture using this sampler.
		 * \param anisotropy The new anisotropic filter to use.
		 */
		virtual void SetAnisotropicFilter(AnisotropicFilter anisotropy) = 0;

		/**
		 * \brief Interface to get the current anisotropic filter of this sampler.
		 * \return The current anisotropic filter.
		 */
		virtual AnisotropicFilter GetAnisotropicFilter() = 0;

		/**
		 * \brief Interface to set the edge sampling operation of this sampler.
		 * \param edgeSampling The new edge sampling operation.
		 */
		virtual void SetEdgeSamplingOperation(EdgeSampling edgeSampling) = 0;

		/**
		 * \brief Interface to get the current edge sampling operation of this sampler.
		 * \return The current edge sampling operation.
		 */
		virtual EdgeSampling GetEdgeSamplingOperation() = 0;

		/**
		 * \brief Interface to set the border color of this sampler.
		 * \param color The new border color.
		 */
		virtual void SetBorderColor(const Vec4& color) = 0;

		/**
		 * \brief Interface to get the current border color of this sampler.
		 * \return The current border color.
		 */
		virtual Vec4 GetBorderColor() = 0;
	};
}