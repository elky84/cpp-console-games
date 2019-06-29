#ifndef _GAMEHOST_H_
#define _GAMEHOST_H_

#include "Library.h"

void MovePlayer();
void SetCharName(char _name[]);
void ShowState();
void EarnExp(double n);
void PrintMyName();
void SubHp(double n);

void CheckState();
double GetHp();
double GetMaxHp();
double GetExp();
double GetMaxExp();
void SetHpFull();
void SetLevel(int n);
void SetName(char* _name);
int GetLevel();
void SetMyJob(const char* str);
void DrawPlayer();
void Load();
void Save();
void EarnMoney(double n);
void SetMoney(double n);
double GetMoney();

#endif