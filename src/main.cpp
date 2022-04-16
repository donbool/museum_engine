#include<iostream>
#include "artwork.cpp"
#include "splay.cpp"
#include "redblacktree.cpp"
#include <fstream>
#include <vector>
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

int main() {
	ifstream input;
	string line, function, title, id, link;

	input.open("artData.csv");

	getline(input, line);
	vector<ArtWork> first10;
	int x;
	cin >> x;
	for(int i = 0; i < x; i++){
		getline(input, line);
	}
	for(int i = 0; i < 100000; i++){
		getline(input, line);
		first10.push_back(ArtWork(line));	

		cout << "==============================================" << endl;
		cout << first10.back().getID() << endl;
		cout << first10.back().getTitle() << endl;
		cout << first10.back().getCulture() << endl;
		cout << first10.back().getObjectYear() << endl;
		cout << first10.back().getCountry() << endl;
		cout << first10.back().getLink() << endl;
		cout << i+x << endl;
	}
	input.close();
}
