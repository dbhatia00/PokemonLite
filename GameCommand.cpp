#include "GameCommand.h"
    void GameCommand::DoMoveCommand(Model & model, int pokemon_id, Point2D p1){
        
        if((model.GetPokemonPtr(pokemon_id)) != NULL){
            Pokemon * poke = model.GetPokemonPtr(pokemon_id);
            poke -> StartMoving(p1);
            if(poke -> GetState() == MOVING) cout << "Moving " << poke ->GetName() << " to " << p1 << endl;
        }
        else
            cout << "Invalid input, please try again" << endl;
    }
    void GameCommand::DoMoveToCenterCommand(Model & model, int pokemon_id, int center_id){
        if((model.GetPokemonPtr(pokemon_id)) != NULL){
            Pokemon * poke = model.GetPokemonPtr(pokemon_id);
            PokemonCenter * pc = model.GetPokemonCenterPtr(center_id);
            poke ->StartMovingToCenter(pc);
            if(poke->GetState() == MOVING_TO_CENTER)
                cout << "Moving " << poke->GetName() << " to Pokemon Center " << pc->GetId() << endl;
        }
        else
            cout << "Invalid input, please try again" << endl;
    }
    void GameCommand::DoMoveToGymCommand(Model & model, int pokemon_id, int gym_id){
        if((model.GetPokemonPtr(pokemon_id)) != NULL){
            Pokemon * poke = model.GetPokemonPtr(pokemon_id);
            PokemonGym * pg = model.GetPokemonGymPtr(gym_id);
            poke ->StartMovingToGym(pg);
            if(poke->GetState() == MOVING_TO_GYM)
                cout << "Moving " << poke->GetName() << " to Pokemon Gym " << pg->GetId() << endl;
        }
        else
            cout << "Invalid input, please try again" << endl;
    }
    void GameCommand::DoStopCommand(Model & model, int pokemon_id){
        if((model.GetPokemonPtr(pokemon_id)) != NULL){
            Pokemon * poke = model.GetPokemonPtr(pokemon_id);
            poke ->Stop();
            if(poke ->GetState() == STOPPED)
                cout << "Stopping " << poke->GetName() << endl; 
        }
        else
            cout << "Invalid input, please try again" << endl;
    }
    void GameCommand::DoTrainInGymCommand(Model & model, int pokemon_id, unsigned int training_units){
        if((model.GetPokemonPtr(pokemon_id)) != NULL){
            Pokemon * poke = model.GetPokemonPtr(pokemon_id);
            poke ->StartTraining(training_units);
            if(poke->GetState() == TRAINING_IN_GYM)
                cout << "Training " << poke->GetName() << endl;
        }
        else
            cout << "Invalid input, please try again" << endl;
    }
    void GameCommand::DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points){
        if((model.GetPokemonPtr(pokemon_id)) != NULL){
            Pokemon * poke = model.GetPokemonPtr(pokemon_id);
            poke -> StartRecoveringStamina(stamina_points);
            if (poke->GetState() == RECOVERING_STAMINA)
                cout << "Recovering " << poke->GetName() <<"'s stamina" << endl;
        }
        else
            cout << "Invalid input, please try again" << endl;
    }
    void GameCommand::DoGoCommand(Model& model, View& view){
        cout << "Advancing one tick" << endl;
        model.Update();
        //, View &view
        model.ShowStatus();
        model.Display(view);
    }
    void GameCommand::DoRunCommand(Model& model, View& view){
        //, View &view
        int counter = 0;
        cout << "Advancing to next event..." << endl;
        while (!model.Update() && counter<5){
            counter++;
        }    
        model.ShowStatus();
        model.Display(view);
    }