#pragma once
#include "MusicTrack.hpp"
#include <string>
#include <iostream>

// Класс для песни
class Song : public MusicTrack {
public:
	Song(const std::string& title, const std::string& author, int duration, const std::string& genre)
		: MusicTrack(title, author, duration, genre) {}
};