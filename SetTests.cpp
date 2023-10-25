#include "pch.h"
#include "CppUnitTest.h"
#include "../SetLibrary/SetLibrary.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace SetLibrary;
using namespace std;

namespace SetTest
{
	TEST_CLASS(Constructor)
	{
	public:

		TEST_METHOD(ConstructorEmpty)
		{
			Set set;
			Assert::IsTrue(set.isEmpty());
			std::string setString = "";
			set.getSubsetsToString(&setString);
			string expected = "{}";
			Assert::AreEqual(expected, setString);
		}

		TEST_METHOD(ConstructorCharArray)
		{
			char elements[]{ "{a,b,c}" };
			Set set(elements);
			std::string setString = "";
			set.getSubsetsToString(&setString);
			string expected = "{a,b,c}";
			Assert::AreEqual(expected, setString);
		}

		TEST_METHOD(ConstructorString)
		{
			string elements = "{a,b,c,{e,d}}";
			Set set(elements);
			std::string setString = "";
			set.getSubsetsToString(&setString);
			string expected = "{a,b,c,{e,d}}";
			Assert::AreEqual(expected, setString);
		}
	};

	TEST_CLASS(Push) {
public:
	TEST_METHOD(PushChar) {
		Set set;
		set.push('a');
		std::string setString = "";
		set.getSubsetsToString(&setString);
		string expected = "{a}";
		Assert::AreEqual(expected, setString);
	}

	TEST_METHOD(PushStringAndCharArray) {
		Set set;
		set.push("a");
		std::string setString = "";
		set.getSubsetsToString(&setString);
		string expected = "{a}";
		Assert::AreEqual(expected, setString);
	}

	TEST_METHOD(PushSet) {
		Set set;
		Set otherSet("{a,b}");
		set.push(otherSet);
		std::string setString = "";
		set.getSubsetsToString(&setString);
		string expected = "{{a,b}}";
		Assert::AreEqual(expected, setString);
	}
	};

	TEST_CLASS(Pop) {
public:
	TEST_METHOD(PopChar) {
		Set set("{a,b,c}");
		set.pop('a');
		std::string setString = "";
		set.getSubsetsToString(&setString);
		string expected = "{b,c}";
		Assert::AreEqual(expected, setString);
	}

	TEST_METHOD(PopStringAndCharArray) {
		Set set("{a,b,c}");
		set.pop("a");
		std::string setString = "";
		set.getSubsetsToString(&setString);
		string expected = "{b,c}";
		Assert::AreEqual(expected, setString);
	}

	TEST_METHOD(PopSet) {
		Set set("{a,b,c,{e,d}}");
		Set otherSet("{e,d}");
		set.pop(otherSet);
		std::string setString = "";
		set.getSubsetsToString(&setString);
		string expected = "{a,b,c}";
		Assert::AreEqual(expected, setString);
	}
	};

	TEST_CLASS(Operators) {
		TEST_METHOD(Union1) {
			Set set1("{a,b,c}");
			Set set2("{a,b,d}");
			Set result = set1 + set2;
			std::string setString = "";
			result.getSubsetsToString(&setString);
			string expected = "{a,b,c,d}";
			Assert::AreEqual(expected, setString);
		}

		TEST_METHOD(Union2) {
			Set set1("{a,b,c}");
			Set set2("{a,d,e}");
			set1 += set2;
			std::string setString = "";
			set1.getSubsetsToString(&setString);
			string expected = "{a,b,c,d,e}";
			Assert::AreEqual(expected, setString);
		}

		TEST_METHOD(Intersection1) {
			Set set1("{a,b,c}");
			Set set2("{a,b,d}");
			Set result = set1 * set2;
			std::string setString = "";
			result.getSubsetsToString(&setString);
			string expected = "{a,b}";
			Assert::AreEqual(expected, setString);
		}

		TEST_METHOD(Intersection2) {
			Set set1("{a,b,c}");
			Set set2("{a,d,e}");
			set1 *= set2;
			std::string setString = "";
			set1.getSubsetsToString(&setString);
			string expected = "{a}";
			Assert::AreEqual(expected, setString);
		}

		TEST_METHOD(Difference1) {
			Set set1("{a,b,c}");
			Set set2("{a,b,d}");
			Set result = set1 - set2;
			std::string setString = "";
			result.getSubsetsToString(&setString);
			string expected = "{c}";
			Assert::AreEqual(expected, setString);
		}

		TEST_METHOD(Difference2) {
			Set set1("{a,b,c}");
			Set set2("{a,d,e}");
			set1 -= set2;
			std::string setString = "";
			set1.getSubsetsToString(&setString);
			string expected = "{b,c}";
			Assert::AreEqual(expected, setString);
		}
	};
}
