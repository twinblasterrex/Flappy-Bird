#include <iostream>
#include <string>
#include "Graphics.hpp"
#include "FlappyBirdMain.hpp"


GLFWwindow* WindowVar;

int main(void)
{
    srand(time(NULL));


    Graphics::Rendering::CurentRenderingFuncVar = GameFunction::GameStart;
    Graphics::CreatingWindow();



}

