#include <iostream>
#include <ctime>
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include "roll.h"
using std::cout;


int main() 
{
	srand(time(0));
	Die die1, die2;
	Shooter shooter;

	Roll* roll = shooter.throw_dice(die1, die2);
	int rolled_value = roll->roll_value();
	cout<<"Rolled " << rolled_value << " start of ComeOut Phase" ;
	ComeOutPhase come_out_phase;

	while (come_out_phase.get_outcome(roll) == RollOutcome::natural ||
			come_out_phase.get_outcome(roll) == RollOutcome::craps)
			{
				cout << "Rolled " << rolled_value << ", roll again" ;
				roll = shooter.throw_dice(die1, die2);
				rolled_value = roll->roll_value();
			}

	cout << "Rolled " << rolled_value << " start of point phase";
	cout << "Roll until " << rolled_value << " or a 7 is rolled";

	int point = rolled_value;
	roll = shooter.throw_dice(die1, die2);

	PointPhase point_phase(point);
	while (point_phase.get_outcome(roll) != RollOutcome::seven_out &&
			point_phase.get_outcome(roll) != RollOutcome::nopoint)
	{
		cout << "Rolled " << roll->roll_value() << ", roll again";
		roll = shooter.throw_dice(die1, die2);
	}

	cout << "Rolled " << roll->roll_value() << " end of point phase";

	shooter.display_rolled_values ();

	return 0;
}