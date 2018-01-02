// Gra Kolko i Krzyzyk dla 2 graczy

#include <iostream>

using namespace std;

void show_board();
void player_move();
bool gameover();

char turn;
bool draw = false;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int main() {
  cout << "#Zagrajmy w Kolko i Krzyzyk\n";
  cout << "#Gracz 1  X\n";
  cout << "#Gracz 2  O\n";
  turn = 'X';

  while (!gameover()) {
    show_board();
    player_move();
    gameover();
  }

  if (turn == 'O' && !draw) {
    show_board();
    cout << endl << endl << "Gracz 1 [X] wygrywa! Koniec gry!\n";
  } else if (turn == 'X' && !draw) {
    show_board();
    cout << endl << endl << "Gracz 1 [X] wygrywa! Koniec gry!\n";
  } else {
    show_board();
    cout << endl << endl << "Remis! Koniec gry!\n";
  }
}

void show_board() {
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
       << board[2][2] << endl;
  cout << "     |     |    " << endl << endl;
}

void player_move() {
  int choice;
  int row = 0, column = 0;

  if (turn == 'X') {
    cout << "ruch Gracza 1 [X]: ";
  } else if (turn == 'O') {
    cout << "ruch Gracza 2 [O]: ";
  }
  cin >> choice;

  switch (choice) {
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
    default:
      cout << "Wprowadziles nieodpowiednia wartosc! Sprobuj jeszcze raz\n";
      player_move();
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

bool gameover() {
  for (int i = 0; i < 3; i++)  // sprawdzanie wygranej
  {
    if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
        (board[0][i] == board[1][i] && board[1][i] == board[2][i]) ||
        ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
         (board[0][2] == board[1][1] && board[1][1] == board[2][0]))) {
      return true;
    }
  }

  for (int i = 0; i < 3; i++)  // sprawdzanie remisu
  {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != 'X' && board[i][j] != 'O') {
        return false;
      }
    }
  }
  draw = true;
  return true;
}
