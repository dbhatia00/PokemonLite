#include "Model.h"

Model::Model(){
    time =0;
    Point2D p(5,1);
    Pokemon * p1 = new Pokemon("Pikachu", 1,'P', 2,p);
    p.x = 10;
    Pokemon * p2 = new Pokemon("Lucario", 2, 'P', 1, p);

    p.y = 20; p.x = 1;
    PokemonCenter* c1 = new PokemonCenter(1, 1, 100, p);
    p.x = 10;
    PokemonCenter* c2 = new PokemonCenter(2, 2, 200,p);

    PokemonGym* g1 = new PokemonGym();
    p.x = 5; p.y =5;
    PokemonGym* g2 = new PokemonGym(20, 5,7.5,8,2,p);

    BattleArena* b1 = new BattleArena(2, 5, 5, 1, Point2D(10,10));

    Rival* r1 = new Rival("Gary", 5, 10, 5, 5, 5, 1, Point2D(10,10));
    Rival* r2 = new Rival("Silver", 5,10,5,5,5,2, Point2D(10,10));
    
    
    //object_ptrs  ={ p1, p2, c1 , c2 , g1,g2,b1,r1,r2};
    object_ptrs.push_back(p1);
    object_ptrs.push_back(p2);
    object_ptrs.push_back(c1);
    object_ptrs.push_back(c2);
    object_ptrs.push_back(g1);
    object_ptrs.push_back(g2);
    object_ptrs.push_back(b1);
    object_ptrs.push_back(r1);
    object_ptrs.push_back(r2);

    active_ptrs.assign(object_ptrs.begin(), object_ptrs.end());


    //pokemon_ptrs = {p1,p2};
    pokemon_ptrs.push_back(p1);
    pokemon_ptrs.push_back(p2);

    //center_ptrs = {c1,c2};
    center_ptrs.push_back(c1);
    center_ptrs.push_back(c2);

    //gym_ptrs = {g1,g2};
    gym_ptrs.push_back(g1);
    gym_ptrs.push_back(g2);

    //rival_ptrs = {r1,r2};
    rival_ptrs.push_back(r1);
    rival_ptrs.push_back(r2);

    //arena_ptrs = {b1};
    arena_ptrs.push_back(b1);

    cout << "Model default constructed" << endl;
}
Model::~Model(){
    object_ptrs.clear();
    cout << "Model destructed" << endl;
}
Pokemon * Model::GetPokemonPtr(int id){
    if(id <= pokemon_ptrs.size() && id>0){
        list<Pokemon*>::iterator it = pokemon_ptrs.begin();
        advance(it,id-1);
        return *it;
        }
    else{
        return 0;
}}
PokemonCenter * Model::GetPokemonCenterPtr(int id){
    if(id <= center_ptrs.size() && id>0){
        list<PokemonCenter*>::iterator it = center_ptrs.begin();
        advance(it,id-1);
        return *it;
        }
    else{
        return 0;
}
}
PokemonGym * Model::GetPokemonGymPtr(int id){
    if(id <= gym_ptrs.size() && id>0){
        list<PokemonGym*>::iterator it = gym_ptrs.begin();
        advance(it,id-1);
        return *it;
        }
    else{
        return 0;
}}

BattleArena* Model::GetPokemonArenaPtr(int id){
    if(id <= arena_ptrs.size() && id>0){
        list<BattleArena*>::iterator it = arena_ptrs.begin();
        advance(it,id-1);
        return *it;
        }
    else{
        return 0;
}}
Rival * Model::GetRivalPtr(int id){
    if(id <= pokemon_ptrs.size() && id>0){
        list<Rival*>::iterator it = rival_ptrs.begin();
        advance(it,id-1);
        return *it;
        }
    else{
        return 0;
}}
bool Model::Update(){
    time++;
    list<bool> tempBool;
    tempBool.assign(active_ptrs.size(), false);

    for(list<GameObject*>::iterator it = active_ptrs.begin(); it!=active_ptrs.end(); advance(it,1)){
        tempBool.push_front((*it) ->Update());
    }

    for(list<bool>::iterator it = tempBool.begin(); it!=tempBool.end(); advance(it,1)){
        if(*it) return true;
    }

    
    //clean pointers
    for(list<GameObject*>::iterator it = active_ptrs.begin(); it!=active_ptrs.end(); advance(it,1)){
        if(!((*it) ->ShouldBeVisible())){
             it = active_ptrs.erase(it);
             cout << "Dead object removed..." << endl;
    }}

    //gyms beaten / games lost

                /*if (gym_ptrs[0] ->IsBeaten() && gym_ptrs[1] ->IsBeaten())
                {
                    cout << endl <<"You won the game! All Gyms Have been Defeated! " << endl;
                    exit(EXIT_SUCCESS);
                }
                if (pokemon_ptrs[0] ->IsExhausted() && pokemon_ptrs[1] ->IsExhausted())
                {
                    cout << endl << "You lost the game, all pokemon are exhausted" << endl;
                    exit(EXIT_FAILURE);
                }*/

    
    
}

void Model::Display(View& v){
    v.Clear();

    /*for(int i =0 ; i<num_objects; i++){
        v.Plot(object_ptrs[i]);
    }*/
    for(list<GameObject*>::iterator it = active_ptrs.begin(); it!=active_ptrs.end(); advance(it,1)){
        v.Plot(*it);
    }
    v.Draw();
    
}
void Model::ShowStatus(){
    for(list<GameObject*>::iterator it = object_ptrs.begin(); it!=object_ptrs.end(); advance(it,1)){
        (*it) -> ShowStatus();
    }
    cout << "Time: " << time << endl;
}

void Model::newObject(char inChar){
    //cout << "Please enter location (x y) ";
    int x, y, id;
    cin >> id >> x >> y;
    if(inChar == 'g'){
        for(list<PokemonGym*>::iterator it = gym_ptrs.begin(); it!=gym_ptrs.end(); advance(it,1)){
            if((*it)->GetId() == id) throw Invalid_Input("Bad ID! (ID Already taken)");
        }

        PokemonGym * g = new PokemonGym(20, 5,7.5,8,id,Point2D(x,y));
        object_ptrs.push_back(g);
        active_ptrs.push_back(g);
        gym_ptrs.push_back(g);
    }
    else if(inChar == 'r'){
        bool temp1 = false;
        for(list<Rival*>::iterator it = rival_ptrs.begin(); it!=rival_ptrs.end(); advance(it,1)){
            if((*it)->GetId() == id) throw Invalid_Input("Bad ID! (ID Already taken)");
        }
        for(list<BattleArena*>::iterator it = arena_ptrs.begin(); it!=arena_ptrs.end(); advance(it,1)){
            if((*it)->GetLocation().x == x && (*it)->GetLocation().y == y){
                temp1 = true;
            }
        }
        if(!temp1){
            throw Invalid_Input("Bad location, there is no arena here!");
        }
        Rival * r = new Rival("Rival", 5,10,5,5,5,id, Point2D(x,y));
        object_ptrs.push_back(r);
        active_ptrs.push_back(r);
        rival_ptrs.push_back(r);
    }
    else if(inChar == 'c'){
        for(list<PokemonCenter*>::iterator it = center_ptrs.begin(); it!=center_ptrs.end(); advance(it,1)){
            if((*it)->GetId() == id) throw Invalid_Input("Bad ID! (ID Already taken)");
        }

        PokemonCenter * c = new PokemonCenter(id, 1, 100,Point2D(x,y));
        object_ptrs.push_back(c);
        active_ptrs.push_back(c);
        center_ptrs.push_back(c);
    }
    else
    {
        for(list<Pokemon*>::iterator it = pokemon_ptrs.begin(); it!=pokemon_ptrs.end(); advance(it,1)){
            if((*it)->GetId() == id) throw Invalid_Input("Bad ID! (ID Already taken)");
        }
         Pokemon * p = new Pokemon("Missingno", id,'P', 2,Point2D(x,y));
        object_ptrs.push_back(p);
        active_ptrs.push_back(p);
        pokemon_ptrs.push_back(p);
    }
    
}