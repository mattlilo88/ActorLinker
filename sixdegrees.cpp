#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>
#include "sixdegrees.h"

using namespace std;

int main(int argc, char** argv)
{
	if(argc != 3){
		throw std::invalid_argument("Usage: ./sixdegrees <INPUT FILE> <OUTPUT FILE>");
	}

	ifstream txtfile("cleaned_movielist.txt");

	unordered_map<string, set<string>> actorMap;
	unordered_map<string, set<string>> movieMap;
	
	
	string inputLine;
	while(getline(txtfile, inputLine)){
		stringstream s(inputLine);
		string lineStr;
		vector<string> currLine;

		while(s >> lineStr){
			currLine.push_back(lineStr);
		}

		string movie = currLine[0];
		if(movieMap.find(movie) != movieMap.end()){
			int counter = 0;
			while(true){
				if(movieMap.find(movie + "+" + to_string(counter)) == movieMap.end()){
					movie = movie + "+" + to_string(counter);
					break;
				}
				else{
					counter++;
				}
			}
		}
		for(int i = 1; i < currLine.size(); i++){
			actorMap[currLine[i]].insert(movie);
			movieMap[movie].insert(currLine[i]);
		}
		
	}
	txtfile.close();

	ifstream input;
	ofstream output;
	input.open(argv[1]);
	output.open(argv[2]);

	while(getline(input, inputLine)){
		if(inputLine.length() == 0){
			continue;
		}
		stringstream s(inputLine);
		string lineStr;
		vector<string> currLine;

		while(s >> lineStr){
			currLine.push_back(lineStr);
		}
		if(actorMap.find(currLine[0]) == actorMap.end() || actorMap.find(currLine[1]) == actorMap.end()){
			output << "Not present" << endl;
			continue;
		}
		if(currLine[0] == currLine[1]){
			output << currLine[0] << endl;
			continue;
		}
		vector<string> shortPath = path(actorMap, movieMap, currLine[0], currLine[1]);
		if(shortPath.empty()){
			output << "Not present" << endl;
		}
		else{
			output << printPath(shortPath) << endl;
		}
	}
	input.close();
	output.close();

}