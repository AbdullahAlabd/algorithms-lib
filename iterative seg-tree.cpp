struct seg_tree{

    const static int n = 1<<17; //size of array
    int tree[n<<1]; // n*2
    int e = 0; //identity

    int (*op)(int, int); // function of get

    int get(int a, int b) {
        a += n; b += n;
        int s = e;
        while (a <= b) {
            if (a&1) s = op(s, tree[a++]);
            if (b%2 == 0) s = op(s, tree[b--]);
            a >>= 1; b >>= 1;
        }
        return s;
    }

    void update(int k, int x){ //update index k by value x
        k += n;
        tree[k] = x;
        for (k >>= 1; k >= 1; k >>= 1) {
            tree[k] = op(tree[k<<1], tree[k<<1|1]);
        }
    }
};

int sum(int a, int b){return a+b;}
int maxx(int a, int b){return max(a,b);}
 
seg_tree seg1, seg2;
 
int main(){
 
 
    //segment tree of sum
    seg1.e=0, seg1.op=&sum;
    seg1.update(1, 1);
    seg1.update(2, 2);
    seg1.update(3, 3);
    cout << seg1.get(2, 8) << endl;

}
