#include "Util.h"

vector<string> Util::splitString(string s, char del) {
	vector<string> newString;
	stringstream ss(s);
	string token;

	while (getline(ss, token, del)) {
		newString.push_back(token);
	}

	return newString;
}