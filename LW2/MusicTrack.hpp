#pragma once
#include "AudioFile.hpp"
#include <iostream>

// Класс для музыкального трека
class MusicTrack : public AudioFile {
public:
	std::string genre;

	MusicTrack(const std::string& title, const std::string& author, int duration, const std::string& genre)
		: AudioFile(title, author, duration), genre(genre) {}

	void displayInfo() const override;
};
