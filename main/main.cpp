
#include <iostream>
#include <string.h>
#include "Point2D.h"
#include "Vector2D.h"
#include <math.h>
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "View.h"
#include "Model.h"
#include "GameCommand.h"
#include <string>
using namespace std;

string* separateCommands(string, int&);
bool hasquit = true;


int main() {
    Point2D loc_n;

    //Game
    Model *model = new Model;
    //Model model;
    View *view = new View;
   // View view;
    model->ShowStatus();
    //model->ShowStatus();
    model->Display(*view);
    //do a check to see if the pokemon have fainted or if the battles have all been completed
    if (model->GameOver()) {
        DoQuit(model);
        return 0;
    }
    do
    {
        //do the check each time
        if (model->GameOver()) {
            DoQuit(model);
            return 0;
       }
        //read in the user command
        string input;
        cout << endl << "Enter command: ";
        getline(cin, input);

        int numCommands = 0;
        string* commands = separateCommands(input, numCommands);
        if (commands == 0)
        {
            continue;
        }
       
        //switch statement for each command
        switch (commands[0][0])
        {
        case 'm':
           //MOVE COMMAND - trainer x y
            if (numCommands != 3)
            {
                cout << "Error: Please enter valid command!" << endl;
                break;
            }
           
            DoMoveCommand(*model,stoi(commands[1]), Point2D(stod(commands[2]), stod(commands[3])));
            break;

        case 'c':
            //MOVE TO CENTER - trainer center
            if (numCommands != 2)
            {
                cout << "Error: Please enter valid command!" << endl;
                break;
            }
            DoMoveToCenterCommand(*model, stoi(commands[1]), stoi(commands[2]));
            break;
        case 'n':
            loc_n.x = stoi(commands[3]);
            loc_n.y = stoi(commands[4]);
            model->NewCommand(commands[1][0], stoi(commands[2]),loc_n);
            break;
        case 'g':
            //MOVE TO GYM - trainer gym
            if (numCommands != 2)
            {
                cout << "Error: Please enter valid command!" << endl;
                break;
            }
            DoMoveToGymCommand(*model, stoi(commands[1]), stoi(commands[2]));
            break;

        case 's':
            //STOP - stop the current state
            if (numCommands != 1)
            {
                cout << "Error: Please enter valid command!" << endl;
                break;
            }
            DoStopCommand(*model, stoi(commands[1]));
            break;

        case 'p':
            //HEAL - trainer numberofpotions
            if (numCommands != 2)
            {
                cout << "Error: Please enter valid command!" << endl;
                break;
            }
            DoRecoverInCenterCommand(*model, stoi(commands[1]), stoi(commands[2]));
            break;

        case 'b':
            //BATTLE - trainer numofbattles
            if (numCommands != 2)
            {
                cout << "Error: Please enter valid command!" << endl;
                break;
            }
            DoBattleCommand(*model, stoi(commands[1]), stoi(commands[2]));
            break;

        case 'a':
            //ADVANCE - nothing
            DoAdvanceCommand(*model, *view);
            model->Update();
            break;

        case 'r':
            //RUN - nothing
            cout << "Advancing to the next event" << endl;
            for (int i = 0; i < 5; i++)
            {
                if (model->Update())
                {
                    break;
                }
            }
            break;

        case 'q':
            //QUIT
            DoQuit(model);
            return 0;
            break;

        default:
            break;
        }

        if (hasquit)
        {
            //display the status each new command
            model->ShowStatus();
            model->Display(*view);
        }

    } while (hasquit);

    return 0;
}

//function to take in the user commands
string* separateCommands(string input, int& count)
{
    string* output = new string[5]; //Four is the max that you should pass

    string word = "";
    for (auto x : input)
    {
        if (count == 6)
        {
            cout << "Error: Please enter valid command!" << endl;
            return 0;
        }

        if (x == ' ')
        {
            output[count] = word;
            word = "";
            count++;
        }
        else
        {
            word = word + x;
        }
    }
    output[count] = word;
    
    return output;
}