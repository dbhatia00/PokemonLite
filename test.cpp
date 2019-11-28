using namespace std;
#include "GameCommand.h"
int main(){
   srand(time(NULL));
   Model * h = new Model();
   View v;
   char input;
   int ID1, ID2, staminaAmt, unitAmt, x,y;
   bool displayFlag = false;   
   h ->ShowStatus();
   h->Display(v);
   do
   {
      displayFlag = false;
      cout << "Command: " ;
      cin >> input;
      switch (input)
      {
      case 'm':
         //cout << endl << "Please enter ID: ";
         cin >> ID1;
         //cout << endl <<"Please enter x and y: ";
         cin >> x >> y;
         //cout << endl << x << y;
         //cout << " Moving " << h->GetPokemonPtr(ID1) ->GetName() << " to " << Point2D(x,y) << endl;
         GameCommand().DoMoveCommand(*h,ID1,Point2D(x,y));
         break;
      case 'g':
         //cout << "Please enter pokemon id then gym id: ";
         cin >> ID1 >> ID2;
         //cout << " Moving " << h->GetPokemonPtr(ID1) ->GetName() << " to gym " << h->GetPokemonGymPtr(ID2)->GetId()<< endl; 
         GameCommand().DoMoveToGymCommand(*h, ID1,ID2); 
         break;
      case 'c':
         //cout << "Please enter pokemon id then center id: ";
         cin >> ID1 >> ID2;
         //cout << endl;
         //cout << " Moving " << h->GetPokemonPtr(ID1) ->GetName() << " to center " << h->GetPokemonCenterPtr(ID2) ->GetId() << endl; 
         GameCommand().DoMoveToCenterCommand(*h, ID1,ID2); 
         break;
      case 's':
         //cout << "Pkmn ID: ";
         cin >> ID1;
         //cout << " Stopping " << h->GetPokemonPtr(ID1) ->GetName() << endl;
         GameCommand().DoStopCommand(*h,ID1);
         break;
      case 'r':   
         //cout << "pkmn RecAMT ";
         cin >> ID1 >> staminaAmt;
         GameCommand().DoRecoverInCenterCommand(*h,ID1,staminaAmt);
         break; 
      case 't':
         //cout << "pkmnID TrainAmt " ;
         cin >> ID1 >> unitAmt;
         GameCommand().DoTrainInGymCommand(*h, ID1,unitAmt);
         break;
      case 'v':
         GameCommand().DoGoCommand(*h,v);
         displayFlag = true;
         break;
      case 'x':
         GameCommand().DoRunCommand(*h,v);
         displayFlag = true;
         break;
      default:
         break;
      }
      if(input == 'q') displayFlag = true;
      
      if(!displayFlag) h->Display(v);
   } while (input!='q');
   delete h;
}