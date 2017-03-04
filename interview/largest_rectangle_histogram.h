#include "common.h"
using namespace std;

namespace largest_rectangle_histogram {

#define MAX(a,b) ((a)>=(b)?(a):(b))

int largest_rectangle_area(const vector<unsigned int> &input_height) {

    stack<unsigned int> s;
    vector<unsigned int> height(input_height);
    height.push_back(0);
    unsigned int result = 0;
    for (unsigned int i = 0; i < height.size();){
        if (s.empty() || height[i]>height[s.top()])
            s.push(i++);
        else{
            int tmp = s.top();
            s.pop();
            result = MAX(result, height[tmp]*(s.empty()?i:i-s.top()-1));
        }
    }
    return result;
}

}
