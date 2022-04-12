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
	//demo of the first 33 lines of the csv
	for(int i = 0; i < 33; i++){
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
		cout << first10.back().getMedium() << endl;
		cout << first10.back().getCountry() << endl;
		cout << first10.back().getLink() << endl;
	}
	input.close();
}
