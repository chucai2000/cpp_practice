/*
Given two words(start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that :

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given :
	  start = "hit"
	  end = "cog"
	  dict = ["hot", "dot", "dog", "lot", "log"]
	  Return
	  [
		  ["hit", "hot", "dot", "dog", "cog"],
		  ["hit", "hot", "lot", "log", "cog"]
	  ]
*/

#include "common.h"
using namespace std;

namespace word_ladder {

vector< string > find_neighbors(string str, unordered_set<string> &visited, unordered_set<string> &dict)
{
    unsigned int i;
    char j;
    vector<string> str_neighbors;

    for (i = 0; i < str.size(); i++){
        for (j = 'a'; j <= 'z'; j++){
            if (str[i] == j)
                continue;
            char tmp = str[i];
            str[i] = j;

            // not yet be visited, and in the dictionary
            if (visited.count(str) == 0 && dict.count(str) != 0)
                str_neighbors.push_back(str);
            str[i] = tmp;
        }
    }

    return str_neighbors;
}

void build_path(
    unordered_map<string, vector<string>> &parent,
    string &start,
    string &end,
    vector<string> &path,
    vector<vector<string>> &results
    ) // DFS scheme
{
    // base
    if (!start.compare(end)){
        path.push_back(start);
        reverse(path.begin(), path.end());
        results.push_back(path);
        reverse(path.begin(), path.end());
        path.pop_back();
        return;
    }

    // recursive search
    path.push_back(end);
    vector<string> &pr = parent[end];
    for (unsigned int i = 0; i < pr.size(); i++){
        build_path(parent, start, pr[i], path, results);
    }
    path.pop_back();
}

vector<vector<string>> find_ladders(string start, string end, unordered_set<string> &dict) {

    // build two queues to represent two levels
    unordered_set<string> current, next;
    unordered_map<string, vector<string>> parent;
    unordered_set<string> visited;
    bool found = false;
    vector< vector<string> > results;

    current.insert(start);

    while (!current.empty() && !found){

        // mark the strings in current set as visited strings
        for (auto itr = current.begin(); itr != current.end(); itr++)
            visited.insert(*itr);

        // iteratively processing each neighbor of the strings in current set
        for (auto itr = current.begin(); itr != current.end(); itr++){
            string str = *itr;
            vector< string > str_neighbors = find_neighbors(str, visited, dict);
            for (unsigned int i = 0; i < str_neighbors.size(); i++){
                string &str_n = str_neighbors[i];
                parent[str_n].push_back(str);
                if (!str_n.compare(end))
                    found = true;
                next.insert(str_n);
            }

        }

        current.clear();
        swap(current, next);

    }

    // if finding the end string, then build the paths by using the "parent" map
    if (found){
        vector<string> path;
        build_path(parent, start, end, path, results);
    }

    return results;
}

}
