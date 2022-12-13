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

vector<string> path(unordered_map<string, set<string>> actorMap, unordered_map<string, set<string>> movieMap, string a1, string a2){
	queue<vector<string>> q;
	vector<string> start;
	start.push_back(a1);
	q.push(start);

	set<string> visited;

	while(!q.empty()){
		vector<string> u = q.front();
		q.pop();

		if(u.back() == a2){
			return u;
		}
		
		for(auto itr = actorMap[u.back()].begin(); itr != actorMap[u.back()].end(); itr++){
			for(auto itr2 = movieMap[*itr].begin(); itr2 != movieMap[*itr].end(); itr2++){
				if(visited.count(*itr2)){
					continue;
				}
				else{
					vector<string> path = u;
					path.push_back(*itr);
					visited.insert(*itr2);
					path.push_back(*itr2);
					q.push(path);
				}

			}
		}
	}
	vector<string> empty;
	return empty;
}

string printPath(vector<string> path){
	int counter = 0;
	string ret;
	for(auto i : path){
		string curr_str = i;
		int str_len = curr_str.length();
		if(curr_str[str_len - 2] == '+'){
			curr_str.resize(str_len - 2);
		}
		else if(curr_str[str_len-3] == '+'){
			curr_str.resize(str_len - 3);
		}
		if(counter % 2 == 0){
			ret = ret + curr_str + "";
			counter++;
		}
		else{
			ret = ret + " -(" + curr_str + ")- ";
			counter++;
		}
	}
	return ret;
}