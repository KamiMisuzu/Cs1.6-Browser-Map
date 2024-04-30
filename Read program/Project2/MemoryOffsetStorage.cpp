#include "MemoryOffsetStorage.h"

inline string strSplit(string&& a, const char&& sign) {
	for (int i = a.size(); i != 0; i--)
	{
		if (static_cast<int>(a[i]) == static_cast<int>(sign)) {
			return a.substr(i+1);
		}
	}
}

MemoryOffsetStorage::MemoryOffsetStorage(const wchar_t* windowClassName)
{
	HWND h = FindWindow(windowClassName, NULL);
	
	if (h == 0){return;}

	GetWindowThreadProcessId(h, &this->pid);

	this->hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->pid);
}

MemoryOffsetStorage::MemoryOffsetStorage(int authority, bool bol, DWORD pid)
{
	this->hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	this->pid = pid;
}

bool MemoryOffsetStorage::initModuledata()
{
	DWORD p;
	HMODULE* handleAddress = new HMODULE[256];
	char handleName[1024];
	EnumProcessModules(this->hProcess, handleAddress, 256, &p);
	for (int i = 0; i < p / sizeof(HMODULE); i++)
	{
		GetModuleFileNameExA(this->hProcess, handleAddress[i], handleName,1024);
		addModuleAddress(move(string(handleName)), (int)handleAddress[i]);
	}

	delete[] handleAddress;
	return true;
}

bool MemoryOffsetStorage::insertAddressMap(const char* sign,vector<int>* offsetArr,int endoffset)
{
	vector<int>::iterator it;
	stack<int> stk;
	for (it= offsetArr->begin();it!= offsetArr->end();it++)
	{
		stk.push(*it);
	}

	this->addressMap.insert(pair<string, stack<int>>(sign, stk));
	addEndOffset(move(sign), endoffset);
	return true;
}


stack<int>* MemoryOffsetStorage::getAddressMap(const char* name)
{
	auto it = this->addressMap.find(name);
	return &it->second;
}

int MemoryOffsetStorage::getEndOffset(const char* name)
{
	auto it = this->endOffset.find(name);
	return it->second;
}

HANDLE& MemoryOffsetStorage::getClassProcess()
{
	return this->hProcess;
}

int MemoryOffsetStorage::getModuleAddress(string* name)
{
	auto it = this->moduleAddress.find(*name);
	return it->second;
}

bool MemoryOffsetStorage::addEndOffset(string&& sign, int endoff)
{
	this->endOffset.insert(pair<string, int>(sign, endoff));
	return true;
}

//void MemoryOffsetStorage::Printmodule() const
//{
//	map<string, stack<int>>::const_iterator it;
//	for (it = this->addressMap.begin(); it !=this->addressMap.end();it++)
//	{
//		cout << it->first << endl;
//		cout << "人物坐标X最后偏移" << it->second.top() << endl;
//	}
//}

bool MemoryOffsetStorage::addModuleAddress(string&& name, int address)
{
	this->moduleAddress.insert(pair<string,int>(strSplit(move(name),'\\'), address));
	return true;
}


