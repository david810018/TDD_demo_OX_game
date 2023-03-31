#ifndef __TENNIS_GAME_H__
#define __TENNIS_GAME_H__

#undef EXT
#ifdef GAME_SET
#define EXT
#else
#define EXT extern
#endif

EXT int add(int a, int b);

// typdef struct player {

// }

typedef struct game_s {
  char score[256];
  int play1_score;
  int play2_score;
} game_t;

EXT void tennis_create_game(game_t *game);
EXT void tennis_playerP1_add_scored(game_t *game);
EXT void tennis_playerP2_add_scored(game_t *game);
#endif