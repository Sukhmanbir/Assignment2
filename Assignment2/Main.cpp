#include "User.h"
#include "Menu.h"

#include <iostream>

using namespace std;

int main() {

	// login the user
	User user = User();
	user.login();
	cout << "Logged in as " << user.getUsername() << endl;
	
	vector<string> options = vector<string>();
	options.push_back("Set score");
	options.push_back("Show high score");
	options.push_back("Update user");
	options.push_back("Delete user");

	// enter main program loop
	while (true) {

		Menu m = Menu("Please select an option", options);
		int response = m.getPromptResponse();
		cout << response;
		// exit the program if requested
		if (response == -1) {
			exit(EXIT_SUCCESS);
		}

		// set a new high score
		if (response == 0) {
			cout << "set a high score" << endl;

			// show the current high score
		} else if (response == 1) {
			cout << "show the high score" << endl;

			// update the user
		} else if (response == 2) {
			user.updateUser();

			// delete the user
		} else if (response == 3) {
			user.deleteUser();
			cout << "You have been removed from the system" << endl;
			system("PAUSE");
			exit(EXIT_SUCCESS);
		}

	}

	system("PAUSE");

	return 0;

}
