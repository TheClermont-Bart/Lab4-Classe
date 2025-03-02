#pragma once

#ifdef __cplusplus
extern "C"{
#endif

void raylib_start(void);

#ifdef __cplusplus
}
#endif

class Ball{
public:
    void Draw();
    void Update(float dt);
    void Set(float p_x, float p_y, int p_speed_x, int p_speed_y, int p_radius){
        this->x = p_x;
        this->y = p_y;
        this->speed_x = p_speed_x;
        this->speed_y = p_speed_y;
        this->radius = p_radius;
    }
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
    int getSpeedX(){
        return speed_x;
    }
    int getSpeedY(){
        return speed_y;
    }
    int getRadius(){
        return radius;
    }
private:
    float x;
    float y;
    int speed_x;
    int speed_y;
    int radius; 
};


class Paddle{
public:
    void Draw();
    void Update(float dt);
private:
    float x;
    float y;
    float width;
    float height;
    int speed;
};




