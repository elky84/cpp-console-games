#ifndef _MAP_H_
#define _MAP_H_

#include "Library.h"



void DrawMap();
void SetMapID(int n);
int GetMapID();
int GetMapEntry(int ID, int x, int y);
void SetMapEntry(int ID, int x, int y, int entry);
void ShowMap(int ID, int x, int y);

#endif