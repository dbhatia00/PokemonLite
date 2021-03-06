#include "BattleArena.h"

    BattleArena::BattleArena(){
        display_code = 'A';
        pokemon_count = 0;
        max_num_rivals = 3;
        num_rivals_remaining = max_num_rivals;
        dollar_cost_per_fight = 4;
        stamina_cost_per_fight = 3;
        state = RIVALS_AVAILABLE;
        cout << "Battle Arena default constructed." << endl;
    }

    BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D in_loc):Building('A',in_id,in_loc){
        max_num_rivals = max_rivals;
        num_rivals_remaining = max_num_rivals;
        pokemon_count =0;
        dollar_cost_per_fight = 4;
        stamina_cost_per_fight = 3;
        state = RIVALS_AVAILABLE;
        cout << "BattleArena constructed." << endl;
    }
    unsigned int BattleArena::GetNumRivalsRemaining(){
        return num_rivals_remaining;
    }
    bool BattleArena::HasEnoughRivals(){
        if (num_rivals_remaining > 0 ){
            return true;
        }
        else{
            return false;
        }
    }
    double BattleArena::GetDollarCost(){
        return dollar_cost_per_fight;
    }
    unsigned int BattleArena::GetStaminaCost(){
        return stamina_cost_per_fight;
    }
    bool BattleArena::IsAbleToFight(double budget, unsigned int stamina){
        if (budget>=dollar_cost_per_fight && stamina>=stamina_cost_per_fight){
            return true;
        }
        else{
            return false;
        }
    }
    bool BattleArena::Update(){
        if(state !=NO_RIVALS_AVAILABLE && num_rivals_remaining == 0){
            display_code =tolower(display_code);
            state = NO_RIVALS_AVAILABLE;
            return true;
        }
        else{
            return false;
        }
    }
    bool BattleArena::IsBeaten(){
        if (num_rivals_remaining == 0){
            return true;
        }
        else
        {
            return false;
        }
        
    }
    void BattleArena::ShowStatus(){
        cout << "Battle Arena status: " << endl;
        Building::ShowStatus();
        cout << "\tMax number of rivals: " << max_num_rivals << endl;
        cout << "\tStamina cost per fight: " << stamina_cost_per_fight << endl;
        cout << "\tPokemon dollars per fight: " << dollar_cost_per_fight<< endl;
        cout << "\t"<<num_rivals_remaining << " rival(s) are reminaing for this arena."<< endl;
    }

    void BattleArena::RemoveRivals(){
        num_rivals_remaining--;
    }