#include <iostream>
#include <math.h>
#include "Point2D.h"

using namespace std;

    Point2D::Point2D(){
        x = 0;
        y = 0;
    }
    Point2D::Point2D(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }

double GetDistanceBetween(Point2D p1, Point2D p2){
        return sqrt(pow((p1.x -p2.x), 2) + pow((p1.y -p2.y), 2));
    }

ostream& operator<<(ostream& out, Point2D inPoint){
        out <<  "(" << inPoint.x << ", " << inPoint.y << ")";
        return out;
        
    }

Point2D operator+(Point2D p1, Vector2D v1){
        Point2D outPt;      
        outPt.x = p1.x + v1.x;
        outPt.y = p1.y + v1.y; 
        return outPt;
    }

Vector2D operator-(Point2D p1, Point2D p2){
        Vector2D outPt;
        outPt.x = p1.x - p2.x;
        outPt.y = p1.y - p2.y;       
        return outPt;
    }