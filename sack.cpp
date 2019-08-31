#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5;

vector<int> g[MAXN]; //tree
vector<int> *vec[MAXN];
int sz[MAXN]; // size of tree

//////////////////////////
// your sack data stucture.
//////////////////////////

int subTreeSize(int v, int p) {
    sz[v] = 1;
    for(auto u: g[v])
        if(u - p)
            sz[v] += subTreeSize(u, v);
    return sz[v];
}

void dfs(int v, int p, bool keep) {

    int mx = 0, big = -1;

    for(auto u: g[v])
        if(u - p && sz[u] > mx)
            big = u, mx = sz[u];

    for(auto u: g[v])
        if(u - p && u - big)
            dfs(u, v, 0);

    if(big+1)
        dfs(big, v, 1), vec[v] = vec[big];
    else
        vec[v] = new vector<int> (); // no big child => no childs at all.

    vec[v]->push_back(v);

    ////////////////
    // add v to sack
    ////////////////

    for(auto u: g[v]) { // add light child's subtree.
        if(u - p && u - big) {
            for(auto x: *vec[u]) {
                vec[v]->push_back(x);
                ////////////////
                // add x to sack
                ///////////////
            }
        }
    }
    ///////////////////////////////
    // now we have answer of node v
    ////////////////////////////////
    if(!keep) {
        // can reset sack vars here.
        for(auto u: *vec[v]) {
            ////////////////////
            // remove u from sack
            ////////////////////
        }
    }
}

int main() {
    int n, u, v;
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    subTreeSize(1, -1);
    dfs(1, -1, 0); // last param better be 0 if theres multiple testcases.
}
