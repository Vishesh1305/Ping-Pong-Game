#include "PingPong.h"
using namespace std;

Color Green = Color{38, 185, 154, 255};
Color DarkGreen = Color{20, 160, 133, 255};
Color LightGreen = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

class Ball
{
    public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw()
    {
        DrawCircle(x, y, radius, Yellow);
    }

    void Update()
    {
        x += speed_x;
        y += speed_y;

        if (y+radius >= SCREEN_HEIGHT || y - radius <= 0)
        {
            speed_y *= -1;
        }
        if (x + radius >= SCREEN_WIDTH ) // CPU Wins - ||  speed_x *= -1;
        {
            cpuScore++;
            ResetBall();
        }
        if (x - radius <= 0)
        {
            playerScore++;
            ResetBall();
        }
    }

    void ResetBall()
    {
        x = SCREEN_WIDTH / 2;
        y = SCREEN_HEIGHT / 2;

        int speed_choices[2] = {-1, 1};
        speed_x *= speed_choices[GetRandomValue(0,1)];
        speed_y *= speed_choices[GetRandomValue(0,1)];
    }
};

class Paddle
{
protected:
    void LimitMovement()
    {
        if (y <= 0)
        {
            y = 0;
        }if (y + height >= SCREEN_HEIGHT)
        {
            y = SCREEN_HEIGHT - height;
        }
    }
    
public:
    float x,y, width, height;
    int speed;
    void Draw()
    {
        DrawRectangleRounded(Rectangle{x,y,width, height},0.8,0,WHITE);
    }

    void Update()
    {
        if (IsKeyDown(KEY_UP))
        {
            y -= speed;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            y += speed;
        }
        LimitMovement();
    }
};

class CpuPaddle: public Paddle
{
    public:
    void Update(int ball_y)
    {
        if (y + height/2 > ball_y)
            y = y - speed;
        if (y + height/2 <= ball_y)
            y = y + speed;
        LimitMovement();
    }
};

Ball ball;
Paddle player;
CpuPaddle cpu;
int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ping Pong Game!");
    SetTargetFPS(60);

    //Declaring Ball
    ball.radius = 20;
    ball.x = SCREEN_WIDTH / 2;
    ball.y = SCREEN_HEIGHT / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    //Declaring Player
    player.width = 25;
    player.height = 120;
    player.x = SCREEN_WIDTH - player.width -10;
    player.y = SCREEN_HEIGHT/2 - player.height/2;
    player.speed = 6;

    //Declaring Cpu
    cpu.width = 25;
    cpu.height = 120;
    cpu.x = 10;
    cpu.y = SCREEN_HEIGHT/2 - cpu.height/2;
    cpu.speed = 6;
    

    while (!WindowShouldClose())
    {
        // BEGINNING OF GAME LOOP!
        BeginDrawing();

        //updating
        ball.Update();
        player.Update();
        cpu.Update(ball.y);

        //Checking Collisions
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
        {
            ball.speed_x *= -1;
        }
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height}))
        {
            ball.speed_x *= -1;
        }
            
        //Drawing a Circle
        ClearBackground(DarkGreen);
        DrawRectangle(SCREEN_WIDTH/2 ,0,SCREEN_WIDTH/2, SCREEN_HEIGHT, Green);
        DrawCircle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 150, LightGreen);
        ball.Draw();
        
        //Drawing Rectangles
        cpu.Draw();
        player.Draw();
        DrawText(TextFormat("%i", cpuScore),SCREEN_WIDTH/4 - 20,20,80,WHITE);
        DrawText(TextFormat("%i", playerScore),3 * SCREEN_WIDTH/4 - 20,20,80,WHITE);

        //Drawing screen divider
        DrawLine(SCREEN_WIDTH/2,0, SCREEN_WIDTH/2, SCREEN_HEIGHT, WHITE);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
