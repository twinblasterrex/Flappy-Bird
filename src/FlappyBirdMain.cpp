#include "Graphics.hpp"
#include "FlappyBirdMain.hpp"
#include <sstream>


Obsticles::ObsticlesClass ObsticleVar1;
Obsticles::ObsticlesClass ObsticleVar2;
Obsticles::ObsticlesClass ObsticleVar3;
int x = 1;



FlappyBird::GameClass GameFunction::GameDeffults(FlappyBird::GameClass GameClassVar) {
    GameClassVar.YHightOfBird = 450;
    GameClassVar.SpeedPerTick = 8; // This means that the x cord of everthing will be subtracted by 2 every tick.
    GameClassVar.Dead = false;
    GameClassVar.TickCounter = 0; //
    GameClassVar.ScoreFirstDiggit = 0;
    return GameClassVar;
}

void GameFunction::GameInit() {

    FlappyBird::GameStarted = false;
    Graphics::Rendering::CurentRenderingFuncVar = GameFunction::GameInit;
    FlappyBird::GameClassDeffult = GameFunction::GameDeffults(FlappyBird::GameClassDeffult);
    FlappyBird::GameClassVar = FlappyBird::GameClassDeffult;
    //Bird Init Function
    Bird::BirdClassVar.BirdInit();
    ObsticleVar1 = ObsticleVar3;
    ObsticleVar2 = ObsticleVar3;
    FlappyBird::GameClassVar.Dead = false;
    Bird::BirdClassVar.BirdResentlyMoved = false;
    Bird::BirdClassVar.BirdYCordMin = 450;

    // std::cout << "If You want the Game to start Press Enter\n";
    Graphics::Rendering::CurentRenderingFuncVar = GameTick;

}

void GameFunction::GameStart() {
    Graphics::Rendering::RetengleGrpahing(Graphics::Rendering::WholeScreen, Colors::MoonstoneBlue);
    int Points1[3] = {750 , 50, 8};
    Graphics::Rendering::RenderingWord(Points1, false , Colors::Green , "WELCOME TO FLAPPY BIRD", Colors::Gray);
    int Points2[3] = {500, 20, 5};
    Graphics::Rendering::RenderingWord(Points2, false, Colors::Green, "HIGHEST SCORE 67" , Colors::Gray);
    Points2[0] = 350;
    Points2[1] = 20;
    Graphics::Rendering::RenderingWord(Points2, false, Colors::Green, "PRESS THE ENTER BUTTON TO START THE GAME" , Colors::Gray);
    if (FlappyBird::GameStarted == true)
        GameFunction::GameInit();



}


void GameFunction::RenderingScore() {
    std::stringstream Secondint;
    std::stringstream FirstInit;

    FirstInit << FlappyBird::GameClassVar.ScoreFirstDiggit;
    Secondint << FlappyBird::GameClassVar.ScoreSecondDiggit;
    std::string X;
    std::string Y;
    Secondint >> X;
    FirstInit >> Y;
    std::string Bolth = "SCORE " + X + Y;
    if (FlappyBird::GameClassVar.ScoreSecondDiggit == 0)
    {
        Bolth = "SCORE " + Y;
    }else{
        Bolth = "SCORE " + X + Y;
    }



    int Points[3] = {750,10,5};
    Graphics::Rendering::RenderingWord(Points, false,Colors::Green,Bolth,Colors::White);
}

void GameFunction::GameTick() {
    FlappyBird::GameClassVar.TickCounter = FlappyBird::GameClassVar.TickCounter + 1;

    // Obsticle Tick
    ObsticleVar1.ObsticleTick();
    ObsticleVar1.SpawnedYet = true;

    if (ObsticleVar2.SpawnedYet == false)
    {
        if (ObsticleVar1.FrontXCord < 850)
        {
            ObsticleVar2.ObsticleTick();
            ObsticleVar2.SpawnedYet = true;
        }
    }else{
        ObsticleVar2.ObsticleTick();
    }
    // Bird Tick Functions
    Bird::BirdClassVar.BirdTick();


    FlappyBird::GameClassVar.Dead = HitBoxes::HitBoxCheek(ObsticleVar1, Bird::BirdClassVar);
    if (FlappyBird::GameClassVar.Dead == false){
        FlappyBird::GameClassVar.Dead = HitBoxes::HitBoxCheek(ObsticleVar2, Bird::BirdClassVar);
    }

    // Testing Immige Rendering

    if (Bird::BirdClassVar.BirdYCordMin <= 0)
    {
        FlappyBird::GameClassVar.Dead = true;
    }
    if (Bird::BirdClassVar.BirdYCordMax >= 800)
    {
        FlappyBird::GameClassVar.Dead = true;

    }
    // Cheeking Score
    FlappyBird::GameClassVar.CheekingScore();


    // Rendering
    GameFunction::GameRender();

    // UpdataingSpeed
    FlappyBird::GameClassVar.UpdatingSpeed();
    // Cheeking If dead
    if (FlappyBird::GameClassVar.Dead == true)
    {
        Graphics::Rendering::CurentRenderingFuncVar = GameDead;
    }
    GameFunction::RenderingScore();


}
void GameFunction::GameRender() {
    Graphics::Rendering::RetengleGrpahing(Graphics::Rendering::WholeScreen, Colors::MoonstoneBlue);
    Obsticles::RenderingObsticles();
    Bird::RenderingBird();
}

void Obsticles::RenderingObsticles() {
    // Background
    // Obsticle 1;

    glBegin(GL_QUADS);
    glColor3f(0.00f,0.80f,0.00f);
    glVertex2d(ObsticleVar1.FrontXCord, ObsticleVar1.BottlemYMin);
    glVertex2d(ObsticleVar1.BackXCord, ObsticleVar1.BottlemYMin);
    glVertex2d(ObsticleVar1.BackXCord, ObsticleVar1.BottlemYMax);
    glVertex2d(ObsticleVar1.FrontXCord, ObsticleVar1.BottlemYMax);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00f,0.80f,0.00f);
    glVertex2d(ObsticleVar1.FrontXCord, ObsticleVar1.TopYMin);
    glVertex2d(ObsticleVar1.BackXCord, ObsticleVar1.TopYMin);
    glVertex2d(ObsticleVar1.BackXCord, ObsticleVar1.TopYMax);
    glVertex2d(ObsticleVar1.FrontXCord, ObsticleVar1.TopYMax);
    glEnd();
    // Obsticle 2


    glBegin(GL_QUADS);
    glColor3f(0.00f,0.80f,0.00f);
    glVertex2d(ObsticleVar2.FrontXCord, ObsticleVar2.BottlemYMin);
    glVertex2d(ObsticleVar2.BackXCord, ObsticleVar2.BottlemYMin);
    glVertex2d(ObsticleVar2.BackXCord, ObsticleVar2.BottlemYMax);
    glVertex2d(ObsticleVar2.FrontXCord, ObsticleVar2.BottlemYMax);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00f,0.80f,0.00f);
    glVertex2d(ObsticleVar2.FrontXCord, ObsticleVar2.TopYMin);
    glVertex2d(ObsticleVar2.BackXCord, ObsticleVar2.TopYMin);
    glVertex2d(ObsticleVar2.BackXCord, ObsticleVar2.TopYMax);
    glVertex2d(ObsticleVar2.FrontXCord, ObsticleVar2.TopYMax);
    glEnd();
//    // Obsticle 3
//    glBegin(GL_QUADS);
//        glColor3f(0,0,.255);
//        glVertex2d(FrontXCord, BottlemYMin);
//        glVertex2d(BackXCord, BottlemYMin);
//        glVertex2d(BackXCord, BottlemYMax);
//        glVertex2d(FrontXCord, BottlemYMax);
//    glEnd();
//
//    glBegin(GL_QUADS);
//    glColor3f(0,0,.255);
//    glVertex2d(FrontXCord, TopYMin);
//    glVertex2d(BackXCord, TopYMin);
//    glVertex2d(BackXCord, TopYMax);
//    glVertex2d(FrontXCord, TopYMax);
//    glEnd();
}

void Bird::RenderingBird() {
    int Points[8] = {
            340,390,390,340,
            Bird::BirdClassVar.BirdYCordMin, BirdClassVar.BirdYCordMin,
            Bird::BirdClassVar.BirdYCordMax, Bird::BirdClassVar.BirdYCordMax
    };
    Graphics::Rendering::RetengleGrpahing(Points, Colors::LightBlue);
    //Graphics::Rendering::RenderingFile(Points, "Bird.png", false);

}

void Bird::KeyboardInput(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){

        exit(0);
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {

        Bird::BirdClassVar.BirdMove(FlappyBird::GameClassVar.TickCounter);

    }
    if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        FlappyBird::GameClassVar.Dead == false;
        Graphics::Rendering::CurentRenderingFuncVar = GameFunction::GameInit;
    }
    if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
    {
        FlappyBird::GameStarted = true;
    }
    if (key == GLFW_KEY_DOWN  && action == GLFW_PRESS)
    {

    }
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        Bird::BirdClassVar.BirdMove(FlappyBird::GameClassVar.TickCounter);

    }


}

void GameFunction::GameDead() {
    Graphics::Rendering::RetengleGrpahing(Graphics::Rendering::WholeScreen, Colors::Blue);
    int Points[4] = {600,150 , 10};
    int Point2 = Points[2] * 8;
    Graphics::Rendering::RenderingWord(Points, false, Colors::Green, "Press R To Reset" ,Colors::Gray);


    GameFunction::RenderingScore();

}