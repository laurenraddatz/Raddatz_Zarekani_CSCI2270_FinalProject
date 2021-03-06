#include "Tournament.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h> // for atoi
using namespace std;

int main()
{
    Tournament newTournament;
    bool found = false;
    string userInput, userInput2;
    string name, attribute, health, attack, agility, dominant, inferior, speech, tier;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~   Welcome to the Divine Tournament!     ~~~" << endl;
    cout << "~~~   Immortal blood will be shed today...  ~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
     while(true){
        openingMenu:;
        cout << "======Main Menu======" << endl;
        cout << "1. Start New Tournament" << endl;
        cout << "2. Find God" << endl;
        cout << "3. Print Gods" << endl;
        cout << "4. Quit" << endl;
        getline(cin, userInput);

        if(userInput == "1"){
            cout << "================" << endl;
            cout << "1. Choose a God" << endl;
            cout << "2. Create a God" << endl;
            cout << "3. Join the Audience" << endl;
            cout << "4. Go Back" << endl;
            getline(cin, userInput2);
            if(userInput2 == "2"){ //make god
                cout << "What would you like to name your God?" << endl;
                getline(cin, name);
                attribute = "";
                while (attribute != "normal" and attribute != "lightning" and attribute != "fire" and attribute != "water" and attribute != "earth" ){ //make sure player choses available attribute
                    cout << "Choose Your God's Attribute (normal, lightning, fire, water, or earth)" << endl;
                    getline(cin, attribute);
                }
                dominant = "";
                while (dominant != "attack" and dominant != "health" and dominant != "agility"){ //make sure player choses available stat
                    cout << "Choose Your God's dominant stat (attack, health, or agility)" << endl;
                    getline(cin, dominant);
                }
                inferior = "";
                while (inferior != "attack" and inferior != "health" and inferior != "agility"){ //make sure player choses available stat
                    cout << "Choose Your God's inferior stat (attack, health, or agility)" << endl;
                    getline(cin, inferior);
                    while(inferior==dominant){
                        cout << "Your dominant and inferior stats cannot be the same. Please choose a different inferior stat (attack, health, or agility)" << endl;
                        getline(cin, dominant);
                    }
                }
                cout << "Finally, write your God's winning speech" << endl;
                getline(cin, speech);
                newTournament.makeGod(name, attribute, dominant, inferior, speech);     
                found = newTournament.findGod(name);
                found = false;
                newTournament.runTournament();
            }else if(userInput2 == "1"){ //choose god
                newTournament.printGods();
                while(found == false){
                    cout << "\nChoose your Champion" << endl;
                    getline(cin, name);
                    found = newTournament.findGod(name);
                }
                found = false; //reset found
                cout << "You have chosen: " << name << endl;
                newTournament.runTournament();

            }else if(userInput2 == "3"){
                newTournament.player = NULL;
                newTournament.runTournament();
            }else if(userInput2 == "4"){
                goto openingMenu;
            }
        }else if(userInput == "2"){
            cout << "Which God are you looking for?" << endl;
            getline(cin, name);
            if(newTournament.findGod(name)){
                newTournament.findGodHistory(name, newTournament.getRoot());
            }else{
                cout << "Please enter a valid Deity." << endl;
            }
        }else if(userInput == "3"){
            tier = "";
            while(tier != "1" and tier != "2" and tier != "3" and tier != "4"){
                cout << "Which Tier Would you Like to See? 1-4" << endl;
                getline(cin, tier);
                if(tier != "1" and !newTournament.getRoot()){
                    cout << "You Must First Start a Tournament to See Past Tier 1!" << endl;
                    tier = "";
                }else if(!newTournament.getRoot()){
                    newTournament.printGods();
                }else{
                    cout << "Gods in this Tier:" << endl;
                    newTournament.printGods(atoi(tier.c_str()), newTournament.getRoot());
                }
            }
        }else if(userInput == "4"){
            cout << "Thanks for playing!" << endl;
            return 0;
        }
     }
    
}
