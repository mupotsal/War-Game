/** 
  /** L0: GAme of War
: Liberty Mupotsa 
: username(s): mupotsal
Purpose: 
Acknowledgements:
Modified from original code written by Dr. Jan Pearce
*/
 

#include <iostream> 
#include <algorithm>    // has shuffle
#include <vector> 
#include <random>
#include <chrono>

using namespace std;


class Getrandom {
	/** Uses <random> and <chrono> from C++11 to return a random integer in range [1..size] */
public:
	Getrandom(int size) {
		auto seed = chrono::system_clock::now().time_since_epoch().count(); //gets a new seed for the randomness
		default_random_engine generator(seed);			//seeds our randomness
		uniform_int_distribution<int> intdist(1, size); //a distibution to make each in-range integer equally likely
		self_rand_int_ = intdist(generator);			//generates the randme number
	}
	int roll() {
		return self_rand_int_;
	}
private:
	int self_rand_int_;
};


class War{
/** 
FIXME
*/
public:
	War() {
		//FIXME

		// This code makes the 5 decks of cards that are in order
		newdecks.reserve(125);
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 10; j++){
				newdecks.push_back(j);
			}
		}
		// This code gets a time-based seed for randomness
		unsigned seed = std::chrono::system_clock::now()
			.time_since_epoch()
			.count();

		//The following code shuffles
		shuffle(newdecks.begin(), newdecks.end(), std::default_random_engine(seed));

		//FIXME: The following code should be removed or commented out
		cout << "We see our randomized cards" << endl; //FIXME: Remove thisLine
		for (int i = 0; i < 50; i++) { //FIXME: Remove this loop--it is for testing only
			cout << newdecks[i]<<endl; //FIXME: remove this line
		} // FIXME: remove this }

	}

	
private:
	vector<int> newdecks; //This is the ONLY vector you are allowed to use

	/* For each set of piles (except possibly the dealing pile as described), 
	you are required to use stacks, queues, and deques data structures appropriately, 
	you may NOT use vectors for these, and you must use each data structures correctly. 
	i.e. you MAY NOT iterate through the data structures. 
	You may use ONLY 1 vector, and that is for your new cards because the vector class 
	has a shuffle feature which you will see in this starter code. 
	This single vector may be used for your dealing pile or you can choose to use a stack, 
	queue or deque for the dealing pile.*/



}; //a semi colon must end every C++ class declaration.


//---------------------------------------------------------------------
// main begins here

int main(){
	char stopme;

	War game;



	cin >> stopme; //holds open the window in some cases
	return 0;
}



