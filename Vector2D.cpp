#include <iostream>
#include <math.h>
#include "Vector2D.h"
using namespace std;
    
    Vector2D::Vector2D(){
        x = 0;
        y = 0;
    }
    Vector2D::Vector2D(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }

ostream& operator<<(ostream& out, Vector2D inPoint){
        out <<  "<" << inPoint.x << ", " << inPoint.y << ">";
        return out;
    }

Vector2D operator*(Vector2D v1, double mult){
    Vector2D outV;
    outV.x = v1.x * mult;
    outV.y = v1.y * mult;
    return outV;
    }

Vector2D operator/(Vector2D v1, double div){
    Vector2D outV;
    outV.x = v1.x / div;
    outV.y = v1.y / div;
    return outV;
}