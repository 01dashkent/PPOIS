#include "BozoSort.h"
#include "Song.h"
#include <cstdlib> 

template <typename T>
bool isSorted(const std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

template void bozoSort(std::vector<int>& arr);
template void bozoSort(std::vector<double>& arr);
template void bozoSort(std::vector<Song>& arr);

template <typename T>
void bozoSort(std::vector<T>& arr) {
    while (!isSorted(arr)) {
        size_t i = rand() % arr.size();
        size_t j = rand() % arr.size();
        std::swap(arr[i], arr[j]);
    }
}

template void bozoSort(std::vector<int>& arr);
template void bozoSort(std::vector<double>& arr);