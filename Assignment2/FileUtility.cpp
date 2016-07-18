#include <sstream>
#include <fstream>
#include "FileUtility.h"

string FileUtility::file_load(string file_name) {

	// load file contents into stream
	std::ifstream ifs;

	if (!ifs) {
		// do error here
	}

	ifs.open(file_name, std::ifstream::in);

	// return the stream as a string4
	stringstream sstr;
	sstr << ifs.rdbuf();
	return sstr.str();

}

bool FileUtility::file_write(string file_name, vector<string> contents) {

	// build file contents
	string fileContents;
	int index = 0;
	for (auto i = contents.begin(); i != contents.end(); i++) {
		fileContents += contents[index] + "\n";
		index++;
	}

	// open file and write contents
	std::ofstream fs;
	fs.open(file_name);
	fs << fileContents;
	fs.close();

	return true;

}
