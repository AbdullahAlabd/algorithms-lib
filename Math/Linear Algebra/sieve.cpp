const int MAXN = 1e5 + 5; 
vector<int> sieve() {
    vector<bool> isPrime(MAXN, 1);
    vector<int> primes;
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i * i < MAXN; i++) {
        if(isPrime[i]) {
            for(int p = i * i; p < MAXN; p += i) {
                isPrime[p] = false;
            }
        }
    }
    for(int p = 2; p < MAXN; p++) {
        if(isPrime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}
