#define BOOST_TEST_MODULE ExampleTests
#include <boost/test/included/unit_test.hpp>

// Function to be tested
int add(int a, int b)
{
    return a + b;
}

// Test cases
BOOST_AUTO_TEST_CASE(TestAddition)
{
    // Test addition with positive numbers
    BOOST_CHECK(add(1, 1) == 2);
    BOOST_CHECK(add(2, 3) == 5);
}

BOOST_AUTO_TEST_CASE(TestAdditionNegative)
{
    // Test addition with negative numbers
    BOOST_CHECK(add(-1, -1) == -2);
    BOOST_CHECK(add(-2, 3) == 1);
}

// More test cases can be added here
