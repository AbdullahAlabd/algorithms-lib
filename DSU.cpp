const int MAXNODE = 52;
 
struct DSU{
 
    int id[MAXNODE], sz[MAXNODE];
 
    DSU() {
        for(int i = 0; i < MAXNODE; i++)
            id[i] = i, sz[i] = 1;
    }
 
    int root(int i) {
        while(i != id[i])
            i = id[i] = i[id][id]; //equivalent to id[id[i]]
        return i;
    }
 
    void unite(int a , int b) {
        a = root(a), b = root(b);
        if(a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        if (sz[a] == sz[b]) ++sz[a];
        id[b] = a;
    }
};
