#ifndef __TENNIS_GAME_H__
#define __TENNIS_GAME_H__

#undef EXT
#ifdef GAME_SET
#define EXT
#else
#define EXT extern
#endif

#define STR_LEN 16
#define STR_NAME_LEN (STR_LEN - 6)

typedef struct game_s {
  char score[STR_LEN];
  int scorePlayerOne;
  int scorePlayerTwo;
  char PlayerOneName[STR_NAME_LEN];
  char PlayerTwoName[STR_NAME_LEN];
} TENNIS_GAME_S;

EXT int add(int a, int b);
EXT void tennis_create_game(TENNIS_GAME_S **game);
void tennis_free_game(TENNIS_GAME_S *game);
void tennis_p1_add_point(TENNIS_GAME_S *game);
void tennis_p2_add_point(TENNIS_GAME_S *game);
void tennis_p1_set_point(TENNIS_GAME_S *game, int point);
void tennis_p2_set_point(TENNIS_GAME_S *game, int point);
void tennis_p1_set_name(TENNIS_GAME_S *game, const char *name);
void tennis_p2_set_name(TENNIS_GAME_S *game, const char *name);
void tennis_update_game_score(TENNIS_GAME_S *game);

#endif