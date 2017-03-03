#include "common.h"
using namespace std;

namespace str_to_int {

class Solution {
public:

    int pure_digits(const string str, const int sign) {
        int val = 0;
        for (size_t i = 0; i < str.length(); i++) {
            int digital_val = char(str[i]) - '0';
            if (-1.0*val <= 1.0*(INT_MIN + digital_val)/10) {
                printf("val=%d, INT_MIN=%d, digital_val=%d\n", val, INT_MIN, digital_val);
                printf("-val=%d, RIGHT=%d\n", -val, (INT_MIN+digital_val)/10);
                if (sign == -1) return INT_MIN;
                else return INT_MAX;
            }
            else if (1.0*val >= 1.0*(INT_MAX-digital_val)/10) {
                printf("2\n");
                if (sign == 1) return INT_MAX;
                else return -(val*10+digital_val);
            }
            else {
                val = val * 10 + digital_val;
            }
            
        }
        return sign * val;
    }

    int my_atoi(string str) {
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
        
        int initial_index = index;
        while (index < str.length()) {
            if (!(str[index] < '0' || str[index] > '9')) {
                index++;
            }
            else {
                break;
            }
        }
        string pure_digitsPortion = str.substr(initial_index, index-initial_index);
        
        return pure_digits(pure_digitsPortion, sign);
    }

    void test_case1() {
        string str = "-2147483647";
        std::cout << my_atoi(str) << std::endl;
    }
};

}
