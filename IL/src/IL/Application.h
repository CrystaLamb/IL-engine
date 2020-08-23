#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "LayerStack.h"

#include "ImGui/ImGuiLayer.h"

#include "IL/Renderer/Shader.h"
#include "IL/Renderer/VertexArray.h"
#include "IL/Renderer/Camera/Camera.h"

namespace IL
{

	class IL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);  // use this function to dispatch event to window

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& GetApplication() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
		bool OnKeyPressed(KeyPressedEvent& e);

		std::unique_ptr<Window> m_Window;

		bool m_Running = true;
		bool m_ShowWindowTrace = false;

		LayerStack  m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;
	private:
		static Application* s_Instance;  // we only need one application

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray; // it contains the vertexBuffers and indexBuffer
		std::shared_ptr<Camera> m_Camera;
	};

	// To be define in client
	Application* CreateApplication();
}
