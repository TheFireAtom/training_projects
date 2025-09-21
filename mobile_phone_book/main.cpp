#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <utility>

// Console font color changing setup
struct Color {
	std::string name;
	std::string code;
};

// A collection of common colors using ANSI escape codes
// The codes are strings that the console interprets to change color
const Color RESET    = {"Reset", "\033[0m"};
const Color BLACK    = {"Black", "\033[30m"};
const Color RED      = {"Red", "\033[31m"};
const Color GREEN    = {"Green", "\033[32m"};
const Color YELLOW   = {"Yellow", "\033[33m"};
const Color BLUE     = {"Blue", "\033[34m"};
const Color MAGENTA  = {"Magenta", "\033[35m"};
const Color CYAN     = {"Cyan", "\033[36m"};
const Color WHITE    = {"White", "\033[37m"};

void set_text_color(const Color& color) {
	std::cout << color.code;
}

struct UserData {		
	long long phoneNumber;
	long long tempNumber;
	std::string name;
	std::string surname;
};

std::unordered_map<long long, std::string> phoneBook;

void startScreen() {
	set_text_color(GREEN);
	std::cout << "Welcome to the adress book database." << std::endl;
	std::cout << "In this database, you can create, change and delete specific user" << std::endl;
	set_text_color(RED);
	std::cout << "So, what do you want to do? Please, write a number: " << std::endl; 
	set_text_color(BLUE);
	std::cout << "1. Add user\n2. Change user\n3. Delete user" << std::endl; 
	set_text_color(YELLOW);
	std::cout << "To leave this menu, press ctrl + c" << std::endl;
	//set_text_color(RESET);
}

void choiceOne(const UserData& user) {
	set_text_color(YELLOW);
	std::string fullName = user.name + " " + user.surname;
	phoneBook.insert({user.phoneNumber, fullName});
	// system("cls");
	std::cout << "\nNew user was added to the phone book" << std::endl;
	std::cout << "Full name: " << fullName << "\nPhone number: " << user.phoneNumber << std::endl;
	std::cout << "\n";
}

void choiceTwo(UserData& user) {
	auto it = phoneBook.find(user.phoneNumber);

	if (it != phoneBook.end()) {
		phoneBook.erase(it);
		std::string fullName = user.name + " " + user.surname;
		if (fullName == "S S" ) {   //|| fullName == user.name + " S" || fullName == "S " + user.surname
			fullName = it->second;
		} else if ()

		else if (user.phoneNumber != 0) {
			user.phoneNumber = user.tempNumber;
		}
		phoneBook.insert({user.phoneNumber, fullName});
		// it->first = user.phoneNumber;
		// it->second = fullName;
		std::cout << "The change was successful. New user data: " << std::endl;
		std::cout << "Full name: " << fullName << "\nPhone number: " << user.phoneNumber << std::endl;
		std::cout << "\n";
	} else {
		std::cout << "User with that phone number not found " << std::endl;
	}
}

void choiceThree() {
	system("cls");
	std::cout << "choiceThree";
}

UserData dataChoiceOne() {
	UserData user;
	set_text_color(MAGENTA);
	std::cout << "Write name, surname and phone number of a user: " << std::endl;
	std::cout << "Name: ";
	std::cin >> user.name;
	std::cout << "Surname: ";
	std::cin >> user.surname;
	std::cout << "Phone number (in this format: 89999999999): ";
	std::cin >> user.phoneNumber;

	return user;
}

UserData dataChoiceTwo() {
	UserData user;

	std::cout << "Write parameters that you want to change. If you don't want to change something, write 'S' symbol when needed." << std::endl;

	set_text_color(MAGENTA);
	// std::cout << "Find the phone number of user that you want to change: " << std::endl;
	// std::cin >> user.phoneNumber;
	// auto it = phoneBook.find(user.number);

	std::cout << "Write name, surname and phone number of a user: " << std::endl;
	std::cout << "New name: ";
	std::cin >> user.name;
	std::cout << "New surname: ";
	std::cin >> user.surname;
	std::cout << "Existing phone number that you want to change :(in this format: 89999999999): ";
	std::cin >> user.phoneNumber;
	std::cout << "New phone number: ";
	std::cin >> user.tempNumber;
	std::cout << "\n";

	return user;
}
	
void startOptions() {
 	int choice;
 	std::cout << "\n";
 	std::cin >> choice;
 	std::cout << "\n";
 	UserData user;
 	switch(choice) {
 		case 1:
 			user = dataChoiceOne();
 			choiceOne(user);
 			break;
 		case 2:
 			user = dataChoiceTwo();
 			choiceTwo(user);
 			break;
 		case 3:
 			choiceThree();
 			break;
 		default: 
 			std::cout << "Please, write a number to make a choice!" << std::endl;
 	} 
}

void userUI() {
	startScreen();
	startOptions();
}

int main() {
	bool isRunning = true;

	userUI();
	

	while(isRunning) {
		userUI();
	}

	//system("cls");
	
	return 0;
}