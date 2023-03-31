#include "include/gtest/gtest.h"

#include "app.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#define GAME_SET

// int add(int a, int b) { return a + b; }

void tennis_create_game(game_t *game) {
  if (game == NULL) {
    game = (game_t *)malloc(sizeof(game_t));
  }
  strcpy(game->score, "Love-All");
  game->play1_score = 0;
}

void tennis_playerP1_add_scored(game_t *game) {
  game->play1_score++;
  if (game->play1_score == 1) {
    strcpy(game->score, "Fifteen-Love");
  }
  if (game->play1_score == 2) {
    strcpy(game->score, "Thirty-Love");
  }
}

void tennis_playerP2_add_scored(game_t *game) {
  game->play2_score++;
  if (game->play2_score == 1) {
    strcpy(game->score, "Fifteen-One");
  }
  if (game->play2_score == 2) {
    strcpy(game->score, "Thirty-All");
  }
}
