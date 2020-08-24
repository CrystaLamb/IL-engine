#pragma once

#include "RenderCommand.h"

#include <glm/glm.hpp>

#include "VertexArray.h"
#include "Shader.h"
#include "Camera/Camera.h"

namespace IL
{

	class Renderer
	{
	public:
		// TODO
		static void BeginScene(const std::shared_ptr<Camera>& camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& VertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData
		{
			glm::mat4 m_ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};

}