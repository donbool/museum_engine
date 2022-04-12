#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class ArtWork{
	private:
		string id;
		bool publicDomain;
		string department;
		string objectName;
		string title;
		string culture;
		string period;
		string artistAlphaSort;
		string artistNationality;
		int objectYear;
		string medium;
		string country;
		string link;
	public:
		ArtWork(string csvLine);
		//Accessors
		string getID();
		bool isPublicDomain();
		string getDepartment();
		string getObjectName();
		string getPeriod();
		string getTitle();
		string getCulture();
		string getArtistName();
		string getArtistNationality();
		int getObjectYear();
		string getMedium();
		string getCountry();
		string getLink();
};
//takes line from csv, creates artwork obj
ArtWork::ArtWork(string csvLine){
	istringstream ss(csvLine);
	string value;
	//id
	getline(ss, id, ',');
	
	getline(ss, value, ',');
	publicDomain = value == "TRUE";

	getline(ss, department, ',');

	getline(ss, objectName, ',');
	getline(ss, title, ',');

	getline(ss, culture, ',');
	getline(ss, period, ',');
	
	getline(ss, value, '"');
	getline(ss, artistAlphaSort, '"');
	getline(ss, artistNationality, ',');//need this to skip whitespace
	getline(ss, artistNationality, ',');
	
	//year. takes avg of start and end year
	getline(ss, value, ',');
	objectYear = stoi(value);
	getline(ss, value, ',');
	objectYear = (objectYear + stoi(value)) / 2;

	getline(ss, medium, ',');
	getline(ss, country, ',');
	getline(ss, link, ',');
	//debugging
/*	while(getline(ss, value, ',')){
		cout << value << endl;
	}*/	
}


string ArtWork::getID(){
	return id;
}
bool ArtWork::isPublicDomain(){
	return publicDomain;
}
string ArtWork::getDepartment(){
	return department;
}
string ArtWork::getObjectName(){
	return objectName;
}
string ArtWork::getPeriod(){
	return period;
}
string ArtWork::getTitle(){
	return title;
}
string ArtWork::getCulture(){
	return culture;
}
string ArtWork::getArtistName(){
	return artistAlphaSort;
}
string ArtWork::getArtistNationality(){
	return artistNationality;
}
int ArtWork::getObjectYear(){
	return objectYear;
}
string ArtWork::getMedium(){
	return medium;
}
string ArtWork::getCountry(){
	return country;
}
string ArtWork::getLink(){
	return link;
}
