#pragma once
#include "AudioCollection.hpp"
#include <string>
#include <iostream>

class UserCollection : public AudioCollection {
public:
	std::string userName;

	UserCollection(const std::string& userName) : userName(userName) {}

	void displayInfo() const;
};