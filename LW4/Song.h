#pragma once
#include <iostream>

class Song {
public:
    Song() : title(""), duration(0) {}

    Song(const std::string& title, int duration) : title(title), duration(duration) {}

    bool operator<=(const Song& other) const;
    bool operator<(const Song& other) const;

private:
    std::string title;
    int duration;
};