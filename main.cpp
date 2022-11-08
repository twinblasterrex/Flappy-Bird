#include "Graphics/Graphics.hpp"

Shader ShaderVar;
Window WindowVar;

void Run()
{

    Render4V Box;
    Box.SetShaderPrt(&ShaderVar);
    Box.Draw();
}


int main()
{


    win::RunFunction = Run;
    WindowVar.CreateWindow();
    ShaderVar.Init(&WindowVar);
    WindowVar.Run();
}