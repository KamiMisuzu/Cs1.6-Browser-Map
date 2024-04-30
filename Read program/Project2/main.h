#pragma once

#include "NetworkDispatcher.h"
#include "MemoryDataProcessor.h"
#include "MemoryOffsetStorage.h"
#include "InforMationLoading.h"
#include <cstring>
#include <nlohmann/json.hpp>
#include <conio.h>
bool lastState = false;

using json = nlohmann::json;
using namespace std;
extern int RoomNumber;
static int characterPosXaddr; //人物坐标x地址
static int characterPosYaddr; //人物坐标y地址
static int characterPosZaddr; //人物坐标z地址
static int characterHealthaddr; //人物血量地址
static int characterStatusaddr; //人物状态地址
static int deathStatusaddr; //死亡标志位地址
static vector<int> teamFlagaddr({ 0x11069bc, 0x7c, 0x1C8 }); //敌我标志位地址
static int characterArrayoffset = 0x324; // 人物偏移
static int mapNameAddress = 0x2D60070; //地图名地址
static string currentMap_name;
bool initializeGameData(MemoryOffsetStorage* memory_off_1, MemoryDataProcessor* memory_data_1);
int main();