#include "SetLibrary.h"
#include <iostream>

namespace SetLibrary {
	Set::Set() {};

	Set::Set(std::string input) {
		if (input.size() == 1) {
			element = input[0];
			return;
		}
		if (input.size() == 2 && input[0] == '{' && input[1] == '}') {
			return;
		}
		else if (input.size() == 2) {
			throw std::runtime_error("invalid input");
		}
		std::string temp;
		for (int i = 1; i < input.size() - 1; i++) {
			switch (input[i]) {
			case '{':
				push(recursiveCreation(input, &i));
				temp = "";
				break;
			case ',':
				push(Set(temp[0]));
				temp = "";
				break;
			default:
				temp += input[i];
				break;
			}
		}
		if (subsets.size() == 0) {
			push(Set((char)temp[0]));
		}
		else if (subsets.size() != 0 && temp != "") {
			push(Set((char)temp[0]));
		}
	}

	Set::Set(char* input) {
		std::string stringInput(input);
		*this = Set(stringInput);
	}

	Set::Set(char input) {
		element = input;
	}

	Set Set::recursiveCreation(std::string input, int* position) {
		(*position)++;
		if (input[*position] == '}') {
			return Set();
		}
		Set element;
		std::string temp;
		for (int i = *position; i < input.size() - 1; i++) {
			switch (input[i])
			{
			case '{':
				*position = i;
				element.push(recursiveCreation(input, position));
				break;
			case ',':
				element.push(Set(temp[0]));
				temp = "";
				break;
			case '}':
				element.push(Set(temp[0]));
				*position = i + 1;
				return element;
			default:
				temp += input[i];
				break;
			}
		}
		throw std::runtime_error("invalid input");
	}

	void Set::push(std::string element) {
		if (checkPresence(element)) {
			return;
		}
		subsets.push_back(Set(element));
		if (subsets.size() > 1) {
			this->element = "";
		}
	}

	void Set::push(char* element) {
		push(std::string(element));
	}

	void Set::push(Set element) {
		if (checkPresence(element)) {
			return;
		}
		subsets.push_back(element);
		if (subsets.size() == 1) {
			this->element = "";
		}
	}

	void Set::push(char element) {
		//std::string elementString = "";
		//elementString+= element;
		//push(elementString);
		push(Set(element));
	}

	void Set::pop(std::string element) {
		int position = -1;
		for (int i = 0; i < subsets.size(); i++)
			if (subsets[i].getElement() == element) {
				position = i;
				break;
			}
		if (position == -1) {
			throw std::runtime_error("element is not found");
		}
		subsets.erase(subsets.begin() + position);
	}

	void Set::pop(char* element) {
		pop(std::string(element));
	}

	void Set::pop(Set element) {
		int position = -1;
		for (int i = 0; i < subsets.size(); i++) {
			if (subsets[i].getElement() == element.getElement() && subsets[i].cardinality() == element.cardinality()) {
				std::vector<Set> sets = subsets[i].getSubsets();
				std::vector<Set> otherSets = element.getSubsets();
				if (sets.size() == 0) {
					position = i;
					break;
				}
				bool found = true;
				for (int j = 0; j < sets.size(); j++)
					if (sets[j].getElement() != otherSets[j].getElement()) {
						found = false;
						return;
					}
				if (found) {
					position = i;
				}
			}
			if (position >= 0)
				break;
		}
		if (position == -1) {
			throw std::runtime_error("element is not found");
		}
		subsets.erase(subsets.begin() + position);
	}

	void Set::pop(char element) {
		std::string stringElement = "";
		stringElement += element;
		pop(stringElement);
	}

	std::vector<Set> Set::getSubsets() const {
		return subsets;
	}

	std::string Set::getElement() const {
		return element;
	}

	bool Set::isEmpty() const {
		return subsets.size() == 0 && element == "";
	}

	int Set::cardinality() const {
		return subsets.size();
	}

	Set Set::operator[](int position) const {
		if (position < 0 || position >= subsets.size()) {
			throw std::runtime_error("invalid index");
		}
		return subsets[position];
	}

	Set Set::operator+(Set other) const {
		Set result = *this;
		std::vector<Set> sets = other.getSubsets();
		for (int i = 0; i < sets.size(); i++)
			result.push(sets[i]);
		return result;
	}

	Set& Set::operator+=(Set other) {
		std::vector<Set> sets = other.getSubsets();
		for (int i = 0; i < sets.size(); i++)
			push(sets[i]);
		return *this;
	}

	Set Set::operator*(Set other) const {
		Set result;
		std::vector<Set> sets = other.getSubsets();
		for (int i = 0; i < sets.size(); i++)
			if (checkPresence(sets[i])) {
				result.push(subsets[i]);
			}
		return result;
	}

	Set& Set::operator*=(Set other) {
		std::vector<int> popPositions;
		std::vector<Set> sets = other.getSubsets();
		for (int i = 0; i < subsets.size(); i++)
			if (!other.checkPresence(subsets[i])) {
				popPositions.push_back(i);
			}
		for (int i = popPositions.size() - 1; i >= 0; i--)
			subsets.erase(subsets.begin() + popPositions[i]);
		return *this;
	}

	Set Set::operator-(Set other) const {
		Set result;
		std::vector<Set> sets = other.getSubsets();
		for (int i = 0; i < sets.size(); i++)
			if (!checkPresence(sets[i])) {
				result.push(subsets[i]);
			}
		return result;
	}

	Set& Set::operator-=(Set other) {
		std::vector<int> popPositions;
		std::vector<Set> sets = other.getSubsets();
		for (int i = 0; i < subsets.size(); i++)
			if (other.checkPresence(subsets[i])) {
				popPositions.push_back(i);
			}
		for (int i = popPositions.size() - 1; i >= 0; i--)
			subsets.erase(subsets.begin() + popPositions[i]);
		return *this;
	}

	void Set::print() const {
		if (isEmpty()) {
			std::cout << "{}";
			return;
		}
		if (subsets.size() == 0) {
			std::cout << element;
			return;
		}
		std::cout << "{";
		int sizeCount = 0;
		for (auto i : subsets) {
			i.print();
			sizeCount++;
			std::cout << (sizeCount == subsets.size() ? "" : ",");
		}
		std::cout << "}";
	}

	void Set::getSubsetsToString(std::string* result) const {
		if (isEmpty()) {
			(*result) += "{}";
			return;
		}
		if (subsets.size() == 0) {
			(*result) += element;
			return;
		}
		(*result) += "{";
		int sizeCount = 0;
		for (auto i : subsets) {
			i.getSubsetsToString(result);
			sizeCount++;
			(*result) += (sizeCount == subsets.size() ? "" : ",");
		}
		(*result) += "}";
	}

	bool Set::checkPresence(std::string element) const {
		for (int i = 0; i < subsets.size(); i++)
			if (subsets[i].getElement() == element) {
				return true;
			}
		return false;
	}

	bool Set::checkPresence(Set element) const {
		for (int i = 0; i < subsets.size(); i++)
			if (subsets[i].getElement() == element.getElement() && subsets[i].cardinality() == element.cardinality()) {
				std::vector<Set> sets = subsets[i].getSubsets();
				std::vector<Set> otherSets = element.getSubsets();
				if (sets.size() == 0) {
					return true;
				}
				for (int j = 0; j < sets.size(); j++)
					if (sets[j].getElement() != otherSets[j].getElement()) {
						return false;
					}
				return true;
			}
		return false;
	}

	Set Set::boolean() const {
		Set result;
		if (subsets.size() == 0) {
			result.push(Set());
			result.push(element);
			return result;
		}
		int subsetsCount = pow(2, (int)subsets.size());
		for (int i = 0; i < subsetsCount; i++) {
			Set temp;
			for (int j = 0; j < subsets.size(); j++)
				if (i & (1 << j))
					temp.push(subsets[j]);
			result.push(temp);
			//temp.print();
		}
		return result;
	}
}
