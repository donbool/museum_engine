#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/* Values: 
			Object ID, Object Name, Title,
			Culture, Object Year (avg),
			Country, Link Resource,,,,
*/

class ArtWork{
	private:
		string id;
		string title;
		string culture;
		int objectYear;
		string country;
		string link;

	public:
		ArtWork();
		ArtWork(string csvLine);
		//Accessors
		string getID();
		string getTitle();
		string getCulture();
		string getArtistNationality();
		int getObjectYear();
		string getCountry();
		string getLink();
};
ArtWork::ArtWork(){
	id = "";
	title = "";
	culture = "";
	objectYear = 0;
	country = "";
	link = "";
}
//takes line from csv, creates artwork obj
ArtWork::ArtWork(string csvLine){
	istringstream ss(csvLine);
	string value;
	//id
	getline(ss, id, ',');
	if(id[0] == '"'){
		id.erase(0,1);
		getline(ss, value, '"');
		id += ',' + value;
		getline(ss, value, ',');
	}
	
	getline(ss, title, ','); 
	if(title[0] == '"'){
		title.erase(0,1);
		getline(ss, value, '"'); //detecting ending quotes in csv file
		title += ',' + value;
		getline(ss, value, ',');
	}

	getline(ss, culture, ',');
	if(culture[0] == '"'){
		culture.erase(0,1);
		getline(ss, value, '"');
		culture += ',' + value;
		getline(ss, value, ',');
	}
	//takes avg of start year and end year	
	getline(ss, value, ',');
	objectYear = stoi(value);
	getline(ss, value, ',');
	objectYear = (objectYear + stoi(value)) / 2;

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
string ArtWork::getTitle(){
	return title;
}
string ArtWork::getCulture(){
	return culture;
}
int ArtWork::getObjectYear(){
	return objectYear;
}
string ArtWork::getCountry(){
	return country;
}
string ArtWork::getLink(){
	return link;
}
