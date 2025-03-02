#include "entrypoint.h"
#include "raylib.h"

void DrawBall(Ball* x,Ball* y,Ball* radius){
    DrawCircle(x,y,radius,WHITE);
}

void UpdateBall(Ball* x,Ball* y,Ball* speed_x,Ball* speed_y,Ball* radius){
    x += speed_x;
    y += speed_y;
    if(y+radius >= GetScreenHeight() || y-radius <=0){ //Position + grosseur de la boule
        speed_y *= -1;
    }
    if(x+radius >= GetScreenWidth()){
        score_PC++;
        speed_x *= -1;
    }
    if(x-radius <=0){
        score_H++;
        speed_x *= -1;
    }
}

void DrawPaddle(Paddle* x, Paddle* y, Paddle* width, Paddle* height){
    DrawRectangle(x,y,width,height,WHITE);
}

void UpdatePaddle(Paddle* y,Paddle* speed,Paddle* height){
    if(IsKeyDown(KEY_UP)){
        y -= speed;
    }
    if(IsKeyDown(KEY_DOWN)){
        y += speed;
    }
    if(y <= 0){
        y = 0;
    }
    if(y + height >= GetScreenHeight()){
        y = GetScreenHeight() - height;
    }
}

//Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.
void raylib_start(void){
    const int screen_Width = 720;
    const int screen_Height = 480;
    InitWindow(screen_Width, screen_Height, "Breakout!");
    SetWindowState(FLAG_VSYNC_HINT);
    // SetTargetFPS(60);
    float dt = GetFrameTime(); // A reverifier ......
    //Remplacer par constructeur
    int radius = 20;
    float x = screen_Width/2;
    float y = screen_Height/2;
    int speed_x = 5;
    int speed_y = 5;

    Ball* ball; //Constructeur
    ball->Set(x,y,speed_x,speed_y,radius);
    
    

    paddle.width = 25; // Ici aussi
    paddle.height = 120;
    paddle.x = screen_Width - paddle.width - 10; // Largeur de l'ecran - la palette - 10 pour decoller du mur
    paddle.y = screen_Height/2 - paddle.height/2;
    paddle.speed = 7;

    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_ESCAPE)){
            break;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10,10);


        DrawBall((Ball*)ball.x,(Ball*)ball.y,(Ball*)ball.radius);

        DrawPaddle(paddle.x,paddle.y,paddle.width,paddle.height);

        player.Update();

        if(CheckCollisionCircleRec(Vector2{ball.x,ball.y}, ball.radius, Rectangle{player.x,player.y,player.width,player.height})){
            ball.speed_y *= -1;
            ball.speed_x *= -1;
        }

        EndDrawing();
    }
}