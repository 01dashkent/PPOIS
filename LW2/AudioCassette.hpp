#pragma once
#include "AudioCollection.hpp"
#include <string>
#include <iostream>


class AudioCassette : public AudioCollection {
public:
	std::string name;

	AudioCassette(const std::string& name) : name(name) {}

	void displayInfo() const;
};