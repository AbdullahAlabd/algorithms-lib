#include <bits/stdc++.h>
using namespace std;

const char MAX_CHAR = 'z', MIN_CHAR = 'A';

struct node {
    node *fail, *child[MAX_CHAR-MIN_CHAR+1];
    vector<int> patIdx;
    node() {
        memset(child, 0, sizeof child);
    }
};

struct aho_corasick {

    int range, patCount;
    node *root;
    vector<int> ans;

    aho_corasick() {
        patCount = 0;
        range = MAX_CHAR-MIN_CHAR+1;
        root = new node();
    }

    void insert(char *str) {
        node *cur = root;
        int ch;
        for(; *str; str++){
            ch = *str-MIN_CHAR;
            if(cur->child[ch] == 0)
                cur->child[ch] = new node();
            cur = cur->child[ch];
        }
        cur->patIdx.push_back(patCount++);
        ans.push_back(0);
    }

    void build() { //build failure on the trie
        queue<node*> q;
        for(int i = 0; i < range; i++)
            if(root->child[i])
                q.push(root->child[i]), root->child[i]->fail = root;
	    
        node *cur, *chld, *k;
        vector<int> *failList, *curList;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            for(int i = 0; i < range; i++){
                chld = cur->child[i];
                if(chld){
                    k = cur->fail;
                    while(!(k->child[i])){
                        if(k == root) break;
                        k = k->fail;
                    }
                    if(k->child[i])
                        chld->fail = k->child[i];
                    else
                        chld->fail = root;
                    curList = &(chld->patIdx);
                    failList = &(chld->fail->patIdx);
                    curList->insert(curList->end(), failList->begin(), failList->end());

                    q.push(chld);
                }
            }
        }
    }

    void answer(char *str) {
        node *cur = root, *k;
        int ch;
        for(; *str; str++){
            ch = *str-MIN_CHAR;
            k = cur;
            while(!(k->child[ch])){
                if(k == root) break;
                k = k->fail;
            }
            if(k->child[ch])
                cur = k->child[ch];
            else
                cur = root;
            for(int ptrn : cur->patIdx)
                ans[ptrn]++;
        }
    }

};

int main(){

    int q, k;
    string T, S;
    cin >> k;
    while(k--){
        aho_corasick aho;

        cin >> S;
        cin >> q;
        for(int i = 0; i < q; i++){
            cin >> T;
            aho.insert(&T[0]);
        }

        aho.build();

        aho.answer(&S[0]);

        for(int counter : aho.ans){
            puts(counter?"y":"n");
        }
    }
}
