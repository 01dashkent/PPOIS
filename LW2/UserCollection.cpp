#include "UserCollection.hpp"
#include <iostream>

void UserCollection::displayInfo() const {
	std::cout << "User Collection Name: " << userName << "\n";
	AudioCollection::displayInfo();
}