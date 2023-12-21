#include "Teacher.h"
#include <algorithm>

Course* Teacher::createCourse(std::string title, std::string description, int duration) {
	auto course = new Course();
	course->setTitle(title);
	course->setDescription(description);
	course->setDuration(duration);

	courses.insert(course);

	return course;
}

void Teacher::removeCourse(Course* course) {
	courses.erase(course);
	delete course;
}
Course* Teacher::getCourse(std::string title) const{
	return *std::find_if(courses.begin(), courses.end(), [title](Course* x) { return x->getTitle() == title; });
}