#include "common.h"
using namespace std;

namespace trie_tree {

class trie_node {
private:
    char m_label;
    bool m_word_complete;
    vector<trie_node*> m_children;
public:

    // Initialize your data structure here.
    trie_node(char label) : m_label(label), m_word_complete(false) {
    }

    void set_label(const char &label) {m_label = label;}
    char get_label() const {return m_label;}
    void set_word_complete(const bool &word_complete) {m_word_complete = word_complete;}
    bool get_word_complete() const {return m_word_complete;}
    vector<trie_node*> &get_children() {return m_children;}
};

class Trie {
public:
    Trie() {
        root = new trie_node('#');
    }

    // Inserts a word into the trie.
    void insert(string word) {
        insert_helper(word, root);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return search_helper(word, root);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool starts_with(string prefix) {
        return starts_withHelper(prefix, root);
    }

private:
    trie_node* root;

    bool search_specified_child(trie_node *node, char target, trie_node* &searched_node) {
        for (trie_node* &child : node->get_children()) {
            if (child->get_label() == target) {
                searched_node = child;
                return true;
            }
        }
        return false;
    }

    bool insert_helper(string word, trie_node *node) {
        if (word.empty()) {
            node->set_word_complete(true);
            return true;
        }

        trie_node *child_node = NULL;
        if (search_specified_child(node, word[0], child_node)) {
            return insert_helper(word.substr(1), child_node);
        }
        else {
            child_node = new trie_node(word[0]);
            node->get_children().push_back(child_node);
            return insert_helper(word.substr(1), child_node);
        }
    }

    bool search_helper(string word, trie_node *node) {
        if (word.empty()) {
            return node->get_word_complete();
        }

        trie_node *child_node = NULL;
        if (search_specified_child(node, word[0], child_node)) {
            return search_helper(word.substr(1), child_node);
        }
        else {
            return false;
        }
    }

    bool starts_withHelper(string word_prefix, trie_node *node) {

        if (word_prefix.empty()) return true;

        trie_node *child_node = NULL;
        if (search_specified_child(node, word_prefix[0], child_node)) {
            return starts_withHelper(word_prefix.substr(1), child_node);
        }
        else {
            return false;
        }
    }

};

class Solution {
public:
    void test_case1() {
        Trie trie;
        trie.insert("abcde");
        trie.insert("apple");
        trie.insert("car");
        trie.insert("carpool");

        bool b1 = trie.search("apple");
        bool b2 = trie.search("car");
        bool b3 = trie.search("cars");
        bool b4 = trie.search("cdar");
        bool b5 = trie.search("carpool");

        bool b6 = trie.starts_with("app");
        bool b7 = trie.starts_with("api");

        int ep = 0;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
}
