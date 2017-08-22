#include <ContextState.h>
#include "Logging.h"

/**
 * \brief Creates the context state and sets the state of the graphics API to equal the default values if they don't already.
 * \param stateFunctions 
 */
GFW::ContextState::ContextState(IContextStateFunctions* stateFunctions) : m_stateFunctions(stateFunctions)
{
	GFW_ASSERT(m_stateFunctions != nullptr);
	InitializeState();
}

GFW::ContextState::~ContextState()
{
	if(m_stateFunctions)
	{
		delete m_stateFunctions;
		m_stateFunctions = nullptr;
	}
}

/**
 * \brief Record the state. Use RestoreRecordedState() to go back to this state.
 */
void GFW::ContextState::RecordState()
{
	m_recordedState = m_currentState;
}

/**
 * \brief Restores the context to the last recorded state.
 */
void GFW::ContextState::RestoreRecordedState()
{
	m_currentState = m_recordedState;

	SetDepthRange(m_currentState.depthRangeMin, m_currentState.depthRangeMax);
	SetPointSize(m_currentState.pointSize);
	SetPointAntialiasing(m_currentState.pointAntialiasing);
	SetLineWidth(m_currentState.lineWidth);
	SetLineAntialiasing(m_currentState.lineAntialiasing);
	SetFaceCulling(m_currentState.faceCullingEnabled);
	SetFacesToCull(m_currentState.cullBackFace);
	SetFrontFace(m_currentState.frontFaceCounterClockwise);
	SetPolygonRasterization(m_currentState.polygonRasterization);
	SetStencilTest(m_currentState.stencilTestEnabled);
	SetStencilFunction(FaceDirection::FRONT_AND_BACK, m_currentState.frontFaceStencilFunction);
	SetStencilMask(FaceDirection::FRONT_AND_BACK, m_currentState.frontFaceStencilMask);
	SetStencilOperation(FaceDirection::FRONT_AND_BACK, m_currentState.frontFaceStencilOperation[0], m_currentState.frontFaceStencilOperation[1], m_currentState.frontFaceStencilOperation[2]);
	SetAlphaTest(m_currentState.alphaTestEnabled);
	SetAlphaFunction(m_currentState.alphaTestFunction, m_currentState.alphaTestReference);
	SetDepthTest(m_currentState.depthTestEnabled);
	SetDepthFunction(m_currentState.depthTestFunction);
	SetBlend(m_currentState.blendEnabled);
	SetBlendFunction(m_currentState.sourceBlendFunction, m_currentState.destinationBlendFunction);
	SetColorClearValue(m_currentState.clearColor);
	SetDepthClearValue(m_currentState.clearDepth);
	SetStencilClearValue(m_currentState.clearStencil);
}

/**
 * \brief Set the position and the dimensions of the viewport.
 * \param position The position of the viewport.
 * \param dimensions The dimentions of the viewport.
 */
void GFW::ContextState::SetViewport(const Vec2& position, const Vec2& dimensions)
{
	if (m_currentState.viewportPosition != position || m_currentState.viewportDimensions != dimensions)
	{
		m_stateFunctions->SetViewport(position, dimensions);
		m_currentState.viewportPosition = position;
		m_currentState.viewportDimensions = dimensions;
	}
}

/**
 * \return The set position of the viewport.
 */
GFW::Vec2 GFW::ContextState::GetViewportPosition() const
{
	return m_currentState.viewportPosition;
}

/**
 * \return The set dimensions of the viewport.
 */
GFW::Vec2 GFW::ContextState::GetViewportDimensions() const
{
	return m_currentState.viewportDimensions;
}

/**
 * \brief Set the low and high end of the depth range.
 * \param min The low end of the depth range.
 * \param max The high end of the depth range.
 */
void GFW::ContextState::SetDepthRange(float min, float max)
{
	if(m_currentState.depthRangeMin != min || m_currentState.depthRangeMax != max)
	{
		m_stateFunctions->SetDepthRange(min, max);
		m_currentState.depthRangeMin = min;
		m_currentState.depthRangeMax = max;
	}
}

/**
 * \brief The low and high end of the set depth range.
 * \param min output the low end of the depth range.
 * \param max output the high end of the depth range.
 */
void GFW::ContextState::GetDepthRange(float& min, float& max) const
{
	min = m_currentState.depthRangeMin;
	max = m_currentState.depthRangeMax;
}

/**
 * \brief Set the point size when drawing points.
 * \param size The point size in pixels.
 */
void GFW::ContextState::SetPointSize(float size)
{
	if(m_currentState.pointSize != size)
	{
		m_stateFunctions->SetPointSize(size);
		m_currentState.pointSize = size;
	}
}

/**
 * \return The set point size in pixels.
 */
float GFW::ContextState::GetPointSize() const
{
	return m_currentState.pointSize;
}

/**
 * \brief Enable/Disable antialiasing for points.
 * \param enabled If antialiasing should be enabled.
 */
void GFW::ContextState::SetPointAntialiasing(bool enabled)
{
	if(m_currentState.pointAntialiasing != enabled)
	{
		m_stateFunctions->SetPointAntialiasing(enabled);
		m_currentState.pointAntialiasing = enabled;
	}
}

/**
 * \return If antialiasing for points is enabled.
 */
bool GFW::ContextState::IsPointAntialiasingEnabled() const
{
	return m_currentState.pointAntialiasing;
}

/**
 * \brief Set the line width when drawing lines.
 * \param width The width in pixels.
 */
void GFW::ContextState::SetLineWidth(float width)
{
	if(m_currentState.lineWidth != width)
	{
		m_stateFunctions->SetLineWidth(width);
		m_currentState.lineWidth = width;
	}
}

/**
 * \return The set line width in pixels.
 */
float GFW::ContextState::GetLineWidth() const
{
	return m_currentState.lineWidth;
}

/**
 * \brief Enable/Disable antialiasing for lines.
 * \param enabled If antialiasing should be enabled.
 */
void GFW::ContextState::SetLineAntialiasing(bool enabled)
{
	if(m_currentState.lineAntialiasing != enabled)
	{
		m_stateFunctions->SetLineAntialiasing(enabled);
		m_currentState.lineAntialiasing = enabled;
	}
}

/**
 * \return If antialiasing for lines is enabled.
 */
bool GFW::ContextState::IsLineAntialiasingEnabled() const
{
	return m_currentState.lineAntialiasing;
}

/**
 * \brief Enable/Disable face culling.
 * \param enabled If face culling should be enabled.
 */
void GFW::ContextState::SetFaceCulling(bool enabled)
{
	if(m_currentState.faceCullingEnabled != enabled)
	{
		m_stateFunctions->SetCullFace(enabled);
		m_currentState.faceCullingEnabled = enabled;
	}
}

/**
 * \return If face culling is enabled.
 */
bool GFW::ContextState::IsFaceCullingEnabled() const
{
	return m_currentState.faceCullingEnabled;
}

/**
 * \brief Set the faces to be culled when face culling is enabled.
 * \param backFacing If back faces should be culled.
 */
void GFW::ContextState::SetFacesToCull(bool backFacing)
{
	if(m_currentState.cullBackFace != backFacing)
	{
		m_stateFunctions->SetFacesToCull(backFacing);
		m_currentState.cullBackFace = backFacing;
	}
}

/**
 * \return If the faces to be culled are back faces.
 */
bool GFW::ContextState::IsCullingBackFaces() const
{
	return m_currentState.cullBackFace;
}

/**
 * \brief Set the winding order of front faces.
 * \param counterClockwise If the winding order for front faces should be counter clockwise.
 */
void GFW::ContextState::SetFrontFace(bool counterClockwise)
{
	if(m_currentState.frontFaceCounterClockwise != counterClockwise)
	{
		m_stateFunctions->SetFrontFace(counterClockwise);
		m_currentState.frontFaceCounterClockwise = counterClockwise;
	}
}

/**
 * \return If front faces are counter clockwise.
 */
bool GFW::ContextState::FrontFaceIsCounterClockwise() const
{
	return m_currentState.frontFaceCounterClockwise;
}

/**
 * \brief Set the mode to use when rasterizing polygons.
 * \param mode The mode to set.
 */
void GFW::ContextState::SetPolygonRasterization(RasterizationMode mode)
{
	if(m_currentState.polygonRasterization != mode)
	{
		m_stateFunctions->SetPolygonRasterization(mode);
		m_currentState.polygonRasterization = mode;
	}
}

/**
 * \return The set mode to use when rasterizing polygons.
 */
GFW::RasterizationMode GFW::ContextState::GetPolygonRasterization() const
{
	return m_currentState.polygonRasterization;
}

/**
 * \brief Enable/Disable stencil testing.
 * \param enabled If stencil testing should be enabled.
 */
void GFW::ContextState::SetStencilTest(bool enabled)
{
	if(m_currentState.stencilTestEnabled != enabled)
	{
		m_stateFunctions->SetStencilTest(enabled);
		m_currentState.stencilTestEnabled = enabled;
	}
}

/**
 * \return If stencil testing is enabled.
 */
bool GFW::ContextState::IsStencilTestEnabled() const
{
	return m_currentState.stencilTestEnabled;
}

/**
 * \brief Set the function to use when stencil testing.
 * \param face The faces to set the function for.
 * \param function The function to set.
 */
void GFW::ContextState::SetStencilFunction(FaceDirection face, TestFunction function)
{
	switch(face)
	{
	case FaceDirection::FRONT: 
		if(m_currentState.frontFaceStencilFunction != function)
		{
			m_stateFunctions->SetStencilFunction(face, function);
			m_currentState.frontFaceStencilFunction = function;
		}
		break;
	case FaceDirection::BACK:
		if (m_currentState.backFaceStencilFunction != function)
		{
			m_stateFunctions->SetStencilFunction(face, function);
			m_currentState.backFaceStencilFunction = function;
		}
		break;
	case FaceDirection::FRONT_AND_BACK:
		if (m_currentState.frontFaceStencilFunction != function || m_currentState.backFaceStencilFunction != function)
		{
			m_stateFunctions->SetStencilFunction(face, function);
			m_currentState.frontFaceStencilFunction = function;
			m_currentState.backFaceStencilFunction = function;
		}
		break;
	default: ;
	}
}

/**
* \return The stencil function to use when stencil testing front faces.
*/
GFW::TestFunction GFW::ContextState::GetFrontFaceStencilFunction() const
{
	return m_currentState.frontFaceStencilFunction;
}

/**
* \return The stencil function to use when stencil testing back faces.
*/
GFW::TestFunction GFW::ContextState::GetBackFaceStencilFunction() const
{
	return m_currentState.backFaceStencilFunction;
}

/**
 * \return The stencil function to use when stencil testing both front and back faces. Asserts if the function of front and back faces don't equal each other.
 */
GFW::TestFunction GFW::ContextState::GetStencilFunction() const
{
	GFW_ASSERT(m_currentState.frontFaceStencilFunction == m_currentState.backFaceStencilFunction);
	return m_currentState.frontFaceStencilFunction;
}

/**
 * \brief Set the stencil mask to use when stencil testing.
 * \param face The faces to set the mask for.
 * \param mask The mask to set.
 */
void GFW::ContextState::SetStencilMask(FaceDirection face, int mask)
{
	switch (face)
	{
	case FaceDirection::FRONT:
		if (m_currentState.frontFaceStencilMask != mask)
		{
			m_stateFunctions->SetStencilMask(face, mask);
			m_currentState.frontFaceStencilMask = mask;
		}
		break;
	case FaceDirection::BACK:
		if (m_currentState.backFaceStencilMask != mask)
		{
			m_stateFunctions->SetStencilMask(face, mask);
			m_currentState.backFaceStencilMask = mask;
		}
		break;
	case FaceDirection::FRONT_AND_BACK:
		if (m_currentState.frontFaceStencilMask != mask || m_currentState.backFaceStencilMask != mask)
		{
			m_stateFunctions->SetStencilMask(face, mask);
			m_currentState.frontFaceStencilMask = mask;
			m_currentState.backFaceStencilMask = mask;
		}
		break;
	default:;
	}
}

/**
* \return The set stencil mask to use when stencil testing for front faces.
*/
int GFW::ContextState::GetFrontFaceStencilMask() const
{
	return m_currentState.frontFaceStencilMask;
}

/**
* \return The set stencil mask to use when stencil testing for back faces.
*/
int GFW::ContextState::GetBackFaceStencilMask() const
{
	return m_currentState.backFaceStencilMask;
}

/**
 * \return The set stencil mask to use when stencil testing for both front and back faces. Asserts if the mask of front and back faces don't equal each other.
 */
int GFW::ContextState::GetStencilMask() const
{
	GFW_ASSERT(m_currentState.frontFaceStencilMask == m_currentState.backFaceStencilMask);
	return m_currentState.frontFaceStencilMask;
}

/**
 * \brief Set the operations to use when the stencil test fails, the depth test fails or both pass.
 * \param face The faces to set these operations for.
 * \param stencilFails The operation to use when the stencil test fails.
 * \param depthFails The operation to use when the depth test fails.
 * \param pass The operation to use when both tests pass.
 */
void GFW::ContextState::SetStencilOperation(FaceDirection face, TestOperation stencilFails, TestOperation depthFails, TestOperation pass)
{
	switch (face)
	{
	case FaceDirection::FRONT:
		if (m_currentState.frontFaceStencilOperation[0] != stencilFails || m_currentState.frontFaceStencilOperation[1] != depthFails || m_currentState.frontFaceStencilOperation[2] != pass)
		{
			m_stateFunctions->SetStencilOperation(face, stencilFails, depthFails, pass);
			m_currentState.frontFaceStencilOperation[0] = stencilFails;
			m_currentState.frontFaceStencilOperation[1] = depthFails;
			m_currentState.frontFaceStencilOperation[2] = pass;
		}
		break;
	case FaceDirection::BACK:
		if (m_currentState.backFaceStencilOperation[0] != stencilFails || m_currentState.backFaceStencilOperation[1] != depthFails || m_currentState.backFaceStencilOperation[2] != pass)
		{
			m_stateFunctions->SetStencilOperation(face, stencilFails, depthFails, pass);
			m_currentState.backFaceStencilOperation[0] = stencilFails;
			m_currentState.backFaceStencilOperation[1] = depthFails;
			m_currentState.backFaceStencilOperation[2] = pass;
		}
		break;
	case FaceDirection::FRONT_AND_BACK:
		if (m_currentState.frontFaceStencilOperation[0] != stencilFails || m_currentState.frontFaceStencilOperation[1] != depthFails || m_currentState.frontFaceStencilOperation[2] != pass ||
			m_currentState.backFaceStencilOperation[0] != stencilFails || m_currentState.backFaceStencilOperation[1] != depthFails || m_currentState.backFaceStencilOperation[2] != pass)
		{
			m_stateFunctions->SetStencilOperation(face, stencilFails, depthFails, pass);
			m_currentState.frontFaceStencilOperation[0] = stencilFails;
			m_currentState.frontFaceStencilOperation[1] = depthFails;
			m_currentState.frontFaceStencilOperation[2] = pass;
			m_currentState.backFaceStencilOperation[0] = stencilFails;
			m_currentState.backFaceStencilOperation[1] = depthFails;
			m_currentState.backFaceStencilOperation[2] = pass;
		}
		break;
	default:;
	}
}

/**
* \return The stencil operations to use when the stencil test fails, the depth test fails or both tests pass for front faces.
* \param stencilFails output for the operation when the stencil test fails.
* \param depthFails output for the opertation when the depth test fails.
* \param pass output for the opertation when both tests pass.
*/
void GFW::ContextState::GetFrontFaceStencilOperation(TestOperation& stencilFails, TestOperation& depthFails, TestOperation& pass) const
{
	stencilFails = m_currentState.frontFaceStencilOperation[0];
	depthFails = m_currentState.frontFaceStencilOperation[1];
	pass = m_currentState.frontFaceStencilOperation[2];
}

/**
* \return The stencil operations to use when the stencil test fails, the depth test fails or both tests pass for back faces.
* \param stencilFails output for the operation when the stencil test fails.
* \param depthFails output for the opertation when the depth test fails.
* \param pass output for the opertation when both tests pass.
*/
void GFW::ContextState::GetBackFaceStencilOperation(TestOperation& stencilFails, TestOperation& depthFails, TestOperation& pass) const
{
	stencilFails = m_currentState.backFaceStencilOperation[0];
	depthFails = m_currentState.backFaceStencilOperation[1];
	pass = m_currentState.backFaceStencilOperation[2];
}

/**
 * \return The stencil operations to use when the stencil test fails, the depth test fails or both tests pass for both front and back faces. Asserts if operations of the front and back face are not equal to each other.
 * \param stencilFails output for the operation when the stencil test fails.
 * \param depthFails output for the opertation when the depth test fails.
 * \param pass output for the opertation when both tests pass.
 */
void GFW::ContextState::GetStencilOperation(TestOperation& stencilFails, TestOperation& depthFails, TestOperation& pass) const
{
	GFW_ASSERT(m_currentState.frontFaceStencilOperation[0] == m_currentState.backFaceStencilOperation[0] && m_currentState.frontFaceStencilOperation[1] == m_currentState.backFaceStencilOperation[1] && m_currentState.frontFaceStencilOperation[2] == m_currentState.backFaceStencilOperation[1])
	stencilFails = m_currentState.frontFaceStencilOperation[0];
	depthFails = m_currentState.frontFaceStencilOperation[1];
	pass = m_currentState.frontFaceStencilOperation[2];
}

/**
 * \brief Enable/Disable alpha testing.
 * \param enabled If alpha testing should be enabled.
 */
void GFW::ContextState::SetAlphaTest(bool enabled)
{
	if(m_currentState.alphaTestEnabled != enabled)
	{
		m_stateFunctions->SetAlphaTest(enabled);
		m_currentState.alphaTestEnabled = enabled;
	}
}

/**
 * \return If alpha testing is enabled.
 */
bool GFW::ContextState::IsAlphaTestEnabled() const
{
	return m_currentState.alphaTestEnabled;
}

/**
 * \brief Set the function and the reference value to use when alpha testing.
 * \param function The function to use when alpha testing.
 * \param ref The reference value to use when alpha testing.
 */
void GFW::ContextState::SetAlphaFunction(TestFunction function, float ref)
{
	if(m_currentState.alphaTestFunction != function || m_currentState.alphaTestReference != ref)
	{
		m_stateFunctions->SetAlphaFunction(function, ref);
		m_currentState.alphaTestFunction = function;
		m_currentState.alphaTestReference = ref;
	}
}

/**
 * \return The set function and the reference value to use when alpha testing.
 * \param function output for the function.
 * \param ref output for the reference value.
 */
void GFW::ContextState::GetAlphaFunction(TestFunction& function, float& ref) const
{
	function = m_currentState.alphaTestFunction;
	ref = m_currentState.alphaTestReference;
}

/**
 * \brief Enable/Disable depth testing.
 * \param enabled If depth testing should be enabled.
 */
void GFW::ContextState::SetDepthTest(bool enabled)
{
	if(m_currentState.depthTestEnabled != enabled)
	{
		m_stateFunctions->SetDepthTest(enabled);
		m_currentState.depthTestEnabled = enabled;
	}
}

/**
 * \return If depth testing is enabled.
 */
bool GFW::ContextState::IsDepthTestEnabled() const
{
	return m_currentState.depthTestEnabled;
}

/**
 * \brief Set the function to use when depth testing.
 * \param function The function to use when depth testing.
 */
void GFW::ContextState::SetDepthFunction(TestFunction function)
{
	if(m_currentState.depthTestFunction != function)
	{
		m_stateFunctions->SetDepthFunction(function);
		m_currentState.depthTestFunction = function;
	}
}

/**
 * \return The set function to use when depth testing.
 */
GFW::TestFunction GFW::ContextState::GetDepthFunction() const
{
	return m_currentState.depthTestFunction;
}

/**
 * \brief Enable/Disable blending.
 * \param enabled If blending should be enabled.
 */
void GFW::ContextState::SetBlend(bool enabled)
{
	if(m_currentState.blendEnabled != enabled)
	{
		m_stateFunctions->SetBlend(enabled);
		m_currentState.blendEnabled = enabled;
	}
}

/**
 * \return If blending is enabled.
 */
bool GFW::ContextState::IsBlendingEnabled() const
{
	return m_currentState.blendEnabled;
}

/**
 * \brief Set the blend function to use when blending.
 * \param sourceFunc The function to use when blending the source color.
 * \param destinationFunc The function to use when blending the destination color.
 */
void GFW::ContextState::SetBlendFunction(BlendFunction sourceFunc, BlendFunction destinationFunc)
{
	if(m_currentState.sourceBlendFunction != sourceFunc || m_currentState.destinationBlendFunction != destinationFunc)
	{
		m_stateFunctions->SetBlendFunction(sourceFunc, destinationFunc);
		m_currentState.sourceBlendFunction = sourceFunc;
		m_currentState.destinationBlendFunction = destinationFunc;
	}
}

/**
 * \return The set blend function to use on the source color when blending.
 */
GFW::BlendFunction GFW::ContextState::GetSourceBlendFunction() const
{
	return m_currentState.sourceBlendFunction;
}

/**
 * \return The set blend function to use on the destination color when blending.
 */
GFW::BlendFunction GFW::ContextState::GetDestinationBlendFunction() const
{
	return m_currentState.destinationBlendFunction;
}

/**
 * \brief Set the value to clear the color buffer to when clearing.
 * \param color The value to clear the color buffer to.
 */
void GFW::ContextState::SetColorClearValue(const Vec4& color)
{
	if(m_currentState.clearColor != color)
	{
		m_stateFunctions->SetColorClearValue(color);
		m_currentState.clearColor = color;
	}
}

/**
 * \return The set color to clear the color buffer to.
 */
GFW::Vec4 GFW::ContextState::GetColorClearCalue() const
{
	return m_currentState.clearColor;
}

/**
 * \brief Set the value to clear the depth buffer to when clearing.
 * \param depth The value to clear the depth buffer to.
 */
void GFW::ContextState::SetDepthClearValue(float depth)
{
	if(m_currentState.clearDepth != depth)
	{
		m_stateFunctions->SetDepthClearValue(depth);
		m_currentState.clearDepth = depth;
	}
}

/**
 * \return The set value to clear the depth buffer to.
 */
float GFW::ContextState::GetDepthClearValue() const
{
	return m_currentState.clearDepth;
}

/**
 * \brief Set the value to clear the stencil buffer to when clearing.
 * \param stencil The value to clear the stencil buffer to.
 */
void GFW::ContextState::SetStencilClearValue(int stencil)
{
	if(m_currentState.clearStencil != stencil)
	{
		m_stateFunctions->SetStencilClearValue(stencil);
		m_currentState.clearStencil = stencil;
	}
}

/**
 * \return The set value to clear the stencil buffer to.
 */
int GFW::ContextState::GetStencilClearValue() const
{
	return m_currentState.clearStencil;
}

/**
 * \brief Initializes the state of the context to equal the current state struct.
 */
void GFW::ContextState::InitializeState()
{
	m_stateFunctions->SetDepthRange(m_currentState.depthRangeMin, m_currentState.depthRangeMax);
	m_stateFunctions->SetPointSize(m_currentState.pointSize);
	m_stateFunctions->SetPointAntialiasing(m_currentState.pointAntialiasing);
	m_stateFunctions->SetLineWidth(m_currentState.lineWidth);
	m_stateFunctions->SetLineAntialiasing(m_currentState.lineAntialiasing);
	m_stateFunctions->SetCullFace(m_currentState.faceCullingEnabled);
	m_stateFunctions->SetFacesToCull(m_currentState.cullBackFace);
	m_stateFunctions->SetFrontFace(m_currentState.frontFaceCounterClockwise);
	m_stateFunctions->SetPolygonRasterization(m_currentState.polygonRasterization);
	m_stateFunctions->SetStencilTest(m_currentState.stencilTestEnabled);
	m_stateFunctions->SetStencilFunction(FaceDirection::FRONT_AND_BACK, m_currentState.frontFaceStencilFunction);
	m_stateFunctions->SetStencilMask(FaceDirection::FRONT_AND_BACK, m_currentState.frontFaceStencilMask);
	m_stateFunctions->SetStencilOperation(FaceDirection::FRONT_AND_BACK, m_currentState.frontFaceStencilOperation[0], m_currentState.frontFaceStencilOperation[1], m_currentState.frontFaceStencilOperation[2]);
	m_stateFunctions->SetAlphaTest(m_currentState.alphaTestEnabled);
	m_stateFunctions->SetAlphaFunction(m_currentState.alphaTestFunction, m_currentState.alphaTestReference);
	m_stateFunctions->SetDepthTest(m_currentState.depthTestEnabled);
	m_stateFunctions->SetDepthFunction(m_currentState.depthTestFunction);
	m_stateFunctions->SetBlend(m_currentState.blendEnabled);
	m_stateFunctions->SetBlendFunction(m_currentState.sourceBlendFunction, m_currentState.destinationBlendFunction);
	m_stateFunctions->SetColorClearValue(m_currentState.clearColor);
	m_stateFunctions->SetDepthClearValue(m_currentState.clearDepth);
	m_stateFunctions->SetStencilClearValue(m_currentState.clearStencil);
}
