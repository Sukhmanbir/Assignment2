#pragma once
#include <string>

using namespace std;

class HighScoreManager {
public:
	void createHighScore();
	void updateHighScore();
	void printHighScore();
private:
	struct user {
		string username;
		int score;
		string date;
	};
};