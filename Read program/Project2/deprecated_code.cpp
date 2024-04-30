// deprecated_code.cpp

// 这个文件包含了项目中的废弃代码


//using json = nlohmann::json;
//HWND h = FindWindow(L"Valve001", NULL);
//DWORD pid;
//GetWindowThreadProcessId(h, &pid);
//json j;
//char mapName[24];
/*ReadProcessMemory(hProcess, (LPCVOID)(0x2D60070), &mapName, 24, 0);*/
//float** no = Obtain_enemy_coordinate_socket(hProcess, mkdz);
//for (int i = 0; i < RoomNumber; i++)
//{
//    j["BOT" + to_string(i)] = {
//        {"X",(int)no[i][0]},
//        {"Y",(int)no[i][1]},
//        {"Z",(int)no[i][2]},
//        {"F",(int)no[i][3]},
//        {"HP",(int)no[i][4]},
//        {"Diesign",(int)no[i][5]}
//    };
//}

//json new_j;
//for (auto it = j.begin(); it != j.end(); ++it) {
//    if (it.value()["HP"] >-4000)
//    {
//        new_j[it.key()] = it.value();
//    }
//}
//
//if (equal(begin(mapName), end(mapName), begin(tempMapName)))
//{
//    
//}
//else
//{
//    if (string(mapName) == "") {
//        continue;
//    }
//    copy(begin(mapName), end(mapName), begin(tempMapName));
//    new_j["MapName"] = string(mapName);
//    new_j["Update"] = 1;
//    //std::cout << new_j.dump()<< "\n";
//}
//string json_str = new_j.dump()+"|";
//cout << json_str << "\n";
//char* buf = new char[json_str.size() + 1];
//strcpy_s(buf, json_str.size() + 1, json_str.c_str());
//networkConnect->sendData(buf);
//delete[] buf;
//delete no;




//void printAddresses() {
//    std::cout << "characterPosXaddr: " << characterPosXaddr << std::endl;
//    std::cout << "characterPosYaddr: " << characterPosYaddr << std::endl;
//    std::cout << "characterPosZaddr: " << characterPosZaddr << std::endl;
//    std::cout << "characterHealthaddr: " << characterHealthaddr << std::endl;
//    std::cout << "characterStatusaddr: " << characterStatusaddr << std::endl;
//    std::cout << "deathStatusaddr: " << deathStatusaddr << std::endl;
//    std::cout << "teamFlagaddr: " << teamFlagaddr << std::endl;
//}




////int HPArr[2] = { 0x11069BC,0x88 + drrs * 0x324 + 0x158 }; //血量
////int StatusArr[2] = { 0x11069BC,0x88 + drrs * 0x324 + 0x124 }; //人物状态
////int DieArr[2] = { 0x11069BC,0x88 + drrs * 0x324 + 0x130 }; //是否死亡
////int Friend[3] = { 0x11069bc, 0x88 + drrs * 0x324, 0x1D4 }; // 敌我标识符 ?
////int EnemycoorX[2] = { 0x11069BC,0x88 + drrs * 0x324 }; //X
////int EnemycoorY[2] = { 0x11069BC,0x8c + drrs * 0x324 }; //Y
////int EnemycoorZ[2] = { 0x11069BC,0x90 + drrs * 0x324 }; //Z





//#include "InternalModifications.h"
//#include "accessMemory.h"
//#include "Toolcase.h"
//int RoomNumber = 0;
//int MixedFunction(HWND h, HANDLE hProcess, HMODULE mkdz) {
//    int FOVshifting[3] = { 0x11069BC,0x7C, 0x5C4 };
//    int mouseXshifting[1] = { 0x19E10C4 + 0x4 };
//    int mouseYshifting[1] = { 0x19E10C4 };
//
//    int selfX[3] = { 0x1117C64,0x4B9C ,0x88 };
//    int selfY[3] = { 0x1117C64,0x4B9C ,0x88 + 0x4 };
//    int selfZ[3] = { 0x1117C64,0x4B9C ,0x88 + 0x8 };
//
//    HDC hdc = GetDC(h);
//    SetTextColor(hdc, RGB(255, 0, 0));
//    SetBkMode(hdc, TRANSPARENT);
//    HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); // 红色画笔
//    HGDIOBJ oldPen = SelectObject(hdc, hRedPen); // 选择红色画笔
//    RECT rect;
//    GetClientRect(h, &rect);
//    int width = (rect.right - rect.left) / 2;
//    int height = (rect.bottom - rect.top) / 2;
//    int mouseXtemp = 0;
//    int plzm = 0;
//    float** jz = new float* [4];
//    for (int i = 0; i < 4; i++)
//    {
//        jz[i] = new float[4];
//    }
//    float w = 0;
//    int z = 0;
//    RECT windowRect;
//    GetWindowRect(h, &windowRect);
//
//    float windowWidth = windowRect.right - windowRect.left;
//    float windowHeight = windowRect.bottom - windowRect.top;
//    HBRUSH greenBrush = CreateSolidBrush(RGB(0, 255, 0));
//    int selfFriend = 0;
//    SIZE_T bytesRead;
//    int bullet[4] = { 0x11069bc ,0x7c,0x5ec,0xcc };
//    while (true)
//    {
//        //bool appear = 0;
//        //unsigned int FOV = ReadMemoryData_array(hProcess, FOVshifting, (unsigned int)mkdz, 3, 1); //角度d
//        for (int drrs = 0; drrs < 20; drrs++)
//        {
//            int Friend[3] = { 0x11069bc, 0x7c + drrs * 804, 0x1C8 };
//            int EnemycoorX[2] = { 0x11069BC,0x88 + drrs * 804 };
//            if (Friend[1] == 0x7c)
//            {
//                selfFriend = ReadMemoryData_array(hProcess, Friend, (unsigned int)mkdz, 3, 1);
//                continue;
//            }
//            if (selfFriend == ReadMemoryData_array(hProcess, Friend, (unsigned int)mkdz, 3, 1)) {
//                continue;
//            }
//            int MrecoilForce[4] = { 0x1033240 ,0x7c ,0x5f0 ,0x100 };
//            int test[4] = { 0x11069BC ,0x7c ,0x5ec ,0xb8 };
//            int EnemycoorY[2] = { 0x11069BC,0x8c + drrs * 804 };
//            int EnemycoorZ[2] = { 0x11069BC,0x90 + drrs * 804 };
//
//            int HParr[4] = { 0x11069BC,0x7c + drrs * 804,0x4,0x160 };
//            for (int j = 0; j < 4; j++)
//            {
//                for (int i = 0; i < 4; i++)
//                {
//                    ReadProcessMemory(hProcess, (LPCVOID)(0x02C20100 + z * 4), &jz[j][i], 4, NULL);
//                    z++;
//                }
//
//            }
//            z = 0;
//            float HP = ReadMemoryData_array(hProcess, HParr, (unsigned int)mkdz, 4, 1.1f);  //敌人x
//            if (int(HP) > 100 || HP <= 0.9)
//            {
//                continue;
//            }
//            ReadMemoryDataspecial_array(hProcess, MrecoilForce, (unsigned int)mkdz, 4, isZero, 0.0f);  //敌人x
//            ReadMemoryDataspecial_array(hProcess, bullet, (unsigned int)mkdz, 4, isZero, 30);
//            ReadMemoryDataspecial_array(hProcess, test, (unsigned int)mkdz, 4, isZero, 0.0f);  //敌人x
//            float enemyX = ReadMemoryData_array(hProcess, EnemycoorX, (unsigned int)mkdz, 2, 1.1f);  //敌人x
//            float enemyY = ReadMemoryData_array(hProcess, EnemycoorY, (unsigned int)mkdz, 2, 1.1f); //敌人y
//            float enemyZ = ReadMemoryData_array(hProcess, EnemycoorZ, (unsigned int)mkdz, 2, 1.1f); //敌人z
//
//            w = 1 / (jz[0][3] * enemyX + jz[1][3] * enemyY + jz[2][3] * enemyZ + jz[3][3]);
//            if (w < 0.0001)
//            {
//                continue;
//            }
//            float x = 1024.0f / 2 + (jz[0][0] * enemyX + jz[1][0] * enemyY + jz[2][0] * enemyZ + jz[3][0]) * w * 1024.0f / 2;
//
//            float y = 768.0f / 2 - (jz[0][1] * enemyX + jz[1][1] * enemyY + jz[2][1] * enemyZ - 50 + jz[3][1]) * w * 768.0f / 2;
//            float y2 = 768.0f / 2 - (jz[0][1] * enemyX + jz[1][1] * enemyY + jz[2][1] * (enemyZ + 25) + jz[3][1]) * w * 768.0f / 2;
//            float x1 = x - (y2 - y) / 4;
//            float w1 = (y2 - y) / 2.5;
//            float h = y2 - y;
//            float x2 = x + w1;
//            if (x1 > x2) {
//                std::swap(x1, x2);
//            }
//            if (y > y2) {
//                std::swap(y, y2);
//            }
//            RECT rect = { x1, y - 4,x2 ,  y2 - 4 };
//            FrameRect(hdc, &rect, greenBrush);
//
//            //TextOut(hdc, rect.left + 10, rect.top + 10, hp.c_str(), 13);
//        }
//    }
//}
//
//float** Obtain_enemy_coordinate_socket(HANDLE hProcess, HMODULE mkdz)
//{
//    
//    int RoomArr[1] = { 0x195FC20 };
//    RoomNumber = ReadMemoryData_array(hProcess, RoomArr, (unsigned int)mkdz, 1, 1);
//    float* enemyXSetof = new float[RoomNumber];
//    float* enemyYSetof = new float[RoomNumber];
//    float* enemyZSetof = new float[RoomNumber];
//
//    int* dySelfof = new int[RoomNumber];
//    int* dyHP = new int[RoomNumber];
//    int* Diesign = new int[RoomNumber];
//    float enemyX = 0;
//    float enemyY = 0;
//    float enemyZ = 0;
//    for (int drrs = 0; drrs < RoomNumber; drrs++) {
//        int HPArr[2] = { 0x11069BC,0x88 + drrs * 0x324 + 0x158 };
//        int StatusArr[2] = { 0x11069BC,0x88 + drrs * 0x324 + 0x124 };
//        int DieArr[2] = { 0x11069BC,0x88 + drrs * 0x324 + 0x130 };
//        float HP = ReadMemoryData_array(hProcess, HPArr, (unsigned int)mkdz, 2, 1.1f);  //敌人x
//        int isDie= ReadMemoryData_array(hProcess, DieArr, (unsigned int)mkdz, 2, 1.1f);
//        int isStatus = ReadMemoryData_array(hProcess, StatusArr, (unsigned int)mkdz, 2, 1);
//        if (HP > 100 || isDie == 0 || isStatus == 0)
//        {    
//            continue;
//        }
//        
//        int selfFriend = 2;
//        int Friend[3] = { 0x11069bc, 0x7c + drrs * 804, 0x1C8 };
//        int EnemycoorX[2] = { 0x11069BC,0x88 + drrs * 804 };
//        int EnemycoorY[2] = { 0x11069BC,0x8c + drrs * 804 };
//        int EnemycoorZ[2] = { 0x11069BC,0x90 + drrs * 804 };
//       
//        enemyX = ReadMemoryData_array(hProcess, EnemycoorX, (unsigned int)mkdz, 2, 1.1f);  //敌人x
//        enemyY = ReadMemoryData_array(hProcess, EnemycoorY, (unsigned int)mkdz, 2, 1.1f); //敌人y
//        enemyZ = ReadMemoryData_array(hProcess, EnemycoorZ, (unsigned int)mkdz, 2, 1.1f); //敌人z
//        
//        if (Friend[1] == 0x7c)
//        {
//            dySelfof[drrs] = 0;
//            //std::cout << "自己:" << dySelfof[drrs]<<"\n";
//        }
//        else if (selfFriend == ReadMemoryData_array(hProcess, Friend, (unsigned int)mkdz, 3, 1) ==1) {
//            dySelfof[drrs] = 1;
//            //std::cout << "敌人:" << dySelfof[drrs] << "\n";
//        }
//        else
//        {
//            dySelfof[drrs] = selfFriend;
//            //std::cout << "队友:" << dySelfof[drrs] << "\n";
//
//        }
//
//        Diesign[drrs] = isDie;
//        enemyXSetof[drrs] = enemyX;
//        enemyYSetof[drrs] = enemyY;
//        enemyZSetof[drrs] = enemyZ;
//        dyHP[drrs] = HP;
//    }
//    float** CountSetof = new float* [RoomNumber];
//    for (int i = 0; i < RoomNumber; i++)
//    {
//        CountSetof[i] = new float[6];
//        for (int j = 0; j < 6; j++)
//        {
//            switch (j)
//            {
//            case 0:
//                CountSetof[i][j] = enemyXSetof[i];
//                break;
//            case 1:
//                CountSetof[i][j] = enemyYSetof[i];
//                break;
//            case 2:
//                CountSetof[i][j] = enemyZSetof[i];
//                break;
//            case 3:
//                CountSetof[i][j] = dySelfof[i];
//                break;
//            case 4:
//                CountSetof[i][j] = dyHP[i];
//                break;
//            case 5:
//                CountSetof[i][j] = Diesign[i];
//                break;
//            default:
//                break;
//            }
//          
//        }
//    }
//    return CountSetof;
//}



//#pragma once
//#include <iostream>
//#include <Windows.h>
//#include <string>
//#include <Psapi.h>
//#include <cstdint>
//#include <format>
//#include<cmath>
//#include <map>
//#define MAX_MODULE_NAME_SIZE 256
//#define MODE_INT 0
//#define MODE_FLOAT 0.0
//
//unsigned int ReadMemoryData_array(HANDLE handle, int* array, unsigned int baseaddress, int size, int types);
//float ReadMemoryData_array(HANDLE handle, int* array, unsigned int baseaddress, int size, float types);
//void ReadMemoryDataspecial_array(HANDLE handle, int* array, unsigned int baseaddress, int size, bool (*ptr)(float), float writeData = 0.0f);
//void ReadMemoryDataspecial_array(HANDLE handle, int* array, unsigned int baseaddress, int size, bool (*ptr)(float), int writeData = 0);
//HMODULE Get_handle_by_name(const wchar_t handleName, DWORD pid, HANDLE hProcess);




//#include "accessMemory.h"
////传入句柄和基地址,偏移,得到最终的值
////HANDLE handle 句柄
////int* array 偏移数组
////unsigned int baseaddress 基地址
//// int size 数组大小
//// types 指定返回值类型
//
//unsigned int ReadMemoryData_array(HANDLE handle, int* array, unsigned int baseaddress, int size, int types) {
//	unsigned int bufferr;
//	if (size != 0) {
//
//		unsigned int addressm = baseaddress;
//		for (int i = 0; i < size; i++)
//		{
//			unsigned int shifting = array[i];
//			ReadProcessMemory(handle, (LPCVOID)(addressm + shifting), &bufferr, 4, 0);
//			addressm = bufferr;
//		}
//		return (unsigned int)bufferr;
//	}
//	else {
//		ReadProcessMemory(handle, (LPCVOID)baseaddress, &bufferr, 4, 0);
//		return (unsigned int)bufferr;
//	}
//}
//float ReadMemoryData_array(HANDLE handle, int* array, unsigned int baseaddress, int size, float types) {
//	unsigned int bufferr;
//	float bufferrfloat;
//	if (size != 0) {
//		unsigned int addressm = baseaddress;
//		for (int i = 0; i < size; i++)
//		{
//			unsigned int shifting = array[i];
//			if (i == size - 1) {
//				ReadProcessMemory(handle, (LPCVOID)(addressm + shifting), &bufferrfloat, 4, 0);
//				return bufferrfloat;
//			}
//			ReadProcessMemory(handle, (LPCVOID)(addressm + shifting), &bufferr, 4, 0);
//			addressm = bufferr;
//
//		}
//	}
//	else {
//		ReadProcessMemory(handle, (LPCVOID)baseaddress, &bufferr, 4, 0);
//		return (float)bufferr;
//	}
//}
//
//
//void ReadMemoryDataspecial_array(HANDLE handle, int* array, unsigned int baseaddress, int size, bool (*ptr)(float), float writeData) {
//	unsigned int bufferr;
//	float bufferrfloat;
//	if (size != 0) {
//		unsigned int addressm = baseaddress;
//		for (int i = 0; i < size; i++)
//		{
//			unsigned int shifting = array[i];
//			if (i == size - 1) {
//				ReadProcessMemory(handle, (LPCVOID)(addressm + shifting), &bufferrfloat, 4, 0);
//				if (!ptr(bufferrfloat))
//				{
//					WriteProcessMemory(handle, (LPVOID)(addressm + shifting), &writeData, 8, 0);
//				}
//			}
//			ReadProcessMemory(handle, (LPCVOID)(addressm + shifting), &bufferr, 4, 0);
//			addressm = bufferr;
//
//		}
//	}
//	else {
//		ReadProcessMemory(handle, (LPCVOID)baseaddress, &bufferr, 4, 0);
//	}
//}
//void ReadMemoryDataspecial_array(HANDLE handle, int* array, unsigned int baseaddress, int size, bool (*ptr)(float), int writeData) {
//	unsigned int bufferr;
//	float bufferrfloat;
//	if (size != 0) {
//		unsigned int addressm = baseaddress;
//		for (int i = 0; i < size; i++)
//		{
//			unsigned int shifting = array[i];
//			if (i == size - 1) {
//				ReadProcessMemory(handle, (LPCVOID)(addressm + shifting), &bufferrfloat, 4, 0);
//				if (!ptr(bufferrfloat))
//				{
//					WriteProcessMemory(handle, (LPVOID)(addressm + shifting), &writeData, 4, 0);
//
//				}
//			}
//			ReadProcessMemory(handle, (LPCVOID)(addressm + shifting), &bufferr, 4, 0);
//			addressm = bufferr;
//
//		}
//	}
//	else {
//		ReadProcessMemory(handle, (LPCVOID)baseaddress, &bufferr, 4, 0);
//	}
//}
//HMODULE Get_handle_by_name(const wchar_t handleName, DWORD pid, HANDLE hProcess) {
//	HMODULE hModules[1024];
//	HMODULE  mkdz = 0;
//	DWORD needed;
//	if (EnumProcessModules(hProcess, hModules, sizeof(hModules), &needed)) {
//		wchar_t Modulename[MAX_MODULE_NAME_SIZE];
//		for (int i = 0; i < (needed / sizeof(HMODULE)); i++) {
//			if (GetModuleBaseNameW(hProcess, hModules[i], Modulename, MAX_MODULE_NAME_SIZE) != 0) {
//				if (wcscmp(Modulename, L"cstrike.exe") == 0) {
//					mkdz = hModules[i];
//					break;
//				}
//			}
//		}
//	}
//	return mkdz;
//}