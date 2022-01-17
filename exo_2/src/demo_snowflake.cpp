
#include <cmath>
#include <raylib.h>

#include "demo_snowflake.hpp"

Vector2 GenPoint(Vector2 p1, Vector2 p2)
{
    Vector2 temp;
    Vector2 p3;

    temp.x = sin(60 * PI / 180.0);
    temp.y = cos(60 * PI / 180.0);
    p3.x = temp.y * (p1.x - p2.x) - temp.x * (p1.y - p2.y) + p2.x;
    p3.y = temp.x * (p1.x - p2.x) + temp.y * (p1.y - p2.y) + p2.y;

    return p3;
}

Vector2 GetMiddle(Vector2 p1, Vector2 p2)
{
    Vector2 p3;
    p3.x = (p1.x + p2.x) / 2;
    p3.y = (p1.y + p2.y) / 2;
    return p3;
}

void DrawTriangleYann(Vector2 p1, Vector2 p2, Vector2 p3)
{
    DrawLine(p1.x, p1.y, p2.x, p2.y, BLACK);
    DrawLine(p1.x, p1.y, p3.x, p3.y, BLACK);
    DrawLine(p3.x, p3.y, p2.x, p2.y, BLACK);
}

void DrawKochBranch(Vector2 p1, Vector2 p2, int depth)
{
    Vector2 p3 = GenPoint(p1, p2);
    DrawTriangleYann(p1,p2,p3);
    if (depth == 0)
    {
    DrawTriangleYann(p1,p2,p3);
    }
    else
    {
        Vector2 p4 = GetMiddle(p1, p2);
        Vector2 p5 = GetMiddle(p1, p4);
        Vector2 p6 = GetMiddle(p4, p2);
        DrawKochBranch(p5, p6, depth - 1);

        p4 = GetMiddle(p1, p3);
        p5 = GetMiddle(p1, p4);
        p6 = GetMiddle(p4, p3);
        DrawKochBranch(p5, p6, depth - 1);

        p4 = GetMiddle(p3, p2);
        p5 = GetMiddle(p3, p4);
        p6 = GetMiddle(p4, p2);
        DrawKochBranch(p5, p6, depth - 1);
    }
}

void DemoSnowflake::UpdateAndDraw()
{
    DrawKochBranch({100, 200}, {100, 400}, 3);
}