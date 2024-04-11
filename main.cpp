#include "raylib.h"
#include "Menus.h"
#include <iostream>

const int WIDTH = 1080;
const int HEIGHT = 720;

Texture2D factoryBG, table, block;

Menus menu;

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
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WIDTH, HEIGHT, "Make More!");
    SetTargetFPS(60);
    menu.Load();
    factoryBG = LoadTexture("Sprites/MakeMoreBG.png");
    table = LoadTexture("Sprites/TableSprite.png");
    block = LoadTexture("Sprites/BlockSprite.png");
}

void Start()
{
    center_window(WIDTH, HEIGHT);
    menu.Start();
}

void Update()
{
    menu.Update();
}

void Draw()
{
    BeginDrawing();
    DrawTextureEx(factoryBG, Vector2{0,0}, 0, 5, WHITE);
    //juste pour tester les placements
    DrawTextureEx(table, Vector2{ 350, 200 }, 0, 3, WHITE);
    DrawTextureEx(block, Vector2{ 350, 130 }, 0, 2.5, LIME);

    DrawTextureEx(table, Vector2{ 600, 200 }, 0, 3, WHITE);
    DrawTextureEx(block, Vector2{ 600, 130 }, 0, 2.5, BLUE);

    DrawTextureEx(table, Vector2{ 850, 200 }, 0, 3, WHITE);
    DrawTextureEx(block, Vector2{ 850, 130 }, 0, 2.5, BLUE);

    DrawTextureEx(table, Vector2{ 350, 350 }, 0, 3, WHITE);
    DrawTextureEx(block, Vector2{ 350, 280 }, 0, 2.5, BLUE);

    DrawTextureEx(table, Vector2{ 350, 500 }, 0, 3, WHITE);
    DrawTextureEx(block, Vector2{ 350, 430 }, 0, 2.5, BLUE);

    ClearBackground(Color({ 255, 255, 255, 255 }));
    menu.Draw();
    EndDrawing();
}

void Unload()
{
    UnloadTexture(factoryBG);
    UnloadTexture(table);
    UnloadTexture(block);
    menu.Unload();
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