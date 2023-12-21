#include "Student.h"
#include <set>

void Student::addCourse(Course* course){
	courses.push_back(course);
	course->addStudent(this);
}

void Student::removeCourse(Course* course) {
	courses.erase(std::find(courses.begin(), courses.end(), course));
	course->removeStudent(this);
}

void Student::showCourse() const {
	for (auto course : courses)
		std::cout << course->getTitle() << std::endl;
}

const Progress& Student::getProgress() const {
	return progress;
}

const std::vector<Certificate>& Student::getCertificates() const {
	return certificates;
}

void Student::addCertificate(const Certificate& certificate) {
	certificates.push_back(certificate);
}

const std::vector<Course*>& Student::getCourses() const {
	return courses;
}