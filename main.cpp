#include <iostream>
#include <deque>
#include<bits/stdc++.h>
using namespace std;
// this is the game_board numbers
vector<string> game_board = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};

// this the players function where we will change each choice with x
bool players(int choice_1, int choice_2) {
// those two lines are defensive
    if (choice_1 > choice_2) swap(choice_1,choice_2);
    if (choice_2 > 16 ) return false;

//    the next lines checks if the choices are valid and next to each other
    if ( abs(choice_1 - choice_2) == 1 && game_board[choice_1 - 1] != "x" && game_board[choice_2 - 1] != "x") {
// if the next line is true this means that the numbers are not next to each other
        if (choice_1 % 4==0 && choice_2-choice_1==1 ) return false;
// here we change our game_board with Xs
        game_board[choice_1 - 1] = "x";
        game_board[choice_2 - 1] = "x";
        return true;
    }
// this condition means that the chosen one of them is under the other one
    if (abs(choice_1 - choice_2) == 4 && game_board[choice_1 - 1] != "x" && game_board[choice_2 - 1] != "x") {
        game_board[choice_1 - 1] = "x";
        game_board[choice_2 - 1] = "x";
        return true;
    }
    return false;
}
// this function here checks for winners
bool check_for_winner() {

    for (int i = 0; i < game_board.size() - 1; ++i) {
//        the next line checks if there is two numbers under each other are still valid
        if ((i + 1) % 4 == 0 ) { if ((game_board[i] != "x" && game_board[i + 4] != "x")) return false; }

//        the next condition is specialized for the last raw and checks if any two numbers after each other are valid
        else if (i > 11 && game_board[i] != "x" ) { if (game_board[i + 1] != "x") return false; }

//        this condition here checks for normal validation of any two squares
        else if ((game_board[i] != "x" && game_board[i + 1] != "x") || (game_board[i] != "x" && game_board[i + 4] != "x")) {
            return false;
        }

    }
    return true;
}

// this function is pretty obvious that it updates the game`s game_board
auto update() {
    cout << "|    " << game_board[0] << "     |    " << game_board[1] << "     |    " << game_board[2] << "     |    " << game_board[3]
         << "     |\n"
            "|----------|----------|----------|----------|\n"
            "|    " << game_board[4] << "     |    " << game_board[5] << "     |    " << game_board[6] << "     |    " << game_board[7]
         << "     |\n"
            "|----------|----------|----------|----------|\n"
            "|    " << game_board[8] << "     |    " << game_board[9] << "    |    " << game_board[10] << "    |    " << game_board[11]
         << "    |\n"
            "|----------|----------|----------|----------|\n"
            "|    " << game_board[12] << "    |    " << game_board[13] << "    |    " << game_board[14] << "    |    " << game_board[15]
         << "    |\n";
}


int main() {
    cout << endl;

    cout << "                        welcome to this is Two squares game.                    " << endl;

    cout << endl;

    cout << "This game is played on a game_board of 4 x 4 squares. Two players take turns;\n"
            "each of them takes turn to place a rectangle (that covers two squares) on the game_board, covering\n"
            "any 2 squares. Only one rectangle can be on a square. A square cannot be covered twice. The\n"
            "last player who can place a card on the game_board is the check_for_winner." << endl;

    cout << endl;

    update();

//    this the game loop where we will take the players choices
    while (true) {

        int player_1_choice_1, player_1_choice_2, player_2_choice_1, player_2_choice_2;
        cout << endl;
        cout << " enter two numbers separated with a space :  ";
        cin >> player_1_choice_1 >> player_1_choice_2;

//        this line here checks if the choices are valid and then updates every thing
        if (players(player_1_choice_1, player_1_choice_2)) update();

//        here we made a defensive for the wrong or invalid choices
        else if (!players(player_1_choice_1, player_1_choice_2)) {
            while (!players(player_1_choice_1, player_1_choice_2)) {
                cout << "enter correct numbers :  ";
                cin >> player_1_choice_1 >> player_1_choice_2;
            }
            players(player_1_choice_1, player_1_choice_2), update();
        }

//        the order of the code here checks whether player 1 has won or not
        if (check_for_winner()) {
            cout << "  CONGRATS PLAYER 1, you have won the game ! " << endl;
            return 0;
        }

//        this is player two inputs

        cout << " enter two numbers separated with a space :  ";
        cin >> player_2_choice_1 >> player_2_choice_2;

        if (players(player_2_choice_1, player_2_choice_2)) update();

        else if (!players(player_2_choice_1, player_2_choice_2)) {
            while (!players(player_2_choice_1, player_2_choice_2)) {
                cout << "enter correct numbers :  ";
                cin >> player_2_choice_1 >> player_2_choice_2;
            }
            players(player_2_choice_1, player_2_choice_2), update();
        }

        if (check_for_winner()) {
            cout << "  CONGRATS PLAYER 2, you have won the game ! " << endl;
            return 0;
        }

    }

}
