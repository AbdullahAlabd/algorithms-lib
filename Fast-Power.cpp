typedef long long ll;

int fastPower(ll x, ll n, int mod) { //where 1 < mod < max_int;
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
