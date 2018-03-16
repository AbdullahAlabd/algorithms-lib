#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct sparseTable{

    static const int MAXN = 100005; //max arr size
    static const int K = log(MAXN) / log(2); // max level
    static const int I = INT_MAX; // identity element

    int Arr[MAXN]; //input array
    int SpT[MAXN][K+1]; //sparse table array
    int Log2[MAXN]; //log(i) to the base 2

    int op(int a, int b){ //the operation used.
        return min(a, b);
    }
    
    void build(int n){
        
        int pow2 = 0;
        for(int i = 0; i < n; i++){
            if(1<<pow2 == i+1)
                pow2++;
            Log2[i+1] = pow2-1;
            SpT[i][0] = Arr[i];
        }
        for(int j = 1; (1<<j) <= n; j++)
            for(int i = 0; i + (1 << j) -1 < n ; i++)
                SpT[i][j] = op(SpT[i][j-1], SpT[i+(1<<(j-1))][j-1]);
    }
    
    //general case
    int query2(int l, int r){ // O(log n)
        
        int res = I;
        for(int j = K; j >= 0; j--)
            if(l + (1 << j) - 1 <= r) {
                res = op(res, SpT[l][j]);
                l += 1 << j; // instead of having l', we increment l directly
            }
        return res;
    }
    
    //idempotent functions only
    int query(int l, int r){ // O(1)
        
        int k = Log2[r-l+1];
        return op(SpT[l][k],SpT[r-(1<<k)+1][k]);
    }
};

int main(){
    sparseTable sp;
    int n,q,l,r;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d",&sp.Arr[i]);
    }
    sp.build(n);
    scanf("%d",&q);
    for(int i =0;i<q;i++){
        scanf("%d %d",&l,&r);
        printf("%d\n",sp.query(l,r));
    }
}
