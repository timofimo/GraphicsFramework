#pragma once
#include "Math.h"

namespace GFW
{
	using namespace Math;

	/**
	 * \brief Enum with all rasterization modes.
	 */
	enum class RasterizationMode 
	{
		FILL/*Fill triangle interior*/,
		LINE/*Draw triangle edges as lines*/,
		POINTS/*Draw triangle edges as points*/
	};

	/**
	 * \brief Enum with all possible face directions during rasterization.
	 */
	enum class FaceDirection 
	{
		FRONT/*Front faces, pointing towards the camera*/,
		BACK/*Back faces, pointing away from the camera*/,
		FRONT_AND_BACK/*Both front and back faces i.e. all faces*/
	};

	/**
	 * \brief Enum with comparative functions common to graphics APIs.
	 */
	enum class TestFunction 
	{
		NEVER/*Function always fails*/,
		ALWAYS/*Function always passes*/,
		LESS/*Function passes if first value is less than the other*/,
		LEQUAL/*Function passes if first value is less than or equal to the other*/,
		GREATER/*Function passes if the first value is greater than the other*/,
		GEQUAL/*Function passes if the first value is greater than or equal to the other*/,
		EQUAL/*Function passes if the values are equal to each other*/,
		NOTEQUAL/*Function passes if the values don't equal each other*/
	};

	/**
	 * \brief Enum with operations to perform when a test passed. Common to most graphics APIs.
	 */
	enum class TestOperation 
	{
		KEEP/*Keep the value*/,
		ZERO/*Set the value to 0*/,
		INCREMENT/*Increment the value by 1*/,
		DECREMENT/*Decrement the value by 1*/,
		INVERT/*Invert the bits of the value*/,
		REPLACE/*Replace the value with the reference value*/,
		INCREMENT_WRAP/*Increment the value. Wrap to 0 if the maximum is exceeded*/,
		DECREMENT_WRAP/*Decrement the value. Wrap to the maximum when going below 0*/
	};

	/**
	 * \brief Enum with blend function common to graphics APIs.
	 */
	enum class BlendFunction 
	{
		ZERO/*Color doesn't contribute to the result*/,
		ONE/*Color is added to the result*/,
		SRC_COLOR/*Color is multiplied with the source color before adding to the result*/,
		ONE_MIN_SRC_COLOR/*Color is multiplied with 1 - the source color before adding to the result*/,
		DST_COLOR/*Color is multiplied with the destinations color before adding to the result*/,
		ONE_MIN_DST_COLOR/*Color is multiplied with 1 - the destination color before adding to the result*/,
		SRC_ALPHA/*Color is multiplied by the alpha value of the source before adding to the result*/,
		ONE_MIN_SRC_ALPHA/*Color is multiplied by 1 - the alpha vlaue of the source before adding to the result*/,
		DST_ALPHA/*The color is multiplied by the alpha value of the destination before adding to the result*/,
		ONE_MIN_DST_ALPHA/*The color is mulitplied by 1 - the alpha value of the destination before adding to the result*/
	};

	/**
	 * \brief Interface for methods that change the state of the context.
	 */
	class IContextStateFunctions
	{
	public:
		virtual ~IContextStateFunctions() = default;

		/**
		 * \brief Interface for setting the viewport of the context.
		 * \param position The corner position where the viewport starts.
		 * \param dimensions The width and height of the viewport.
		 */
		virtual void SetViewport(const Vec2& position, const Vec2& dimensions) = 0;

		/**
		 * \brief Interface for setting the depth range of the context.
		 * \param min The low end of the depth range.
		 * \param max The high end of the depth range.
		 */
		virtual void SetDepthRange(float min, float max) = 0;

		/**
		 * \brief Interface for setting the size of points drawn using the context.
		 * \param size The size of a point in pixels.
		 */
		virtual void SetPointSize(float size) = 0;

		/**
		 * \brief Interface for enabling/disabling antialiasing on points drawn using the context.
		 * \param enabled If antialiasing should be enabled for points.
		 */
		virtual void SetPointAntialiasing(bool enabled) = 0;

		/**
		 * \brief Interface for setting the width of lines drawn using the context.
		 * \param width The width of a line in pixels.
		 */
		virtual void SetLineWidth(float width) = 0;

		/**
		 * \brief Interface for enabling/disabling antialiasing on lines draw the context.
		 * \param enabled If antialiasing should be enabled for lines.
		 */
		virtual void SetLineAntialiasing(bool enabled) = 0;

		/**
		 * \brief Interface for enabling/disabling face culling.
		 * \param enabled If face culling should be enabled.
		 */
		virtual void SetCullFace(bool enabled) = 0;

		/**
		 * \brief Interface to set front or back facing faces to get culled.
		 * \param backFacing If back faces should get culled. Setting this to false will set front faces to get culled.
		 */
		virtual void SetFacesToCull(bool backFacing) = 0;

		/**
		 * \brief Interface for setting the winding order of front faces.
		 * \param counterClockwise If front faces have a counter clockwise winding order. Setting this to false will make faces with clockwise winding order front faces.
		 */
		virtual void SetFrontFace(bool counterClockwise) = 0;

		/**
		 * \brief Interface to set how polygons should get rasterised when drawn with this context.
		 * \param mode The rasterization mode for the polygons.
		 */
		virtual void SetPolygonRasterization(RasterizationMode mode) = 0;

		/**
		* \brief Interface for enabling/disabling stencil testing.
		* \param enabled If stencil testing should be enabled.
		*/
		virtual void SetStencilTest(bool enabled) = 0;
		
		/**
		 * \brief Interface for setting the test function to use when doing the stencil test for front, back or all faces.
		 * \param face The face to change the function for.
		 * \param function The function to set it to.
		 */
		virtual void SetStencilFunction(FaceDirection face, TestFunction function) = 0;

		/**
		 * \brief Interface for setting the stencil mask to use when doing the stencil test for front, back or all faces.
		 * \param face The face to change the mask for.
		 * \param mask The mask to set it to.
		 */
		virtual void SetStencilMask(FaceDirection face, int mask) = 0;

		/**
		 * \brief Interface for setting the operation to use when the stencil test fails, the depth test fails or both tests pass for front, back or all faces.
		 * \param face The face to change the operation for.
		 * \param stencilFails The operation to use when the stencil test fails.
		 * \param depthFails The operation to use when the depth test fails.
		 * \param pass The operation to use when both tests pass.
		 */
		virtual void SetStencilOperation(FaceDirection face, TestOperation stencilFails, TestOperation depthFails, TestOperation pass) = 0;

		/**
		* \brief Interface for enabling/disabling alpha testing.
		* \param enabled If alpha testing should be enabled.
		*/
		virtual void SetAlphaTest(bool enabled) = 0;

		/**
		 * \brief Interface for setting the function to use when alpha testing.
		 * \param function The function to use when alpha testing.
		 * \param ref The value the test should reference i.e. is relative to.
		 */
		virtual void SetAlphaFunction(TestFunction function, float ref) = 0;

		/**
		* \brief Interface for enabling/disabling depth testing.
		* \param enabled If depth testing should be enabled.
		*/
		virtual void SetDepthTest(bool enabled) = 0;

		/**
		 * \brief Interface for setting the function to use when depth testing.
		 * \param function The function to use when depth testing.
		 */
		virtual void SetDepthFunction(TestFunction function) = 0;

		/**
		* \brief Interface for enabling/disabling blending.
		* \param enabled If blending should be enabled.
		*/
		virtual void SetBlend(bool enabled) = 0;

		/**
		 * \brief Interface for setting the blend function for the source and destination colors.
		 * \param sourceFunc The function to use for the source color.
		 * \param destinationFunc The function to use for the destination color.
		 */
		virtual void SetBlendFunction(BlendFunction sourceFunc, BlendFunction destinationFunc) = 0;

		/**
		 * \brief Interface for setting the color to clear the color buffer to when clearing the screen.
		 * \param color The color to fill the buffer with when clearing.
		 */
		virtual void SetColorClearValue(const Vec4& color) = 0;

		/**
		 * \brief Interface for setting the depth to clear the depth buffer to when clearing the screen.
		 * \param depth The depth value to fill the depth buffer with when clearing.
		 */
		virtual void SetDepthClearValue(float depth) = 0;

		/**
		 * \brief Interface for setting the stencil value to clear the stencil buffer to when clearing the screen.
		 * \param stencil The stencil value to fill the stencil buffer with when clearing.
		 */
		virtual void SetStencilClearValue(int stencil) = 0;
	};
}
