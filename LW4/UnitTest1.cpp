#include "pch.h"
#include "CppUnitTest.h"
#include "Song.h"
#include "BozoSort.h"
#include "MergeSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSorting
{
    TEST_CLASS(SortingTests)
    {
    public:

        TEST_METHOD(MergeSort_SortsSongs)
        {
            std::vector<Song> songs = {
                {"Song A", 180},
                {"Song B", 120},
                {"Song C", 240},
                {"Song D", 200},
            };

            mergeSort(songs, 0, songs.size() - 1);

            for (size_t i = 1; i < songs.size(); ++i) {
                Assert::IsTrue(songs[i - 1] < songs[i]);
            }
        }

        TEST_METHOD(BozoSort_SortsSongs)
        {
            std::vector<Song> songs = {
                {"Song A", 180},
                {"Song B", 120},
                {"Song C", 240},
                {"Song D", 100},
            };

            bozoSort(songs);

            for (size_t i = 1; i < songs.size(); ++i) {
                Assert::IsTrue(songs[i - 1] < songs[i]);
            }
        }
    };
}
