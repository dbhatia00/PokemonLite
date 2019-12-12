#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Rival.h"
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Pokemon : public GameObject{
    
    public:
        Pokemon();
        Pokemon(char);
        Pokemon(string, int, char, unsigned int, Point2D);
	    Pokemon(string in_name, double speed, double hp, double phys_dmg, double
		magic_dmg, double def, int in_id, char in_code, Point2D in_loc);
        virtual ~Pokemon();
        void StartMoving(Point2D);
        void StartMovingToCenter(PokemonCenter*);
        void StartMovingToGym(PokemonGym*);
        void StartTraining(unsigned int);
        void StartRecoveringStamina(unsigned int);
        void Stop();
        bool IsExhausted();
        bool ShouldBeVisible();
        void ShowStatus();
        bool Update();
        string GetName();
        //pa4 additions ->
        bool IsAlive();
        void TakeHit(double, double, double);
        void ReadyBattle(Rival*);
        bool StartBattle();
        void StartMovingToArena(BattleArena* arena);
    protected:
        bool UpdateLocation();
        void SetupDestination(Point2D);
        //pa4 additions ->
	    double health = 20;
	    double store_health = health;
	    double physical_damage = 5;
	    double magical_damage = 4;
	    double defense = 5;
	    Rival* target;
	    bool is_in_arena = 0;
	    BattleArena * current_arena;
    private:
        double speed;
        bool is_in_center = 0;
        bool is_in_gym = 0;
        unsigned int stamina = 20;
        unsigned int experience_points = 0;
        double pokemon_dollars = 100;
        unsigned int training_units_to_buy = 0;
        unsigned int stamina_points_to_buy = 0;
        string name;
        PokemonCenter * current_center = NULL;
        PokemonGym * current_gym = NULL;
        Point2D destination;
        Vector2D delta;
};
enum PokemonStates {
        STOPPED = 0,
        MOVING = 1,
        EXHAUSTED = 2,
        IN_GYM = 3,
        IN_CENTER = 4,
        MOVING_TO_GYM = 5,
        MOVING_TO_CENTER = 6,
        TRAINING_IN_GYM = 7,
        RECOVERING_STAMINA = 8,
        //pa4 additions ->
	IN_ARENA = 9,
	MOVING_TO_ARENA = 10,
	BATTLE = 11,
	FAINTED = 12
    };
static double GetRandomAmountOfPokemonDollars(){
    return rand()%2;
}
