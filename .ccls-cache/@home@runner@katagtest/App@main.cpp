#include "include/gtest/gtest.h"

#include "main.h"
#include "test_code.cpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#define GAME_SET
// #define ABS(A) ((A) > 0) ? (A) : ((-1) * (A))

int add(int a, int b) { return a + b; }
int ABS(int a) { return a > 0 ? a : -a; }
// TEST(fun, add_a) {
//   EXPECT_EQ(-3, add(-2, -1));
//   EXPECT_EQ(-2, add(1, -3));
// }

typedef struct score_list {
  int iScore;
  char sScore[16];
} score_list_t;

score_list_t list[] = {
    {0, "Love"},
    {1, "Fifteen"},
    {2, "Thirty"},
    {3, "Forty"},
};

void same_score(TENNIS_GAME_S *game) {
  TENNIS_GAME_S *tmp_game = game;
  sprintf(tmp_game->score, "%s-All", list[tmp_game->scorePlayerOne].sScore);
}

void deuce_score(TENNIS_GAME_S *game) {
  TENNIS_GAME_S *tmp_game = game;
  sprintf(tmp_game->score, "Deuce");
}

void adv_win_score(TENNIS_GAME_S *game) {
  TENNIS_GAME_S *tmp_game = game;
  char advName[STR_NAME_LEN] = {0};
  if (tmp_game->scorePlayerOne > tmp_game->scorePlayerTwo) {
    sprintf(advName, "%s", tmp_game->PlayerOneName);
  } else {
    sprintf(advName, "%s", tmp_game->PlayerTwoName);
  }

  if (ABS(tmp_game->scorePlayerOne - tmp_game->scorePlayerTwo) == 1) {
    sprintf(tmp_game->score, "Adv. %s", advName);
  } else {
    sprintf(tmp_game->score, "Win. %s", advName);
  }
}

void normal_score(TENNIS_GAME_S *game) {
  TENNIS_GAME_S *tmp_game = game;
  sprintf(tmp_game->score, "%s-%s", list[tmp_game->scorePlayerOne].sScore,
          list[tmp_game->scorePlayerTwo].sScore);
}

int is_deuce(TENNIS_GAME_S *game) {
  TENNIS_GAME_S *tmp_game = game;
  return (tmp_game->scorePlayerOne >= 3);
  // return Y/N
}

int is_same_score(TENNIS_GAME_S *game) {
  TENNIS_GAME_S *tmp_game = game;
  return (tmp_game->scorePlayerOne == tmp_game->scorePlayerTwo);
  // return same_score or deuce
}

int is_adv(TENNIS_GAME_S *game) {
  TENNIS_GAME_S *tmp_game = game;
  return (ABS(tmp_game->scorePlayerOne - tmp_game->scorePlayerTwo) == 1);
}

int is_win_point(TENNIS_GAME_S *game) {
  TENNIS_GAME_S *tmp_game = game;
  return ((tmp_game->scorePlayerOne >= 4) || (tmp_game->scorePlayerTwo >= 4));
}

void tennis_update_game_score(TENNIS_GAME_S *game) {
  TENNIS_GAME_S *tmp_game = game;

  if (is_same_score(game)) {
    is_deuce(game) ? deuce_score(game) : same_score(game);
  }
  else if (is_win_point(game)) {
    adv_win_score(game);
  } else {
    normal_score(game);
  }
}

void tennis_p2_add_point(TENNIS_GAME_S *game) {
  TENNIS_GAME_S *tmp_game = game;
  tmp_game->scorePlayerTwo++;
  tennis_update_game_score(tmp_game);
}

void tennis_p1_add_point(TENNIS_GAME_S *game) {
  TENNIS_GAME_S *tmp_game = game;
  tmp_game->scorePlayerOne++;
  tennis_update_game_score(tmp_game);
}

void tennis_p2_set_point(TENNIS_GAME_S *game, int point) {
  TENNIS_GAME_S *tmp_game = game;
  tmp_game->scorePlayerTwo = point;
  tennis_update_game_score(tmp_game);
}

void tennis_p1_set_point(TENNIS_GAME_S *game, int point) {
  TENNIS_GAME_S *tmp_game = game;
  tmp_game->scorePlayerOne = point;
  tennis_update_game_score(tmp_game);
}

void tennis_p1_set_name(TENNIS_GAME_S *game, const char *name) {
  TENNIS_GAME_S *tmp_game = game;
  sprintf(tmp_game->PlayerOneName, "%s", name);
}

void tennis_p2_set_name(TENNIS_GAME_S *game, const char *name) {
  TENNIS_GAME_S *tmp_game = game;
  sprintf(tmp_game->PlayerTwoName, "%s", name);
}

void tennis_create_game(TENNIS_GAME_S **game) {
  TENNIS_GAME_S *tmp_game;
  tmp_game = (TENNIS_GAME_S *)malloc(sizeof(TENNIS_GAME_S));
  memset(tmp_game, 0, sizeof(TENNIS_GAME_S));
  sprintf(tmp_game->PlayerOneName, "%s", "Player_1");
  sprintf(tmp_game->PlayerTwoName, "%s", "Player_2");

  sprintf(tmp_game->score, "%s", "Love-All");
  *game = tmp_game;
}

void tennis_free_game(TENNIS_GAME_S *game) {
  if (game != NULL)
    free(game);
}

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

  return 0;
}
