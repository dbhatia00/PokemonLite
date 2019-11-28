#include "PokemonGym.h"
using namespace std;

    PokemonGym::PokemonGym(){
        display_code = 'G';
        state =NOT_BEATEN;
        max_number_of_training_units = 10;
        num_training_units_remaining = max_number_of_training_units;
        stamina_cost_per_training_unit = 1;
        dollar_cost_per_training_unit = 1.0;
        experience_points_per_training_unit = 2;
        cout << "PokemonGym default constructed" << endl;
    }
    PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc):Building('G',in_id, in_loc ){
        max_number_of_training_units = max_training_units;
        num_training_units_remaining = max_number_of_training_units;
        state =NOT_BEATEN;
        stamina_cost_per_training_unit = stamina_cost;
        experience_points_per_training_unit = exp_points_per_unit;
        dollar_cost_per_training_unit = dollar_cost;
        cout << "PokemonGym constructed" << endl;
    }
    PokemonGym::~PokemonGym(){
        cout << "Pokemon Gym Destructed" << endl;
        //GameObject::~GameObject();
    }
    double PokemonGym::GetDollarCost(unsigned int unit_qty){
        return unit_qty*dollar_cost_per_training_unit;
    }
    unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty){
        return stamina_cost_per_training_unit*unit_qty;
    }
    unsigned int PokemonGym::GetNumTrainingUnitsRemaining(){
        return num_training_units_remaining;
    }
    bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget,  unsigned int stamina){
        if(budget > GetDollarCost(unit_qty) && stamina > GetStaminaCost(unit_qty)){
            return true;
        }
        else
            return false;
        
    }
    unsigned int PokemonGym::TrainPokemon(unsigned int training_units){
        if(num_training_units_remaining >= training_units){
            num_training_units_remaining -= training_units;
            return training_units * experience_points_per_training_unit;
        }
        else
        {
            int temp = num_training_units_remaining;
            num_training_units_remaining = 0;
            return temp;
        }
        
        
    }
    bool PokemonGym::Update(){
        if(IsBeaten() && state != BEATEN){
            state = BEATEN;
            display_code = 'g';
            cout << display_code << id_num << " has been defeated." << endl; 
            return true; 
        }
        else return false;
    }

    bool PokemonGym::IsBeaten(){
        if (num_training_units_remaining == 0) return true;
        else return false;
    }
    void PokemonGym::ShowStatus(){
        cout << "Pokemon gym status:" << endl; 
        Building :: ShowStatus();
        cout << "\tMax number of training units: " << max_number_of_training_units << endl;
        cout << "\tStamina cost per training unit: " << stamina_cost_per_training_unit << endl;
        cout << "\tPokemon dollar per training unit: " << dollar_cost_per_training_unit <<endl;
        cout << "\tExperience points per training unit: " << experience_points_per_training_unit<< endl;
        cout << "\t" << num_training_units_remaining << " training unit(s) are remaining for this gym" << endl; 

    }
