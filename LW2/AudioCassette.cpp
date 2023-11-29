#include "AudioCassette.hpp"
#include <iostream>

void AudioCassette::displayInfo() const {
	std::cout << "Cassette Name: " << name << "\n";
	AudioCollection::displayInfo();
}