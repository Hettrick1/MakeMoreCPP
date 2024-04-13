#include "raylib.h"
#include "Menus.h"
#include <iostream>

const int WIDTH = 1080;
const int HEIGHT = 720;

Texture2D factoryBg;

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
    factoryBg = LoadTexture("Sprites/MakeMoreBG.png");
    menu.Load();
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
    DrawTextureEx(factoryBg, Vector2{0,0}, 0, 5, WHITE);
    
    ClearBackground(Color({ 255, 255, 255, 255 }));
    menu.Draw();
    EndDrawing();
}

void Unload()
{
    UnloadTexture(factoryBg);
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