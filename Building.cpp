#include "Building.h"
using namespace std;
// Section 15.4.2 - chaining constructors

Building:: Building() : GameObject('B'){
  cout << "Building default constructed" << endl;
}

Building:: Building(char in_code, int in_Id, Point2D in_loc) :GameObject(in_loc, in_Id, in_code){
  cout << "Building Constructed" << endl;
}
void Building::AddOnePokemon(){
  pokemon_count++;
}
void Building::RemoveOnePokemon(){
  pokemon_count--;
}
void Building::ShowStatus(){
  cout << "\t" <<display_code << id_num << " located at " << location;
  if (pokemon_count == 1) cout << endl << "\t" << pokemon_count << " pokemon is in this building" << endl;
  else cout << endl << "\t"<< pokemon_count << " pokemon are in this building" << endl;
    
}
bool Building::ShouldBeVisible(){
  return true;
}

