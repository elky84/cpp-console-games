#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Library.h"

class Player {
	int X, Y;
	int BeforeX, BeforeY;
	int lastblock;
	char name[20];
	double MaxHp;
	double Hp;
	double MaxExp;
	double Exp;
	double money;
	int Level;
	char Job[20];
	char itemList[10];
	int questList[20];
public:
	Player();
	~Player();

	int GetX(){return X;}
	int GetY(){return Y;}
	int GetBeforeX(){return BeforeX;}
	int GetBeforeY(){return BeforeY;}
	int GetLastblock(){return lastblock;}
	int GetLevel(){return Level;}
	double GetExp(){return Exp;}
	double GetMaxExp(){return MaxExp;}
	double GetHp(){return Hp;}
	double GetMaxHp(){return MaxHp;}
	char* GetName(){return name;}
	char* GetJob(){return Job;}
	char GetItemList(int n){return itemList[n];}
	int GetQuestList(int n){return questList[n];}
	double GetMoney(){return money;}

	void SetX(int n){X=n;}
	void SetY(int n){Y=n;}
	void SetBeforeX(int n){BeforeX=n;}
	void SetBeforeY(int n){BeforeY=n;}
	void SetName(char _name[]) {strcpy(name,_name);}
	void SetName(const char* _name) {strcpy(name,_name);}
	void SetLastblock(int n){lastblock=n;}
	void SetExp(double n){Exp += n;}
	void SubHp(double n){Hp -= n;}
	void SetHpFull(){Hp = MaxHp;}
	void SetLevel(int n){Level = n;}
	void SetMyJob(const char* str){strcpy(Job,str); ShowState();}
	void SetHp(double n){Hp = n;}
	void SetMaxHp(double n){MaxHp = n;}
	void SetMaxExp(double n){MaxExp = n;}
	void SetItemList(int n, char ch){itemList[n] = ch;}
	void SetQuestList(int n, int state){questList[n] = state;}
	void SetMoney(double n){money = n;}
	void EarnMoney(double n){money += n;}

	void DrawPlayer();
	void ErasePlayer();
	void CheckState();
	void PrintName();
	void PrintJob();

};

#endif