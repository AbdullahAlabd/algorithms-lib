struct DSU {
    static const int MAXN = 1e5 + 5; 
    int parent[MAXN], rank[MAXN];

    DSU() {
        for(int idx = 0; idx < MAXN; idx++) {
            parent[idx] = idx, rank[idx] = 1;
        }
    }
    
    int root(int idx) { // O(Log N) worst case
        while(idx != parent[idx]) {
            idx = parent[idx] = parent[parent[idx]]; // path compression.
        }
        return idx;
    }
    // using union by rank and path compression yield in amortized time complexity of O(c) in practice.
    int unite(int a, int b) { // O(Log N) worst case
        a = root(a), b = root(b);
        if(a == b) {
            return a;
        }
        if(rank[a] < rank[b]) { // union by rank.
            swap(a, b);
        }
        if(rank[a] == rank[b]) { 
            rank[a]++;
        }
        parent[b] = a;
        return a;
    }
};
