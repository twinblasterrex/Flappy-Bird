#include <iostream>
#include <string>

namespace FlappyBird
{
    class GameClass
    {
    public:
        int YHightOfBird;
        int SpeedPerTick;
        bool Dead;
        int TickCounter;// This is for timers and things
        int ScoreFirstDiggit;
        int ScoreSecondDiggit;
        void CheekingScore()
        {
            if (ScoreFirstDiggit >= 10)
            {
                ScoreFirstDiggit = 0;
                ScoreSecondDiggit++;
            }
        }
        void UpdatingSpeed()
        {
            switch (ScoreSecondDiggit) {
                case 1:
                    SpeedPerTick = 7;
                    break;
                case 2:
                    SpeedPerTick = 8;
                    break;
                case 3:
                    SpeedPerTick = 8;
                    break;
                case 4:
                    SpeedPerTick = 8;
                    break;
                case 5:
                    SpeedPerTick = 8;
                    break;
                case 6:
                    SpeedPerTick = 9;
                    break;
                case 7:
                    SpeedPerTick = 9;
                    break;
                case 8:
                    SpeedPerTick = 9;
                    break;
                case 9:
                    SpeedPerTick = 9;
                    break;
                case 10:
                    SpeedPerTick = 10;
                    break;
                default:
                    SpeedPerTick = 7;
                    break;

            }
        }

    };

    static GameClass GameClassDeffult;
    inline GameClass GameClassVar;

    // Obsticles Static Cords

    inline bool GameStarted = false;
}

namespace HitBoxes
{
    class HitboxClass
    {
    public:
        int X[2];
        int Y[2];
        int Permitrer;
        bool ColisionDetection;
        int OtherYCord[2];
        void CaculatingPermiter(int x1, int x2, int y1, int y2)
        {
            int x, y;
            x = x2 - x1; x * 2;
            y = Y[2] - Y[1]; y * 2;
            Permitrer = x + y;
        }
    };

    inline bool HitBoxCheek(HitboxClass Class1, HitboxClass Class2)
    {
        int XCordsThatneedToBeCheeked;
        XCordsThatneedToBeCheeked = Class2.X[1] - Class2.X[0];
        while (XCordsThatneedToBeCheeked >= 0)
        {
            Class2.X[0] + XCordsThatneedToBeCheeked; // This is the cord that will be cheeked.
            int XCordesThatNeedToBeCheeked2;
            XCordesThatNeedToBeCheeked2 = Class1.X[1] - Class1.X[0];
            while (XCordesThatNeedToBeCheeked2 >= 0)
            {
                if (Class2.X[0] + XCordsThatneedToBeCheeked == Class1.X[0] + XCordesThatNeedToBeCheeked2)
                {
                    // Do What I just did for the y Vars.
                    int YCordsThatNeedToBeCheeked;
                    YCordsThatNeedToBeCheeked = Class1.Y[1] - Class1.Y[0];
                    // Y While Loops
                    while (YCordsThatNeedToBeCheeked >= 0)
                    {
                        if (YCordsThatNeedToBeCheeked + Class1.Y[0] == Class2.Y[0])
                        {
                            return true;
                        }
                        YCordsThatNeedToBeCheeked = YCordsThatNeedToBeCheeked - 1;
                    }
                    int YCordsThatNeedToBeCheeked2;
                    YCordsThatNeedToBeCheeked2 = Class1.OtherYCord[1] - Class1.OtherYCord[0];
                    // Y While Loops
                    while (YCordsThatNeedToBeCheeked2 >= 0)
                    {
                        if (YCordsThatNeedToBeCheeked2 + Class1.OtherYCord[0] == Class2.Y[0])
                        {
                            return true;
                        }
                        YCordsThatNeedToBeCheeked2 = YCordsThatNeedToBeCheeked2 - 1;
                    }
                    // Top Of Bird

                    // Do What I just did for the y Vars.
                    int YCordsThatNeedToBeCheeked3;
                    YCordsThatNeedToBeCheeked3 = Class1.Y[1] - Class1.Y[0];
                    // Y While Loops
                    while (YCordsThatNeedToBeCheeked3 >= 0)
                    {
                        if (YCordsThatNeedToBeCheeked3 + Class1.Y[0] == Class2.Y[1])
                        {
                            return true;
                        }
                        YCordsThatNeedToBeCheeked3 = YCordsThatNeedToBeCheeked3 - 1;
                    }

                    int YCordsThatNeedToBeCheeked4;
                    YCordsThatNeedToBeCheeked4 = Class1.OtherYCord[1] - Class1.OtherYCord[0];
                    // Y While Loops
                    while (YCordsThatNeedToBeCheeked4 >= 0)
                    {
                        if (YCordsThatNeedToBeCheeked4 + Class1.OtherYCord[0] == Class2.Y[1])
                        {
                            return true;
                        }
                        YCordsThatNeedToBeCheeked4 = YCordsThatNeedToBeCheeked4 - 1;
                    }

                }
                XCordesThatNeedToBeCheeked2 = XCordesThatNeedToBeCheeked2 - 1;
            }
            XCordsThatneedToBeCheeked = XCordsThatneedToBeCheeked - 1 ;
        }
        return false;
    }
}



namespace Obsticles
{
    class ObsticlesClass : public HitBoxes::HitboxClass
    {
    public:
        int FrontXCord;
        int BackXCord ;
        int BottlemYMin ; // By deffult this should always be 0;
        int BottlemYMax;
        int TopYMin;
        int TopYMax;
        bool SpawnedYet = false;
        bool StillInFrame = false; // if false should not re generate if true should re generate
        float Red;
        float Green;
        float Blue;
        bool Scored = false;
    private:
        void Genreate()// This function will also cheek if you should re gen
        {
            if (StillInFrame == false)
            {
                Scored = false;

//                FrontXCord = 1700;
//                BackXCord = 1700;
//                BottlemYMin = 0;
//                BottlemYMax = 300;
//                TopYMin = 600;
//                TopYMax = 800;

                //	std::cout << rand() % 5;

                switch (rand()%3) {
                    case 0:
                        FrontXCord = 1700;
                        BackXCord = 1700;
                        BottlemYMin = 0;
                        BottlemYMax = 300;
                        TopYMin = 600;
                        TopYMax = 800;
                        break;
                    case 1:
                        FrontXCord = 1700;
                        BackXCord = 1700;
                        BottlemYMin = 0;
                        BottlemYMax = 100;
                        TopYMin = 400;
                        TopYMax = 800;
                        break;
                    case 2:
                        FrontXCord = 1700;
                        BackXCord = 1700;
                        BottlemYMin = 0;
                        BottlemYMax = 500;
                        TopYMin = 700;
                        TopYMax = 800;
                        break;
                    case 3:
                        FrontXCord = 1700;
                        BackXCord = 1700;
                        BottlemYMin = 0;
                        BottlemYMax = 150;
                        TopYMin = 300;
                        TopYMax = 800;
                        break;
                    case 4:
                        FrontXCord = 1700;
                        BackXCord = 1700;
                        BottlemYMin = 0;
                        BottlemYMax = 0;
                        TopYMin = 200;
                        TopYMax = 800;
                        break;
                    case 5:
                        FrontXCord = 1700;
                        BackXCord = 1700;
                        BottlemYMin = 0;
                        BottlemYMax = 650;
                        TopYMin = 800;
                        TopYMax = 800;
                        break;

                }
                // This is where the gnereate Code will be written.

            }else{
                return; // This just means that it will not re render.
            }
        }
        void CheekingIfStillInFrame()
        {
            if (BackXCord < 0)
            {
                StillInFrame = false;
            }else{
                StillInFrame = true;
            }
        }
        void GraphingObsticle()
        {

        }
        void MovingObsticleCords()
        {

            FrontXCord = FrontXCord - FlappyBird::GameClassVar.SpeedPerTick;
            BackXCord = BackXCord - FlappyBird::GameClassVar.SpeedPerTick;
            if (FrontXCord > 1500)
            {
                BackXCord = BackXCord + FlappyBird::GameClassVar.SpeedPerTick;
            }
        }
        void SettingHitBox()
        {
            X[0] = FrontXCord;
            X[1] = BackXCord;
            Y[0] = BottlemYMin;
            Y[1] = BottlemYMax;

            OtherYCord[0] = TopYMin;
            OtherYCord[1] = TopYMax;
        }
        void ScoreCheek()
        {
            if (BackXCord <= 340 && Scored == false)
            {
                FlappyBird::GameClassVar.ScoreFirstDiggit = FlappyBird::GameClassVar.ScoreFirstDiggit + 1;
                Scored = true;
            }
        }
    public:
        void ObsticleTick()
        {
            SettingHitBox();
            MovingObsticleCords();
            CheekingIfStillInFrame();
            Genreate();
            ScoreCheek();
        }

    };
    void RenderingObsticles();


}

namespace GameFunction
{
    void GameInit();
    void GameTick();
    void GameEnd();
    void GameStart();
    void GameRender();
    void GameDead();
    void RenderingScore();


    FlappyBird::GameClass GameDeffults(FlappyBird::GameClass GameClassVar);
    namespace GameTickFunction
    {
        FlappyBird::GameClass ObsticleGeneration(FlappyBird::GameClass GameClassVar);
        FlappyBird::GameClass BirdDesending(FlappyBird::GameClass GameClassVar);

    }
}


namespace Bird
{
    class BirdClass : public HitBoxes::HitboxClass
    {
    public:
        int BirdYCordMin = 450;// This is the bottlem of the Bird
        int BirdYCordMax;
        int BirdXCord;
        bool BirdResentlyMoved;
        int TickSienceLastMove;
        int TickWhenBirdCanMoveAgain;
        // Hit Box Data

        void SettingHitBoxVar()
        {
            X[0] = 340; X[1] = 390;
            Y[0] = BirdYCordMin;
            Y[1] = BirdYCordMax;

        }
        void CheekingIfBirdCanMoveAgain(int GameTick)
        {
            if (BirdResentlyMoved == true)
            {
                if (GameTick == TickWhenBirdCanMoveAgain - 5 )
                {
                    BirdYCordMin = BirdYCordMin + 15;
                }
                if (GameTick == TickWhenBirdCanMoveAgain - 4 )
                {
                    BirdYCordMin = BirdYCordMin + 15;
                }
                if (GameTick == TickWhenBirdCanMoveAgain - 3 )
                {
                    BirdYCordMin = BirdYCordMin + 15;
                }
                if (GameTick == TickWhenBirdCanMoveAgain - 2 )
                {
                    BirdYCordMin = BirdYCordMin + 15;
                }
                if (GameTick == TickWhenBirdCanMoveAgain - 1 )
                {
                    BirdYCordMin = BirdYCordMin + 15;
                }
                if (TickWhenBirdCanMoveAgain <= GameTick )
                {
                    BirdResentlyMoved = false;
                }
            }
        }
        void SettingMaxCord()
        {
            BirdYCordMax = BirdYCordMin + 50;
        }
        void BirdMove(int GameTick)
        {
            if (BirdResentlyMoved == false)
            {
                BirdResentlyMoved = true;
                TickSienceLastMove =  GameTick;
                TickWhenBirdCanMoveAgain = GameTick + 6;
                BirdYCordMin = BirdYCordMin + 10;

                if (TickWhenBirdCanMoveAgain <= GameTick)
                {
                    BirdResentlyMoved == false;
                }

            }
        }
        void BirdTick()
        {
            // Bird Constent Dropping.

            CheekingIfBirdCanMoveAgain(FlappyBird::GameClassVar.TickCounter);
            if (FlappyBird::GameClassVar.TickCounter == TickWhenBirdCanMoveAgain - 5)
            {}else{
                BirdYCordMin = BirdYCordMin - 4;
            }

            // Sets the max cord Needs to happen every tick
            SettingMaxCord();
            SettingHitBoxVar(); // This is created the new hitbox every tick.
        }
        void BirdInit()
        {
            SettingMaxCord();
        }

    };
    // Var
    inline BirdClass BirdClassVar;

    // Function
    void RenderingBird();
    // Keyboard Input
    void KeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods);
}



