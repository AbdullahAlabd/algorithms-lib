#include <bits/stdc++.h>
using namespace std;

struct SegTree{
    static const int MAXN = 1<<17; // smallest power of 2 greater than size of input array.
    int input[MAXN]; // input Array.
    int segTree[2*MAXN]; // one based.

    const int I = INT_MAX; // Identity of the operation.
    int op(int a, int b) { // the operation.
        return min(a, b);
    }
    //Standard Values: nd = 1, st = 0, ed = MAXN-1
    void build(int nd, int st, int ed) {
        if(st == ed) {
            segTree[nd] = input[st];
        } else {
            int md = (st + ed) / 2;
            build(2*nd, st, md);
            build(2*nd+1, md+1, ed);
            segTree[nd] = op(segTree[2*nd], segTree[2*nd+1]);
        }
    }

    void update(int nd, int st, int ed, int idx, int val) {
        if(st == ed) { // the needed update.
            input[idx] = val;
            segTree[nd] = val;
        } else {
            int md = (st + ed) / 2;
            if(st <= idx && idx <= md) {
                update(2*nd, st, md, idx, val);
            } else {
                update(2*nd+1, md+1, ed, idx, val);
            }
            segTree[nd] = op(segTree[2*nd], segTree[2*nd+1]);
        }
    }

    int query(int nd, int st, int ed, int l, int r) {
        if(r < st || ed < l) { // not covered.
            return I;
        }
        if(l <= st && ed <= r) { // completely covered.
            return segTree[nd];
        } // partially covered.
        int md = (st + ed) /2;
        int p1 = query(2*nd, st, md, l, r);
        int p2 = query(2*nd+1, md+1, ed, l, r);
        return op(p1, p2);
    }
};


int main() {
    SegTree sg;
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) {
        scanf("%d", &sg.input[i]);
    }
    sg.build(1, 0, n-1);
    char c; int a, b;
    for(int i = 0; i < q; i++) {
        scanf(" %c %d %d", &c, &a, &b);
        if(c == 'u') {
            sg.update(1, 0, n-1, a-1, b);
        } else {
            printf("%d\n", sg.query(1, 0, n-1, a-1, b-1));
        }
    }
}
