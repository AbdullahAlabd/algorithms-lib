#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50004;
vector<int> *vec[MAXN];
vector<vector<int> >g(MAXN);
int sz[MAXN];

//Global Vars:
int k;
int col[MAXN];

//my sack
////////////////////////////
int cnt[MAXN];
////////////////////////////

int subTreeSize(int v, int p){
    sz[v] = 1;
    for(auto u : g[v])
        if(u != p)
            sz[v] += subTreeSize(u, v);
    return sz[v];
}


void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
           mx = sz[u], bigChild = u;

    for(auto u : g[v])
       if(u != p && u != bigChild)
           dfs(u, v, 0);

    if(bigChild != -1)
        dfs(bigChild, v, 1), vec[v] = vec[bigChild];
    else
        vec[v] = new vector<int> ();

    cnt[ col[v] ]++;
    ////////////////////////////
    vec[v]->push_back(v);
    ////////////////////////////
    for(auto u : g[v])
        if(u != p && u != bigChild)
            for(auto x : *vec[u]){
                ////////////////////////////
                cnt[ col[x] ]++;
                ////////////////////////////
                vec[v] -> push_back(x);
            }

    //now (*cnt[v])[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    // note that in this step *vec[v] contains all of the subtree of vertex v.

    if(keep == 0)
        for(auto u : *vec[v]){
            ////////////////////////////
            cnt[ col[u] ]--;
            ////////////////////////////
        }
}

int main(){
    int n, u, v;
    memset(sz, 0, sizeof sz);
    scanf("%d%d", &n, &k);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    subTreeSize(1, -1);
    dfs(1, -1, 1);

}
