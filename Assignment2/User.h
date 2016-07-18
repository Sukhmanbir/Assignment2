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
	UserStruct activeUser;
private:
	
	vector<UserStruct> userCollection;
};