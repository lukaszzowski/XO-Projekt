#ifndef GAME_H
#define GAME_H
#include <iostream>

int main();

class game                                  //klasa bazowa
{
    public:
        void show_board();
        //void player_move();
        bool check_winner();

        char turn;
        bool draw = false;
        char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};


};

class player : public game                  //klasa pochodna
{
    public:
        void player_move();
        //char turn;
};


class player1 : public player               //potrzebne?
{

};
class player2 : public player
{

};


#endif // GAME_H
