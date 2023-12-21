#include "pch.h"
#include "CppUnitTest.h"
#include "Forum.h"
#include "Test.h"
#include "Progress.h"
#include "Certificate.h"
#include "Module.h"
#include "Administrator.h"
#include "Student.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPlatform
{
        TEST_CLASS(UserTests)
        {
        public:
            TEST_METHOD(ActivityTimeCalculation)
            {
                User user;
                double startTime = 10.0;
                double endTime = 20.0;

                double result = user.calculateActivityTime(startTime, endTime);

                Assert::AreEqual(10.0, result);
            }

            TEST_METHOD(ProgressPercentageCalculation)
            {
                User user;
                int completedModules = 2;
                int totalModules = 5;

                double result = user.calculateProgressPercentage(completedModules, totalModules);

                Assert::AreEqual(40.0, result);
            }
        };

        TEST_CLASS(CourseTests)
        {
        public:
            TEST_METHOD(AverageRatingCalculation)
            {
                Course course;
                std::vector<double> ratings = { 4.0, 3.5, 5.0 };

                double result = course.calculateAverageRating(ratings);

                Assert::AreEqual(4.16666666667, result, 0.0001);
            }

            TEST_METHOD(TimeSpentCalculation)
            {
                Course course;
                double averageTimePerModule = 2.5;
                int numberOfModules = 4;

                double result = course.calculateTimeSpent(averageTimePerModule, numberOfModules);

                Assert::AreEqual(10.0, result);
            }
        };


        TEST_CLASS(ForumTests)
        {
        public:
            TEST_METHOD(DiscussionActivityCalculation)
            {
                Forum forum;
                int numberOfMessages = 10;
                int numberOfRatings = 5;

                double result = forum.calculateDiscussionActivity(numberOfMessages, numberOfRatings);

                Assert::AreEqual(8.5, result);
            }
            TEST_METHOD(TestShowMessages)
            {
                Forum forum;
                forum.setTheme("Sample Theme"); 
                User author;
                author.setname("John Doe");
                forum.setAuthor(&author); 
                forum.sendMessage("Message 1"); 

                std::stringstream output;
                std::streambuf* coutBuf = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf());

                forum.showMessages();

                std::string expectedOutput = "Sample Theme\nJohn Doe\nMessage 1\n";
                Assert::AreEqual(expectedOutput, output.str(), L"The output should match the expected result");

                std::cout.rdbuf(coutBuf);
            }
        };

        TEST_CLASS(TestTests)
        {
        public:
            TEST_METHOD(TestDifficultyCalculation)
            {
                Test test;
                test.addQuestionAnswer("Q1", "A1");
                test.addQuestionAnswer("Q2", "A2");
                test.addQuestionAnswer("Q3", "A3");

                double result = test.calculateTestDifficulty();

                Assert::AreEqual(3.6, result, 0.1);
            }

            TEST_METHOD(TestTimeCalculation)
            {
                Test test;
                test.addQuestionAnswer("Q1", "A1");
                test.addQuestionAnswer("Q2", "A2");
                test.addQuestionAnswer("Q3", "A3");
                double averageAnswerTime = 5.0;

                double result = test.calculateTestTime(averageAnswerTime);

                Assert::AreEqual(15.0, result);
            }

            TEST_METHOD(TestAddQuestionAnswer)
            {
                Test test;

                test.addQuestionAnswer("What is 2+2?", "4");

                Assert::AreEqual(static_cast<size_t>(1), test.getQuestions().size(), L"There should be one question");
                Assert::AreEqual(static_cast<size_t>(1), test.getAnswers().size(), L"There should be one answer");
                Assert::AreEqual("What is 2+2?", test.getQuestions()[0].c_str(), L"The question should match");
                Assert::AreEqual("4", test.getAnswers()[0].c_str(), L"The answer should match");
            }
        };

        TEST_CLASS(ProgressTests)
        {
        public:
            TEST_METHOD(AverageGradeCalculation)
            {
                Progress progress;
                std::vector<int> grades = { 90, 85, 95, 100 };

                double result = progress.calculateAverageGrade(grades);

                Assert::AreEqual(92.5, result);
            }

         
            TEST_METHOD(TaskProgressCalculation)
            {
                Progress progress;
                int completedTasks = 3;
                int totalTasks = 0;

                Assert::ExpectException<std::invalid_argument>(
                    [&] { progress.calculateTaskProgress(completedTasks, totalTasks); },
                    L"calculateTaskProgress should throw std::invalid_argument when totalTasks is 0."
                    );
            }
        };

        TEST_CLASS(CertificateTests)
        {
        public:
            TEST_METHOD(CertificateLevelCalculation)
            {
                Certificate certificate;
                double userGrade = 85.0;

                std::string result = certificate.calculateCertificateLevel(userGrade);

                Assert::AreEqual(std::string("Advanced"), result);
            }

            TEST_METHOD(CertificateStatusCalculation)
            {
                Certificate certificate;
                bool isCompleted = true;

                std::string result = certificate.calculateCertificateStatus(isCompleted);

                Assert::AreEqual(std::string("Issued"), result);
            }
        };

        TEST_CLASS(AdministratorTests)
        {
        public:

            TEST_METHOD(CalculateAdminRating)
            {
                Administrator admin;
                int numberOfTasks = 5;

                double adminRating = admin.calculateAdminRating(numberOfTasks);
                Assert::AreEqual(2.5, adminRating);
            }

            TEST_METHOD(IsTaskCompleted)
            {
                Administrator admin;
                admin.setTasks("Task1 Task2 Task3");

                bool taskCompleted = admin.isTaskCompleted("Task2");
                Assert::IsTrue(taskCompleted);

                taskCompleted = admin.isTaskCompleted("Task4");
                Assert::IsFalse(taskCompleted);
            }
        };
        TEST_CLASS(StudentTests)
        {
        public:

            TEST_METHOD(TestAddCourse)
            {
                Course course;
                course.setTitle("Math");
                Student student;

                student.addCourse(&course);

                Assert::AreEqual(static_cast<size_t>(1), student.getCourses().size(), L"The student should have one course");
                Assert::AreEqual(static_cast<size_t>(1), course.getStudents().size(), L"The course should have one student");
            }
            TEST_METHOD(TestRemoveCourse)
            {
                Course course;
                course.setTitle("Math");
                Student student;
                student.addCourse(&course);

                student.removeCourse(&course);

                Assert::AreEqual(static_cast<size_t>(0), student.getCourses().size(), L"The student should have no courses");
                Assert::AreEqual(static_cast<size_t>(0), course.getStudents().size(), L"The course should have no students");
            }

            TEST_METHOD(TestAddCertificate)
            {
                Student student;
                Certificate certificate; 

                student.addCertificate(certificate);

                Assert::AreEqual(static_cast<size_t>(1), student.getCertificates().size(), L"The student should have one certificate");
            }
        };
}