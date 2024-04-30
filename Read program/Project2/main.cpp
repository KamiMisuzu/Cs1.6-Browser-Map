#include "main.h"

int main() {
    vector<int> oneoff({ 0x11069BC });
    const wchar_t* windowClassName = L"Valve001";
    MemoryOffsetStorage* memory_off_1 = new MemoryOffsetStorage(windowClassName);
    MemoryDataProcessor* memory_data_1 = new MemoryDataProcessor(memory_off_1);
    if (!initializeGameData(memory_off_1, memory_data_1)) {
        cout << "[!]初始化地址偏移失败" << endl;
        return -1;
    };
    unique_ptr<NetworkDispatcher> networkConnect = make_unique<NetworkDispatcher>(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    networkConnect->setAddress(AF_INET, "127.0.0.1", 8083);
    networkConnect->runServer();
    cout << "按下F9刷新手动刷新当前地图" << endl;
    try
    {
        while (true)
        {
                json characterJson;
            bool currentState = GetAsyncKeyState(VK_F9) & 0x8000;
            if (currentState && !lastState) {
                characterJson["Update"] = 1;
                characterJson["MapName"] = currentMap_name;
                cout <<"当前地图为:" << currentMap_name << endl;
            }
            lastState = currentState;
            string nowMap_name = memory_data_1->ReadMemoryChar(move(mapNameAddress), 24);
            int number = 0;
            for (int i = 0; i < 20; i++) {
                int nowOffset = i* characterArrayoffset;
                string robotNumber("BOT" + to_string(number));
                if (memory_data_1->ReadMemoryINT_4(deathStatusaddr + nowOffset) == 0 ||
                    memory_data_1->ReadMemoryINT_4(characterStatusaddr + nowOffset) == 0
                    ) {
                    continue;
                }
                characterJson[robotNumber]["X"] = memory_data_1->ReadMemoryFloat_4(characterPosXaddr + nowOffset);
                characterJson[robotNumber]["Y"] = memory_data_1->ReadMemoryFloat_4(characterPosYaddr + nowOffset);
                characterJson[robotNumber]["Z"] = memory_data_1->ReadMemoryFloat_4(characterPosZaddr + nowOffset);
                characterJson[robotNumber]["HP"] = memory_data_1->ReadMemoryFloat_4(characterHealthaddr + nowOffset);
                if (i == 0)
                {
                    characterJson[robotNumber]["F"] = 0;
                    //cout << characterJson[robotNumber]["F"] <<  "-----------------" << endl;
                }
                else { 
                    characterJson[robotNumber]["F"] = memory_data_1->RecursiveReadInt(vector<int>(teamFlagaddr),1, nowOffset);
                    //cout << characterJson[robotNumber]["F"] << endl;
                }
                number++;
            }

            if (nowMap_name.length() >= 4 && currentMap_name != nowMap_name && nowMap_name.substr(nowMap_name.length() - 4) == ".bsp")
            {
                currentMap_name = nowMap_name;
                characterJson["Update"] = 1;
                characterJson["MapName"] = currentMap_name;
            }
            //const char* buf
            
            networkConnect->sendData(characterJson.dump().c_str());
        }
    }
    catch (const std::runtime_error& e)
    {
        cout << e.what() << endl;
    }
    
    
    return 0; 
}
//0x11069bc, 0x7c + drrs * 804, 0x1C8

bool initializeGameData(MemoryOffsetStorage* memory_off_1, MemoryDataProcessor* memory_data_1) {
    vector<int> oneoff({ 0x11069BC });
    memory_off_1->insertAddressMap("人物坐标x", &oneoff, 0x88);
    memory_off_1->insertAddressMap("人物坐标y", &oneoff, 0x88 + 4);
    memory_off_1->insertAddressMap("人物坐标z", &oneoff, 0x88 + 8);
    memory_off_1->insertAddressMap("人物血量", &oneoff, 0x88 + 0x158);
    memory_off_1->insertAddressMap("人物状态", &oneoff, 0x88 + 0x124);
    memory_off_1->insertAddressMap("死亡标志位", &oneoff, 0x88 + 0x130);
    //memory_off_1->inserpendingData("敌我标志位", vector<int>({ 0x11069bc + 0x7c,0x1C8 }));
    memory_off_1->insertAddressMap("人物", &oneoff, 0x88 + 0x98);
    memory_off_1->initModuledata();
    string* moduleName = new string("cstrike.exe");
    memory_data_1->setCurrentmoduleName(moduleName);
    characterPosXaddr = memory_data_1->Getfixedaddress("人物坐标x");
    characterPosYaddr = memory_data_1->Getfixedaddress("人物坐标y");
    characterPosZaddr = memory_data_1->Getfixedaddress("人物坐标z");
    characterHealthaddr = memory_data_1->Getfixedaddress("人物血量");
    characterStatusaddr = memory_data_1->Getfixedaddress("人物状态");
    currentMap_name = memory_data_1->ReadMemoryChar(move(mapNameAddress), 24);
    return true;
}