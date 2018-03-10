#include <bits/stdc++.h>
using namespace std;

const char MAX_CHAR = 'z', MIN_CHAR = 'A';

struct node {
    node *fail, *child[MAX_CHAR-MIN_CHAR+1];
    vector<int> patIdx;
    node() {
        memset(child, 0, sizeof child); // initialize to null
    }
};

struct aho_corasick {

    int range, patCount; // the range betwean min and max, patCount is the number of inserted patterns.
    node *root; // root of the trie
    vector<int> ans; // for pattern number i how many times is appears in the main string.
    
    aho_corasick() {
        patCount = 0;
        range = MAX_CHAR-MIN_CHAR+1;
        root = new node();
    }

    void insert(char *str) { // insert a pattern in the trie
        node *cur = root;
        int ch;
        for(; *str; str++){
        ch = *str-MIN_CHAR;
        if(cur->child[ch] == 0)
            cur->child[ch] = new node();
            cur = cur->child[ch];
        }
        cur->patIdx.push_back(patCount++); // end node of a pattern
        ans.push_back(0); // add another element ans to hold the answer of this pattern.
    }

    void build() { // build failure on the trie
        queue<node*> q;
        // initalize failure of first level childs.
        for(int i = 0; i < range; i++)
            if(root->child[i])
                q.push(root->child[i]), root->child[i]->fail = root;

        node *cur, *chld, *k;
        vector<int> *failList, *curList;
        // bfs
        while(!q.empty()){
            cur = q.front();
            q.pop();

            for(int i = 0; i < range; i++){
                // calculate failure of this child
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
                    // insert failure list of patterns to cur list;
                    curList = &(chld->patIdx);
                    failList = &(chld->fail->patIdx);
                    curList->insert(curList->end(), failList->begin(), failList->end());
                    // insert child to queue;
                    q.push(chld);
                }
            }
        }
    }

    void answer(char *str) { // find inserted patterns in the main string str.
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
            
            for(int ptrn: cur->patIdx)
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
        // get patterns
        for(int i = 0; i < q; i++){
            cin >> T;
            aho.insert(&T[0]);
        }
        // build failure on trie
        aho.build();
        //answer for this main string S
        aho.answer(&S[0]);
        for(int counter: aho.ans)
            puts(counter?"y":"n");
    }
}
