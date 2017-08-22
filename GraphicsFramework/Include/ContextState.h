#pragma once
#include "Math.h"
#include "Interfaces/IContextStateFunctions.h"

namespace GFW
{
	using namespace Math;

	/**
	 * \brief This class is used to manage the state of the context. It's used the change the state and get the current state.
	 * Unnecessary state change will not be executed. The current state can be recorded and restored using this class.
	 */
	class ContextState
	{
	public:
		ContextState(IContextStateFunctions* stateFunctions);
		~ContextState();

		void RecordState();
		void RestoreRecordedState();

		void SetViewport(const Vec2& position, const Vec2& dimensions);
		Vec2 GetViewportPosition() const;
		Vec2 GetViewportDimensions() const;

		void SetDepthRange(float min, float max);
		void GetDepthRange(float& min, float& max) const;

		void SetPointSize(float size);
		float GetPointSize() const;
		void SetPointAntialiasing(bool enabled);
		bool IsPointAntialiasingEnabled() const;

		void SetLineWidth(float width);
		float GetLineWidth() const;
		void SetLineAntialiasing(bool enabled);
		bool IsLineAntialiasingEnabled() const;

		void SetFaceCulling(bool enabled);
		bool IsFaceCullingEnabled() const;
		void SetFacesToCull(bool backFacing);
		bool IsCullingBackFaces() const;
		void SetFrontFace(bool counterClockwise);
		bool FrontFaceIsCounterClockwise() const;

		void SetPolygonRasterization(RasterizationMode mode);
		RasterizationMode GetPolygonRasterization() const;

		void SetStencilTest(bool enabled);
		bool IsStencilTestEnabled() const;
		void SetStencilFunction(FaceDirection face, TestFunction function);
		TestFunction GetFrontFaceStencilFunction() const;
		TestFunction GetBackFaceStencilFunction() const;
		TestFunction GetStencilFunction() const;
		void SetStencilMask(FaceDirection face, int mask);
		int GetFrontFaceStencilMask() const;
		int GetBackFaceStencilMask() const;
		int GetStencilMask() const;
		void SetStencilOperation(FaceDirection face, TestOperation stencilFails, TestOperation depthFails, TestOperation pass);
		void GetFrontFaceStencilOperation(TestOperation& stencilFails, TestOperation& depthFails, TestOperation& pass) const;
		void GetBackFaceStencilOperation(TestOperation& stencilFails, TestOperation& depthFails, TestOperation& pass) const;
		void GetStencilOperation(TestOperation& stencilFails, TestOperation& depthFails, TestOperation& pass) const;

		void SetAlphaTest(bool enabled);
		bool IsAlphaTestEnabled() const;
		void SetAlphaFunction(TestFunction function, float ref);
		void GetAlphaFunction(TestFunction& function, float& ref) const;

		void SetDepthTest(bool enabled);
		bool IsDepthTestEnabled() const;
		void SetDepthFunction(TestFunction function);
		TestFunction GetDepthFunction() const;

		void SetBlend(bool enabled);
		bool IsBlendingEnabled() const;
		void SetBlendFunction(BlendFunction sourceFunc, BlendFunction destinationFunc);
		BlendFunction GetSourceBlendFunction() const;
		BlendFunction GetDestinationBlendFunction() const;

		void SetColorClearValue(const Vec4& color);
		Vec4 GetColorClearCalue() const;
		void SetDepthClearValue(float depth);
		float GetDepthClearValue() const;
		void SetStencilClearValue(int stencil);
		int GetStencilClearValue() const;

	private:
		void InitializeState();

		IContextStateFunctions* m_stateFunctions;	// Interface with function to change the state of the context.

		struct ContextStateVariables
		{
			Vec2 viewportPosition;
			Vec2 viewportDimensions;
			float depthRangeMin = 0.0f;
			float depthRangeMax = 1.0f;
			float pointSize = 1.0f;
			bool pointAntialiasing = false;
			float lineWidth = 1.0f;
			bool lineAntialiasing = false;
			bool faceCullingEnabled = false;
			bool cullBackFace = true;
			bool frontFaceCounterClockwise = true;
			RasterizationMode polygonRasterization = RasterizationMode::FILL;
			bool stencilTestEnabled = false;
			TestFunction frontFaceStencilFunction = TestFunction::ALWAYS;
			TestFunction backFaceStencilFunction = TestFunction::ALWAYS;
			int frontFaceStencilMask = 1;
			int backFaceStencilMask = 0;
			TestOperation frontFaceStencilOperation[3]{ TestOperation::KEEP };
			TestOperation backFaceStencilOperation[3]{ TestOperation::KEEP };
			bool alphaTestEnabled = false;
			TestFunction alphaTestFunction = TestFunction::ALWAYS;
			float alphaTestReference = 0.0f;
			bool depthTestEnabled = false;
			TestFunction depthTestFunction = TestFunction::LESS;
			bool blendEnabled = false;
			BlendFunction sourceBlendFunction = BlendFunction::ONE;
			BlendFunction destinationBlendFunction = BlendFunction::ZERO;
			Vec4 clearColor;
			float clearDepth = 1.0f;
			int clearStencil = 0;
		};

		ContextStateVariables m_currentState;	// The current state of the context.
		ContextStateVariables m_recordedState;	// The recorded state of the context.
	};
}
