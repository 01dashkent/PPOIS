#pragma once
#include <iostream>

// Интерфейс для воспроизведения
class IPlayable {
public:
	virtual void play() const = 0;
};