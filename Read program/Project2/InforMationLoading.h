#pragma once
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class InforMationLoading
{
public:
	bool setJsonBodyData(const char* keyFather,const char* key, int value);
private:
	json Allcharacters;
};
