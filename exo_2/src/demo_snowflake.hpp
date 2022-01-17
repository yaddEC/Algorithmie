#pragma once

#include "demo.hpp"

Vector2 GenPoint(Vector2 p1, Vector2 p2);

class DemoSnowflake : public Demo
{
public:
    const char* GetName() override { return "Snowflake"; }
    void UpdateAndDraw() override;
};