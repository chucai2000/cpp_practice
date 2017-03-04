#include "common.h"

namespace split_merged_documents {

#define MAX_VALUE 100000

std::map<std::string, bool> dictionary;

void Solve(std::string &sentence)
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
            std::string candidate;
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
        std::cout << DP[i] << ",";
    std::cout << std::endl;
	for (i=0;i<LEN;i++)
        std::cout << next[i] << ",";
    std::cout << std::endl;

    std::cout << "Incorrect word #: " << DP[0] << std::endl;
	i = 0;
	while (i != -1){
		if (next[i] != -1)
            std::cout << sentence.substr(i, next[i]-i).c_str() << std::endl;
		else
            std::cout << sentence.substr(i).c_str() << std::endl;
		i = next[i];
	}
	
	if (DP){
		delete DP;
		DP = NULL;
	}
}

}
