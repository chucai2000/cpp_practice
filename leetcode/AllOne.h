#ifndef ALL_ONE_H
#define ALL_ONE_H

#include "common.h"
using namespace std;

class AllOne {
public:

    using Bucket = pair<int, unordered_set<string>>;

    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {

        if (mData.count(key) == 0) {
            if (mBuckets.empty() || mBuckets.begin()->first > 1) {
                Bucket nb = {1, unordered_set<string>{key}};
                mBuckets.insert(mBuckets.begin(), nb);
            }
            else if (mBuckets.begin()->first == 1) {
                mBuckets.begin()->second.insert(key);
            }
            mData[key] = mBuckets.begin();
        }
        else {
            list<Bucket>::iterator bucketItr = mData[key];
            int keyVal = bucketItr->first + 1;

            list<Bucket>::iterator prevBucketItr = bucketItr;
            //auto vis1 = *bucketItr;
            ++bucketItr;
            if (bucketItr == mBuckets.end() || bucketItr->first > keyVal) {
                bucketItr = mBuckets.insert(bucketItr, make_pair(keyVal, unordered_set<string>{key}));
            }
            else {
                bucketItr->second.insert(key);
            }
            //auto vis2 = *bucketItr;
            prevBucketItr->second.erase(key);
            if (prevBucketItr->second.empty()) {
                mBuckets.erase(prevBucketItr);
            }

            mData[key] = bucketItr;
        }

    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (mData.count(key) == 0) {
            return;
        }

        list<Bucket>::iterator bucketItr = mData[key];
        if (bucketItr->first == 1) {
            bucketItr->second.erase(key);
            if (bucketItr->second.empty()) {
                mBuckets.erase(bucketItr);
            }
            mData.erase(key);
        }
        else if (bucketItr->first > 1) {
            int keyVal = bucketItr->first - 1;

            list<Bucket>::iterator postBucketItr = bucketItr;

            if (bucketItr == mBuckets.begin()) {
                bucketItr = mBuckets.insert(bucketItr, make_pair(keyVal, unordered_set<string>{key}));
            }
            else if ((--bucketItr)->first < keyVal) {
                bucketItr = mBuckets.insert(postBucketItr, make_pair(keyVal, unordered_set<string>{key}));
            }
            else {
                bucketItr->second.insert(key);
            }

            postBucketItr->second.erase(key);
            if (postBucketItr->second.empty()) {
                mBuckets.erase(postBucketItr);
            }

            mData[key] = bucketItr;
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (mBuckets.empty()) return "";
        return *(mBuckets.rbegin()->second.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (mBuckets.empty()) return "";
        return *(mBuckets.begin()->second.begin());
    }

private:
    list<Bucket> mBuckets;
    unordered_map<string, list<Bucket>::iterator> mData;
};

class Solution
{
public:
    void test_case1() {
        AllOne obj;
        string minstr, maxstr;

        obj.inc("apple");
        obj.inc("orange");
        obj.inc("orange");
        obj.inc("orange");
        obj.inc("orange");
        obj.dec("orange");
        obj.dec("orange");

        minstr = obj.getMinKey();
        maxstr = obj.getMaxKey();

        int ep = 0;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
#endif
