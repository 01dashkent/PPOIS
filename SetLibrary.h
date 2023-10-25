#pragma once
#include <string>
#include <vector>

namespace SetLibrary {
	class Set {
	private:
		std::vector<Set> subsets;
		std::string element;
		Set recursiveCreation(std::string, int*);
	public:
		Set();
		Set(std::string);
		Set(char*);
		bool isEmpty() const;
		void push(char);
		void push(std::string);
		void push(char*);
		void push(Set);
		void pop(char);
		void pop(std::string);
		void pop(char*);
		void pop(Set);
		int cardinality() const;
		Set operator[](int) const;
		Set operator+(Set) const;
		Set& operator+=(Set);
		Set operator*(Set) const;
		Set& operator*=(Set);
		Set operator-(Set) const;
		Set& operator-=(Set);
		void boolean(std::vector<std::string>*, Set, int) const;
		std::vector<Set> getSubsets() const;
		std::string getElement() const;
		void print() const;
		bool checkPresence(std::string) const;
		bool checkPresence(Set) const;
		void getSubsetsToString(std::string*) const;
	};
}