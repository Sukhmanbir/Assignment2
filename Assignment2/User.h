#pragma once

#include <string>
#include <vector>

using namespace std;


class User {
public:
	User();
	void login();
	void checkIfUserExists();
	void updateUserList();
	void deleteUser();
	void setHighScore();
private:
	struct UserStruct {
		string username;
		string password;
		struct UserInfo {
			string firstName;
			string lastName;
			string city;
			string phone;
		};
		UserInfo userInfo;
	};
	vector<UserStruct> userCollection;
};