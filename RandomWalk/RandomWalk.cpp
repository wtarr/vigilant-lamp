#include <iostream>
#include <vector>
#include <raylib.h>

int screenWidth = 800;
int screenHeight = 450;

// Function declarations
std::vector<Vector2> WalkRandom(int num, Vector2 start);

int main()
{
    //std::cout << "Hello World!\n";
    InitWindow(screenWidth, screenHeight, "Random Walk");

    SetTargetFPS(60);

    Vector2 start = { (float)screenWidth / 2,  (float)screenHeight / 2 }; // also start point

    auto points = WalkRandom(10000, Vector2{ start.x, start.y });

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        for (size_t i = 0; i < points.size() - 1; i++)
        {
            auto a = points[i];
            auto b = points[i + 1];

            DrawLine(a.x, a.y, b.x, b.y, RED);
        }

        DrawText("This took longer than it should have!", 190, 200, 20, BLUE);

        EndDrawing();

    }

    CloseWindow();

    return 0;
}


std::vector<Vector2> WalkRandom(int num, Vector2 start)
{
    int stepSize = 10;

    int x = start.x;
    int y = start.y;

    std::vector <Vector2> points;

    points.push_back(start);

    for (size_t i = 0; i < num - 1; i++)
    {
        int dir = GetRandomValue(0, 3);

        if (dir == 0) // up
        {
            y -= stepSize;
        }
        else if (dir == 1) // right
        {
            x += stepSize;
        }
        else if (dir == 2) // down
        {
            y += stepSize;
        }
        else
        {
            x -= stepSize;
        }

        Vector2 point = { x, y };

        points.push_back(point);

    }

    return points;

}