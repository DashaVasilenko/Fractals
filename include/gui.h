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
#include "types.h"
#include "fractalController.h"


class Gui {
public:
    void Init(Window* window, FractalController* fr);
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

    FractalController* fractalController;
    Window* window;
    FrameBuffer* fbo;
    Camera* camera;
    bool show_demo_window = true;
    bool show_another_window = false;

    float light_direction[3] = { 0.0f, -1.0f, 0.0f };
    float ambient_light_color[3] = { 1.0, 1.0, 1.0 };
    float diffuse_light_color[3] = { 1.0, 1.0, 1.0 };
    float specular_light_color[3] = { 1.0, 1.0, 1.0 };

    float ambient_fractal_color[3] = { 0.19225, 0.19225, 0.19225 };
    float diffuse_fractal_color[3] = { 0.50754, 0.50754, 0.50754 };
    float specular_fractal_color[3] = { 0.50827, 0.50827, 0.50827 };
    float shininess = 20.0;

    bool hard_shadows = false;
    bool soft_shadows = false;
    bool ambient_occlusion = false;

    ExportType currentExportType = ExportType::Png;
    FractalType currentFractalType = FractalType::Test;

    bool exportWindowFlag = false;
    ImGuiWindowFlags parametersWindowFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse ;

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    ImGui::FileBrowser fileBrowserSaveImage = ImGui::FileBrowser(ImGuiFileBrowserFlags_EnterNewFilename | ImGuiFileBrowserFlags_CreateNewDir);
    std::string output_path = std::filesystem::current_path().u8string() + "/";
    std::string output_name = "image";
    std::string output_name_obj = "image.obj";

    int output_width = 1920;
    int output_height = 1080;
    int output_quality = 100;

    int mandelbulb_iterations = 8;
    float mandelbulb_bailout = 10.0f;
    float mandelbulb_power = 9.0f;

    void MenuBar();
    void Preview();
    void Stats();
    void MainParameters();
    void FractalColor();
    void FractalParameters();
    void ExportAs();
    void FileBrowserExport();

    void Test();
    void Mandelbulb();

};

#endif /* End of __GUI__ */