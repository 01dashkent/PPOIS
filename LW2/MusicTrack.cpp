#include "MusicTrack.hpp"
#include <iostream>

void MusicTrack::displayInfo() const {
	std::cout << "Title: " << title << ", Author: " << author << ", Duration: " << duration << "s, Genre: " << genre << "\n";
}