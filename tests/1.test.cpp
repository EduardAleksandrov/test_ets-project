#define BOOST_TEST_MODULE MyTestModule
#include <boost/test/unit_test.hpp>
#include "../headers/calc.h"

BOOST_AUTO_TEST_SUITE(TestSuite_One)

BOOST_AUTO_TEST_CASE(test_case_1)
{
    // Arrange
    std::string pik = "./task/mo_pik.csv";
    std::string temp = "./task/mo_temp.csv";
    Calc calc;
    
    // Act
    int temp_error {-1};
    calc.get_temperature(temp, temp_error);

    int pik_error {-1};
    calc.get_pik(pik, pik_error);

    // Assert
    BOOST_TEST(temp_error == 3);
    BOOST_TEST(pik_error == 3);
}

BOOST_AUTO_TEST_CASE(test_case_2)
{
    // Arrange
    std::string pik = "./task/mo_pik.csv";
    std::string temp = "./task/mo_temp.csv";
    Calc calc(pik, temp);
    
    // Act
    bool result = calc.check_pik_time("2017-01-11 18:00:00.000");

    // Assert
    BOOST_TEST(result == 1);
}

BOOST_AUTO_TEST_CASE(test_case_3_throw)
{
    // Arrange
    std::string pik = "./task/mo_pik.csv";
    std::string temp = "./task/mo_temp.csv";
    Calc calc(pik, temp);
    
    // Act // Assert
    BOOST_CHECK_THROW(calc.check_pik_time("2017-01-11 :00:00.000"), Pexception);
}

BOOST_AUTO_TEST_CASE(test_case_4_throw)
{
    // Arrange
    std::string pik = "./task/mo_pik.csv";
    std::string temp = "./testdata/1.test.csv";
    Calc calc(pik, temp);
    
    // Act // Assert
    BOOST_CHECK_THROW(calc.predict_peak_hour(9), Pexception);
}

BOOST_AUTO_TEST_SUITE_END()