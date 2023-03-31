 #include "app.h"
#include "include/gtest/gtest.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

TEST(Create, Player) {
  player_t player;
  CreatePlayer(&player);
  EXPECT_STREQ("還沒出", player.States);
  EXPECT_EQ(0, player.Score);
  EXPECT_EQ(0, player.Choice);
}

TEST(choice, Player) {
  player_t player;
  int choice;
  choice = 1;
  PlayerChoice(&player, choice);
  EXPECT_EQ(1, player.Choice);

  choice = 2;
  PlayerChoice(&player, choice);
  EXPECT_EQ(2, player.Choice);

  choice = 3;
  PlayerChoice(&player, choice);
  EXPECT_EQ(3, player.Choice);
}

TEST(choicetype, Player) {
  player_t player;
  int choice;
  choice = 1;
  PlayerChoice(&player, choice);
  EXPECT_EQ(1, player.Choice);
  PlayerChoiceType(&player);
  EXPECT_STREQ("石頭", player.States);
  choice = 2;
  PlayerChoice(&player, choice);
  EXPECT_EQ(2, player.Choice);
  PlayerChoiceType(&player);
  EXPECT_STREQ("剪刀", player.States);
  choice = 3;
  PlayerChoice(&player, choice);
  EXPECT_EQ(3, player.Choice);
  PlayerChoiceType(&player);
  EXPECT_STREQ("布", player.States);
  choice = 4;
  PlayerChoice(&player, choice);
  EXPECT_EQ(0, player.Choice);
  PlayerChoiceType(&player);
  EXPECT_STREQ("還沒出", player.States);
}

TEST(Win, Player) {
  player_t player;
  player_t computer;
  player.Choice = 1;
  computer.Choice = 2;
  PlayerChoiceType(&player);
  PlayerChoiceType(&computer);
  bool win1 = PlayerWin(&player, &computer);
  EXPECT_TRUE(win1);
  player.Choice = 2;
  computer.Choice = 3;
  PlayerChoiceType(&player);
  PlayerChoiceType(&computer);
  bool win2 = PlayerWin(&player, &computer);
  EXPECT_TRUE(win2);
  player.Choice = 3;
  computer.Choice = 1;
  PlayerChoiceType(&player);
  PlayerChoiceType(&computer);
  bool win3 = PlayerWin(&player, &computer);
  EXPECT_TRUE(win3);
}

TEST(Win, Computer) {
  player_t player;
  player_t computer;
  player.Choice = 2;
  computer.Choice = 1;
  PlayerChoiceType(&player);
  PlayerChoiceType(&computer);
  bool win1 = ComputerWin(&player, &computer);
  EXPECT_TRUE(win1);
  player.Choice = 3;
  computer.Choice = 2;
  PlayerChoiceType(&player);
  PlayerChoiceType(&computer);
  bool win2 = ComputerWin(&player, &computer);
  EXPECT_TRUE(win2);
  player.Choice = 1;
  computer.Choice = 3;
  PlayerChoiceType(&player);
  PlayerChoiceType(&computer);
  bool win3 = ComputerWin(&player, &computer);
  EXPECT_TRUE(win3);
}

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  if (ret != 0)
    return -1;
  player_t Player;
  player_t Computer;

  CreatePlayer(&Player);
  CreatePlayer(&Computer);
  InitInfo();
  while (Player.Score < 3 && Computer.Score < 3) {
    ret = scanf("%d", &Player.Choice);
    GameStart(&Player, &Computer);
  }
  WhoWin(&Player, &Computer);
  return 0;
}
