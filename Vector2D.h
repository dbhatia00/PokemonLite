#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
using namespace std;

class Vector2D{
    public:
    double x;
    double y;
    Vector2D();
    Vector2D(double in_x, double in_y);
};

ostream& operator<<(ostream& out, Vector2D inPoint);

Vector2D operator*(Vector2D v1, double mult);

Vector2D operator/(Vector2D v1, double div);
#endif