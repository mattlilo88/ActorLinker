#ifndef SIXDEGREES_H
#define SIXDEGREES_H

#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;


vector<string> path(unordered_map<string, set<string>> actorMap, unordered_map<string, set<string>> movieMap, string a1, string a2);
string printPath(vector<string> path);

#endif
