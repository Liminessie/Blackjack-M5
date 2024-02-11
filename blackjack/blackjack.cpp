// blackjack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <cstdlib>
#include <cctype>


using namespace std;
// get a suit from random values (1-4) 
int randomSuit() {
    int randSuitVal = (rand() % 4) + 1;
    return(randSuitVal);
}
// Get a random value for the cards (0-12) 
int randomRank(){
    int randomNumber = (rand() % 12);
    return(randomNumber);
}
// change 1 to 0 machine ;) i am a genious! -- deprecated hehe
void oneToZero(int randNumCard, int arraySuit[]) {
        arraySuit[randNumCard] = 0;
    }
// put a zero in the arrays of the card!! -- deprecated
void markingCards(int clubs[], int diamonds[], int hearts[], int spades[], int suit, int rank) {
        //Drawed cards
        switch (suit) {
        case 1:
            oneToZero(rank, clubs);
            break;
        case 2:
            oneToZero(rank, diamonds);
            break;
        case 3:
            oneToZero(rank, hearts);
            break;
        case 4:
            oneToZero(rank, spades);
            break;
        default:
            cout << "Error: Suit no válido." << endl;
        }
}
//AceCard Value machine :v!
int aceCard(int player, int &score) {
    int aceValue = 0;
    if (player == 0) {
        while (true) {
            cout << "Hey man > v >!!! What value do you give to the Ace? 1 or 11? ";
            cin >> aceValue;
            if (aceValue == 1 or aceValue == 11) {
                return(aceValue);
            }
            else {
                cout << "Hey you sucker!! Enter a valid value! >:c 1 or 11, ONE OR ELEVEN!!! D:<\n";
            }
        }
    }
    else if (player == 1) {
        if (score <= 10) {
            return (11);
        } else if (score >= 11)
            return(1);
    }
    
 }

// Getting suits ; )     
string puttingSuit(int randSuit) {
    if (randSuit == 1) return "Clubs";

    else if (randSuit == 2) return "Diamonds";

    else if (randSuit == 3) return "Hearts";

    else if (randSuit == 4) return "Diamonds";

    else
    {
        cout << "There is an error >:l, close the f&%!ing program and try again!";
    }
}
// Assigning value to the cards using the array from 0 to 12
int assignRank (int randRank) {
    if (randRank == 0) {  //Ace
        return(0);
    }
    else if (randRank >= 1 && randRank < 9) //2-9
    {   
        return(randRank + 1);
    }
    else if (randRank >= 9) { //10-K
        return(10);
    }
}
// Convert numbers in the figure, ace, jack, queen and king 
string intToFig(int rank) {
    if (rank == 0)
    {
        return("Ace");
    }
    if (rank > 0 && rank < 10)
    {
        return to_string(rank + 1);
    }
    else if (rank == 10) {

        return("Jack");
    }
    else if (rank == 11) {

        return("Queen");
    }
    else if (rank == 12) {

        return("King");
    }
}
// was this necessary?? 
void ace1or11(int rank, int& playerScore, int player) {
    if (rank == 0)
    {
        playerScore += aceCard(player, playerScore);
    }
}
// This program print shows the card in the console! duh!
void printCard(string fig, string suit ) {
    cout << fig << " of " << suit << "\n";
}

//Older version of checkCards
//int checkCards(int clubs[], int diamonds[], int hearts[], int spades[], int& suit, int& rank) {
//    while (true) {
//        suit = randomSuit();
//        rank = randomRank();
//        markingCards(clubs, diamonds, hearts, spades, suit, rank);
//        switch (suit) {
//        case 1:
//            if (clubs[rank] == 1) return(0);
//            break;
//        case 2:
//            if (diamonds[rank] == 1) return(0);
//            break;
//        case 3:
//            if (hearts[rank] == 1) return(0);
//            break;
//        case 4:
//            if (spades[rank] == 1) return(0);
//            break;
//        default:
//            cout << "Error: Invalid suit, i dont know how this could be possible :l" << endl;
//        }
//    }
//
//}

int checkCards(int clubs[], int diamonds[], int hearts[], int spades[], int& suit, int& rank) {
    while (true) {
        suit = randomSuit();
        rank = randomRank();
        /*markingCards(clubs, diamonds, hearts, spades, suit, rank);*/
        switch (suit) {
        case 1:
            if (clubs[rank] == 1) 
            clubs[rank] = 0;
            return(0);
                break;
        case 2:
            if (diamonds[rank] == 1) 
                diamonds[rank] = 0;
                return(0);
            break;
        case 3:
            if (hearts[rank] == 1)
                hearts[rank] = 0;
                return(0);
            break;
        case 4:
            if (spades[rank] == 1)
                spades[rank] == 0;
                return(0);
            break;
        default:
            cout << "Error: Invalid suit, i dont know how this could be possible :l" << endl;
        }
    }
    
}
// Yes or No machina. Convert letters into lower and return 1 for yes and 0 for no. A boolean non boolean ;)  
int yesOrNo(int &playerScore) {
    while (true)
    {
        cout << "Do you want another card? you little bastard?? >:), yes or no?: ";
        string yesOrNo;
        cin >> yesOrNo; 
        if (playerScore >= 16 && playerScore <= 21) {
            cout << "think it better >v> hehe, yes or no? ";
            cin >> yesOrNo;
        }

        for (char& c : yesOrNo) {
            c = tolower(c);
        }

        if (yesOrNo == "yes") {
            return (1);
        }
        else if (yesOrNo == "no") {
            return (0);
        } 
        else cout << "Hey! Yes or no! Is not so hard!!\nOk, Try again...\n";
    }
}

int drawAnother(int& score, int player, int clubs[], int diamonds[], int hearts[], int spades[], bool& endgame) {
    if (player == 0)
    {
        while (true)
        {
            int answer = yesOrNo(score);

            if (answer == 0) {
                cout << "Your current score is: " << score << "\n";
                return(0);
            }
            else if (answer == 1) {
                int playerSuit;
                int playerRank;
                checkCards(clubs, diamonds, hearts, spades, playerSuit, playerRank);
                string fig = intToFig(playerRank);
                string suit = puttingSuit(playerSuit);
                int rank = assignRank(playerRank);
                score += rank;
                printCard(fig, suit);

                ace1or11(playerRank, score, player);
                cout << "Your current score is: " << score << "\n";

               /* WinOrLoseCheck(score, cpuScore, turn, endGame);*/

                if (score > 21) {
                    cout << "WTF! You dumbass!! :V HAHA!!";
                    endgame = true; 
                    return(0);
                }
                
            }
        }
    }
    else if (player == 1 && endgame == false) {
        cout << "Uhmmm... Allright badass... Its my turn... again... >_>\n";
        while (true)
        {
            int playerSuit;
            int playerRank;
            checkCards(clubs, diamonds, hearts, spades, playerSuit, playerRank);
            string fig = intToFig(playerRank);
            string suit = puttingSuit(playerSuit);
            int rank = assignRank(playerRank);
            score += rank;
            printCard(fig, suit);

            ace1or11(playerRank, score, player);
            
            if (score > 21)
            {
                cout << score << " Oh f&$k... -_-\n";
                endgame = true; 
                return(0);
            }
            else if (score > 21)
            {
                cout << "Ok... i have a score of " << score << "\n";
                return(0);
            }
            else if (score == 21) {
                cout << "Wow" << score <<  "... today it's my lucky day!! HAHA! >:D\n";
                return(0);
            }
            else if (score < 16) cout << "Ok ok, im gonna draw another card... :l\n";

            else if (score >= 16) {
                cout <<"Ok ... " << score <<  " Its not bad... Greed is a capital sin >v> haha..\n" ;
                return(0);
            }
        }
    }
    
} 

void WinOrLoseCheck(int& playerScore, int& cpuScore, int phase, bool& endGame) {
    if (playerScore == 21 && cpuScore == 21) {
        cout << "Remember you idiot! in blackjack the dealer always win!! You loose XD HAHA :v!!";
        endGame = true;
    }
    else if (phase == 1 && playerScore < cpuScore) {
        cout << "Lol! Don't you see the score you idiot!!? XD\n";
        endGame = true;
    }
    else if (phase == 3 && playerScore == cpuScore) {
        cout << "WTH!? D:< Draw Game!!";
        endGame = true;
    }
    else if (phase == 3 && playerScore == 21 && cpuScore < 21) {
        cout << "Blackjack!? D:!! You have won, you f$&king cheater!!\n";
        endGame = true;
    }
    else if (phase == 3 && cpuScore == 21 && playerScore < 21) {
        cout << "You loose dumbass XD!!\n";
        endGame = true;
    }
    else if (playerScore > 21) {
        cout << "You loose sucker!!";
        endGame = true;
    }
    else if (phase == 3 && cpuScore > 21) {
        cout << "You win... >_>\n";
        endGame = true;
    }
    else if (phase == 3 && cpuScore > playerScore) {
        cout << "You were a little bit short of points...:C\nIDIOT! XD!\n";
        endGame = true;
    }
    else if (phase == 3 && cpuScore < playerScore) {
        cout << "Oh f%&k... you beat me by only " << playerScore - cpuScore << " f%&cking points!! DX!!\n";
        endGame = true;
    }
    else if (phase == 3 && playerScore == 21 && cpuScore < 21) {
        cout << "Oh wow ... blackjack -_- you win!...";
        endGame = true;
    }
        
}

// MAIN //
    int main() {   
    srand(time(NULL));

    int clubs[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };
    int diamonds[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };
    int hearts[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };
    int spades[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };
    
    int player = 0;
    int cpuPlay = 1;
    int playerScore = 0;
    int cpuScore = 0;
    int phase = 0;

    bool endGame = false;   

     
    phase = 0;
        // Player turn 
        cout << "Ok, you got these cards you lucky guy or girl or aah... galah cockatoo i dont know... \n";
        phase = 1;
        for (size_t i = 0; i < 2; i++)
        {
            int playerSuit;
            int playerRank;
            /*int playerSuit = randomSuit();
            int playerRank = randomRank();
            markingCards(clubs, diamonds, hearts, spades, playerSuit, playerRank);*/
            checkCards(clubs, diamonds, hearts, spades, playerSuit, playerRank);
            string fig = intToFig(playerRank);
            string suit = puttingSuit(playerSuit);
            int rank = assignRank(playerRank);
            playerScore += rank;
            printCard(fig, suit);
     
            ace1or11(playerRank, playerScore, player);
        }
        cout << "Your current score is: " << playerScore << "\n";
    
        // CPU drawing a Card
        cout << "Ok and now, A card for me ;) hehe \n";
        
        int cpuSuit;
        int cpuRank;
        checkCards(clubs, diamonds, hearts, spades, cpuSuit, cpuRank);
        string cpuFig = intToFig(cpuRank);
        string suit = puttingSuit(cpuSuit);
        int rank = assignRank(cpuRank);
        cpuScore += rank;
        ace1or11(cpuRank, cpuScore, cpuPlay);
        printCard(cpuFig, suit);

        cout << "Uhmmm ... My score is " << cpuScore << "\n";
        // second turn
       
        /*Player turn*/
        phase = 1; //
        drawAnother(playerScore, player, clubs, diamonds, hearts, spades,endGame);
        WinOrLoseCheck(playerScore, cpuScore, phase, endGame);
        
        /*phase = 2;*/
        /*WinOrLoseCheck(playerScore, cpuScore, phase, endGame);*/
        
        phase = 3;
        // Cpu second chance
        drawAnother(cpuScore, cpuPlay, clubs, diamonds, hearts, spades, endGame);
        if (playerScore < 22)
        {
            WinOrLoseCheck(playerScore, cpuScore, phase, endGame);
        }
     
        
     
        
         //Testing arrays!!  
        /*cout << "Clubs ";
        for (size_t i = 0; i < 13; i++)
        {
           cout << clubs[i];
        }
        cout << " \n";
        cout << "Diamonds ";
        for (size_t i = 0; i < 13; i++)
        {
            cout << diamonds[i];
        }
        cout << " \n";
        cout << "Hearts ";
        for (size_t i = 0; i < 13; i++)
        {
            cout << hearts[i];
        }
        cout << " \n";
        cout << "Spades";

        for (size_t i = 0; i < 13; i++)
        {
            cout << spades[i];
        }
        cout << " \n";
         */
         
         

    } // end of main!!!

