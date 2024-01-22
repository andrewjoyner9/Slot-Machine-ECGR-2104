#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

string slotRoll;
int playerTokens = 10;


int spinSlotMachine(){ // this function simulates the spinning of the slot machine.
    
    srand(time(0));
    int index;
    char symbols[4] = {'7', '#', '$', 'X'};
    string slotRoll = "";
    
    for(int i = 0; i<3; i++)
    {
        index = rand() % 4;
        slotRoll += symbols[index];
    }
    
    cout << slotRoll << endl;
    
    if(slotRoll == "777"){ // This part of the function checks if the player won. Originally it was a seperate function but I couldn't figure out how to edit the global varibles with functions.
        playerTokens += 100;
        cout << "You win 100 tokens! your new balance is " << playerTokens << " Tokens." << endl;
    }else if(slotRoll == "$$$"){
        playerTokens += 50;
        cout << "You win 50 tokens! your new balance is " << playerTokens << " Tokens." << endl;
    }else if(slotRoll == "###"){
        playerTokens+= 25;
        cout << "You win 25 tokens! your new balance is " << playerTokens << " Tokens." << endl;
    }else if(slotRoll == "XXX"){
        playerTokens += 10;
        cout << "You win 10 tokens! your new balance is " << playerTokens << " Tokens." << endl;
    }else{
        cout << "You lose! One token has been subtracted from your balance." << endl;
    }
    return 0;
}



int main(){
    
    char playerChoice;
    
    cout << "Would you like to spin the slot machine? Current balance is " << playerTokens << " tokens. The slot machine costs 1 token to spin. (Y/N): " << endl;
    cin >> playerChoice;
    cin.clear();
    cin.ignore(256, '\n'); // cin.clear() and cin.ignore() make sure that only the first letter of the user's input is read by the program.
    playerChoice = toupper(playerChoice);
    
    while(playerChoice != 'Y' && playerChoice != 'N'){
            cout << "The last input was not acceptable. Please try again." << endl;
            cin >> playerChoice;
            cin.clear();
            cin.ignore(256, '\n');
            playerChoice = toupper(playerChoice);
        }

    if (playerChoice == 'Y'){
    } else if (playerChoice == 'N'){ 
        cout << "You have chosen not to play. Goodbye." << endl;
        return 0;
    }
    
    while(playerTokens != 0 && playerChoice == 'Y'){
        
        playerTokens -= 1;
        spinSlotMachine();
        
        if(playerTokens == 0){
            break;
        }
        
        cout << "_____________________________________________" << endl;
        cout << "Your balance is " << playerTokens << " tokens. Spin again? (Y/N): " << endl;
        cin >> playerChoice;
        cin.clear();
        cin.ignore(256, '\n');
        playerChoice = toupper(playerChoice);
        
        while(playerChoice != 'Y' && playerChoice != 'N'){
            cout << "The last input was not acceptable. Please try again." << endl;
            cin >> playerChoice;
            cin.clear();
            cin.ignore(256, '\n');
            playerChoice = toupper(playerChoice);
        }
    }
    if (playerTokens == 0){
        cout << "You have no tokens to gamble with. Goodbye." << endl;
        return 0;
    }else if(playerChoice == 'N'){
        cout << "You have chosen to leave the slot machine. Your final balance was " << playerTokens << " tokens." << endl;
        return 0;
    
    return 0;
    }
}