#pragma once
#include <iostream>

// ��������� ��� ���������������
class IPlayable {
public:
	virtual void play() const = 0;
};