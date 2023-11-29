#include "UserPlaylist.hpp"
#include <iostream>

void UserPlaylist::displayInfo() const {
	std::cout << "Playlist Name: " << playlistName << "\n";
	AudioCollection::displayInfo();
}
