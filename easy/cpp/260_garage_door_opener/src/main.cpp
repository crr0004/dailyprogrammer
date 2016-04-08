#include <iostream>
#include <string>

using namespace std;

class State {
	private:
		string name;
	public:
		State(){}
		~State() {}
		State(string name): name(name){}
		virtual void transit(int *current_state){}
		string get_name(){
			return name;
		}
};

class Open_State: public State {
	public:
		void transit(int *current_state){

			cout << current_state << endl;
			if((*current_state) == 0){
				(*current_state) = 1;
			}


		}
	Open_State(string name): State(name){}

};
class Closing_State: public State {
	public:
		void transit(int *current_state){


		}
	Closing_State(string name): State(name){}

};

int main(int argc, char *argv[])
{

	State *states[6] = { };
	int current_state = 0;
	Open_State open("Open");
	Closing_State closing("Closing");

	states[0] = &open;
	states[1] = &closing;

	string input;

	cout << "Current state: " << states[current_state]->get_name() << endl;

	while(input != "end"){
		getline(cin,input);
		states[current_state]->transit(&current_state);

		cout << "Current state: " << states[current_state]->get_name() << endl;

	}


	return 0;
}
