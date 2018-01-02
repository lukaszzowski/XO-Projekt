// Gra Kolko i Krzyzyk dla 2 graczy
#include <iostream>
#include "game.h"

using namespace std;

int main() {
    game mygame;                                //wskazanie objektu klasy
    player myplayer;                            //wskazanie objektu klasy
  cout << "#Zagrajmy w Kolko i Krzyzyk\n";
  cout << "#Gracz 1  X\n";
  cout << "#Gracz 2  O\n";
    myplayer.turn = 'X';


  while (!mygame.check_winner()) {
    mygame.show_board();
    myplayer.player_move();
    mygame.check_winner();
  }

  if (myplayer.turn == 'O' && !mygame.draw) {
    mygame.show_board();
    cout << endl << endl << "Gracz 1 [X] wygrywa! Koniec gry!\n";
  } else if (myplayer.turn == 'X' && !mygame.draw) {
    mygame.show_board();
    cout << endl << endl << "Gracz 2 [O] wygrywa! Koniec gry!\n";
  } else {
    mygame.show_board();
    cout << endl << endl << "Remis! Koniec gry!\n";
  }

}
