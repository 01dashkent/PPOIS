#include "AudioCollection.hpp"
#include <iostream>
#include "MusicTrack.hpp"
#include <string>

void AudioCollection::addAudioFile(AudioFile* audioFile) {
	audioFiles.push_back(audioFile);
}

void AudioCollection::removeAudioFile(AudioFile* audioFile) {
	audioFiles.erase(std::remove(audioFiles.begin(), audioFiles.end(), audioFile), audioFiles.end());
}

void AudioCollection::displayInfo() const {
	for (const auto& audioFile : audioFiles) {
		audioFile->displayInfo();
	}
}

void AudioCollection::play() const {
	std::cout << "Playing the entire audio collection\n";
	for (const auto& audioFile : audioFiles) {
		audioFile->play();
	}
}

void AudioCollection::sort() {
	std::sort(audioFiles.begin(), audioFiles.end(), [](AudioFile* a, AudioFile* b) {
		return a->title < b->title;
		});
}

int AudioCollection::countAudioFiles() const {
	return audioFiles.size();
}
AudioFile* AudioCollection::findAudioFileByTitle(const std::string& title) const {
	for (const auto& audioFile : audioFiles) {
		if (audioFile->title == title) {
			return audioFile;
		}
	}
	return nullptr; // Если не найдено
}

AudioFile* AudioCollection::findAudioFileByAuthor(const std::string& author) const {
	for (const auto& audioFile : audioFiles) {
		if (audioFile->author == author) {
			return audioFile;
		}
	}
	return nullptr; // Если не найдено
}

AudioFile* AudioCollection::findAudioFileByGenre(const std::string& genre) const {
	for (const auto& audioFile : audioFiles) {
		MusicTrack* musicTrack = dynamic_cast<MusicTrack*>(audioFile);
		if (musicTrack && musicTrack->genre == genre) {
			return audioFile;
		}
	}
	return nullptr; // Если не найдено
}
