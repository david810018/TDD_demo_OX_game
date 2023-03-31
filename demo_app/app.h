#ifndef __TENNIS_GAME_H__
#define __TENNIS_GAME_H__

#undef EXT
#ifdef GAME_SET
#define EXT
#else
#define EXT extern
#endif

typedef struct player_s {
  int Choice;
  int Score;
  char States[256];
} player_t;

EXT void CreatePlayer(player_t * player);
EXT void InitInfo(void);
EXT void PlayerChoice(player_t * player, int choice);
EXT void PlayerChoiceType(player_t * player);
EXT void ComputerRandomChoice(player_t * computer);
EXT bool ComputerWin(player_t * player, player_t * computer);
EXT bool PlayerWin(player_t * player, player_t * computer);
EXT void GameStart(player_t * player, player_t * computer);
EXT void WhoWin(player_t * player, player_t * computer);
#endif