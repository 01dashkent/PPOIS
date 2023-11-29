#include "AudioCD.hpp"
#include <iostream>

void AudioCD::addAudioFile(AudioFile* audioFile) {
	audioFiles.push_back(audioFile);
}

void AudioCD::removeAudioFile(AudioFile* audioFile) {
	audioFiles.erase(std::remove(audioFiles.begin(), audioFiles.end(), audioFile), audioFiles.end());
}

void AudioCD::displayInfo() const {
	std::cout << "CD Name: " << name << "\n";
	for (const auto& audioFile : audioFiles) {
		audioFile->displayInfo();
	}
}

void AudioCD::play() const {
	std::cout << "Playing the entire CD: " << name << "\n";
	for (const auto& audioFile : audioFiles) {
		audioFile->play();
	}
}

void AudioCD::sort() {
	std::sort(audioFiles.begin(), audioFiles.end(), [](AudioFile* a, AudioFile* b) {
		return a->duration < b->duration;
		});
}