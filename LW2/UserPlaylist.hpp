#pragma once
#include "AudioCollection.hpp"
#include <string>
#include <iostream>

class UserPlaylist : public AudioCollection
{
public:
	std::string playlistName;

	UserPlaylist(const std::string& playlistName) : playlistName(playlistName) {}

	void displayInfo() const;
};