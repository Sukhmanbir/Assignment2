#pragma once

#include <string>

#include "User.h"
#include "FileUtility.h"
#include "Util.h"


User::User() {

	// load the user file
	FileUtility fu = FileUtility();
	string userFile = fu.file_load("users.txt");
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
		if (userInfoString.size() != 5) {
			continue;
		}

		// holds the user info
		UserStruct us = UserStruct();
		us.username = userInfoString[0];
		us.userInfo.city = userInfoString[1];
		us.userInfo.phone = userInfoString[2];
		us.userInfo.firstName = userInfoString[3];
		us.userInfo.lastName = userInfoString[4];

		// add to the user collection
		userCollection.push_back(us);

		counter++;
	}

}

// login a new user or register an account and then log them in
void User::login() {

	// get the username
	cout << "Please enter your username: ";
	string usernamePrompt;
	getline(cin, usernamePrompt);
	
	// normalize the input
	Util u = Util();
	u.lowercase(usernamePrompt);

	// see if the user already exists
	int counter = 0;
	for (auto i = userCollection.begin(); i < userCollection.end(); i++) {

		// set the active user
		if (userCollection[counter].username == usernamePrompt) {
			activeUser = userCollection[counter];
			return;
		}

		counter++;
	}

	// create a new user and add them to the vector
	cout << endl << "No user with the name " << usernamePrompt << " found." << endl;
	cout << "Please register as a new user in order to continue." << endl << endl;
	UserStruct userStruct = getUserInfo();
	userStruct.username = usernamePrompt;
	userCollection.push_back(userStruct);
	activeUser = userStruct;
	saveUsers();
}

// gets the users information
User::UserStruct User::getUserInfo() {

	UserStruct userStruct = UserStruct();

	cout << "Please enter your first name: ";
	string firstname;
	getline(cin, userStruct.userInfo.firstName);

	cout << "Please enter your last name: ";
	string lastname;
	getline(cin, userStruct.userInfo.lastName);

	cout << "Please enter your city: ";
	string city;
	getline(cin, userStruct.userInfo.city);

	cout << "Please enter your phone number: ";
	string phone;
	getline(cin, userStruct.userInfo.phone);

	return userStruct;
}

string User::getUsername() {
	return activeUser.username;
}

void User::saveUsers() {

	vector<string> userVector;
	int counter = 0;
	for (auto i = userCollection.begin(); i < userCollection.end(); i++) {
		string contents;
		contents += userCollection[counter].username;
		contents += "," + userCollection[counter].userInfo.firstName;
		contents += "," + userCollection[counter].userInfo.lastName;
		contents += "," + userCollection[counter].userInfo.city;
		contents += "," + userCollection[counter].userInfo.phone;
		userVector.push_back(contents);

		counter++;
	}

	FileUtility fu = FileUtility();
	fu.file_write("users.txt", userVector);

}

void User::checkIfUserExists() {

}

void User::updateUserList() {

}

void User::deleteUser() {

}

void User::setHighScore() {

}