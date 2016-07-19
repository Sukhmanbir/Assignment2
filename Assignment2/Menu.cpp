#include "Menu.h"

/**
Loads a prompt and choice into a class variables
@param prompt The menu prompt
@param choices The menu choices the user can select
*/
Menu::Menu(string prompt, vector<string> choices) {
	Menu::menuPrompt = prompt;
	Menu::choices = choices;
	Menu::totalChoices = choices.size();
}

/**
Gets the users repsonse to the prompt.
@return the vector element the user selected (zero-indexed)
*/
int Menu::getPromptResponse() {
	showPrompt();
	return prompt();
}

/**
Displays the prompt provided to the constructor
*/
void Menu::showPrompt() {
	// show the prompt
	cout << endl << Menu::menuPrompt << endl;
	cout << '\t' << "[0] Exit program" << endl;

	// show the choices
	int counter = 0;
	for (auto i = Menu::choices.begin(); i != Menu::choices.end(); ++i) {
		counter++;
		std::cout << '\t' << "[" << counter << "] " << *i << endl;
	}
}


/**
Obtains the users response
*/
int Menu::prompt() {

	int choice;
	string input;

	while (true) {

		// show an input caret
		cout << "-> ";

		// get the users input
		getline(cin, input);

		// show invalid input prompt if input is not a valid number
		stringstream myStream(input);
		if (!(myStream >> choice)) {
			showInvalidInputMsg();
			showPrompt();
			continue;
		}

		// show invalid range prompt if number doesn't coorespond to any vector element
		if (choice < 0 || choice > Menu::totalChoices) {
			showInvalidRangeMsg();
			showPrompt();
			continue;
		}

		// exit the loop if the input is a valid choice
		break;
	}

	return --choice;
}

/**
Tells the user that they must enter a number
*/
void Menu::showInvalidInputMsg() {
	cout << endl << "*********************************" << endl;
	cout << "** Please enter a valid number **";
	cout << endl << "*********************************" << endl;
}

/**
Tells the user that they can only enter a number within the specified range
*/
void Menu::showInvalidRangeMsg() {
	cout << endl << "*******************************************" << endl;
	cout << "** Please enter one of the numbers shown **";
	cout << endl << "*******************************************" << endl;
}