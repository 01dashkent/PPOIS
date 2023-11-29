#pragma once
#include "ISortable.hpp"
#include "IPlayable.hpp"
#include "AudioFile.hpp"
#include <vector>
#include <algorithm>
#include <iostream>


// Класс для аудио коллекции
class AudioCollection : public ISortable, public IPlayable {
public:
	std::vector<AudioFile*> audioFiles;

	void addAudioFile(AudioFile* audioFile);

	void removeAudioFile(AudioFile* audioFile);

	void displayInfo() const;

	void play() const override;

	void sort() override;

	int countAudioFiles() const;

	AudioFile* findAudioFileByTitle(const std::string& title) const;

	AudioFile* findAudioFileByAuthor(const std::string& author) const;

	AudioFile* findAudioFileByGenre(const std::string& genre) const;
};