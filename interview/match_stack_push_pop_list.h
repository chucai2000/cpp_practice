#include "common.h"
using namespace std;

namespace match_stack_push_pop_list {

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



}
