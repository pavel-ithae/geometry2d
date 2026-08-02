#include "test.hpp"
#include <iostream>
#include <sstream>

using namespace galla::unit_test;
using namespace std;

int test_count_;
int fail_count_;
bool passed_all = true;

void galla::unit_test::startTestCase(const string &label)
{
    test_count_ = 0;
    fail_count_ = 0;

    cout << "TEST: " << label << endl;
}

void galla::unit_test::processTestUnitEquals(test_unit_equals_handle_function handleFunc, string testLabel, string expectedLabel)
{
    cout << "\t" << test_count_ << ": ";

    try
    {
        bool result = handleFunc();

        if (result)
        {
            cout << "PASS " << "[" << testLabel << " == " << expectedLabel << "]";
        }
        else
        {
            cout << "FAIL " << "[" << testLabel << " == " << expectedLabel << "]";

            fail_count_++;
        }
    }
    catch (const std::exception &e)
    {
        cout << "ERROR" << "[" << testLabel << " == " << expectedLabel << "]" << endl;

        cerr << "\t" << e.what();

        fail_count_++;
    }

    test_count_++;

    cout << endl;
}

void galla::unit_test::endTestCase()
{
    cout << "RESULT:";

    if (fail_count_ > 0)
    {
        cout << "FAILED! ";

        passed_all = false;
    }
    else
    {
        cout << "SUCCESS! ";
    }

    cout << "[" << (test_count_ - fail_count_) << "/" << test_count_ << "]" << endl << endl;
}
