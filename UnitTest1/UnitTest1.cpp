#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10.1.a.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountLowAverageStudents)
        {
            // Test data
            Student students[3] = {
                { "Ivanenko", 1, KN, {5, 4, 3} },
                { "Petrenko", 2, PM, {3, 3, 3} },
                { "Shevchenko", 3, FI, {4, 4, 4} }
            };

            // Expected result: 1 student with average < 4
            int count = CountLowAverageStudents(students, 3);
            Assert::AreEqual(1, count);
        }

        TEST_METHOD(TestFindSubjectWithLowestAverage)
        {
            // Test data
            Student students[3] = {
                { "Ivanenko", 1, KN, {5, 4, 3} },
                { "Petrenko", 2, PM, {3, 3, 3} },
                { "Shevchenko", 3, FI, {4, 4, 4} }
            };

            // Expected result: "Інформатика" has the lowest average (3+3+4)/3 = 3.33
            string lowestAvgSubject = FindSubjectWithLowestAverage(students, 3);
            Assert::AreEqual(string("Інформатика"), lowestAvgSubject);
        }
    };
}
