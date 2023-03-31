#include "app.h"
#include "include/gtest/gtest.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

TEST(score, Love_All) {
  game_t game;
  tennis_create_game(&game);
  EXPECT_STREQ("Love-All", game.score);
}

TEST(score, Fifteen_Love) {
  game_t game;
  tennis_create_game(&game);
  tennis_playerP1_add_scored(&game);
  EXPECT_STREQ("Fifteen-Love", game.score);
}

TEST(score, Thirty_Love) {
  game_t game;
  tennis_create_game(&game);
  tennis_playerP1_add_scored(&game);
  tennis_playerP1_add_scored(&game);
  EXPECT_STREQ("Thirty-Love", game.score);
}

TEST(score, Thirty_All) {
  game_t game;
  tennis_create_game(&game);
  tennis_playerP1_add_scored(&game);
  tennis_playerP1_add_scored(&game);
  tennis_playerP2_add_scored(&game);
  tennis_playerP2_add_scored(&game);
  EXPECT_STREQ("Thirty-All", game.score);
}

// TEST(fun, add_a) {
//   EXPECT_EQ(-3, add(-2, -1));
//   EXPECT_EQ(-2, add(1, -3));
// }

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

  return 0;
}
