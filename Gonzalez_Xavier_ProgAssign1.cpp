// Xavier Gonzalez
// Applied Programming Assignment 1 - The Game of Pig
// 1/23/2020

/*  Pig is a folk jeopary dice game with simple rules.
    Two players race to reach 100 points. Each turn,
    a player repeatedly rolls a die until either a 1 ("pig")
    is rolled or the player holds and scores the sum of the rolls
    (i.e. the turn total). At any time during a player's turn,
    the player is faced with two decisions:

    roll - if the player rolls a:
            1: the player scores nothing and it becomes the opponent's turn
            2 - 6:  the number is added to the player's turn total
                    and the player's turn continues
    hold - The turn total is added to the player's score and it becomes
    the opponent's turn

    Welcome to The Game of Pig!
*/

#include <iostream>
#include <string>
#include <ctime>

int dieRoll(); // simulates a die roll
int p_Chooser(); // chooses what player is the user
int user_Turn(int &u_score);
int comp_Turn(int &c_score);

int main() {

    srand(time(0));

    int user_Score = 0;
    int comp_Score = 0;

    int u_Player = p_Chooser();

    std::cout << "You will be player " << u_Player << std::endl;
    std::cout << "Enter R to roll; enter any other character to hold." << std::endl;

    if (u_Player == 1) { 
        // user goes first

        std::cout << "Player 1 score: " << user_Score << std::endl; // user
        std::cout << "Player 2 score: " << comp_Score << std::endl; // comp

        do {
        std::cout << "It is player 1's turn." << std::endl;
        user_Turn(user_Score);
        std::cout << "It is player 2's turn." << std::endl;
        comp_Turn(comp_Score);

        std::cout << "Player 1 score: " << user_Score << std::endl; //user
        std::cout << "Player 2 score: " << comp_Score << std::endl; //comp

        } while (user_Score < 100 && comp_Score < 100);

    } else {

        std::cout << "Player 1 score: " << comp_Score << std::endl; // comp
        std::cout << "Player 2 score: " << user_Score << std::endl; // user

        // computer goes first
        do {
        std::cout << "It is player 1's turn." << std::endl;
        comp_Turn(comp_Score);
        std::cout << "It is player 2's turn." << std::endl;
        user_Turn(user_Score);

        std::cout << "Player 1 score: " << comp_Score << std::endl; // comp
        std::cout << "Player 2 score: " << user_Score << std::endl; // user

        } while (user_Score < 100 && comp_Score < 100);
    }

     if (user_Score >= 100) {
        std::cout << "You have won! Congratulations!" << std::endl;
    } else {
        std::cout << "You lost. Better luck next time!" << std::endl;
    }

    return 0;
}

int dieRoll() {
    int roll = rand() % 6 + 1;
    return roll;
}

int p_Chooser() {
    int player = rand() % 2 + 1;
    return player;
}

int user_Turn(int &u_score) {
    int turn_Total = 0;
    int roll = 0;
    std::string decision;

    do {
        roll = dieRoll();
        std::cout << "Roll: " << roll << std::endl;
        if (roll == 1) {
            turn_Total = 0;
            break;
        } else {
            turn_Total += roll;
            std::cout << "Turn total: " << turn_Total << "  Roll/Hold? (R)" << std::endl;
            std::cin >> decision;
            if (decision != "R") {
                u_score += turn_Total;
                std::cout << "Turn total: " << turn_Total << std::endl;
                break;
            }
        }
    } while (turn_Total < 20);

    std::cout << "Turn total: " << turn_Total << std::endl;
    std::cout << "New Score: " << u_score << std::endl;

    return 0;
}

int comp_Turn(int &c_score) {
    int turn_Total = 0;
    int roll = 0;

    do {
        roll = dieRoll();
        if (roll == 1) {
            turn_Total = 0;
            std::cout << "Roll: " << roll << std::endl;
            break;
        } else {
            turn_Total += roll;
            std::cout << "Roll: " << roll << std::endl;
        }

    } while (turn_Total < 20);

    c_score += turn_Total;

    std::cout << "Turn total: " << turn_Total << std::endl;
    std::cout << "New Score: " << c_score << std::endl;

    return 0;
}
