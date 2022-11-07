#include <widgeteditor.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

//WidgetEditor::WidgetEditor(Widget& widget, void* window) noexcept: m_Widget{widget} 
WidgetEditor::WidgetEditor(void* window) noexcept//: m_Widget{widget} 
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)window, true);
    ImGui_ImplOpenGL3_Init("#version 460");
}

WidgetEditor::~WidgetEditor()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void WidgetEditor::show()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // DRAW

    ImGui::Begin("Simple Window");

    ImGui::End();

    // DRAW
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
