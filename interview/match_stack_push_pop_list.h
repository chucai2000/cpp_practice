#include "common.h"
using namespace std;

namespace match_stack_push_pop_list {

class Solution {

    bool confirm_stack(vector<int> &src, vector<int> &dest)
    {
        if (src.size() == 0 && dest.size() == 0)
            return true;
        else{
            if (src.size()==0 || dest.size()==0)
                return false;
        }

        stack<int> buffer;
        unsigned int i = 0;
        unsigned int j = 0;
        while (i < dest.size()){
            if (!buffer.empty() && buffer.top() == dest[i]){
                buffer.pop();
                i++;
            }
            else {
                while (j < src.size() && dest[i] != src[j]){
                    buffer.push(src[j]);
                    j++;
                }
                if (j == src.size())
                    return false;
                else{
                    i++; // eq. that src[j] is first pushed into the buffer and then taken out
                    j++;
                }
            }
        }

        return true;
    }

public:
    void test_case1()
    {
        int s1[] = { 1, 2, 3, 4, 5, 6, 7 };
        int s2[] = { 4, 3, 6, 5, 7, 2, 1 };
        vector<int> src(s1, s1+sizeof(s1)/sizeof(int));
        vector<int> dst(s2, s2+sizeof(s2)/sizeof(int));
        bool ret = confirm_stack(src, dst);
        std::cout << ret << std::endl;
    }
};

}