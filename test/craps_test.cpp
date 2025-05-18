#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "come_out_phase.h"
#include "point_phase.h"
#include "shooter.h"
#include "roll.h"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}



TEST_CASE("Test that ComeOutPhase get outcomes returns values") {
	ComeOutPhase phase;
	Die die1;
	Die die2;
	Roll* roll = new Roll(die1, die2);
	roll->roll_dice();

	REQUIRE(phase.get_outcome(roll) == RollOutcome::natural);
	REQUIRE(phase.get_outcome(roll) == RollOutcome::craps);
	REQUIRE(phase.get_outcome(roll) == RollOutcome::point);

	delete roll;

}

TEST_CASE("Test that PointPhase get outcomes returns values"){
	PointPhase phase(5);
	Die die1;
	Die die2;
	Roll* roll = new Roll(die1, die2);
	roll->roll_dice();

	REQUIRE(phase.get_outcome(roll) == RollOutcome::point);
	REQUIRE(phase.get_outcome(roll) == RollOutcome::seven_out);
	REQUIRE(phase.get_outcome(roll) == RollOutcome::nopoint);

	delete roll;
}


/*
TEST_CASE("ttesting shooter returning a value 2 to 12 10 times"){
	Die die1;
	Die die2;
	Shooter shooter;

	for (int i=0; i<10; ++i) {
		Roll* roll = shooter.throw_dice(die1, die2);
		REQUIRE(roll != nullptr);
		REQUIRE(roll->roll_value() >= 2);
		REQUIRE(roll->roll_value() <= 12);
	}
}

TEST_CASE("testing roll class returning a value 2 to 12 10 times"){
	Die die1;
	Die die2;
	Roll roll(die1, die2);

	for (int i=0; i<10; ++i) {
		roll.roll_dice();
		int value = roll.roll_value();
		REQUIRE(value >= 2);
		REQUIRE(value <= 12);
	}
}

TEST_CASE (" Die rolls return a value from 1 to 6") {
	Die die;
	for (int i=0; i<10; ++i) {
		int value = die.roll();
		REQUIRE(value >= 1);
		REQUIRE(value <= 6);
	}
}

*/