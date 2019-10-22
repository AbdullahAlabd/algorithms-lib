#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int MAXN = 1e3+3;
int dist[MAXN];

struct edge{
    int f, t, w;
};

int main() {
    memset(dist, inf, sizeof dist); // initialize all distances from source to infinity
    int src = 0; // source node;
    dist[src] = 0;
    vector<edge> edges;
    for(int i = 0; i < n-1; i++) { // O(V*E)
        for(auto e: edges) {
            dist[e.t] = min(dist[e.t], dist[e.f]+e.w);
        }
    }
}
