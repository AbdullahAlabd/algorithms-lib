struct BIT {
    static const int MAXN = 1e5 + 5; // max possible idx + 2 at least 1-based
    int data[MAXN] = {}; // 1-based

    int get(int idx) { // get sum of element in range [1, idx].
        int res = 0;
        while(idx) {
            res += data[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    void update(int idx, int val) { // add val to element at idx
        while(idx < MAXN) {
            data[idx] += val;
            idx += idx & -idx;
        }
    }
};
