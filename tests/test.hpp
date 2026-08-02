#pragma once
#include <iostream>
#include <string>

using namespace std;

#define TEST_CASE(label, units)             \
    galla::unit_test::startTestCase(label); \
    units                                   \
    galla::unit_test::endTestCase();

#define TEST_UNIT_EQUALS(test, expected) galla::unit_test::processTestUnitEquals([]() { return test == expected; }, #test, #expected);

#define TEST_UNIT_EQUALS_EXECUTE(init, execute, expected) galla::unit_test::processTestUnitEquals([]() { auto temp = init; temp.execute; return temp == expected; }, #init, #expected);

#define TEST_UNIT_IMMUTABLE(init, execute) galla::unit_test::processTestUnitEquals([]() { auto a = init; auto b = init; a.execute; return a == b; }, #init, #execute);

namespace galla::unit_test
{
    typedef bool (*test_unit_equals_handle_function)(void);
    typedef void (*test_unit_immutable_handle_function)(void);

    void startTestCase(const string &label);

    void processTestUnitEquals(test_unit_equals_handle_function handleFunc, string testLabel, string expectedLabel);

    void endTestCase();

}