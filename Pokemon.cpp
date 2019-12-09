#include "Pokemon.h"
#include <iostream>
using namespace std;

    Pokemon::Pokemon():GameObject('P'){
        speed = 5;
        state = STOPPED;
        cout << "Pokemon Default Constructed" << endl;
    }
    Pokemon::Pokemon(char in_code): GameObject(in_code){
        speed = 5;
        state = STOPPED;
        display_code = in_code;
        cout << "Pokemon Constructed" << endl;
    }
    Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc):GameObject(in_loc, in_id, in_code ){
        speed = in_speed;
        state = STOPPED;
        name = in_name;
        cout << "Pokemon Constructed" << endl;
    }
    Pokemon::~Pokemon(){
        cout << "Pokemon destructed" << endl;
        //GameObject::~GameObject();
    }
    void Pokemon::StartMoving(Point2D dest){
        SetupDestination(dest);
        state = MOVING;
        if (location.x == dest.x && location.y == dest.y){
            cout << display_code<< id_num << ": I'm already there. See?" << endl;}
        else if (IsExhausted()){
            cout << display_code << id_num << ": I am exhausted. I may move but you cannot see me." << endl;} 
        else
            cout << display_code << id_num << ": On my way." << endl;
    }

    void Pokemon::StartMovingToCenter(PokemonCenter * center){
        if(IsExhausted()) 
            cout << display_code << id_num << ": I am exhausted so I can't move to recover stamina..." << endl;
        else if((center->GetLocation()).x == location.x && (center->GetLocation()).y == location.y) 
            cout << display_code << id_num << ": I am already at the Pokemon Center!" << endl;
        else {
            SetupDestination(center -> GetLocation());
            state = MOVING_TO_CENTER;
            current_center = center;
            cout << display_code << id_num << ": on my way to center " << (center -> GetId()) << endl;
        }
    }

    void Pokemon::StartMovingToGym(PokemonGym* gym){
        if(IsExhausted()) 
            cout << display_code << id_num << ": I am exhausted so I shouldn't be going to the gym..." << endl;
        else if ((gym->GetLocation()).x == location.x && (gym->GetLocation()).y == location.y) 
            cout << display_code << id_num << ": I am already at the Pokemon Gym!" << endl;
        else {
            SetupDestination(gym -> GetLocation());
            state = MOVING_TO_GYM;
            current_gym = gym;
            cout << display_code << id_num << ": on my way to gym " << gym -> GetId() << endl;
        }
    }

    void Pokemon::StartTraining(unsigned int num_training_units){
        if (IsExhausted())
            cout << display_code << id_num << ": I am exhausted so no more training for me..." << endl;
        else if (state != IN_GYM)
            cout << display_code << id_num << ": I can only train in a Pokemon Gym!" << endl;
        else if (!(current_gym -> IsAbleToTrain(num_training_units, pokemon_dollars, stamina)))
            cout << display_code << id_num << ": Not enough stamina and/or money for training" << endl;
        else if (current_gym ->GetState() == BEATEN)
            cout << display_code << id_num << ": Cannot Train! This gym has already been beaten" << endl;
        else {
            state = TRAINING_IN_GYM;
            cout << display_code << id_num << ": Started to train at Pokemon Gym " << current_gym ->GetId() << " with " << num_training_units << " training units" << endl;
            if(current_gym -> GetNumTrainingUnitsRemaining() >= num_training_units){
                training_units_to_buy = num_training_units;
            }
            else{
                training_units_to_buy = current_gym -> GetNumTrainingUnitsRemaining();
                }
        }
    }

    void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points){
        if(!(state == IN_CENTER))
            cout << display_code << id_num << ": I can only recover at a Pokemon Center!" << endl; 
        else if (current_center ->GetState() == NO_STAMINA_POINTS_AVAILABLE)
            cout << display_code << id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center." << endl;
        else if (!(current_center -> CanAffordStaminaPoints(num_stamina_points, pokemon_dollars)))
            cout << display_code << id_num << ": Not enough money to recover stamina." << endl;
        else{
            state = RECOVERING_STAMINA;
            stamina_points_to_buy = num_stamina_points;
            cout << display_code << id_num << " Started recovering " << num_stamina_points << " stamina points at Pokemon Center " << current_center->GetId() << endl;
    }}

    void Pokemon::Stop(){
        state = STOPPED;
        cout << display_code << id_num << ": Stopping.." << endl;
    }

    bool Pokemon::IsExhausted(){   
        if (stamina == 0)
            return true;
        else
            return false;
    }

    bool Pokemon::ShouldBeVisible(){
        if (IsExhausted())
            return false;
        else
            return true;
    }

    bool Pokemon::UpdateLocation(){
        Point2D oneStep = location+delta; 

        if(!IsExhausted()) stamina--;
    
        if (fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y)){
            location = destination;
            cout << display_code << id_num << ": I'm there!" << endl;

            if(state == MOVING_TO_CENTER){
                current_center -> AddOnePokemon();
                is_in_center = true;
            }
            else if (state == MOVING_TO_GYM){
                current_gym -> AddOnePokemon();
                is_in_gym = true;
            }
            else if(state == MOVING_TO_ARENA){
                current_arena -> AddOnePokemon();
                is_in_arena = true;
            }
            return true;
        }
        else
        {
            pokemon_dollars += GetRandomAmountOfPokemonDollars();
            location = oneStep;
            cout << display_code << id_num << ": step.." << endl;

            if (is_in_center){
                is_in_center = 0;
                current_center ->RemoveOnePokemon();
            }
            if(is_in_gym){
                is_in_gym = 0;
                current_gym ->RemoveOnePokemon();
            }
            if(is_in_arena){
                is_in_arena = 0;
                current_arena ->RemoveOnePokemon();
            }

            return false;
        }
    }

    void Pokemon::SetupDestination(Point2D dest){
        destination = dest;
        delta = (destination - location) * (speed / GetDistanceBetween(destination,location));
    }

    void Pokemon::ShowStatus(){
        cout << name << " status: " <<endl;
        cout << "\tStamina: " << stamina << endl << "\tPokemon Dollars: " << pokemon_dollars << endl << "\tExperience points: " << experience_points << endl;
        GameObject::ShowStatus();
         //cout << "*******SHOW STATUS"<<int(state)<< endl;
        switch (state)
        {
            case STOPPED: 
                cout << "\tstopped" << endl;
                break;
            case MOVING: 
                cout << "\tmoving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << endl;
                break;
            case MOVING_TO_CENTER: 
                cout << "\theading to Pokemon Center " << current_center -> GetId() << " at a speed of " << speed << " at each step of " << delta<< endl;
                break;
            case MOVING_TO_GYM: 
                cout << "\theading to Pokemon Gym " << current_gym -> GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
                break;
            case IN_CENTER: 
                cout << "\tinside Pokemon Center " << current_center ->GetId() << endl;
                break;
            case IN_GYM: 
                cout << "\tinside Pokemon Gym " << current_gym -> GetId() << endl;
                break;
            case TRAINING_IN_GYM: 
                cout << "\ttraining in Pokemon Gym " << current_gym -> GetId() << endl;
                break;
            case RECOVERING_STAMINA: 
                cout << "\trecovering stamina in Pokemon center " << current_center-> GetId() << endl;
                break;
            case MOVING_TO_ARENA:
                cout << "\tmoving to arena " << current_arena->GetId() << endl;
                break;
            case BATTLE:
                cout << "\tbattling in arena "<< endl;
                break;
            case IN_ARENA:
                cout << "\tchilling in arena"   << endl;
                break;
        }   
        if (IsExhausted()) cout << "\tExhausted!" << endl;
    }

    bool Pokemon::Update(){
        //cout << "**************"<<int(state)<< endl;
        unsigned int temp, temp2;
        if(IsExhausted()){
            cout << name << " is exhausted!" << endl;
        }    
        switch (state)
        {
            case STOPPED:
                return false;
                break;
            case MOVING:
                if (UpdateLocation())
                {
                    state = STOPPED;
                    return true;
                }
                else 
                    return false;
                break;
            case MOVING_TO_CENTER:
                if(UpdateLocation()){
                    state = IN_CENTER;
                    return true;
                }
                else return false;
                break;
            case MOVING_TO_GYM:
                if(UpdateLocation()){
                    state = IN_GYM;
                    return true;
                }
                else return false;
                break;
            case IN_CENTER:
                return false;
                break;
            case IN_GYM:
                return false;
                break;
            case TRAINING_IN_GYM:
                stamina = stamina - current_gym -> GetStaminaCost(training_units_to_buy);
                temp = current_gym -> TrainPokemon(training_units_to_buy);
                experience_points += temp;
                pokemon_dollars = pokemon_dollars - current_gym ->GetDollarCost(training_units_to_buy);
                cout << "** " << name << " completed " << training_units_to_buy << " training units(s) " << endl;
                cout << "** " << name << " gained " << temp << " experience points!" << endl;
                state = IN_GYM;
                return true;
                break;
            case RECOVERING_STAMINA:
                temp2 = current_center -> DistributeStamina(stamina_points_to_buy);
                stamina += temp2;
                pokemon_dollars -= current_center ->GetDollarCost(stamina_points_to_buy);
                cout << "** " << name << " recovered " << temp2 << " stamina points!"<< endl;
                state = IN_CENTER;
                return true;
                break;
            case EXHAUSTED:
                return false;
                break;
            case MOVING_TO_ARENA:
                if(UpdateLocation()){
                    state = IN_ARENA;
                    return true;
                }
                else return false;
                break;
            case IN_ARENA:
                return false;
                break;
            case BATTLE:
                pokemon_dollars -= current_arena ->GetDollarCost();
                stamina -= current_arena ->GetStaminaCost();
                StartBattle();
                if(target -> get_health() == 0){
                    health = store_health;
                    state = IN_ARENA;
                    target -> IsAlive();
                }
                else
                {
                    state = FAINTED;
                    target ->IsAlive();
                }
        }
    }
    string Pokemon:: GetName(){
        return name;
    }
    bool Pokemon::IsAlive(){
            if(state == FAINTED){
                return true;
            }
            else return false;
    }

    void Pokemon::TakeHit(double phys_dmg, double mgk_dmg, double defense){
        double damage;
        int dmgTypeRandomizer = rand()%2;
        if(dmgTypeRandomizer == 0){
            damage = (100.0 - defense) / 100 * phys_dmg;
        }
        else{
            damage = (100.0 - defense) / 100 * mgk_dmg;   
        }
        if (health > damage) health = health - damage;
        else health = 0;
        
        //if(health ==0) state = FAINTED;
    }
    
    void Pokemon::StartMovingToArena(BattleArena* arena){
        if(IsExhausted()) 
            cout << display_code << id_num << ": I am exhausted so I shouldn't be going to the arena..." << endl;
        else if ((arena->GetLocation()).x == location.x && (arena->GetLocation()).y == location.y) 
            cout << display_code << id_num << ": I am already at the Arena!" << endl;
        else {
            SetupDestination(arena -> GetLocation());
            state = MOVING_TO_ARENA;
            current_arena = arena;
            cout << display_code << id_num << ": on my way to Battle Arena " << arena -> GetId() << endl;
        }
    }

    void Pokemon::ReadyBattle(Rival* in_target){
        if(state == IN_ARENA && current_arena->IsAbleToFight(pokemon_dollars, stamina) && !current_arena->IsBeaten() && in_target->IsAlive()){
            target = in_target;
            state = BATTLE;
        }
        else
        {
            state = IN_ARENA;
        }
    }

    bool Pokemon::StartBattle(){
        while (health>0 || target->get_health() > 0)
        {
            target->TakeHit(physical_damage, magical_damage, defense);

            if (target ->get_health() != 0) TakeHit(target ->get_phys_dmg(), target->get_magic_dmg(), target->get_defense());
        }
    }