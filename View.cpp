#include "View.h"

    bool  View::GetSubscripts(int &out_x, int &out_y, Point2D location){
        out_x = (location.x - origin.x) / scale;
        out_y = (location.y - origin.y) / scale;
        if((out_x < view_maxsize && out_x >= 0) && (out_y < view_maxsize && out_y >= 0)) 
            return true;
        else 
            cout << "Object is outside the display" << endl;
            return false;
    }

    View::View(){
        size = 11;
        scale = 2;
        origin = Point2D();
    }

    void View::Clear(){
        for(int i = 0; i<view_maxsize; i++){
            for (int j = 0; j<view_maxsize; j++){
                grid[i][j][0] = '.';
            }
        }
    }

    void View::Plot(GameObject* ptr){
        int x,y;
        bool flag = GetSubscripts(x,y, ptr ->GetLocation());
        if(flag){
            if(grid[y][x][0] == '.' && ptr->ShouldBeVisible()) {ptr -> DrawSelf(&grid[y][x][0]);}
            else if (ptr->ShouldBeVisible()) {grid[y][x][0] = '*'; grid[y][x][1] = ' ';}
        }
    }

    void View::Draw(){
        
        for(int i = (view_maxsize / scale) ; i>=0; i--){
            if(i%2 == 0){
                if((i*scale)<10) cout << i*scale << " ";
                else cout << i*scale;
            }
            else
            {
                cout << "  ";
            }
            

            for(int j = 0; j <= view_maxsize / scale; j++){
                if(grid[i][j][0] == '.') cout << ". ";
                else cout << grid[i][j][0] << grid[i][j][1];  
            }
            cout << endl;
        }
        cout << "  ";
        for(int i = 0; i<=(view_maxsize / scale) ; i++){
            if(i%2 == 0){
                if((i*scale)<10) cout << i*scale << " ";
                else cout << i*scale;
            }
            else
            {
                cout << "  ";
            }
    }
    cout << endl;
    }