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
