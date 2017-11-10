#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll mulmod(const ll&a, const ll&b, const ll&p){ // faster way to get (a * b) % mod
	ll y = (ld)a*b/p + 0.5; // y = (a*b)/p + 0.5
	ll  r = a*b - y*p;
	if (r < 0) r = r+p;
	return r;
    	//return a*b%p;
}

ll powmod(ll n, ll exponent, ll modulus){
/* return by (n^exponent)%modulus, here exponent>=0 */
	ll result=1, powres=n%modulus;

	while(exponent){
        if(exponent&1)
            result = mulmod(result, powres, modulus);
        powres = mulmod(powres, powres, modulus);
        exponent >>= 1;
	}
	return result;
}

/*Miller–Rabin Strong Pseudoprime Test*/
bool strong_pseudo_primetest(ll n,int base){ // O(log n)
/* return by 1 if n is a strong pseudo prime for base, otherwise by 0 */

	ll n2 = n-1, res;
	int s = 0;
	//a = base
    	//n-1 = (2^s)*d where d is odd
    	//strong pseudo prime iff [ ( (a^d)%n == 1 ) || ( a^(d*(2^r)) %n == n-1 where r in {0,..,s-1} ) ]
	while(!(n2&1))  n2>>=1, ++s;

	res = powmod(base, n2, n);
	if((res==1) || (res==n-1)) return 1;

	while(--s >= 0)  {
		res = mulmod(res, res, n);
		if(res == n-1) return 1;
	}
	return 0;
}

/*Miller–Rabin primality test*/
bool isprime(ll n){ // tested up to 10e9
	if(n<2) return 0;
	if(n<4) return 1;

	if(!strong_pseudo_primetest(n,2)) return 0;
	if(!strong_pseudo_primetest(n,3)) return 0;
	if(n < 1373653LL) return 1;

	if(!strong_pseudo_primetest(n,5)) return 0;
	if(n < 25326001LL) return 1;

	if(!strong_pseudo_primetest(n,7)) return 0;
	if(n < 3215031751LL) return 1;

	if(!strong_pseudo_primetest(n,11)) return 0;
	if(n < 2152302898747LL) return 1;

	if(!strong_pseudo_primetest(n,13)) return 0;
	if(n < 3474749660383LL) return 1;

	if(!strong_pseudo_primetest(n,17)) return 0;
	if(n < 341550071728321LL) return 1;

	if(!strong_pseudo_primetest(n,19)) return 0;
	if(!strong_pseudo_primetest(n,23)) return 0;
	if(n < 3825123056546413051LL) return 1;

	if(!strong_pseudo_primetest(n,29)) return 0;
	if(!strong_pseudo_primetest(n,31)) return 0;
	if(!strong_pseudo_primetest(n,37)) return 0;

	return 1;
}
