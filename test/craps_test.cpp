#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE (" Die rolls return a value from 1 to 6") {
	die die;
	for (int i=0; i<10; ++i) {
		int value = die.roll();
		REQUIRE(value >= 1);
		REQUIRE(value <= 6);
	}
}