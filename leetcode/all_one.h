#include "common.h"
using namespace std;

namespace all_one {

class all_one {
public:

    using Bucket = pair<int, unordered_set<string>>;

    /** Initialize your data structure here. */
    all_one() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {

        if (m_data.count(key) == 0) {
            if (m_buckets.empty() || m_buckets.begin()->first > 1) {
                Bucket nb = {1, unordered_set<string>{key}};
                m_buckets.insert(m_buckets.begin(), nb);
            }
            else if (m_buckets.begin()->first == 1) {
                m_buckets.begin()->second.insert(key);
            }
            m_data[key] = m_buckets.begin();
        }
        else {
            list<Bucket>::iterator bucket_itr = m_data[key];
            int key_val = bucket_itr->first + 1;

            list<Bucket>::iterator prev_bucket_itr = bucket_itr;
            //auto vis1 = *bucket_itr;
            ++bucket_itr;
            if (bucket_itr == m_buckets.end() || bucket_itr->first > key_val) {
                bucket_itr = m_buckets.insert(bucket_itr, make_pair(key_val, unordered_set<string>{key}));
            }
            else {
                bucket_itr->second.insert(key);
            }
            //auto vis2 = *bucket_itr;
            prev_bucket_itr->second.erase(key);
            if (prev_bucket_itr->second.empty()) {
                m_buckets.erase(prev_bucket_itr);
            }

            m_data[key] = bucket_itr;
        }

    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (m_data.count(key) == 0) {
            return;
        }

        list<Bucket>::iterator bucket_itr = m_data[key];
        if (bucket_itr->first == 1) {
            bucket_itr->second.erase(key);
            if (bucket_itr->second.empty()) {
                m_buckets.erase(bucket_itr);
            }
            m_data.erase(key);
        }
        else if (bucket_itr->first > 1) {
            int key_val = bucket_itr->first - 1;

            list<Bucket>::iterator post_bucket_itr = bucket_itr;

            if (bucket_itr == m_buckets.begin()) {
                bucket_itr = m_buckets.insert(bucket_itr, make_pair(key_val, unordered_set<string>{key}));
            }
            else if ((--bucket_itr)->first < key_val) {
                bucket_itr = m_buckets.insert(post_bucket_itr, make_pair(key_val, unordered_set<string>{key}));
            }
            else {
                bucket_itr->second.insert(key);
            }

            post_bucket_itr->second.erase(key);
            if (post_bucket_itr->second.empty()) {
                m_buckets.erase(post_bucket_itr);
            }

            m_data[key] = bucket_itr;
        }
    }

    /** Returns one of the keys with maximal value. */
    string get_max_key() {
        if (m_buckets.empty()) return "";
        return *(m_buckets.rbegin()->second.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string get_min_key() {
        if (m_buckets.empty()) return "";
        return *(m_buckets.begin()->second.begin());
    }

private:
    list<Bucket> m_buckets;
    unordered_map<string, list<Bucket>::iterator> m_data;
};

class Solution
{
public:
    void test_case1() {
        all_one obj;
        string minstr, maxstr;

        obj.inc("apple");
        obj.inc("orange");
        obj.inc("orange");
        obj.inc("orange");
        obj.inc("orange");
        obj.dec("orange");
        obj.dec("orange");

        minstr = obj.get_min_key();
        maxstr = obj.get_max_key();
    }
};

/**
 * Your all_one object will be instantiated and called as such:
 * all_one obj = new all_one();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.get_max_key();
 * string param_4 = obj.get_min_key();
 */
}
