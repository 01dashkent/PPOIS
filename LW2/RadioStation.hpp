#pragma once
#include "AudioCollection.hpp"
#include <string>
#include <iostream>

class RadioStation : public AudioCollection {
public:
	std::string stationName;

	RadioStation(const std::string& stationName) : stationName(stationName) {}

	void displayInfo() const;
};