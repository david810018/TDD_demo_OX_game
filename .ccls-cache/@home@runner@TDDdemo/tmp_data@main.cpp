#include "include/gtest/gtest.h"
#include "app.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

// TEST(fun, add_a) {
//   EXPECT_EQ(-3, add(-2, -1));
//   EXPECT_EQ(-2, add(1, -3));
// }

TENNIS_GAME_S *game;

void test_init() {
  tennis_create_game(&game);
  tennis_p1_set_name(game, "Max");
  tennis_p2_set_name(game, "Xam");
}

TEST(score, Love_All) {
  test_init();
  EXPECT_STREQ("Love-All", game->score);
  free(game);
}

TEST(score, Love_Fifteen) {
  test_init();
  tennis_p2_add_point(game);
  EXPECT_STREQ("Love-Fifteen", game->score);
  free(game);
}

TEST(score, Love_Thirty) {
  test_init();
  tennis_p2_add_point(game);
  tennis_p2_add_point(game);
  EXPECT_STREQ("Love-Thirty", game->score);
  free(game);
}

TEST(score, Love_Forty) {
  test_init();
  tennis_p2_set_point(game, 3);
  free(game);
}

TEST(score, Forty_Love) {
  test_init();
  tennis_p1_set_point(game, 3);
  EXPECT_STREQ("Forty-Love", game->score);
  free(game);
}

TEST(score, Fifteen_All) {
  test_init();
  tennis_p1_add_point(game);
  tennis_p2_add_point(game);
  EXPECT_STREQ("Fifteen-All", game->score);
  free(game);
}

TEST(score, Deuce) {
  test_init();
  tennis_p1_set_point(game, 3);
  tennis_p2_set_point(game, 3);
  EXPECT_STREQ("Deuce", game->score);
  free(game);
}

TEST(score, Adv_Max) {
  test_init();
  tennis_p1_set_point(game, 4);
  tennis_p2_set_point(game, 3);
  EXPECT_STREQ("Adv. Max", game->score);
  free(game);
}

TEST(score, Adv_Xam) {
  test_init();
  tennis_p1_set_point(game, 4);
  tennis_p2_set_point(game, 5);
  EXPECT_STREQ("Adv. Xam", game->score);
  free(game);
}

TEST(score, Win_Max) {
  test_init();
  tennis_p1_set_point(game, 4);
  tennis_p2_set_point(game, 2);
  EXPECT_STREQ("Win. Max", game->score);
  free(game);
}

TEST(score, Win_Xam) {
  test_init();
  tennis_p1_set_point(game, 4);
  tennis_p2_set_point(game, 6);
  EXPECT_STREQ("Win. Xam", game->score);
  free(game);
}

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

  return 0;
}
