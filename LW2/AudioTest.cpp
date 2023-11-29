#include "pch.h"
#include "CppUnitTest.h"
#include "../IS/AudioCollection.hpp"
#include "../IS/AudioFile.hpp"
#include "../IS/MusicTrack.hpp"
#include "../IS/Audiobook.hpp"
#include "../IS/AudioCD.hpp"
#include "../IS/AudioCassette.hpp"
#include "../IS/RadioStation.hpp"
#include "../IS/UserCollection.hpp"
#include "../IS/UserPlaylist.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AudioLibraryTests
{
    TEST_CLASS(AudioFileTests)
    {
    public:

        TEST_METHOD(MusicTrackDisplayInfo)
        {
            MusicTrack musicTrack("Song Title", "Artist Name", 180, "Rock");
            std::ostringstream stream;
            musicTrack.displayInfo();
            std::string expected = "Title: Song Title, Author: Artist Name, Duration: 180s, Genre: Rock\n";
            Assert::AreEqual(expected, stream.str());
        }

        TEST_METHOD(AudiobookDisplayInfo)
        {
            Audiobook audiobook("Book Title", "Author Name", 3600, "Narrator Name");
            std::ostringstream stream;
            audiobook.displayInfo();
            std::string expected = "Title: Book Title, Author: Author Name, Duration: 3600s\n";
            Assert::AreEqual(expected, stream.str());
        }

        TEST_METHOD(AddAndSortAudioFiles)
        {
            AudioCD audioCD("Test CD");
            MusicTrack musicTrack1("Song1", "Artist1", 200, "Pop");
            MusicTrack musicTrack2("Song2", "Artist2", 180, "Rock");
            audioCD.addAudioFile(&musicTrack1);
            audioCD.addAudioFile(&musicTrack2);
            audioCD.sort();

            std::ostringstream stream;
            audioCD.displayInfo();
            std::string expected = "CD Name: Test CD\nTitle: Song2, Author: Artist2, Duration: 180s, Genre: Rock\nTitle: Song1, Author: Artist1, Duration: 200s, Genre: Pop\n";
            Assert::AreEqual(expected, stream.str());
        }

        TEST_METHOD(RemoveAudioFile)
        {
            AudioCD audioCD("Test CD");
            MusicTrack musicTrack1("Song1", "Artist1", 200, "Pop");
            MusicTrack musicTrack2("Song2", "Artist2", 180, "Rock");
            audioCD.addAudioFile(&musicTrack1);
            audioCD.addAudioFile(&musicTrack2);
            audioCD.removeAudioFile(&musicTrack1);

            std::ostringstream stream;
            audioCD.displayInfo();
            std::string expected = "CD Name: Test CD\nTitle: Song2, Author: Artist2, Duration: 180s, Genre: Rock\n";
            Assert::AreEqual(expected, stream.str());
        }

        TEST_METHOD(AddAndFindAudioFileByTitle)
        {
            AudioCollection audioCollection;
            MusicTrack musicTrack("Song1", "Artist1", 200, "Pop");
            audioCollection.addAudioFile(&musicTrack);

            AudioFile* foundFile = audioCollection.findAudioFileByTitle("Song1");

            Assert::IsNotNull(foundFile);
            Assert::AreEqual("Song1", foundFile->title.c_str());
        }

        TEST_METHOD(SortByTitle)
        {
            AudioCollection audioCollection;
            MusicTrack musicTrack1("Song1", "Artist1", 200, "Pop");
            MusicTrack musicTrack2("Song2", "Artist2", 180, "Rock");
            audioCollection.addAudioFile(&musicTrack1);
            audioCollection.addAudioFile(&musicTrack2);
            audioCollection.sort();

            std::ostringstream stream;
            audioCollection.displayInfo();
            std::string expected = "Title: Song1, Author: Artist1, Duration: 200s, Genre: Pop\nTitle: Song2, Author: Artist2, Duration: 180s, Genre: Rock\n";
            Assert::AreEqual(expected, stream.str());
        }


        TEST_METHOD(CountAudioFiles)
        {
            UserCollection userCollection("first");
            MusicTrack musicTrack1("Song1", "Artist1", 200, "Pop");
            MusicTrack musicTrack2("Song2", "Artist2", 180, "Rock");
            userCollection.addAudioFile(&musicTrack1);
            userCollection.addAudioFile(&musicTrack2);

            int count = userCollection.countAudioFiles();

            Assert::AreEqual(2, count);
        }
        TEST_METHOD(FindAudioFileByAuthor)
        {
            UserCollection userCollection("first");
            MusicTrack musicTrack("Song1", "Artist1", 200, "Pop");
            userCollection.addAudioFile(&musicTrack);

            AudioFile* foundFile = userCollection.findAudioFileByAuthor("Artist1");

            Assert::IsNotNull(foundFile);
            Assert::AreEqual("Artist1", foundFile->author.c_str());
        }

        TEST_METHOD(FindAudioFileByGenre)
        {
            UserCollection userCollection("first");
            MusicTrack musicTrack("Song1", "Artist1", 200, "Pop");
            userCollection.addAudioFile(&musicTrack);

            AudioFile* foundFile = userCollection.findAudioFileByGenre("Pop");

            Assert::IsNotNull(foundFile);
            MusicTrack* musicTrackFound = dynamic_cast<MusicTrack*>(foundFile);
            Assert::AreEqual("Pop", musicTrackFound->genre.c_str());
        }

        TEST_METHOD(DisplayInfo1)
        {
            UserPlaylist userPlaylist("My Playlist");
            MusicTrack musicTrack1("Song1", "Artist1", 200, "Pop");
            MusicTrack musicTrack2("Song2", "Artist2", 180, "Rock");
            userPlaylist.addAudioFile(&musicTrack1);
            userPlaylist.addAudioFile(&musicTrack2);

            std::ostringstream stream;
            userPlaylist.displayInfo();
            std::string expected = "Playlist Name: My Playlist\nTitle: Song1, Author: Artist1, Duration: 200s, Genre: Pop\nTitle: Song2, Author: Artist2, Duration: 180s, Genre: Rock\n";
            Assert::AreEqual(expected, stream.str());
        }

        TEST_METHOD(DisplayInfo2)
        {
            RadioStation radioStation("Rock Hits");
            MusicTrack musicTrack1("Song1", "Artist1", 200, "Rock");
            MusicTrack musicTrack2("Song2", "Artist2", 180, "Alternative");
            radioStation.addAudioFile(&musicTrack1);
            radioStation.addAudioFile(&musicTrack2);

            std::ostringstream stream;
            radioStation.displayInfo();
            std::string expected = "Radio Station Name: Rock Hits\nTitle: Song1, Author: Artist1, Duration: 200s, Genre: Rock\nTitle: Song2, Author: Artist2, Duration: 180s, Genre: Alternative\n";
            Assert::AreEqual(expected, stream.str());
        }

        TEST_METHOD(DisplayInfoTest)
        {
            AudioCassette audioCassette("Mix Tape");
            MusicTrack musicTrack1("Song1", "Artist1", 200, "Pop");
            MusicTrack musicTrack2("Song2", "Artist2", 180, "Rock");
            audioCassette.addAudioFile(&musicTrack1);
            audioCassette.addAudioFile(&musicTrack2);

            std::ostringstream stream;
            audioCassette.displayInfo();
            std::string expected = "Cassette Name: Mix Tape\nTitle: Song1, Author: Artist1, Duration: 200s, Genre: Pop\nTitle: Song2, Author: Artist2, Duration: 180s, Genre: Rock\n";
            Assert::AreEqual(expected, stream.str());
        }


        TEST_METHOD(AudioCDSort)
        {
            AudioCD audioCD("Test CD");
            MusicTrack musicTrack1("Song1", "Artist1", 200, "Pop");
            MusicTrack musicTrack2("Song2", "Artist2", 180, "Rock");
            audioCD.addAudioFile(&musicTrack1);
            audioCD.addAudioFile(&musicTrack2);

            audioCD.sort();

            std::ostringstream stream;
            audioCD.displayInfo();
            std::string expected = "CD Name: Test CD\nTitle: Song2, Author: Artist2, Duration: 180s, Genre: Rock\nTitle: Song1, Author: Artist1, Duration: 200s, Genre: Pop\n";
            Assert::AreEqual(expected, stream.str());
        }

        TEST_METHOD(AudioCollectionTest)
        {
            AudioCollection audioCollection;
            MusicTrack musicTrack1("Song1", "Artist1", 200, "Pop");
            MusicTrack musicTrack2("Song2", "Artist2", 180, "Rock");
            audioCollection.addAudioFile(&musicTrack1);
            audioCollection.addAudioFile(&musicTrack2);

            audioCollection.sort();
            std::ostringstream stream;
            audioCollection.displayInfo();
            std::string expected = "Title: Song1, Author: Artist1, Duration: 200s, Genre: Pop\nTitle: Song2, Author: Artist2, Duration: 180s, Genre: Rock\n";
            Assert::AreEqual(expected, stream.str());
        }
    };
}
