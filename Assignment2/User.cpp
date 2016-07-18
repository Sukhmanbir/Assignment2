#pragma once

#include <string>

#include "User.h"
#include "FileUtility.h"
#include "Util.h"


User::User() {

	// load the user file
	FileUtility fu = FileUtility();
	string userFile = fu.file_load("users.txt");
	cout << userFile << endl;
	Util u = Util();
	
	// parse the file into users
	vector<string> users = u.splitString(userFile, '\n');
	
	// do nothing if there are no users
	if (users.size() == 0) {
		return;
	}

	// add the users to the user vector
	int counter = 0;
	for (auto i = users.begin(); i < users.end(); i++) {
	
		// parse the user info
		vector<string> userInfoString = u.splitString(users[counter], ',');

		// skip user if ill-formatted
		if (userInfoString.size() != 6) {
			continue;
		}

		// holds the user info
		UserStruct us = UserStruct();
		us.username = userInfoString[0];
		us.password = userInfoString[1];
		us.userInfo.city = userInfoString[2];
		us.userInfo.phone = userInfoString[3];
		us.userInfo.firstName = userInfoString[4];
		us.userInfo.lastName = userInfoString[5];

		// add to the user collection
		userCollection.push_back(us);

		counter++;
	}

}

void User::login() {

}

void User::checkIfUserExists() {

}

void User::updateUserList() {

}

void User::deleteUser() {

}

void User::setHighScore() {

}