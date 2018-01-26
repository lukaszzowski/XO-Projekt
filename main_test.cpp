#include <gtest/gtest.h>
#include "game.h"


TEST(check_winner, its_false){
	game mygame;
	char board[3][3] = {{'X', 'O', 'X'}, 
					   {'O', 'X', 'O'}, 
					   {'O', 'X', 'O'}};

	EXPECT_FALSE(mygame.check_winner());
}

TEST(check_winner, its_a_win){
	game mygame;
	char board[3][3] = {{'X', 'X', 'X'}, 
					   {'X', 'O', 'O'}, 
					   {'O', 'X', 'O'}};

	EXPECT_FALSE(mygame.check_winner());
}

int main(int argc, char **argv) {

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}