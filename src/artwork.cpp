#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/* Values: 
			Object Number, Object Name, Title,
			Culture, Object Year (avg), Link Resource
*/

class ArtWork{
	private:
		string id;
		string objectName;
		string title;
		string culture;
		int objectYear;
		string link;

	public:
		ArtWork(string csvLine);
		//Accessors
		string getID();
		string getObjectName();
		string getTitle();
		string getCulture();
		int getObjectYear();
		string getLink();
};
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
	
	getline(ss, value, ',');
	publicDomain = value == "TRUE";

	getline(ss, department, ',');

	getline(ss, objectName, ',');
	if(objectName[0] == '"'){
		objectName.erase(0,1);
		getline(ss, value, '"');
		objectName += ',' + value;
		getline(ss, value, ',');
	} 
	getline(ss, title, ','); //this is important to fix
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

	getline(ss, period, ',');
	
	getline(ss, artistAlphaSort, ',');
	if(artistAlphaSort[0] == '"'){
		artistAlphaSort.erase(0,1);
		getline(ss, value, '"');
		artistAlphaSort += ',' + value;
		getline(ss, value, ',');
	}	
	getline(ss, artistNationality, ',');
	if(artistNationality[0] == '"'){
		artistNationality.erase(0,1);
		getline(ss, value, '"');
		artistNationality += ',' + value;
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
string ArtWork::getObjectName(){
	return objectName;
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
string ArtWork::getLink(){
	return link;
}
