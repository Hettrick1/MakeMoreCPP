#include "raylib.h"
#include <iostream>

const int WIDTH = 1080;
const int HEIGHT = 720;

Texture2D factoryBG, table, block;

void Load();
void Start();
void Update();
void Draw();
void Unload();
void center_window(float window_width, float window_height);

int main() {
    Load();
    Start();
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
    Unload();
    return 0;
}
void Load()
{
    InitWindow(WIDTH, HEIGHT, "Make More!");
    SetTargetFPS(60);
    factoryBG = LoadTexture("Sprites/MakeMoreBG.png");
    table = LoadTexture("Sprites/TableSprite.png");
    block = LoadTexture("Sprites/BlockSprite.png");
}

void Start()
{
    center_window(WIDTH, HEIGHT);
}

void Update()
{

}

void Draw()
{
    BeginDrawing();
    DrawTextureEx(factoryBG, Vector2{0,0}, 0, 5, WHITE);
    //juste pour tester les placements
    DrawTextureEx(table, Vector2{ 350, 200 }, 0, 3, WHITE);
    DrawTextureEx(block, Vector2{ 350, 104 }, 0, 3, LIME);

    DrawTextureEx(table, Vector2{ 600, 200 }, 0, 3, WHITE);
    DrawTextureEx(block, Vector2{ 600, 104 }, 0, 3, BLUE);

    DrawTextureEx(table, Vector2{ 850, 200 }, 0, 3, WHITE);
    DrawTextureEx(block, Vector2{ 850, 104 }, 0, 3, BLUE);

    DrawTextureEx(table, Vector2{ 350, 350 }, 0, 3, WHITE);
    DrawTextureEx(block, Vector2{ 350, 254 }, 0, 3, BLUE);

    DrawTextureEx(table, Vector2{ 350, 500 }, 0, 3, WHITE);
    DrawTextureEx(block, Vector2{ 350, 404 }, 0, 3, BLUE);

    ClearBackground(Color({ 255, 255, 255, 255 }));
    EndDrawing();
}

void Unload()
{
    UnloadTexture(factoryBG);
    UnloadTexture(table);
    UnloadTexture(block);
    CloseWindow();
}

void center_window(float window_width, float window_height)
{
    int monitor = GetCurrentMonitor();
    int monitor_width = GetMonitorWidth(monitor);
    int monitor_height = GetMonitorHeight(monitor);
    SetWindowPosition(monitor_width / 2 - static_cast<int>(window_width / 2),
        monitor_height / 2 - static_cast<int>(window_height / 2));
}