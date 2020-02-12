// Xavier Gonzalez
// Applied Programming Languages
// 2/13/2020

#include <iostream>
#include <fstream>
#include <string>

//Initialized Functions
void initialFile(std::string fn);
void finalFile(std::string fn);

// Initialized Variables
std::fstream file;
std::string filename;
std::string word;
std::string newFile = "filestats.txt";
std::string longestWord = "";
std::string uChoice = "y";

void initialFile(std::string fn) {
	// Opens initial file
	file.open(fn, std::ios::in);

	// If file wasn't open successfully
	if (!file) {
		std::cout << "File did not open successfully. Please try again." << std::endl;
		exit(1);
	}
	// Creates and appends words from existing file to this one.
	std::ofstream nFile(newFile);
	while (file >> word) {
		nFile << word << ' ';
	}
	file.close();
	nFile.close();
}

void finalFile(std::string fn) {

	// Initialized Variables
	std::string lWord;
	int nWords = 0;
	int nCharInWord = 0;

	// Opens new file
	file.open(fn, std::ios::in);
	// grabs one word at a time and analyzes it
	while(file >> word) {
		// Counts how many words include the letter 'e'
		std::size_t letter = word.find("e");
		if (letter != std::string::npos) {
			nWords += 1;
			lWord = word;
		}

		// Finds the longest word with 'e'
		if (lWord.length() > longestWord.length()) {
			longestWord = lWord;
		}
	}

	// Counts how many characters is in the longest word with the
	// letter 'e'
	nCharInWord = longestWord.length();
	std::cout << "\nNumber of words where e appears: " << nWords << std::endl;
	std::cout << "Longest word with e: " << longestWord << std::endl;
	std::cout << "Number of characters in longest word with e: " << nCharInWord << std::endl;

	// closes file
	file.close();
}

int main() {

	std::cout << "Welcome to the File Words Analyzer!" << std::endl;

    // do-while while uChoice is 'y'. Until user says no to opening another file.
	do {
		std::cout << "\nEnter name of file: ";
		std::cin >> filename;
		std::cin.ignore(100,'\n');

		initialFile(filename);
		finalFile(newFile);

        // Asks user if they would want to try again.
		std::cout << "\nWould you like to try another file? (y/n): " << std::endl;
		std::cin >> uChoice;

        // If user types in 'n', the program exits.
		if (uChoice == "n") {
			std::cout << "Good bye!" << std::endl;
			exit(1);
		}

	} while (uChoice == "y");
	return 0;
}
