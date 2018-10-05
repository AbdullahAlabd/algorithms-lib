#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+5;

string treeCan(vector<int> g[], int v, int p = -1) { // treeCanonicalForm of a tree rooted at v;
    vector<string> childs;
    for(auto u: g[v])
        if(u - p)
            childs.push_back(treeCan(g, u, v));
    string nodeRep = "(";
    sort(childs.begin(), childs.end());
    for(auto chRep: childs)
        nodeRep += chRep;
    nodeRep += ")";
    return nodeRep;
}

int mxlv, far;
int P[MAXN];
void dfs(vector<int> g[], int v, int p = -1, int lv = 0) {
    P[v] = p;
    if(lv == 0)
        mxlv = far = -1;
    if(lv > mxlv) {
        far = v;
        mxlv = lv;
    }
    for(auto u: g[v])
        if(u - p)
            dfs(g, u, v, lv+1);
}

pair<int, int> centers(vector<int> g[]) {
    pair<int, int> ans = {-1, -1};
    dfs(g, 1);
    dfs(g, far);
    vector<int> diameterPath;
    int nd = far;
    diameterPath.push_back(nd);
    while(P[nd]+1)
        diameterPath.push_back(nd = P[nd]);
    ans.first = diameterPath[diameterPath.size()/2];
    if(diameterPath.size() > 1 && diameterPath.size()%2 == 0)
        ans.second = diameterPath[diameterPath.size()/2-1];
    return ans;
}

int main() {
    int t, n, u, v;
    vector<int> T1[MAXN], T2[MAXN];
    string canT11, canT12, canT21, canT22;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if(n <= 2) {
            for(int i = 0; i < 2*n-2; i++)
                scanf("%d %d", &u, &v);
            puts("YES");
            continue;
        }
        for(int i = 0; i < MAXN; i++) {
            T1[i].clear();
            T2[i].clear();
        }
        for(int i = 0; i < n-1; i++) {
            scanf("%d %d", &u, &v);
            T1[u].push_back(v);
            T1[v].push_back(u);
        }
        for(int i = 0; i < n-1; i++) {
            scanf("%d %d", &u, &v);
            T2[u].push_back(v);
            T2[v].push_back(u);
        }
        pair<int, int> ct1 = centers(T1), ct2 = centers(T2);
        if((ct1.second == -1 && ct2.second != -1) || (ct2.second == -1 && ct1.second != -1)) {
            puts("NO");
        } else {
            if(ct1.second == -1) {
                puts(treeCan(T1, ct1.first) == treeCan(T2, ct2.first)? "YES" : "NO");
            } else {
                canT11 = treeCan(T1, ct1.first), canT12 = treeCan(T1, ct1.second),
                canT21 = treeCan(T2, ct2.first), canT22 = treeCan(T2, ct2.second);
                puts(canT11 == canT21 || canT11 == canT22 || canT12 == canT21 || canT12 == canT22 ? "YES" : "NO");

            }
        }
    }
}
