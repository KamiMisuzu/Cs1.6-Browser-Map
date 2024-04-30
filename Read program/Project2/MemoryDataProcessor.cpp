#include "MemoryDataProcessor.h"



MemoryDataProcessor::MemoryDataProcessor(MemoryOffsetStorage* mos) : memoryDatasource(mos), hProcess(mos->getClassProcess())
{
}


int MemoryDataProcessor::ReadMemoryAddressing(stack<int>* stk)
{
	int lpBuffer;
	int address = stk->top();
	stk->pop();
	if (stk->empty())
	{
		ReadProcessMemory(this->hProcess, (LPCVOID)(address + this->currentmoduleAddress), (LPVOID)&lpBuffer, this->currentReadByte, NULL);
		return lpBuffer;
	}
	else {
		ReadProcessMemory(this->hProcess, (LPCVOID)(ReadMemoryAddressing(stk)+ address), (LPVOID)&lpBuffer, this->currentReadByte, NULL);
		return lpBuffer;
	}
}

bool MemoryDataProcessor::setCurrentmoduleName(string* moduleName)
{
	this->moduleName = *moduleName;
	this->currentmoduleAddress = this->memoryDatasource->getModuleAddress(moduleName);
	return true;
}

int MemoryDataProcessor::Getfixedaddress(const char* name)
{
	return this->ReadMemoryAddressing(this->memoryDatasource->getAddressMap(name))+this->memoryDatasource->getEndOffset(name);
}

int MemoryDataProcessor::RecursiveReadInt(vector<int> panding, int devia, int pos)
{
	panding[devia] = panding[devia] + pos;
	stack<int> stk;
	for (int i = 0; i < panding.size(); i++)
	{
		stk.push(panding[i]);
	}
	return this->ReadMemoryAddressing(&stk);
}

//int MemoryDataProcessor::RecursiveReadInt(int* devia, int&& pos) {}
float MemoryDataProcessor::RecursiveReadFloat(int&& devia, int&& pos){	return 0.0f;}


float MemoryDataProcessor::ReadMemoryFloat_4(int&& ipAddress)
{
	float lpBuffer;
	ReadProcessMemory(this->hProcess, (LPCVOID)(ipAddress), &lpBuffer, 4, NULL);
	return lpBuffer;
}

int MemoryDataProcessor::ReadMemoryINT_4(int&& ipAddress)
{
	int lpBuffer;
	ReadProcessMemory(this->hProcess, (LPCVOID)(ipAddress), &lpBuffer, 4, NULL);
	return lpBuffer;
}

int MemoryDataProcessor::ReadMemoryINT_8(int&& ipAddress)
{
	int lpBuffer;
	ReadProcessMemory(this->hProcess, (LPCVOID)(ipAddress), &lpBuffer, 8, NULL);
	return lpBuffer;
}

string MemoryDataProcessor::ReadMemoryChar(int&& ipAddress, int&& lenght)
{
	char* str = new char[lenght+1];
	ReadProcessMemory(this->hProcess, (LPCVOID)(ipAddress), str, lenght, NULL);
	string s1(str);
	delete[] str;
	return s1;
}
