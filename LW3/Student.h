#pragma once
#include "User.h"
#include "Course.h"
#include <vector>
#include <memory>
#include "Progress.h"
#include "Certificate.h"

class Student : public User {
private:
	std::vector<Course*> courses;
	Progress progress;
	std::vector<Certificate> certificates;

public:
	~Student() {
		for (auto course : courses)
			removeCourse(course);
	}
	void addCourse(Course* course);

	void removeCourse(Course* course);

	void showCourse() const;

	const Progress& getProgress() const;

	const std::vector<Certificate>& getCertificates() const;

	void addCertificate(const Certificate& certificate);

	const std::vector<Course*>& getCourses() const;
};