#ifndef MODEL_H
#define MODEL_H
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "View.h"
#include "Input_Handling.h"
#include <list>
#include <iostream>
using namespace std;
class Model{
 private:
    list<GameObject*> object_ptrs;
    list<GameObject*> active_ptrs;
    int time;
    //GameObject * object_ptrs[10];
    //Pokemon * pokemon_ptrs[10];
   list<Pokemon*> pokemon_ptrs;
    //PokemonCenter * center_ptrs[10];
    list<PokemonCenter*> center_ptrs;
    //PokemonGym * gym_ptrs[10];
    list<PokemonGym*> gym_ptrs;
    //BattleArena * arena_ptrs[10];
    list<BattleArena*> arena_ptrs;
    //Rival * rival_ptrs[10];
    list<Rival*> rival_ptrs;
     /*int num_objects;
     int num_pokemon;
     int num_centers;
      int num_gyms;
      int num_arenas;
      int num_rivals;*/
 public: 
    Model();
    ~Model();
    Pokemon * GetPokemonPtr(int);
    PokemonCenter * GetPokemonCenterPtr(int);
    PokemonGym * GetPokemonGymPtr(int);
      BattleArena * GetPokemonArenaPtr(int);
    Rival* GetRivalPtr(int);
    bool Update();
    void Display(View&);
    void ShowStatus();
    void newObject(char);
};
#endif