#include "Rival.h"
Rival::Rival(string nam, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D loc):GameObject(loc, id, 'R'){
    name = nam;
    mvmtspeed = speed;
    health = hp;
    physical_damage = phys_dmg;
    magical_damage= magic_dmg;
    defense = def;
    state = ALIVE_RIVAL;
    //current_arena = arena;
}
void Rival::TakeHit(int phys, int mag, int def){
    double damage;
    int dmgTypeRandomizer = rand()%2;
    if(dmgTypeRandomizer == 0){
        damage = (100.0 - def) / 100 * phys;
    }
    else{
        damage = (100.0 - def) / 100 * mag;   
    }
    if (health > damage) health = health - damage;
    else health = 0;

    //if (health == 0) state = FAINTED_RIVAL;
    
}
double Rival::get_phys_dmg(){
    return physical_damage;
}
double Rival::get_magic_dmg(){
    return magical_damage;
}
double Rival::get_defense(){
    return defense;
}
double Rival::get_health(){
    return health;
}
bool Rival::Update(){
    if(IsAlive() && state != FAINTED_RIVAL){
            state = FAINTED_RIVAL;
            cout << display_code << id_num << " has been defeated." << endl; 
            return true; 
        }
        else return false;
}
void Rival::ShowStatus(){
    cout << name <<" status:" << endl;
    cout << "\thealth: " << health << endl << "\tstate: ";
    if(state == ALIVE_RIVAL){
      cout <<  "RIVAL ALIVE";
    }
    else
    {
        cout << "RIVAL FAINTED";
    }
    cout << endl;
}
bool Rival::IsAlive(){
    if(health>0){
        return true;
    }
    else{
        return false;
    }
}
bool Rival::ShouldBeVisible(){
    if (IsAlive())
            return false;
        else
            return true;
}