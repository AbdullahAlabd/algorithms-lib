#include <bits/stdc++.h>
using namespace std;

const char MAX_CHAR = 'z', MIN_CHAR = 'a';

struct node{
    node *child[MAX_CHAR-MIN_CHAR+1];
    bool isLeaf;
    node() {
        isLeaf = 0;
        memset(child, 0, sizeof child);
    }
};

struct trie {
    
    node *root;
    
    trie() {
        root = new node();
    }
    
	void insert(char *str) { // reference to the current char in the char sequence starting at str;
        node *cur = root;
        int ch;
        for(; *str; str++){
            ch = *str-MIN_CHAR;
            if(cur->child[ch] == 0) // have no child;
                cur->child[ch] = new node();
            cur = cur->child[ch];
        }
        cur->isLeaf = true; // end of char sequence
	}

	bool find(char *str) {
        node *cur = root;
        int ch;
        for(; *str; str++){
            ch = *str-MIN_CHAR;
            if(cur->child[ch]) // have the neaded child;
                cur = cur->child[ch];
            else
                return false;
        }
        return cur->isLeaf; // end of char sequence
	}
};
