#include<iostream>
#include "artwork.cpp"
//#include "splay.cpp"
//#include "redblacktree.cpp"
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

/** PREMISE **
* Storing Artwork nodes into a Splay Tree and a Red-Black Tree
*
* Goal: Search via 2-3 separate values and compare the efficiency via clock and time complexity
*
* Required functions for trees: Insert, Search via Title, Search via Link
*****/


/***** TO DO ******
* Touch up Red-Black Tree adjust to Artwork nodes,
  create search functions for title, link, and ID

* Touch up Splay Tree adjust to Artwork nodes
  create search functions for title, link, and ID

* In main add searching and insertion functionality,
  like if input == "search id 12.2.2", then RBtree.searchID()

* Create user interface and printing in main, 
  add clock to compare searching efficiency

* Final touches, make sure all functionality works

* Record Demo video!

* Create PDF report!
*****/
void parseInput(string input, vector<ArtWork>& tree){
	stringstream ss(input);
	vector<string> fullCommand;
	
	while(ss.good()){
		string commandWord;
		getline(ss, commandWord, ' ');
		fullCommand.push_back(commandWord);
	}
	
	const vector<string> validCommands{"search", "remove", "insert", "recommend"};

	auto keyword = find(validCommands.begin(), validCommands.end(), fullCommand.at(0));

	if(keyword == validCommands.end()){
		cout << "Invalid command" << endl;
		return;
	}
	int commandIndex = keyword - validCommands.begin();
	if(commandIndex == 0){
		cout << "searching" << endl;
	}
	else if(commandIndex == 1){
		cout << "removing" << endl;
	}
	else if(commandIndex == 2){
		cout << "inserting" << endl;
	}
	else if(commandIndex == 3){
		cout << "recommending" << endl;
	}
}
void initRBT(vector<ArtWork>& tree){
	ifstream input;
	string line;

	input.open("artData.csv");

	getline(input, line);
	auto start = chrono::high_resolution_clock::now();
	int count = 0;
	while(getline(input, line)){
		count++;
		tree.push_back(ArtWork(line));//tree.insert(ArtWork(line));
	}
	auto stop = chrono::high_resolution_clock::now();
	input.close();

	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time taken for " << count << " insertions into RBT: " << duration.count() << " microseconds" <<  endl;
}
int main() {
	cout << "Welcome to the Museum Engine" << endl;

	vector<ArtWork> dummyContainer;
	initRBT(dummyContainer);

	string command;
	getline(cin, command);
	while(command != "quit"){
		parseInput(command, dummyContainer);
		getline(cin, command);
	}
}
//for directing commands
/*vector <long> ids;
    sprout.searchName(sprout.returnRoot(), name, ids);
    if (ids.empty()) {
                    cout << "unsuccessful" << endl;
                }
                else {
                    for (int k = 0; k < ids.size(); k++){
                        cout << to_string(ids[k]) << endl;
                    }
                }
    */