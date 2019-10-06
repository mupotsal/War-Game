/** 
  /** L0: GAme of War
: Liberty Mupotsa 
: username(s): mupotsal
Purpose: 
Acknowledgements:
Modified from original code written by Dr. Jan Pearce
*/
 

#include <iostream> 
#include <algorithm>    // has shuffle// One has to include this to get the algorithm
#include <vector> 
#include <random>
#include <chrono>
#include <deque> // this will add the deque template
#include <stack> // this will add the stack template
#include <queue> // This will add the queue in the program

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
FIXME here I have to make a constructor below
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
	void add_dealingPile() {
		// adds the shuffled decks of cards to the dealer's pile
		for (int i = 0; i < 50; i++) {
			dealingPile.push(newdecks[i]);
		}
		cout << "This is the myplaying" << dealingPile.top() << endl;
	}

	void deal() {
		// deals out 25 cards from to each player's playing pile from shuffled dealers pile
		for (int i = 0; i < 25; i++) { // put 25 to because the loop shall go for 25 times before all cards are distributed
			myPlayingPile.push(dealingPile.top());			
			dealingPile.pop();
			otherPlayingPile.push(dealingPile.top());
			dealingPile.pop();
		}
		//for (int i = 0; i < 25; i++) { //FIXME: Remove this loop--it is for testing only
			//cout<< "This is the myplaying "<< myPlayingPile.top() << endl;
			//myPlayingPile.pop();
		//}
	}
	int remove_my_card() {
		// Precondition: myPlayingPile is not empty 
	    // If it is not empty, the function removes a card from myPlayingPile, 
		// returning the stored value
		if (myPlayingPile.empty() == 0) {
			int topcard = myPlayingPile.top();
			myPlayingPile.pop();
			return topcard;
		}
	}

	int remove_other_card() {
		// Precondition: otherPlayingPile is not empty 
	    // If it is not empty, the function removes a card from otherPlayingPile,
        // returning the stored value
		if (otherPlayingPile.empty() == 0) {
			int topcard = otherPlayingPile.top();
			otherPlayingPile.pop();
			return topcard;
		}
	}
	int display_card() {
		// displays a card on the screen and returns the value

	}
	bool compare_cards() {
		// compares myCurrent to otherCurrent and behaves appropriately  
		
		myCurrent = remove_my_card();
		otherCurrent = remove_other_card();
		if (myCurrent > otherCurrent) {
			lootPile.push(myCurrent);
			lootPile.push(otherCurrent);
			cout << "my current valeu is " << myCurrent << endl;
			return true;
		}
		else if (myCurrent < otherCurrent) {
			lootPile.push(myCurrent);
			lootPile.push(otherCurrent);
			cout << "other current value is " << otherCurrent << endl;
			return false;
		}
		else {
			breaking_the_war();
			return true;
		}
		
	}

	void breaking_the_war() {
		cout << "Broke the war" << endl;
		int mycc = myCurrent;
		int othercc = otherCurrent;
		while (mycc == othercc) {
			commonlootPile.push(mycc);
			commonlootPile.push(othercc);
			mycc = remove_my_card();
			othercc = remove_other_card();

			if (mycc > othercc) {
				commonlootPile.push(mycc);
				commonlootPile.push(othercc);
				bool isempty = commonlootPile.empty();
				while (isempty == 0) {
					myStoragePile.push(commonlootPile.front());
					commonlootPile.pop();
					isempty = commonlootPile.empty();

				}

			}		
			else if (mycc < othercc) {
				commonlootPile.push(mycc);
				commonlootPile.push(othercc);
				bool isempty = commonlootPile.empty();
				while (isempty == 0) {
					otherStoragePile.push(commonlootPile.front());
					commonlootPile.pop();
					isempty = commonlootPile.empty();
				}
			}
			else {
				mycc = remove_my_card();
				othercc = remove_other_card();
			}
		}
	}

	void move_my_loot() {	
		
		if (myCurrent > otherCurrent) {
			cout << "we moved my loot to mystorage file" << endl;
			bool val = lootPile.empty();
			while (val == 0) {
				myStoragePile.push(lootPile.front());
				lootPile.pop();
				val = lootPile.empty();
			}
		}
		cout << "The lootpile went to my storagepile" << endl;
		// moves everything from lootPile to myStoragePile    

	}
	void move_other_loot() {
		// moves everything from lootPile to otherStoragePile
		if (myCurrent < otherCurrent) {
			cout << "we moved from lootpil other storagepile" << endl;
			bool val = lootPile.empty();
			while (val == 0) {
				otherStoragePile.push(lootPile.front());
				lootPile.pop();
				val = lootPile.empty();
			}
		}
		cout << "The lootpile went to otherstorage pile" << endl;
	}
	void move_my_storage() {
		// moves everything from otherStoragePile to otherPlayingPile
		bool x = myStoragePile.empty();
		while (x != 1) {
			myPlayingPile.push(myStoragePile.front());
			myStoragePile.pop();
			x = myStoragePile.empty();
		}


	}
	void move_other_storage() {
		bool y = otherStoragePile.empty();
		while (y != 1) {
			otherPlayingPile.push(otherStoragePile.front());
			otherStoragePile.pop();
			y = otherStoragePile.empty();
		}

	}

	bool proceed() {
		if ((myPlayingPile.size() > 0) && (otherPlayingPile.size() > 0)) {
			return currentState;
		}
		else {
			currentState = false;
			return currentState;
		}
	}

	void who_won() {
		if (myPlayingPile > otherPlayingPile) {
			cout << "the user Won the game" << endl;
		}
		else if (myPlayingPile < otherPlayingPile) {
			cout << "The Computer Won" << endl;
		}
		else {
			cout << "we do not know" << endl;
		}
	}
	void play_game() {
		compare_cards();
		move_my_loot();
		move_other_loot();
		move_my_storage();
		move_other_storage();
		/*if (myPlayingPile.size() < 10){
			move_my_storage();
		}
		if (otherPlayingPile.size() <10) {
			move_other_storage();
		}*/
	}
private:
	vector<int> newdecks; //This is the ONLY vector you are allowed to use
	int myCurrent;
	int otherCurrent;
	bool currentState = true;
	stack <int> dealingPile;
	stack <int> myPlayingPile;
	stack <int> otherPlayingPile;
	queue <int> myStoragePile;
	queue <int> otherStoragePile;
	queue <int> lootPile;
	queue <int> commonlootPile;


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
	game.add_dealingPile();
	game.deal();
	bool x = game.proceed();
	cout << x << endl;
	int y = 0;
	int z = 2;
	while ( x == 1) {	
		cout << "This is round" << y << endl;
		game.play_game();
		 x = game.proceed();
		 y += 1;
		 cout << "The value of yfinal" << y << endl;
		
	}
	cout << "The game took" << y << "rounds to end" << endl;
	game.who_won();

	cin >> stopme; //holds open the window in some cases
	return 0;
}



