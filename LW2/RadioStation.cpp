#include "RadioStation.hpp"
#include <iostream>

void RadioStation:: displayInfo() const {
	std::cout << "Radio Station Name: " << stationName << "\n";
	AudioCollection::displayInfo();
}