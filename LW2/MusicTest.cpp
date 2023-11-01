#include "pch.h"
#include "CppUnitTest.h"
#include "../AudioItems/AudioItems.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AudioItems;
using namespace std;

TEST_CLASS(ItemOfAudioTests)
{
public:

    TEST_METHOD(ItemOfAudio_Play)
    {
        ItemOfAudio item("Test Audio", 120);

        item.Play();
    }

    TEST_METHOD(ItemOfAudio_GetInfo)
    {
        ItemOfAudio item("Test Audio", 120);
        std::string info = item.GetInfo();
        std::string expectedInfo = "Название Test Audio, Время проигрывания: 120 секунд";
        Assert::AreEqual(expectedInfo, info);
    }
};
TEST_CLASS(SongTests)
{
public:

    TEST_METHOD(Song_CreatePlaylist)
    {
        Song mySong("My Song", 240, "SingerName");
        mySong.AddToPlaylist("Song1");
        mySong.AddToPlaylist("Song2");
        mySong.CreatePlaylist();
    }
};
    
    TEST_CLASS(SoundEffectTests)
    {
    public:
        TEST_METHOD(TestAdjustPitch)
        {
            SoundEffect mySoundEffect("My Sound Effect", 15);
            mySoundEffect.AdjustPitch();
        }

        TEST_METHOD(TestLoopEffect)
        {
            SoundEffect mySoundEffect("My Sound Effect", 10);
            mySoundEffect.LoopEffect();
        }
    };
    TEST_CLASS(InterviewTests)
    {
    public:
        
        TEST_METHOD(TestShareInterview)
        {
            Interview myInterview("My Interview", 300, "Interviewer");
            myInterview.SetSendText(true);
            myInterview.SetSendAudio(true);
            myInterview.ShareInterview();
        }
    };
    TEST_CLASS(LiveMusicTests)
    {
    public:
        TEST_METHOD(TestBuyTickets)
        {
            LiveMusic myLiveMusic("Concert", 180, "Venue");
            myLiveMusic.AddTicketPrice(50.0);
            myLiveMusic.AddTicketPrice(75.0);
            myLiveMusic.BuyTickets();
        }
    };

