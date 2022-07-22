
#include <iostream>
#include <string>
#include "Graphics.hpp"
#include "FlappyBirdMain.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <freetype/freetype.h>
#include FT_FREETYPE_H
#include <sstream>

void Graphics::CreatingWindow() {
    /* Initialize the library */
    if (!glfwInit())
        std::cout << "Failed To Create Window\n";

    Graphics::WindowVar = glfwCreateWindow(Graphics::Width, Graphics::Hight, "Flappy Bird", NULL, NULL);
    if (!Graphics::WindowVar)
    {
        glfwTerminate();
        std::cout << "Failed To create Window\n";
    }
    // Making Shit Work
    glfwMakeContextCurrent(Graphics::WindowVar);
    glfwMakeContextCurrent(Graphics::WindowVar);
    glViewport(4, 3, Graphics::Width, Graphics::Hight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 1700.0f, 0.0f, 800.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glfwSetKeyCallback(Graphics::WindowVar, Bird::KeyboardInput);
    glfwWindowHint(GLFW_REFRESH_RATE,60);
    // fps limmiter
    const double fpsLimit = 1.0 / 60.0;
    double lastUpdateTime = 0;  // number of seconds since the last loop
    double lastFrameTime = 0;   // number of seconds since the last frame

    while (!glfwWindowShouldClose(Graphics::WindowVar))
    {
        double now = glfwGetTime();
        double deltaTime = now - lastUpdateTime;
        glfwPollEvents();


        if ((now - lastFrameTime) >= fpsLimit)
        {
            // draw your frame here
            glClear(GL_COLOR_BUFFER_BIT);
            //Rendering Function
            Rendering::CurentlyRenedringFunction();

            glfwSwapBuffers(Graphics::WindowVar);

            // only set lastFrameTime when you actually draw something
            lastFrameTime = now;
        }

        // set lastUpdateTime every iteration
        lastUpdateTime = now;
    }
    glfwTerminate();
}

void Graphics::Rendering::CurentlyRenedringFunction() {

    (*Graphics::Rendering::CurentRenderingFuncVar)();
}

void Graphics::Rendering::DeffultRender() {
    int PointsArrayVar[8] = {0,1500,0,0,0,800};
    Graphics::Rendering::SquareGraphing(PointsArrayVar,Colors::Gray);
}

void Graphics::Rendering::SquareGraphing(int Points[8] , float ColorVar[3]) {
    glBegin(GL_QUADS);
        glColor3f(ColorVar[0], ColorVar[1], ColorVar[2]);
        glVertex2d(Points[0], Points[4]);
        glVertex2d(Points[1], Points[4]);
        glVertex2d(Points[1], Points[5]);
        glVertex2d(Points[0], Points[5]);
    glEnd();
}
void Graphics::Rendering::RetengleGrpahing(int Points[8], float ColorVar[3]) {
    glBegin(GL_QUADS);
    glColor3f(ColorVar[0], ColorVar[1], ColorVar[2]);
    glVertex2d(Points[0], Points[4]);
    glVertex2d(Points[1], Points[5]);
    glVertex2d(Points[2], Points[6]);
    glVertex2d(Points[3], Points[7]);
    glEnd();
}

void Graphics::Rendering::RenderingTringle(int Points[6], float ColorVar[3]) {
    glBegin(GL_TRIANGLES);
    glColor3f(ColorVar[0], ColorVar[1], ColorVar[2]);
    glVertex2d(Points[0], Points[3]);
    glVertex2d(Points[1], Points[4]);
    glVertex2d(Points[2], Points[5]);
    glEnd();
}


void Graphics::Rendering::RenderingFile(int Points[8], const char* FileName, bool Flip) {
    GLuint Texture = Graphics::Rendering::LoadingTexture(FileName , Flip );
    int x,y, Size;

    x = 0;
    y = 0;

    Size = 200;
    glBindTexture(GL_TEXTURE_2D, Texture);

    glBegin(GL_POLYGON);
    glVertex2f(Points[0],Points[4]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(Points[1], Points[5]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(Points[2], Points[6]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(Points[3], Points[7]);
    glTexCoord2f(0.0f, 0.0f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);

}


GLuint Graphics::Rendering::LoadingTexture(const char *FileName, bool Flip) {
    int widthImg, heightImg, numColCh;

    if (Flip == false)
    {
        stbi_set_flip_vertically_on_load(true);
    }
    unsigned char* bytes = stbi_load(FileName, &widthImg, &heightImg, &numColCh,0);
    GLuint texture;

    

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &texture);
    //glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
    //glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    //glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    //stbi_image_free(bytes);
    stbi_image_free(bytes);
    //glBindTexture(GL_TEXTURE_2D, 0);
    return texture;

}


int Graphics::Rendering::ConvertingCharToInt(char Char) {
    int CharInt;
    switch (Char) {
        case ' ':
            CharInt = 32;
            break;
        case '!':
            CharInt = 33;
            break;
        case '"':
            CharInt = 34;
            break;
        case '#':
            CharInt = 35;
            break;
        case '$':
            CharInt = 36;
            break;
        case '%':
            CharInt = 37;
            break;
        case '&':
            CharInt = 38;
            break;
            // Skiped ' 39
        case '(':
            CharInt = 40;
            break;
        case ')':
            CharInt = 41;
            break;
        case '*':
            CharInt = 42;
            break;
        case '+':
            CharInt = 43;
            break;
        case ',':
            CharInt = 44;
            break;
        case '-':
            CharInt = 45;
            break;
        case '.':
            CharInt = 46;
            break;
            // Skipping 47
        case '0':
            CharInt = 48;
            break;
        case '1':
            CharInt = 49;
            break;
        case '2':
            CharInt = 50;
            break;
        case '3':
            CharInt = 51;
            break;
        case '4':
            CharInt = 52;
            break;
        case '5':
            CharInt = 53;
            break;
        case '6':
            CharInt = 54;
            break;
        case '7':
            CharInt = 55;
            break;
        case '8':
            CharInt = 56;
            break;
        case '9':
            CharInt = 57;
            break;
            // Skipping 58 - 64 Starting on 65
        case 'A':
            CharInt = 65;
            break;
        case 'B':
            CharInt = 66;
            break;
        case 'C':
            CharInt = 67;
            break;
        case 'D':
            CharInt = 68;
            break;
        case 'E':
            CharInt = 69;
            break;
        case 'F':
            CharInt = 70;
            break;
        case 'G':
            CharInt = 71;
            break;
        case 'H':
            CharInt = 72;
            break;
        case 'I':
            CharInt = 73;
            break;
        case 'J':
            CharInt = 74;
            break;
        case 'K':
            CharInt = 75;
            break;
        case 'L':
            CharInt = 76;
            break;
        case 'M':
            CharInt = 77;
            break;
        case 'N':
            CharInt = 78;
            break;
        case 'O':
            CharInt = 79;
            break;
        case 'P':
            CharInt = 80;
            break;
        case 'Q':
            CharInt = 81;
            break;
        case 'R':
            CharInt = 82;
            break;
        case 'S':
            CharInt = 83;
            break;
        case 'T':
            CharInt = 84;
            break;
        case 'U':
            CharInt = 85;
            break;
        case 'V':
            CharInt = 86;
            break;
        case 'W':
            CharInt = 87;
            break;
        case 'X':
            CharInt = 88;
            break;
        case 'Y':
            CharInt = 89;
            break;
        case 'Z':
            CharInt = 90;
            break;
            // Skipping 91 - 96 and starting at 97
        case 'a':
            CharInt = 97;
            break;
        case 'b':
            CharInt = 98;
            break;
        case 'c':
            CharInt = 99;
            break;
        case 'd':
            CharInt = 100;
            break;
        case 'e':
            CharInt = 101;
            break;
        case 'f':
            CharInt = 102;
            break;
        case 'g':
            CharInt = 103;
            break;
        case 'h':
            CharInt = 104;
            break;
        case 'i':
            CharInt = 105;
            break;
        case 'j':
            CharInt = 106;
            break;
        case 'k':
            CharInt = 107;
            break;
        case 'l':
            CharInt = 108;
            break;
        case 'm':
            CharInt = 109;
            break;
        case 'n':
            CharInt = 110;
            break;
        case 'o':
            CharInt = 111;
            break;
        case 'p':
            CharInt = 112;
            break;
        case 'q':
            CharInt = 113;
            break;
        case 'r':
            CharInt = 114;
            break;
        case 's':
            CharInt = 115;
            break;
        case 't':
            CharInt = 116;
            break;
        case 'u':
            CharInt = 117;
            break;
        case 'v':
            CharInt = 118;
            break;
        case 'w':
            CharInt = 119;
            break;
        case 'x':
            CharInt = 120;
            break;
        case 'y':
            CharInt = 121;
            break;
        case 'z':
            CharInt = 122;
            break;
    }

    return CharInt;
}


void Graphics::Rendering::RenderingChar(int *Points, bool Background, float BackGroundColor[3], char Char, float TextColor[3])
{
    // Switching to int based on char
    int Number;
    Number = Graphics::Rendering::ConvertingCharToInt(Char);
    int *BitMap = font8x8_basic[Number];
    // I need to set all of the points and then graph to try and reduce lag.
    float ColorOfPixel[9][9][3]; // If it is set to 0 then it is the background color if it is set to 1 then it is filled in
    bool PixelEnabeled[9][9];
    int x,y;
    int set;
    int mask;
    for (x=0; x < 8; x++) {
        for (y=0; y < 8; y++) {
            set = BitMap[x] & 1 << y;
            if (set == 0)
            {// This is if there is nothing there

                if (Background == true)
                {
                    PixelEnabeled[x][y] = true;
                    ColorOfPixel[x][y][0] = BackGroundColor[0];
                    ColorOfPixel[x][y][1] = BackGroundColor[1];
                    ColorOfPixel[x][y][2] = BackGroundColor[2];
                }else
                    PixelEnabeled[x][y] = false;
            }else{ // This is for if there is something there

                PixelEnabeled[x][y] = true;
                ColorOfPixel[x][y][0] = TextColor[0];
                ColorOfPixel[x][y][1] = TextColor[1];
                ColorOfPixel[x][y][2] = TextColor[2];
            }
        }

    }
        // Rendering
        x = 0; y = 0;
        set = 0;
        mask = 0;
        int Y, X;
        int HieghtNotRendered = Points[2] * 8;
        HieghtNotRendered = HieghtNotRendered + Points[1];
        for (x=0; x < 8; x++) {
            for (y = 8; y >= 0; y--) {

                X = 0;
                Y = 0;
                // Rendering Each Pixel
                X = Points[2] * x;
                X = Points[0] - X;
                Y = Points[2] * y;
                Y = HieghtNotRendered + Y;
                if (PixelEnabeled[x][y] == true)
                {
                    int PointsVar[8] = {
                            Y + Points[2] , Y + Points[2] , Y , Y,
                            X + Points[2] , X, X, X  + Points[2]
                    };
                    Graphics::Rendering::RetengleGrpahing(PointsVar, ColorOfPixel[x][y]);
                }
            }
        }




}

void Graphics::Rendering::RenderingWord(int *Points, bool BackGround, float *BackGroundColor, std::string Word, float TextColor[3]) {
    int Size = Word.size();

    // This code convertes the string into an array of char
    char Text[Word.size() + 1];
    strcpy(Text, Word.c_str());


    int AmountOfSpaceEachLetterTakesUp = Points[2] * 8;
    int XCordForEachLetter = Points[1];
    int X = 0;
    while (X < Size)
    {
        Points[1] = XCordForEachLetter;
        Graphics::Rendering::RenderingChar(Points, BackGround, BackGroundColor , Text[X],TextColor);
        XCordForEachLetter = XCordForEachLetter + AmountOfSpaceEachLetterTakesUp;

        X = X + 1; // Adding One To size
    }
}

std::string Graphics::Rendering::ConvertingIntToString(int Integer) {
    std::string StringVar;

    std::stringstream StringStreamInt;
    StringStreamInt << Integer;
    StringStreamInt >> StringVar;
    return StringVar;
}


