#ifndef __GUI__
#define __GUI__

#include "imgui.h"
#include "imfilebrowser.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>

#include "renderer.h"
#include "framebuffer.h"
#include "window.h"
#include "camera.h"


class Gui {
public:
    void Init(Window* window, Renderer* renderer);
    void Update();
    void Destroy();

private:
    enum ExportType {
        Png,
        Bmp,
        Jpg,
        Tga,
        //Obj,
    };

    Renderer* renderer;
    Window* window;
    FrameBuffer* fbo;
    Camera* camera;
    bool show_demo_window = true;
    bool show_another_window = false;

    bool parameters_window_color_previous_state = false;
    bool parameters_window_color = false;

    ExportType currentExportType = ExportType::Png;

    bool exportWindowFlag = false;

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    ImGui::FileBrowser fileBrowserSaveImage = ImGui::FileBrowser(ImGuiFileBrowserFlags_EnterNewFilename | ImGuiFileBrowserFlags_CreateNewDir);
    std::string output_path = std::filesystem::current_path().u8string() + "/";
    std::string output_name = "image";
    std::string output_name_obj = "image.obj";

    int output_width = 1920;
    int output_height = 1080;
    int output_quality = 100;

    void MenuBar();
    void Preview();
    void Parameters();
    void ExportAs();

    void FileBrowserExport();
};

#endif /* End of __GUI__ */