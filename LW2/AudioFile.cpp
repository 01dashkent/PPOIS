#include "AudioFile.hpp"
#include <iostream>


void AudioFile::play() const {
	std::cout << "Playing: " << title << " by " << author << "\n";
}

void AudioFile::displayInfo() const {
	std::cout << "Title: " << title << ", Author: " << author << ", Duration: " << duration << "s\n";
}