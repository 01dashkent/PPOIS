#pragma once
#include "AudioFile.hpp"
#include <string>
#include <iostream>

// Класс для аудиокниги
class Audiobook : public AudioFile {
public:
	std::string narrator;

	Audiobook(const std::string& title, const std::string& author, int duration, const std::string& narrator)
		: AudioFile(title, author, duration), narrator(narrator) {}
};