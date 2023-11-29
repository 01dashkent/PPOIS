#pragma once
#include "IPlayable.hpp"
#include <iostream>

using namespace std;

// Базовый класс для аудио файла
class AudioFile : public IPlayable {
public:
	std::string title;
	std::string author;
	int duration; // в секундах

	AudioFile(const std::string& title, const std::string& author, int duration)
		: title(title), author(author), duration(duration) {}

	void play() const override;

	virtual void displayInfo() const;
};
