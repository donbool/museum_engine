#include<iostream>
#include "artwork.cpp"
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream input;
	string line;

	input.open("artData.csv");

	getline(input, line);
	vector<ArtWork> first10;
	int x;
	cin >> x;
	for(int i = 0; i < x; i++){
		getline(input, line);
	}
	for(int i = 0; i < 100000 - x; i++){
		getline(input, line);
		first10.push_back(ArtWork(line));	

		cout << "==============================================" << endl;
		cout << first10.back().getID() << endl;
		cout << first10.back().isPublicDomain() << endl;
		cout << first10.back().getDepartment() << endl;
		cout << first10.back().getObjectName() << endl;
		cout << first10.back().getTitle() << endl;
		cout << first10.back().getCulture() << endl;
		cout << first10.back().getPeriod() << endl;
		cout << first10.back().getArtistName() << endl;
		cout << first10.back().getArtistNationality() << endl;
		cout << first10.back().getObjectYear() << endl;
		cout << first10.back().getCountry() << endl;
		cout << first10.back().getLink() << endl;
		cout << i+x << endl;
	}
	input.close();
}
