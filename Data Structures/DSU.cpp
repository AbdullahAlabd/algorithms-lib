struct DSU {
    static const int MAXN = 1e5 + 5; 
    int parent[MAXN], rank[MAXN];

    DSU() {
        for(int idx = 0; idx < MAXN; idx++) {
            parent[idx] = idx, rank[idx] = 1;
        }
    }

    int root(int idx) {
        while(idx != parent[idx]) {
            idx = parent[idx] = parent[parent[idx]];
        }
        return idx;
    }

    int unite(int a, int b) {
        a = root(a), b = root(b);
        if(a == b) {
            return a;
        }
        if(rank[a] < rank[b]) {
            swap(a, b);
        }
        if(rank[a] == rank[b]) {
            rank[a]++;
        }
        parent[b] = a;
        return a;
    }
};
