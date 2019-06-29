#ifndef _NPC_H_
#define _NPC_H_
#include "Library.h"

void CheckNPC(int x, int y);
void Talk_NPC(char name[], char chat[]);
void Talk_Player(char chat[]);
void Talk_System(char chat[]);
void Talk_Mob(char chat[]);
void ChatNPC(int ID, int x, int y);
int GetQuestList(int n);
void SetQuestList(int n, int entry);

#endif