#pragma once
#include "User.h"
#include "Course.h"
#include <set>

class Teacher : public User
{
private:
	std::set<Course*> courses;
public:
	Course* createCourse(std::string title, std::string description, int duration);

	void removeCourse(Course*);

	Course* getCourse(std::string title) const;
};

