#include "ilpch.h"
#include "OpenGlRendererAPI.h"

#include "IL/Renderer/VertexArray.h"
#include <glad/glad.h>

namespace IL
{

	void OpenGLRendererAPI::SetViewPortSize(UINT width, UINT height)
	{
		glViewport(0, 0, width, height);
	}

	void OpenGLRendererAPI::SetClearColor(glm::vec4 color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
	{
		glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

}