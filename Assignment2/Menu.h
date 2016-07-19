
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Menu {
public:
	Menu(string prompt, vector<string> choices);
	int getPromptResponse();

private:
	string menuPrompt;
	vector<string> choices;
	size_t totalChoices;
	int prompt();
	void showPrompt();
	void showInvalidInputMsg();
	void showInvalidRangeMsg();
};