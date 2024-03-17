#include <doctest/doctest.h>
#include <phreedf/phreedf.h>

using namespace phre;

TEST_CASE("Phreedf")
{
    CHECK(is_installed());
