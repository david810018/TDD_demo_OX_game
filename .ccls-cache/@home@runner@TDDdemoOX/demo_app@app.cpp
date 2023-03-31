#include "include/gtest/gtest.h"

#include "app.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#define GAME_SET
//玩家選擇出什麼拳頭
//電腦隨機出拳
//判斷勝負
//顯示比分
//判斷最終勝負
void CreatePlayer(player_t * player)
{
  strcpy(player->States ,"還沒出");
  player->Score = 0;
  player->Choice = 0;
}

void InitInfo()
{
  printf("歡迎來到猜拳遊戲！\n");
  printf("請輸入：\n");
  printf("1. 石頭\n");
  printf("2. 剪刀\n");
  printf("3. 布\n");
}

void PlayerChoice(player_t * player, int Choice)
{
  if (Choice > 3 || Choice < 1)
  {
    player->Choice = 0;
    return;
  }
  printf("\n請選擇出什麼拳頭：");
  player->Choice = Choice;
  printf("您出的拳頭：player->Choice= %d\n", player->Choice);
}
void PlayerChoiceType(player_t * player)
{
  switch(player->Choice)
  {
    case 1:
    {
      strcpy(player->States ,"石頭");
      break;
    }
    case 2:
    {
      strcpy(player->States ,"剪刀");
      break;
    }
    case 3:
    {
      strcpy(player->States ,"布");
      break;
    }
    default:
    {
      printf("\n請選擇出什麼拳頭：");
      strcpy(player->States ,"還沒出");
      break;
    }
  }
}
void ComputerRandomChoice(player_t * computer)
{
  srand(time(NULL));
  computer->Choice = rand() % 3 + 1;
  printf("電腦出的拳頭：computer->Choice= %d\n", computer->Choice);
}

bool PlayerWin(player_t * player, player_t * computer)
{
    if ((player->Choice == 1 && computer->Choice == 2) ||
      (player->Choice == 2 && computer->Choice == 3) ||
      (player->Choice == 3 && computer->Choice == 1)) 
    {
      printf("你贏了！ Player:%s Computer: %s\n", player->States, computer->States);
      return true;
    }
  return false;
}
bool ComputerWin(player_t * player, player_t * computer)
{
  if ((computer->Choice == 1 && player->Choice == 2) ||
             (computer->Choice == 2 && player->Choice == 3) ||
             (computer->Choice == 3 && player->Choice == 1)) {
      printf("電腦贏了！ Computer:%s Player: %s\n",computer->States, player->States);
    return true;
    }
  return false;
}

void GameStart(player_t * player, player_t * computer)
{
  PlayerChoice(player, player->Choice);
  ComputerRandomChoice(computer);
  PlayerChoiceType(player);
  PlayerChoiceType(computer);
  if(PlayerWin(player, computer))
    player->Score++;
  else if(ComputerWin(player, computer))
    computer->Score++;
  else if(player->Choice == computer->Choice)
    printf("平手！ Computer:%s Player: %s\n",computer->States, player->States);
  else
    printf("玩家在亂出！ Computer:%s Player: %s\n",computer->States, player->States);
  printf("現在比分 Computer:%d Player: %d\n",computer->Score, player->Score);
}

void WhoWin(player_t * player, player_t * computer)
{
  if (player->Score > computer->Score) 
      printf("\n你僥倖贏得了比賽！\n");
  else 
      printf("\n電腦正常發揮贏得了比賽！\n");
    printf("最終比分 Computer:%d Player: %d\n",computer->Score, player->Score);
}
