#ifndef _TRIE_TREE_H_
#define _TRIE_TREE_H_

#include "CommonDataStructure.h"
using namespace std;

class TrieNode {
private:
    char mLabel;
    bool mWordComplete;
    vector<TrieNode*> mChildren;
public:

    // Initialize your data structure here.
    TrieNode(char label) : mLabel(label), mWordComplete(false) {
    }

    void setLabel(const char &label) {mLabel = label;}
    char getLabel() const {return mLabel;}
    void setWordComplete(const bool &wordComplete) {mWordComplete = wordComplete;}
    bool getWordComplete() const {return mWordComplete;}
    vector<TrieNode*> &getChildren() {return mChildren;}
};

class Trie {
public:
    Trie() {
        root = new TrieNode('#');
    }

    // Inserts a word into the trie.
    void insert(string word) {
        insertHelper(word, root);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return searchHelper(word, root);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return startsWithHelper(prefix, root);
    }

private:
    TrieNode* root;

    bool searchSpecifiedChild(TrieNode *node, char target, TrieNode* &searchedNode) {
        for (TrieNode* &child : node->getChildren()) {
            if (child->getLabel() == target) {
                searchedNode = child;
                return true;
            }
        }
        return false;
    }

    bool insertHelper(string word, TrieNode *node) {
        if (word.empty()) {
            node->setWordComplete(true);
            return true;
        }

        TrieNode *childNode = NULL;
        if (searchSpecifiedChild(node, word[0], childNode)) {
            return insertHelper(word.substr(1), childNode);
        }
        else {
            childNode = new TrieNode(word[0]);
            node->getChildren().push_back(childNode);
            return insertHelper(word.substr(1), childNode);
        }
    }

    bool searchHelper(string word, TrieNode *node) {
        if (word.empty()) {
            return node->getWordComplete();
        }

        TrieNode *childNode = NULL;
        if (searchSpecifiedChild(node, word[0], childNode)) {
            return searchHelper(word.substr(1), childNode);
        }
        else {
            return false;
        }
    }

    bool startsWithHelper(string wordPrefix, TrieNode *node) {

        if (wordPrefix.empty()) return true;

        TrieNode *childNode = NULL;
        if (searchSpecifiedChild(node, wordPrefix[0], childNode)) {
            return startsWithHelper(wordPrefix.substr(1), childNode);
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

        bool b6 = trie.startsWith("app");
        bool b7 = trie.startsWith("api");

        int ep = 0;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

#endif
