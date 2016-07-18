#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class FileUtility {
public:
	string file_load(string file_name);
	bool file_write(string name, vector<string> contents);
};