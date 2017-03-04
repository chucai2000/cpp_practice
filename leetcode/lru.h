#include "common.h"
using namespace std;

namespace lru {

class LRUCache{
public:

    LRUCache(int capacity): m_buckets(capacity, make_pair(0, make_pair(0,0))), m_count(0) {
    }

    int get(int key) {
        if (m_data.count(key) == 0) return -1;

        unsigned int key_idx = m_data.at(key);
        if (key_idx >= m_buckets.size()) {
            throw runtime_error("key index should not exceed capacity.");
        }
        int res = m_buckets[key_idx].second.first;
        m_buckets[key_idx].second.second = m_buckets.size()-1;
        return res;
    }

    void set(int key, int value) {
        if (m_data.count(key) != 0) {
            m_buckets[m_data.at(key)].second.first = value;
            ++m_buckets[m_data.at(key)].second.second;
        }
        else {
            if (m_count < m_buckets.size()) {
                m_buckets[m_count] = make_pair(key, make_pair(value, 1));
                m_data[key] = m_count;
                ++m_count;
            }
            else {
                // remove least recently used
                unsigned int lru_idx = 0;
                int num_of_used = INT_MAX;
                for (unsigned int idx = 0; idx < m_buckets.size(); ++idx) {
                    if (m_buckets[idx].second.second < num_of_used) {
                        num_of_used = m_buckets[idx].second.second;
                        lru_idx = idx;
                    }
                }
                int old_key = m_buckets[lru_idx].first;
                m_buckets[lru_idx] = make_pair(key, make_pair(value, 1));
                m_data.erase(old_key);
                m_data[key] = lru_idx;
            }
        }
    }

private:
    vector<pair<int, pair<int,int>>> m_buckets;
    unordered_map<int, unsigned int> m_data;
    unsigned int m_count;
};

class Solution {
public:
    void test_case1() {
        /*LRUCache obj(4);
        obj.set(1, 100);
        obj.set(2, 100);
        obj.set(3, 100);
        obj.set(4, 100);

        obj.set(1, 1000);
        obj.set(4, 1000);
        obj.get(2);
        obj.get(4);
        int xx = obj.get(5);

        obj.set(4, 4000);
        obj.set(-1, -1);*/

        LRUCache obj(2);
        obj.set(2,1);
        obj.set(2,2);
        obj.get(2);
        obj.set(1,1);
        obj.set(4,1);
        std::cout << obj.get(2) << std::endl;
    }
};

}
