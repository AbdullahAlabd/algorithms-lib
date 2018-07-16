#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9+7, MAXN = 1000000;
int fact[MAXN];

int fast_power(ll x, ll n, int mod) {
    ll ans = 1, base = x % mod;
    while(n){
        if(n&1){
            ans = (ans * base) % mod;
            n--;
        }else{
            base = (base * base) % mod;
            n /= 2;
        }
    }
    if (ans < 0) ans += mod;
    return ans;
}

int mod_inv(int a, int mod){
    return fast_power(a, mod-2, mod);
}

int nCr(int n, int r) { // in O(1)
    return (fact[n] * ((1ll * mod_inv(fact[n-r], mod) * mod_inv(fact[r], mod)) % mod)) % mod;
}


int main() { 
    // pre-computations in O(MAXN)
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = (1LL*i*fact[i-1])%mod;
    }
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r) << endl;
}
