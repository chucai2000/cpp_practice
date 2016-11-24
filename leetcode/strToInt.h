#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_
	
#include "CommonDataStructure.h"

using namespace std;

class Solution {
public:

    int pureDigits(const string str, const int sign) {
        int val = 0;
        for (size_t i = 0; i < str.length(); i++) {
            int digitalVal = char(str[i]) - '0';
            if (-1.0*val <= 1.0*(INT_MIN + digitalVal)/10) {
printf("val=%d, INT_MIN=%d, digitalVal=%d\n", val, INT_MIN, digitalVal);
printf("-val=%d, RIGHT=%d\n", -val, (INT_MIN+digitalVal)/10);
                if (sign == -1) return INT_MIN;
                else return INT_MAX;
            }
            else if (1.0*val >= 1.0*(INT_MAX-digitalVal)/10) {
printf("2\n");
                if (sign == 1) return INT_MAX;
                else return -(val*10+digitalVal);
            }
            else {
                val = val * 10 + digitalVal;
            }
            
        }
        return sign * val;
    }

    int myAtoi(string str) {
        if (str.length() == 0) return 0;
        int index = 0;
        
        if (str[index] == ' ') {
            do {
                index++;
            } while (str[index] == ' ');
        }
        
        int sign = 1;
        if (str[index] == '-') {
            sign = -1;
            ++index;
        }
        else if (str[index] == '+') {
            ++index;
        }
        else if (str[index] == '.') {
            return 0;
        }
        else if (str[index] < '0' || str[index] > '9') {
            return INT_MAX;
        }
        
        int initialIndex = index;
        while (index < str.length()) {
            if (!(str[index] < '0' || str[index] > '9')) {
                index++;
            }
            else {
                break;
            }
        }
        string pureDigitsPortion = str.substr(initialIndex, index-initialIndex);
        
        return pureDigits(pureDigitsPortion, sign);
    }

    void testCase1() {
        string str = "-2147483647";
        std::cout << myAtoi(str) << std::endl;
    }
};

#endif
