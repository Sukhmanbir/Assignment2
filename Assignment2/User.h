#pragma once

#include <string>

using namespace std;


class User {
public:
	void login();
	void checkIfUserExists();
	void updateUserList();
	void deleteUser();
	void setHighScore();
private:
	struct user {
		string username;
		struct userInfo {
			string firstName;
			string lastName;
			string email;
			string phone;
		};
	};
};