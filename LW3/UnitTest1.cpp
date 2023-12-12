#include "pch.h"
#include "CppUnitTest.h"
#include "Forum.h"
#include "Test.h"
#include "Progress.h"
#include "Certificate.h"
#include "Payment.h"
#include "Notification.h"
#include "Module.h"
#include "Administrator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPlatform
{
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

            TEST_METHOD(TopicPopularityCalculation)
            {
                Forum forum;
                int numberOfViews = 50;
                int numberOfReplies = 20;

                double result = forum.calculateTopicPopularity(numberOfViews, numberOfReplies);

                Assert::AreEqual(38.0, result);
            }
        };

        TEST_CLASS(TestTests)
        {
        public:
            TEST_METHOD(TestDifficultyCalculation)
            {
                Test test;
                test.questions = { "Q1", "Q2", "Q3" };

                double result = test.calculateTestDifficulty();

                Assert::AreEqual(3.6, result, 0.1);
            }

            TEST_METHOD(TestTimeCalculation)
            {
                Test test;
                test.questions = { "Q1", "Q2", "Q3" };
                double averageAnswerTime = 5.0;

                double result = test.calculateTestTime(averageAnswerTime);

                Assert::AreEqual(15.0, result);
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

        TEST_CLASS(PaymentTests)
        {
        public:
            TEST_METHOD(DiscountedAmountCalculation)
            {
                Payment payment;
                payment.amount = 100.0;
                double discountPercentage = 10.0;

                double result = payment.calculateDiscountedAmount(discountPercentage);

                Assert::AreEqual(90.0, result);
            }

            TEST_METHOD(AmountWithTaxCalculation)
            {
                Payment payment;
                payment.amount = 100.0;
                double taxRate = 8.0;

                double result = payment.calculateAmountWithTax(taxRate);

                Assert::AreEqual(108.0, result);
            }
        };

        TEST_CLASS(NotificationTests)
        {
        public:
            TEST_METHOD(MessageLengthCalculation)
            {
                Notification notification;
                notification.text = "This is a test notification message.";

                int result = notification.calculateMessageLength();

                Assert::AreEqual(36, result);
            }

            TEST_METHOD(UrgencyLevelCalculation)
            {
                Notification notification;
                notification.text = "This is a short message.";

                std::string result = notification.calculateUrgencyLevel();

                Assert::AreEqual(std::string("Low"), result);
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
                admin.tasks = "Task1 Task2 Task3";

                bool taskCompleted = admin.isTaskCompleted("Task2");
                Assert::IsTrue(taskCompleted);

                taskCompleted = admin.isTaskCompleted("Task4");
                Assert::IsFalse(taskCompleted);
            }
        };

    }

}