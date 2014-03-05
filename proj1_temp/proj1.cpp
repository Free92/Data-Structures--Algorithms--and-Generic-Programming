#include <iostream>
#include <map>
#include <stdlib.h>

using namespace std;

void displayCharResults(map<char,int> & charcount);

int main(void){
	map<char,int> charcount;
	char temp;
	
	while(cin >> temp){
		charcount[temp]++;
	}
	
	displayCharResults(charcount);
	

	


	return 0;
}

void displayCharResults(map<char,int> & charcount){
	cout << "Total " << charcount.size() << "different characters, ";
	if(charcount.size()<10)
		cout<< charcount.size() << " most used characters:\n";
	else
		cout << "10 most used characters:\n";
	int i = 0;
	for(auto itr = charcount.begin(); itr != charcount.end(); ++itr){
		cout << "No. " << i << ": ";
		cout << itr->first << " occurred " << itr->second << endl;
		i++;
	}

}
