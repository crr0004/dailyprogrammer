#include <iostream>
#include <string>

using namespace std;

struct state {
	string name;
};

struct transition {
	state* next;
} ;

int main(int argc, char *argv[])
{
	state* current_state;

	state open;
	state closed;
	state closing;
	state opening;
	state opening_interrupted;
	state closing_interrupted;

	transition open_closing;
	transition closed_opening;
	transition opening_open;
	transition closing_closed;
	transition closing_closing_interrupted;
	transition opening_opening_interrupted;
	transition closing_interrupted_opening;
	transition opening_interrupted_closing;



	return 0;
}
