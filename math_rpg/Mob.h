#ifndef _MOB_H_
#define _MOB_H_

#include "Library.h"

void MakeMob(int mapID,int number);
void ClearMonster(int ID, int entry);
void CheckMob(int ID, int x, int y);
void FightMob(int ID, int x, int y);
void Fight_Add();
void Fight_Sub();
void Fight_Multi();
void Fight_Mixed();
void Fight_Func1();
void Fight_Func2();
void Fight_Permutation();
void Fight_Combination();
void Fight_P_Permutation();
void Fight_H_Combination();
void SetMasterKey(int n);
void Fight_Differentiation1();
void Fight_Differentiation2();
void Fight_Integration1();
void Fight_Integration2();
long long GetMasterKey();

#endif