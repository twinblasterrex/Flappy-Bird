#pragma once

class cordV4F
{
public:
    cordV4F();
private:
    bool Updated = false;
    void Update();
    float Cords[8];
public:
    void SetCords(float origin[2], float size[2], GLfloat ColorPram[3]);
    void SetCords(float PointsPram[8], GLfloat ColorPram);
    void SetCords(float origin[2], float Size, GLfloat ColorPram);
};