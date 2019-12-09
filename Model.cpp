#include "Model.h"

Model::Model(){
    time =0;
    Point2D p(5,1);
    Pokemon * p1 = new Pokemon("Pikachu", 1,'P', 2,p);
    p.x = 10;
    Pokemon * p2 = new Pokemon("Bulbasaur", 2, 'P', 1, p);

    p.y = 20; p.x = 1;
    PokemonCenter* c1 = new PokemonCenter(1, 1, 100, p);
    p.x = 10;
    PokemonCenter* c2 = new PokemonCenter(2, 2, 200,p);

    PokemonGym* g1 = new PokemonGym();
    p.x = 5; p.y =5;
    PokemonGym* g2 = new PokemonGym(20, 5,7.5,8,2,p);

    

    BattleArena* b1 = new BattleArena(2, 5, 5, 1, Point2D(10,10));

    Rival* r1 = new Rival("Gary", 5, 100, 5, 5, 5, 1, Point2D(10,10));
    Rival* r2 = new Rival("Silver", 5,100,5,5,5,2, Point2D(10,10));

    object_ptrs[0] = p1;
    object_ptrs[1] = p2;
    object_ptrs[2] = c1;
    object_ptrs[3] = c2;
    object_ptrs[4] = g1;
    object_ptrs[5] = g2;
    object_ptrs[6] = b1;
    object_ptrs[7] = r2;
    object_ptrs[8] = r1;

    pokemon_ptrs[0] = p1;
    pokemon_ptrs[1] = p2;

    center_ptrs[0] = c1;
    center_ptrs[1] = c2;

    gym_ptrs[0] = g1;
    gym_ptrs[1] = g2;

    rival_ptrs[0] = r1;
    rival_ptrs[1] = r2;

    arena_ptrs[0] = b1;

    num_objects=6;
    num_pokemon=2;
    num_centers=2;
    num_gyms=2;
    num_arenas = 1;
    num_rivals = 2;

    cout << "Model default constructed" << endl;
}
Model::~Model(){
    for(int i = 0; i<num_pokemon;i++){
        pokemon_ptrs[i] -> ~Pokemon();
    }
    for (int i = 0; i<num_centers;i++){
        center_ptrs[i] ->~PokemonCenter();
    }
    for (int i = 0; i< num_gyms;i++){
        gym_ptrs[i] ->~PokemonGym();
    }
    cout << "Model destructed" << endl;
}
Pokemon * Model::GetPokemonPtr(int id){
    if(id <= num_pokemon && id>0){
        return pokemon_ptrs[id-1];}
    else{
        return 0;
}}
PokemonCenter * Model::GetPokemonCenterPtr(int id){
    return center_ptrs[id-1];
}
PokemonGym * Model::GetPokemonGymPtr(int id){
    return gym_ptrs[id-1];
}
BattleArena* Model::GetPokemonArenaPtr(int id){
    return arena_ptrs[id-1];
}
Rival * Model::GetRivalPtr(int id){
    return rival_ptrs[id-1];
}
bool Model::Update(){
    time++;
    bool tempBool[10] = {false};

    for(int i =0 ; i<9; i++){
        tempBool[i] = object_ptrs[i] -> Update();
    }
    for(int i = 0; i<9; i++){
        if(tempBool[i]) return true;
    }
    //gyms beaten / games lost

    if (gym_ptrs[0] ->IsBeaten() && gym_ptrs[1] ->IsBeaten())
    {
        cout << endl <<"You won the game! All Gyms Have been Defeated! " << endl;
        exit(EXIT_SUCCESS);
    }
    if (pokemon_ptrs[0] ->IsExhausted() && pokemon_ptrs[1] ->IsExhausted())
    {
        cout << endl << "You lost the game, all pokemon are exhausted" << endl;
        exit(EXIT_FAILURE);
    }
    
    
}

void Model::Display(View& v){
    v.Clear();
    for(int i =0 ; i<9; i++){
        v.Plot(object_ptrs[i]);
    }
    v.Draw();
    
}
void Model::ShowStatus(){
    for(int i =0 ; i<9; i++){
        object_ptrs[i] -> ShowStatus();
    }
    cout << "Time: " << time << endl;
}