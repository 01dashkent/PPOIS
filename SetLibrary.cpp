/**
 * @file SetLibrary.h
 * @brief Description of the library for working with sets.
 */
#include "SetLibrary.h"
#include <iostream>

namespace SetLibrary {
	/**
  * @class Set
  * @brief A class representing a set.
  */
  /**
 * @brief Default constructor. Creates an empty set.
 */
	Set::Set() {};
	/**
		 * @brief A constructor that creates a set from a string.
		 * @param input string representing a set.
		 */
	Set::Set(std::string input) {
		// Realisation of the constructor
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
	/**
		* @brief A constructor that creates a set from a C string.
		* @param input C-string representing a set.
		*/
	Set::Set(char* input) {
		// Realisation of the constructor
		std::string stringInput(input);
		*this = Set(stringInput);
	}
	/**
		 * @brief A constructor that creates a set with one element.
		 * @param input Element of the set.
		 */
	Set::Set(char input) {
		// Realisation of the constructor
		element = input;
	}
	/**
 * @brief Recursively creates a set from the input string.
 * @param input String representing the set.
 * @param position Pointer to the current position in the string.
 * @return The set created from the string.
 */
	Set Set::recursiveCreation(std::string input, int* position) {
		// Method realisation
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
	/**
 * @brief Adds an element to the set.
 * @param element Element to add.
 */
	void Set::push(std::string element) {
		// Method realisation
		push(Set(element));
	}
	/**
 * @brief Adds an element (char* type) to the set.
 * @param element C-string to add.
 */
	void Set::push(char* element) {
		// Method realisation
		push(std::string(element));
	}
	/**
 * @brief Adds an element of type Set to a set.
 * @param element Set to add.
 */
	void Set::push(Set element) {
		// Method realisation
		if (recursiveCheckPresence(subsets, element)) {
			return;
		}
		subsets.push_back(element);
		if (subsets.size() == 1) {
			this->element = "";
		}
	}
	/**
 * @brief Adds an element (char type) to the set.
 * @param element Element to add.
 */
	void Set::push(char element) {
		// Method realisation
		push(Set(element));
	}
	/**
 * @brief Deletes an element from the set.
 * @param element The element to delete.
 */
	void Set::pop(std::string element) {
		// Method realisation
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
	/**
 * @brief Removes an element (char* type) from the set.
 * @param element C-string to delete.
 */
	void Set::pop(char* element) {
		// Method realisation
		pop(std::string(element));
	}
	/**
	 * @brief Removes an element of type Set from the set.
	 * @param element Set to delete.
	 */
	void Set::pop(Set element) {
		// Method realisation
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
	/**
 * @brief Removes an element (char type) from the set.
 * @param element Element to delete.
 */
	void Set::pop(char element) {
		// Method realisation
		std::string stringElement = "";
		stringElement += element;
		pop(stringElement);
	}
	/**
 * @brief Returns a vector of subsets of the current set.
 * @return Vector of subsets.
 */
	std::vector<Set> Set::getSubsets() const {
		// Method realisation
		return subsets;
	}
	/**
 * @brief Returns an element of the current set.
 * @return An element of the set.
 */
	std::string Set::getElement() const {
		// Method realisation
		return element;
	}
	/**
 * @brief Checks if the current set is empty.
 * @return true if the set is empty, otherwise false.
 */
	bool Set::isEmpty() const {
		// Method realisation
		return subsets.size() == 0 && element == "";
	}
	/**
 * @brief Returns the number of subsets in the current set.
 * @return The number of subsets.
 */
	int Set::cardinality() const {
		// Method realisation
		return subsets.size();
	}
	/**
 * @brief Allows access to subsets by index.
 * @param position Index of the subset.
 * @return Subset by specified index.
 */
	Set Set::operator[](int position) const {
		// Method realisation
		if (position < 0 || position >= subsets.size()) {
			throw std::runtime_error("invalid index");
		}
		return subsets[position];
	}
	/**
 * @brief Set union operator. Returns a new set that is the union of the current set and another set.
 * @param other Another set to merge.
 * @return The result of combining sets.
 */
	Set Set::operator+(Set other) const {
		// Operator realisation
		Set result = *this;
		std::vector<Set> sets = other.getSubsets();
		for (int i = 0; i < sets.size(); i++)
			result.push(sets[i]);
		return result;
	}
	/**
 * @brief Set union operator with assignment. Adds elements of another set to the current set.
 * @param other Another set to merge with the current set.
 * @return Reference to the current set after merging.
 */
	Set& Set::operator+=(Set other) {
		// Operator realisation
		std::vector<Set> sets = other.getSubsets();
		for (int i = 0; i < sets.size(); i++)
			push(sets[i]);
		return *this;
	}
	/**
 * @brief Set intersection operator. Returns a new set that is the intersection of the current set and another set.
 * @param other Another set to intersect.
 * @return Result of intersection of sets.
 */
	Set Set::operator*(Set other) const {
		// Operator realisation
		Set result;
		std::vector<Set> sets = other.getSubsets();
		for (int i = 0; i < sets.size(); i++)
			if (recursiveCheckPresence(subsets, sets[i])) {
				result.push(subsets[i]);
			}
		return result;
	}
	/**
 * @brief Set intersection operator with assignment. Removes elements that are not in the other set.
 * @param other Another set to intersect with the current set.
 * @return A reference to the current set after the intersection.
 */
	Set& Set::operator*=(Set other) {
		// Operator realisation
		std::vector<int> popPositions;
		std::vector<Set> sets = other.getSubsets();
		for (int i = 0; i < subsets.size(); i++)
			if (!other.recursiveCheckPresence(sets, subsets[i])) {
				popPositions.push_back(i);
			}
		for (int i = popPositions.size() - 1; i >= 0; i--)
			subsets.erase(subsets.begin() + popPositions[i]);
		return *this;
	}
	/**
	 * @brief Set difference operator. Returns a new set that is the difference of the current set and another set.
	 * @param other Another set for the difference.
	 * @return The result of a set difference.
	 */
	Set Set::operator-(Set other) const {
		// Operator realisation
		Set result;
		std::vector<Set> sets = other.getSubsets();
		for (int i = 0; i < sets.size(); i++)
			if (!recursiveCheckPresence(subsets, sets[i])) {
				result.push(subsets[i]);
			}
		return result;
	}
	/**
 * @brief Set difference operator with assignment. Removes elements that are also in the other set.
 * @param other Another set to be different from the current set.
 * @return Reference to the current set after the difference.
 */
	Set& Set::operator-=(Set other) {
		// Operator realisation
		std::vector<int> popPositions;
		std::vector<Set> sets = other.getSubsets();
		for (int i = 0; i < subsets.size(); i++)
			if (other.recursiveCheckPresence(sets, subsets[i])) {
				popPositions.push_back(i);
			}
		for (int i = popPositions.size() - 1; i >= 0; i--)
			subsets.erase(subsets.begin() + popPositions[i]);
		return *this;
	}
	/**
 * @brief Outputs the current set in a readable format.
 * If the set is empty, outputs "{}". If there is only an element in the set, outputs it.
 * Otherwise, outputs nested sets and elements in curly braces.
 */
	void Set::print() const {
		// Implementation of the method
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
	/**
 * @brief Returns a string representation of the current set, including subsets.
 * If the set is empty, returns "{}". If there is only an element in the set, returns it.
 * Otherwise returns nested sets and elements in curly braces.
 * @param result Pointer to the string where the result is written.
 */
	void Set::getSubsetsToString(std::string* result) const {
		// Implementation of the method
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
	/**
 * @brief Checks for the presence of an element in the current set.
 * @param element Element to check for presence.
 * @return true if the element is present in the set, otherwise false.
 */
	bool Set::checkPresence(std::string element) const {
		// Implementation of the method
		for (int i = 0; i < subsets.size(); i++)
			if (subsets[i].getElement() == element) {
				return true;
			}
		return false;
	}
	/**
 * @brief Recursively checks if a set exists in the current set.
 * @param otherSubsets Vector of other sets to check for.
 * @param element The set being checked for presence.
 * @return true if the set is present in the current set, otherwise false.
 */
	bool Set::recursiveCheckPresence(std::vector<Set> otherSubsets, Set element) const {
		for (int i = 0; i < otherSubsets.size(); i++) {
			if (otherSubsets[i].getElement() == element.getElement() && otherSubsets[i].cardinality() == element.cardinality()) {
				std::vector<Set> sets = otherSubsets[i].getSubsets();
				std::vector<Set> otherSets = element.getSubsets();
				if (sets.size() == 0) {
					return true;
				}
				bool presence = true;
				for (int j = 0; j < otherSets.size(); j++) {
					presence = std::min(presence, recursiveCheckPresence(sets, otherSets[j]));
				}
				return presence;
			}
		}
		return false;
	}
	/**
 * @brief Creates a set boolean representing all subsets of the current set.
 * @return Boolean of a set.
 */
	Set Set::boolean() const {
		// Implementation of the method
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
