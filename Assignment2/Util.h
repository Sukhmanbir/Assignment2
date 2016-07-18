#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Util {
public:
	vector<string> splitString(string s, char del);
	void lowercase(string &str);
};