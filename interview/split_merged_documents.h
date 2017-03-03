#include "common.h"
using namespace std;

namespace split_merged_documents {

#define MAX_VALUE 100000

map<string, bool> dictionary;

void Solve(string &sentence)
{
	int LEN = sentence.size();
	int *DP = (int*)malloc(sizeof(int)*(LEN+1));
	int *next = (int*)malloc(sizeof(int)*(LEN+1));
	int i, j, k;
	for (i = 0; i < LEN+1; i++){
		DP[i] = MAX_VALUE;
		next[i] = -1;
	}
	
	DP[LEN]  = 0;
		
	for (i = LEN-1; i>=0 ; i--){
		for (j=i+1; j<LEN+1; j++){
			string candidate;
			if (j==LEN)
				candidate = sentence.substr(i);
			else
				candidate = sentence.substr(i, j-i);
			if (dictionary.count(candidate) != 0){
				k = DP[j];
			}
			else{
				k = DP[j]+1;
			}
			if (k < DP[i]){
				DP[i] = k;
				next[i] = j;
			}
		}
	}

	for (i=0;i<LEN;i++)
		printf("%d,",DP[i]);
	printf("\n");
	for (i=0;i<LEN;i++)
		printf("%d,",next[i]);
	printf("\n");

	printf("Incorrect word #: %d\n", DP[0]);
	i = 0;
	while (i != -1){
		if (next[i] != -1)
			printf("%s\n", sentence.substr(i, next[i]-i).c_str());
		else
			printf("%s\n", sentence.substr(i).c_str());
		i = next[i];
	}
	
	if (DP){
		delete DP;
		DP = NULL;
	}
}

class Solution {
public:
    void test_case1()
    {
        dictionary["i"] = true;
        dictionary["want"] = true;
        dictionary["to"] = true;
        dictionary["go"] = true;
        dictionary["home"] = true;
        dictionary["tomorrow"] = true;
        dictionary["row"] = true;

        string sentence = "iwanttogohometomorrow";
        Solve(sentence);
    }

};

}
