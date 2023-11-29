#pragma once
#include "AudioFile.hpp"
#include "ISortable.hpp"
#include "IPlayable.hpp"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>


// Класс для аудио диска
class AudioCD : public ISortable, public IPlayable {
public:
	std::vector<AudioFile*> audioFiles;
	std::string name;

	AudioCD(const std::string& name) : name(name) {}

	void addAudioFile(AudioFile* audioFile);

	void removeAudioFile(AudioFile* audioFile);

	void displayInfo() const;
	
	void play() const override;

	void sort() override;
};