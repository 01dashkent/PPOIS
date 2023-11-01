#include "AudioItems.h"

namespace AudioItems {

    ItemOfAudio::ItemOfAudio(const std::string& title, int duration) : title(title), duration(duration) {}

    void ItemOfAudio::Play() {
        std::cout << "���������������: " << title << " (" << duration << " ������)" << std::endl;
    }

    std::string ItemOfAudio::GetInfo() const {
        return "�������� " + title + ", ����� ������������: " + std::to_string(duration) + " ������";
    }

    Song::Song(const std::string& title, int duration, const std::string& singer) : ItemOfAudio(title, duration), singer(singer) {}

    void Song::AddSoundLevel(int level) {
        soundLevels.push_back(level);

    }

    void Song::ChangeVolume() {
        if (soundLevels.empty()) {
            std::cout << "��� ������ � ������� ��������� ��� �����: " << title << std::endl;
        }
        else {
            int sum = 0;
            for (int level : soundLevels) {
                sum += level;
            }
            int average = sum / soundLevels.size();
            std::cout << "��������� ��������� ��� �����: " << title << std::endl;
            std::cout << "������� ������� ���������: " << average << std::endl;
        }
        std::cout << "��������� ��������� ��� �����: " << title << std::endl;
    }

    void Song::AddToPlaylist(const std::string& songTitle) {
        playlist.push_back(songTitle);
    }

    void Song::CreatePlaylist() {
        if (playlist.empty()) {
            std::cout << "�������� ���� ��� �����: " << title << std::endl;
        }
        else {
            std::cout << "����������� ��������� ��� �����: " << title << std::endl;
            std::cout << "�������� �������� ��������� �����:" << std::endl;
            for (const std::string& song : playlist) {
                std::cout << song << std::endl;
            }
        }
    }

    void Song::Play() {
        std::cout << "������������ �����(�����): " << title << " �����������: " << singer << " (" << duration << " ������)" << std::endl;
    }

    std::string Song::GetInfo() const {
        return "����� - " + ItemOfAudio::GetInfo() + " , �����������: " + singer;
    }


    Podcast::Podcast(const std::string& title, int duration, const std::string& host) : ItemOfAudio(title, duration), host(host) {}

    void Podcast::AdjustPlaybackSpeed(double speed) {
        playbackSpeed = speed;
        std::cout << "��������� �������� ��������������� ��� ��������: " << title << std::endl;
        std::cout << "����� �������� ���������������: " << playbackSpeed << std::endl;
    }

    void Podcast::SetPlaybackError(bool error) {
        playbackError = error;
    }

    void Podcast::DownloadEpisode() {
        std::cout << "�������� ������� ��������: " << title << std::endl;

        if (playbackError) {
            std::cout << "������ �� ����� ��������������� �������: " << title << std::endl;
        }
        else {
            std::cout << "������ �������� �������." << std::endl;
        }
    }

    void Podcast::Play() {
        std::cout << "���������� �������: " << title << " ���������� ��: " << host << " (" << duration << " ������)" << std::endl;
    }

    std::string Podcast::GetInfo() const {
        return "������� - " + ItemOfAudio::GetInfo() + " , �����: " + host;

    }

    AudioBook::AudioBook(const std::string& title, int duration, const std::string& author) : ItemOfAudio(title, duration), author(author), narrator("") {}

    void AudioBook::ChangeNarrator(const std::string& newNarrator) {
        narrator = newNarrator;
        std::cout << "������� ��������� ��� ���������� " << title << " �� " << narrator << std::endl;
    }

    void AudioBook::AddToLibrary() {
        library.push_back(title);
        int position = library.size();  
        std::cout << "���������� ���������� � ����������: " << title << " (�������: " << position << ")" << std::endl;
    }

    void AudioBook::Play() {
        std::cout << "������������� ����������: " << title << " �����: " << author << " ��������: " << narrator << " (" << duration << " ������)" << std::endl;
    }

    std::string AudioBook::GetInfo() const {
        return "���������� - " + ItemOfAudio::GetInfo() + " , �����: " + author + " , ��������: " + narrator;
    }

    Radio::Radio(const std::string& title, int duration, const std::string& station) : ItemOfAudio(title, duration), station(station), selectedEqualizer(""), isRecording(false) {}

    void Radio::AdjustEQ(const std::string& equalizer) {
        selectedEqualizer = equalizer;
        std::cout << "��������� ���������� ��� ������������: " << station << std::endl;
        std::cout << "������ ����������: " << selectedEqualizer << std::endl;
    }

    void Radio::Record() {
        if (isRecording) {
            std::cout << "��������� ������ �������������: " << title << std::endl;
            isRecording = false;
        }
        else {
            std::cout << "������ ������ �������������: " << title << std::endl;
            isRecording = true;
        }
    }

    void Radio::Play() {
        std::string recordingStatus = isRecording ? "������ �������" : "������ �� �������";
        std::cout << "���������� �������������: " << title << " �������: " << station << " (" << duration << " ������)" << std::endl;
        std::cout << "������ ������: " << recordingStatus << std::endl;
    }

    std::string Radio::GetInfo() const {
        std::string recordingStatus = isRecording ? "������ �������" : "������ �� �������";
        return "������������� - " + ItemOfAudio::GetInfo() + " , �������: " + station + " , ��������� ����������: " + selectedEqualizer + " , " + recordingStatus;
    }

    SoundEffect::SoundEffect(const std::string& title, int duration) : ItemOfAudio(title, duration) {}

    void SoundEffect::AdjustPitch() {
        std::cout << "��������� ������ ���� ��� ��������� �������: " << title << std::endl;
    }

    void SoundEffect::LoopEffect() {
        std::cout << "��������� �������� ������: " << title << std::endl;
    }

    void SoundEffect::Play() {
        std::cout << "������������� �������� ������: " << title << " (" << duration << " ������)" << std::endl;
    }

    std::string SoundEffect::GetInfo() const {
        return "�������� ������ - " + ItemOfAudio::GetInfo();
    }

    Interview::Interview(const std::string& title, int duration, const std::string& interviewer)
        : ItemOfAudio(title, duration), interviewer(interviewer), shouldAskQuestions(true), sendText(false), sendAudio(false) {}

    void Interview::SetSendText(bool send) {
        sendText = send;
    }

    void Interview::SetSendAudio(bool send) {
        sendAudio = send;
    }

    void Interview::ShareInterview() {
        std::cout << "���������� ��������: " << title << std::endl;
        if (sendText) {
            std::cout << "��������� �������" << std::endl;
        }
        if (sendAudio) {
            std::cout << "��������� ������������" << std::endl;
        }
    }

    void Interview::Play() {
        std::string questionsStatus = shouldAskQuestions ? "�������� �������" : "������� ��������";
        std::cout << "���������� ��������: " << title << " ����������: " << interviewer << " (" << duration << " ������)" << std::endl;
        std::cout << "������ ��������� ��������: " << questionsStatus << std::endl;
    }

    std::string Interview::GetInfo() const {
        std::string questionsStatus = shouldAskQuestions ? "�������� �������" : "������� ��������";
        return "�������� - " + ItemOfAudio::GetInfo() + " , ����������: " + interviewer + " , ������� ��������: " + (sendText ? "�����" : "") + (sendAudio ? "�����������" : "");
    }


    LiveMusic::LiveMusic(const std::string& title, int duration, const std::string& venue)
        : ItemOfAudio(title, duration), venue(venue) {}

    void LiveMusic::AddTicketPrice(double price) {
        ticketPrices.push_back(price);
    }

    double LiveMusic::FindMinTicketPrice() {
        if (ticketPrices.empty()) {
            return 0;
        }
        return *std::min_element(ticketPrices.begin(), ticketPrices.end());
    }

    double LiveMusic::FindMaxTicketPrice() {
        if (ticketPrices.empty()) {
            return 0;
        }
        return *std::max_element(ticketPrices.begin(), ticketPrices.end());
    }

    void LiveMusic::BuyTickets() {
        double minPrice = FindMinTicketPrice();
        double maxPrice = FindMaxTicketPrice();

        std::cout << "������� ������� �� ������� " << title << " � " << venue << std::endl;
        std::cout << "����������� ���� ������: " << minPrice << std::endl;
        std::cout << "������������ ���� ������: " << maxPrice << std::endl;
    }

    void LiveMusic::Play() {
        std::cout << "���������� �������: " << title << " �����: " << venue << " (" << duration << " ������)" << std::endl;
    }

    int main() {

        return 0;
    }
}