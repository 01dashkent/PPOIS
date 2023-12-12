#include "Song.h"

bool Song::operator<=(const Song& other) const {
    return duration <= other.duration;
}
bool Song::operator<(const Song& other) const {
    return duration < other.duration;
}