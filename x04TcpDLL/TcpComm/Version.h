#pragma once

#include <iostream>
#include <string>

#define API_MAJOR 1
#define API_MINOR 0
#define API_PATCH 1

class Version
{
public:
	static int GetMajor() { return API_MAJOR; }
	static int GetMinor() { return API_MINOR; }
	static int GetPatch() { return API_PATCH; }
	static char* GetVersion();
};

char* Version::GetVersion()
{
	std::string str_ver;
	str_ver.resize(10);
	sprintf(&str_ver[0], "%d.%d.%d", API_MAJOR, API_MINOR, API_PATCH);
	str_ver.resize(strlen(str_ver.data()) + 1);
	return (char*)str_ver.c_str();
}
