#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TEST_DES_TESTES

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(simplest_test_case)
{
    BOOST_CHECK(5 == 5);
}
