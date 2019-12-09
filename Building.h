#ifndef BUILDING_H
#define BUILDING_H
#include "GameObject.h"
using namespace std;
class Building : public GameObject{
 private:
  unsigned int pokemon_count = 0 ;
 public: 
  Building();
  Building(char, int, Point2D);
  void AddOnePokemon();
  void RemoveOnePokemon();
  void ShowStatus();
  bool ShouldBeVisible();
};
#endif
