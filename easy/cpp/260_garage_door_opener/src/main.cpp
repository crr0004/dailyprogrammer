#include <iostream>
#include <string>

using namespace std;

/**
 * States
 *
 * 0: Open
 * 1: Closed
 * 2: Opening
 * 3: Closing
 * 4: Stopped While Opening
 * 5: Stopped While Closing
 */

class State {
	/*
	 * Base template for other states to inherit from
	 * Must implement transit
	 */
	private:
		string name;
	public:
		State(){}
		~State() {}
		State(string name): name(name){}
		/*
		 * Takes the current state number (refer to states for allocation) and can change number to change state
		 */
		virtual void transit(int *current_state){}
		string get_name(){
			return name;
		}
};

class Open_State: public State {
	public:
		void transit(int *current_state){
			//Jumps to closing
			(*current_state) = 3;
		}
	Open_State(string name): State(name){}

};
class Closed_State: public State {
	public:
		void transit(int *current_state){
			(*current_state) = 2;
		}
	Closed_State(string name): State(name){}

};
class Opening_State: public State {
	public:
		void transit(int *current_state){
			(*current_state) = 0;
		}
	Opening_State(string name): State(name){}

};
class Closing_State: public State {
	public:
		void transit(int *current_state){
			(*current_state) = 1;
		}
	Closing_State(string name): State(name){}

};
class Stopped_While_Opening_State: public State {
	public:
		void transit(int *current_state){


		}
	Stopped_While_Opening_State(string name): State(name){}

};
class Stopped_While_Closing_State: public State {
	public:
		void transit(int *current_state){


		}
	Stopped_While_Closing_State(string name): State(name){}

};

int main(int argc, char *argv[])
{

	State *states[6] = { };
	int current_state = 0;
	Open_State open("Open");
	Closed_State closed("Closed");
	Opening_State opening("Opening");
	Closing_State closing("Closing");
	Stopped_While_Opening_State stopped_opening("Stopped Opening");
	Stopped_While_Closing_State stopped_closing("Stopped Closing");

	states[0] = &open;
	states[1] = &closed;
	states[2] = &opening;
	states[3] = &closing;
	states[4] = &stopped_opening;
	states[5] = &stopped_closing;

	string input;

	cout << "Current state: " << states[current_state]->get_name() << endl;
	//Continues to call transit on the current state until 'end' is entered
	while(input != "end"){
		getline(cin,input);
		states[current_state]->transit(&current_state);

		cout << "Current state: " << states[current_state]->get_name() << endl;

	}
	return 0;
}
