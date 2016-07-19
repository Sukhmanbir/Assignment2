#include "User.h"

#include <iostream>

using namespace std;

int main() {

	// login the user
	User user = User();
	user.login();
	cout << "Logged in as " << user.getUsername() << endl;
	


	system("PAUSE");

	return 0;
}
