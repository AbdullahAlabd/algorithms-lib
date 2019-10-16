#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9+7, MAXN = 1000000;
int fact[MAXN];

int fastPower(ll x, ll n, int mod) {
    ll ans = 1, base = x % mod;
    while(n) {
        if(n&1) {
            ans = (ans * base) % mod;
            n--;
        }
        base = (base * base) % mod;
        n >>= 1;
    }
    return (ans + mod) % mod;
}

int modInv(int a, int mod) {
    return fastPower(a, mod-2, mod);
}

int nCr(int n, int r) { // in O(1)
    return (fact[n] * ((1ll * modInv(fact[n-r], mod) * modInv(fact[r], mod)) % mod)) % mod;
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
