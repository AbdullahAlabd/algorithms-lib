    #include <bits/stdc++.h>
    using namespace std;
     
    const int mod = 1e9+7;
    const int MAXN = 1000;
    typedef long long ll;
     
    ///////////////////////////////////////////////////////////////////////
     
    ll fib[MAXN];
     
    ll fibonacci(int n) { //  0 <= n <= 92
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;
        if (fib[n] != -1)
            return fib[n];
     
        ll k = n >> 1;
        ll a = fibonacci(k), b = fibonacci(k+1);
     
        if (n&1)
            return fib[n] = b * b + a * a;
        return fib[n] = a * (2 * b - a);
     
    }
     
    ///////////////////////////////////////////////////////////////////////
     
    void fibonacci1(ll n, ll&x, ll&y){ //O(log n) with mod , the result in x;
        if(n==0){
            x = 0;
            y = 1;
            return;
        }
     
        if(n&1){
            fibonacci1(n-1, y, x);
            y = (y+x)%mod;
        }else{
            ll a, b;
            fibonacci1(n>>1, a, b);
            y = (a*a+b*b)%mod;
            x = (a*b + a*(b-a+mod))%mod;
        }
    }
     
    ///////////////////////////////////////////////////////////////////////
     
    int main(){
        ll x , y;
        memset(fib,-1,sizeof fib);
        for(int i =1;i<=92;i++){
            fibonacci1(ll(i),x,y);
            cout<<fibonacci(i)<<" "<<x<<endl;
        }
    }
     
