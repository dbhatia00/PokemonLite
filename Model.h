#ifndef MODEL_H
#define MODEL_H
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "View.h"

#include <iostream>
using namespace std;
class Model{
 private:
    int time;
    GameObject * object_ptrs[10];
    int num_objects;
    Pokemon * pokemon_ptrs[10];
    int num_pokemon;
    PokemonCenter * center_ptrs[10];
    int num_centers;
    PokemonGym * gym_ptrs[10];
    int num_gyms;
    BattleArena * arena_ptrs[10];
    int num_arenas;
    Rival * rival_ptrs[10];
    int num_rivals;
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
};
#endif
