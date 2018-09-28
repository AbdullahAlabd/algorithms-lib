#include <bits/stdc++.h>
using namespace std;

const int N = 1<<17; // a power of two greater than max n
struct segTree {

    int tree[N<<1];
    int I = 0; // operation identity.

    int op(int a, int b) { // operation.
        return a + b;
    }

    segTree() {
        memset(tree, I, sizeof tree);
    }

    void build() {
        for(int i = N-1; i; i--) {
            tree[i] = op(tree[i<<1], tree[i<<1|1]);
        }
    }

    void update(int idx, int val) {
        idx += N;
        tree[idx] = op(tree[idx], val);
        for (idx >>= 1; idx; idx >>= 1) {
            tree[idx] = op(tree[idx<<1], tree[idx<<1|1]);
        }
    }

    int get(int l, int r) {
        int res = I;
        l += N; r += N;
        while (l <= r) {
            if(l&1) res = op(res, tree[l++]);
            if(!(r&1)) res = op(res, tree[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main() {
    segTree sg;
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &sg.tree[N+i]);
    }
    sg.build();
    scanf("%d", &m);
    int q, l, r, v, idx;
    for(int i = 0; i < m; i++) {
        scanf("%d", &q);
        if(q) {
            scanf("%d %d", &idx, &v);
            sg.update(idx, v);
        } else {
            scanf("%d %d", &l, &r);
            printf("%d\n", sg.get(l, r));
        }
    }
}
