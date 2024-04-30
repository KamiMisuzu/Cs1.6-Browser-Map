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
static int characterPosXaddr; //��������x��ַ
static int characterPosYaddr; //��������y��ַ
static int characterPosZaddr; //��������z��ַ
static int characterHealthaddr; //����Ѫ����ַ
static int characterStatusaddr; //����״̬��ַ
static int deathStatusaddr; //������־λ��ַ
static vector<int> teamFlagaddr({ 0x11069bc, 0x7c, 0x1C8 }); //���ұ�־λ��ַ
static int characterArrayoffset = 0x324; // ����ƫ��
static int mapNameAddress = 0x2D60070; //��ͼ����ַ
static string currentMap_name;
bool initializeGameData(MemoryOffsetStorage* memory_off_1, MemoryDataProcessor* memory_data_1);
int main();