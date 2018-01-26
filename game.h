#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <limits>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>

using namespace std;

class game
{
    public:
        void show_board();
        //int choice();
        void player_move();
        bool check_winner();
        char turn;
        bool draw = false;
        char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

};

class player : public game
{
    public:
        void player_move();
        char turn;
};


class player1 : public player
{

};
class player2 : public player
{

};
//end

#endif // GAME_H
