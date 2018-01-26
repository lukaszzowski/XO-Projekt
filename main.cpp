#include "game.h"

int main() {
    game mygame;
    player myplayer;
  cout << "#Zagrajmy w Kolko i Krzyzyk\n";
  cout << "#Gracz 1  X\n";
  cout << "#Gracz 2  O\n";
    myplayer.turn = 'X';


  while (!myplayer.check_winner()) {
    myplayer.show_board();
    myplayer.player_move();
    mygame.check_winner();
  }

  if (myplayer.turn == 'O' && !myplayer.draw) {
    mygame.show_board();
    cout << endl << endl << "Gracz 1 [X] wygrywa! Koniec gry!\n";
  } else if (myplayer.turn == 'X' && !myplayer.draw) {
    mygame.show_board();
    cout << endl << endl << "Gracz 2 [O] wygrywa! Koniec gry!\n";
  } else {
    mygame.show_board();
    cout << endl << endl << "Remis! Koniec gry!\n";
  }

  return 0;
}
