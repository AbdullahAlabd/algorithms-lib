//solution to https://codeforces.com/gym/100814/problem/C
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

int ans[MAXN]; // ans of ith query.

struct Query {
    int u, v, idx;
};

struct Primitive_DSU { // n Log n total time to merge all.

    vector<int> p;
    vector<vector<int> > comp; // component of node i
    vector<vector<Query> > queries;

    Primitive_DSU(int n) {
        p.resize(n+2);
        queries.resize(n+2);
        comp.resize(n+2);
        for(int i = 0; i <= n; i++) {
            p[i] = i;
            comp[i].push_back(i);
        }
    }

    bool unite(int u, int v, int t) { // t is the time of merge
        u = p[u], v = p[v];
        if(u == v)
            return false;
        if(comp[u].size() < comp[v].size())
            swap(u, v);
        for(auto q: queries[v]) {
            if(p[q.u] == u || p[q.v] == u) {
                if(!ans[q.idx]) {
                    ans[q.idx] = t+1;
                }
            } else {
                queries[u].push_back(q);
            }
        }
        for(int e: comp[v]) {
            comp[u].push_back(e);
            p[e] = u;
        }
        queries[v].clear();
        comp[v].clear();
        return true;
    }
};

int main() {
    int T, n, m, t, u, v;
    scanf("%d", &T);
    queue<Query> q2, q1;
    while(T--) {
        memset(ans, 0, sizeof ans);
        scanf("%d %d", &n, &m);
        Primitive_DSU dsu(n);
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &t, &u, &v);
            if(t == 1) {
                q1.push({u, v, i});
            } else {
                dsu.queries[u].push_back({u, v, i});
                dsu.queries[v].push_back({v, u, i});
                q2.push({u, v, i});
            }
        }
        while(!q1.empty()) {
            Query e = q1.front();
            q1.pop();
            dsu.unite(e.u, e.v, e.idx);
        }
        while(!q2.empty()) {
            Query e = q2.front();
            q2.pop();
            if(dsu.p[e.u] != dsu.p[e.v] || ans[e.idx] > e.idx) {
                printf("-1\n");
            } else {
                printf("%d\n", ans[e.idx]);
            }
        }
    }
}
