#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdlib.h>

using namespace std;

void displayResult(string type, vector<pair<string,int>>  list);
vector<pair<string,int>> charList(map<string,int> count);
vector<pair<string,int>> wordList(map<string,int> count);
bool wordCmp(const pair<string,int> & p1, const pair<string,int> & p2);
bool charCmp(const pair<string,int> & p1, const pair<string,int> & p2);

/*template<typename T>
struct cmp{
	bool operator()(const pair<T,int> & p1, const pair<T,int> & p2) const{
		if(p1.second == p2.second)
			return p1.first < p2.first;
		else
			return p1.second > p2.second;
	}
};*/



int main(void){
	// The three seperate maps to hold the different
	map<string, int> charCount;
	map<string, int> numbCount;
	map<string, int> wordCount;
	// Holds the temporary characters and string as we read them in
	char charTemp;
	string charTemp2;
	string strTemp;
	stringstream ss;
	// Holds a list of all the words so that we can break ties later
	vector<string> allwords;
	// Reads in the chars, words, and numbers
	if(cin.peek() != EOF){
		cin.get(charTemp);
		charTemp2 = string(1,charTemp);
		charCount[charTemp2]++;
	}
	while(cin.peek() != EOF){
		strTemp = "";
		while(!isdigit(charTemp) && cin.peek() != EOF){
			if(isalpha(charTemp))
				strTemp += tolower(charTemp);
			cin.get(charTemp);
			charTemp2 = string(1,charTemp);
			charCount[charTemp2]++;
		}
		if(cin.peek() == EOF)
			strTemp += tolower(charTemp);
		wordCount[strTemp]++;
		strTemp = "";
		bool isDigit = false;
		while(isdigit(charTemp) && cin.peek() != EOF){
			strTemp += charTemp;
			cin.get(charTemp);
			charTemp2 = string(1,charTemp);
			charCount[charTemp2]++;
			isDigit = true;
		}
		if(isDigit){
			if(cin.peek() == EOF)
				strTemp += charTemp; 
			numbCount[strTemp]++;
		}
		isDigit = false;
	}

	displayResult("characters", charList(charCount));
	displayResult("words", wordList(wordCount));
	displayResult("numbers", wordList(numbCount));

	return 0;
}

void displayResult(string type, vector<pair<string,int>>  list){
	cout << "Total " << list.size() << " different " << type << ", ";
	if(list.size()<10)
		cout<< list.size() << " most used " << type <<":\n";
	else
		cout << "10 most used " << type << ":\n";
	int i = 0;


	for(auto itr = list.begin(); itr != list.end() && i < 10; ++itr){
		cout << "No. " << i << ": ";
		if(itr->first != "\n")
			cout << setw(24) << left << itr->first << itr->second << endl;
		else
			cout << setw(24) << left << "\\n" << itr->second << endl;
		i++;
	}
}

vector<pair<string,int>> charList(map<string,int> count){
	vector<pair<string,int>> list(count.begin(), count.end());
	sort(list.begin(),list.end(), charCmp);

	return list;
}

vector<pair<string,int>> wordList(map<string,int> count){
	vector<pair<string,int>> list(count.begin(), count.end());
	sort(list.begin(),list.end(), wordCmp);
	
	// Need to tie break for this
	
	return list;
}

bool wordCmp(const pair<string,int> & p1, const pair<string,int> & p2){
	return p1.second > p2.second;
}

bool charCmp(const pair<string,int> & p1, const pair<string,int> & p2){
	if(p1.second == p2.second)
		return p1.first < p2.first;
	else
		return p1.second > p2.second;
}
