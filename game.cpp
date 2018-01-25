#include "game.h"

void game::show_board() {
  cout << endl << "     |     |    " << endl;
  cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  "
       << board[0][2] << endl;
  cout << "_____|_____|____" << endl;
  cout << "     |     |    " << endl;
  cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  "
       << board[1][2] << endl;
  cout << "_____|_____|____" << endl;
  cout << "     |     |    " << endl;
  cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  "
       << board[2][2] << std::endl;
  cout << "     |     |    " << endl << endl;
}

int choice() {
  int i = 0;
  do {
    char buffer[256];
    fgets(buffer, 256, stdin);
    i = atoi(buffer);

    if (i < 1 || i > 9) {
      cout << "Wprowadziles nieodpowiednia wartosc! Sprobuj jeszcze raz\n";
    }
  } while (i < 1 || i > 9);
  return i;
}

void player::player_move() {
  int row = 0, column = 0;

  if (turn == 'X') {
    cout << "ruch Gracza 1 [X]: ";
  } else if (turn == 'O') {
    cout << "ruch Gracza 2 [O]: ";
  }

  switch (choice()) {
    case 1:
      row = 0;
      column = 0;
      break;
    case 2:
      row = 0;
      column = 1;
      break;
    case 3:
      row = 0;
      column = 2;
      break;
    case 4:
      row = 1;
      column = 0;
      break;
    case 5:
      row = 1;
      column = 1;
      break;
    case 6:
      row = 1;
      column = 2;
      break;
    case 7:
      row = 2;
      column = 0;
      break;
    case 8:
      row = 2;
      column = 1;
      break;
    case 9:
      row = 2;
      column = 2;
      break;
  }

  if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
    board[row][column] = 'X';
    turn = 'O';
  } else if (turn == 'O' && board[row][column] != 'X' &&
             board[row][column] != 'O') {
    board[row][column] = 'O';
    turn = 'X';
  } else {
    cout << "Pole, ktore wybrales jest juz zajete! Sprobuj jeszcze raz\n";
    player_move();
  }
}

bool game::check_winner() {
  for (int i = 0; i < 3; i++) {
    if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
        (board[0][i] == board[1][i] && board[1][i] == board[2][i]) ||
        ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
         (board[0][2] == board[1][1] && board[1][1] == board[2][0]))) {
      return true;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != 'X' && board[i][j] != 'O') {
        return false;
      }
    }
  }
  draw = true;
  return true;
}
