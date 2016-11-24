#include <iostream>
using namespace std;

#define MAXSIZE 1280
static int coin[] = {1, 5, 10, 25};
static int DP[MAXSIZE] = {0};
static int prevSeq[MAXSIZE] = {0};

int minCoins(int expValue)
{
	int i, j, num;
	if (expValue == 0)
		return 0;

	for (i = 1; i <= expValue; i++){
		num = 100; // infinite
		for (j = 0; j < 4; j++){
			if (i>=coin[j] && 1+DP[i-coin[j]] < num){
				num = 1+DP[i-coin[j]];
				prevSeq[i] = i-coin[j];
			}
		}
		DP[i] = num;
	}

	return num;
}

void test()
{
	int expValue = 3;
	int minnum = minCoins(expValue);
	printf("DP = \n");
	for (int i = 0; i <= expValue; i++){
		printf("%d, ", DP[i]);
	}
	printf("\n the coins are: \n");
	int j = expValue;
	while (j){
		printf("%d, ", j-prevSeq[j]);
		j = prevSeq[j];
	}
}