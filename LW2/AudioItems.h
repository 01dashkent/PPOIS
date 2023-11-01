#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace AudioItems {
    class ItemOfAudio {
    protected:
        std::string title;
        int duration;

    public:
        ItemOfAudio(const std::string& title, int duration);

        virtual void Play();
        virtual std::string GetInfo() const;
    };

    class Song : public ItemOfAudio {
    private:
        std::string singer;
        std::vector<int> soundLevels;
        std::vector<std::string> playlist;
    public:
        Song(const std::string& title, int duration, const std::string& singer);

        void AddSoundLevel(int level);
        void ChangeVolume();
        void AddToPlaylist(const std::string& songTitle);
        void CreatePlaylist();

        void Play() override;
        std::string GetInfo() const override;
    };

    class Podcast : public ItemOfAudio {
    private:
        std::string host;
        double playbackSpeed;
        bool playbackError;

    public:
        Podcast(const std::string& title, int duration, const std::string& host);

        void AdjustPlaybackSpeed(double speed);
        void SetPlaybackError(bool error);
        void DownloadEpisode();

        void Play() override;
        std::string GetInfo() const override;
    };

    class AudioBook : public ItemOfAudio {
    private:
        std::string author;
        std::string narrator;
        std::vector<std::string> library;

    public:
        AudioBook(const std::string& title, int duration, const std::string& author);

        void ChangeNarrator(const std::string& newNarrator);
        void AddToLibrary();

        void Play() override;
        std::string GetInfo() const override;
    };

    class Radio : public ItemOfAudio {
    private:
        std::string station;
        std::string selectedEqualizer;
        bool isRecording;

    public:
        Radio(const std::string& title, int duration, const std::string& station);

        void AdjustEQ(const std::string& equalizer);
        void Record();

        void Play() override;
        std::string GetInfo() const override;
    };

    class SoundEffect : public ItemOfAudio {
    public:
        SoundEffect(const std::string& title, int duration);

        void AdjustPitch();
        void LoopEffect();

        void Play() override;
        std::string GetInfo() const override;
    };

    class Interview : public ItemOfAudio {
    private:
        std::string interviewer;
        bool shouldAskQuestions;
        bool sendText;
        bool sendAudio;

    public:
        Interview(const std::string& title, int duration, const std::string& interviewer);

        void SetSendText(bool send);
        void SetSendAudio(bool send);
        void ShareInterview();

        void Play() override;
        std::string GetInfo() const override;
    };

    class LiveMusic : public ItemOfAudio {
    private:
        std::string venue;
        std::vector<double> ticketPrices;

    public:
        LiveMusic(const std::string& title, int duration, const std::string& venue);

        void AddTicketPrice(double price);
        double FindMinTicketPrice();
        double FindMaxTicketPrice();
        void BuyTickets();

        void Play() override;
    };
}