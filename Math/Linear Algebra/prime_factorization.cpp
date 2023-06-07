vector<int> getSmallestPrimeFactors() { // modified version of sieve 
    vector<int> SPF(MAXN, 1); // smallest prime factor
    for(int i = 1; i < MAXN; i++) {
        SPF[i] = (i & 1) ? i : 2;
    }
    for(int p = 3; p * p < MAXN; p += 2) {
        if(SPF[p] == p) { // prime
            for(int i = p * p; i < MAXN; i += 2 * p) {
                if(SPF[i] == i) { // not marked yet
                    SPF[i] = p;
                }
            }
        }
    }
    return SPF;
}


while(num > 1) { // factorization in O Log(num)
    num /= SPF[num];
}
