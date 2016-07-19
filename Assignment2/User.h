#pragma once

#include <string>
#include <vector>

using namespace std;


class User {
public:
	User();
	void login();
	void updateUser();
	void deleteUser();
	void setHighScore();
	struct UserStruct {
		string username;
		struct UserInfo {
			string firstName;
			string lastName;
			string city;
			string phone;
		};
		UserInfo userInfo;
	};
	string getUsername();
	void saveUsers();
private:
	vector<UserStruct> userCollection;
	UserStruct activeUser;
	UserStruct getUserInfo();
};