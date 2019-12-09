#ifndef RIVAL_H
#define RIVAL_H
#include "GameObject.h"
#include "BattleArena.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
class Rival: public GameObject{
    protected:
        double health = 20;
        double physical_damage = 5;
        double magical_damage = 4;
        double defense = 15;
        bool is_in_arena;
        string name;
        double mvmtspeed;
        BattleArena * current_arena;
    public:
        Rival(string nam, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D loc);
        void TakeHit(int, int, int);
        double get_phys_dmg();
        double get_magic_dmg();
        double get_defense();
        double get_health();
        
        bool Update();
        void ShowStatus();
        bool IsAlive();
        bool ShouldBeVisible();
};
enum RivalStates {
        FAINTED_RIVAL = 0,
        ALIVE_RIVAL =1
    };
#endif 