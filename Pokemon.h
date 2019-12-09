#include "PokemonCenter.h"
#include "PokemonGym.h"
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

    protected:
        bool UpdateLocation();
        void SetupDestination(Point2D);

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
        RECOVERING_STAMINA = 8
    };
static double GetRandomAmountOfPokemonDollars(){
    return rand()%2;
}