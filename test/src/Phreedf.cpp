#include <doctest/doctest.h>
#include <Phreedf/Phreedf.h>

using namespace phre;

TEST_CASE("Phreedf")
{
    CHECK(is_installed());
}