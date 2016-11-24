#ifndef _LRU_H_
#define _LRU_H_

#include "common.h"
using namespace std;

class LRUCache{
public:

    LRUCache(int capacity): mBuckets(capacity, make_pair(0, make_pair(0,0))), mCount(0) {
    }

    int get(int key) {
        if (mData.count(key) == 0) return -1;

        unsigned int keyIdx = mData.at(key);
        if (keyIdx >= mBuckets.size()) {
            throw runtime_error("key index should not exceed capacity.");
        }
        int res = mBuckets[keyIdx].second.first;
        mBuckets[keyIdx].second.second = mBuckets.size()-1;
        return res;
    }

    void set(int key, int value) {
        if (mData.count(key) != 0) {
            mBuckets[mData.at(key)].second.first = value;
            ++mBuckets[mData.at(key)].second.second;
        }
        else {
            if (mCount < mBuckets.size()) {
                mBuckets[mCount] = make_pair(key, make_pair(value, 1));
                mData[key] = mCount;
                ++mCount;
            }
            else {
                // remove least recently used
                unsigned int lruIdx = 0;
                int numOfUsed = INT_MAX;
                for (unsigned int idx = 0; idx < mBuckets.size(); ++idx) {
                    if (mBuckets[idx].second.second < numOfUsed) {
                        numOfUsed = mBuckets[idx].second.second;
                        lruIdx = idx;
                    }
                }
                int oldKey = mBuckets[lruIdx].first;
                mBuckets[lruIdx] = make_pair(key, make_pair(value, 1));
                mData.erase(oldKey);
                mData[key] = lruIdx;
            }
        }
    }

private:
    vector<pair<int, pair<int,int>>> mBuckets;
    unordered_map<int, unsigned int> mData;
    int mCount;
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
        int xx = obj.get(2);

        int ep = 0;
    }
};

#endif
