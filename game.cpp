#include "game.h"

void game::show_board() {
  std::cout << std::endl << "     |     |    " << std::endl;
  std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  "
       << board[0][2] << std::endl;
  std::cout << "_____|_____|____" << std::endl;
  std::cout << "     |     |    " << std::endl;
  std::cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  "
       << board[1][2] << std::endl;
  std::cout << "_____|_____|____" << std::endl;
  std::cout << "     |     |    " << std::endl;
  std::cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  "
       << board[2][2] << std::endl;
  std::cout << "     |     |    " << std::endl << std::endl;
}

void player::player_move() {
  int choice;
  int row = 0, column = 0;

  if (turn == 'X') {                            //w tym miejscu przestaje poprawnie dzialac kod, nie rysuje planszy
    std::cout << "ruch Gracza 1 [X]: ";
  } else if (turn == 'O') {
    std::cout << "ruch Gracza 2 [O]: ";
  }
  std::cin >> choice;

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
      std::cout << "Wprowadziles nieodpowiednia wartosc! Sprobuj jeszcze raz\n";
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
    std::cout << "Pole, ktore wybrales jest juz zajete! Sprobuj jeszcze raz\n";
    player_move();
  }
}


// sprawdzanie wygranej
bool game::check_winner() {
  for (int i = 0; i < 3; i++)
  {
    if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
        (board[0][i] == board[1][i] && board[1][i] == board[2][i]) ||
        ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
         (board[0][2] == board[1][1] && board[1][1] == board[2][0]))) {
      return true;
    }
  }

// sprawdzanie remisu
  for (int i = 0; i < 3; i++)
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
