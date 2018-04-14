#include <bits/stdc++.h>
using namespace std;

vector<complex<double> > recursive_fft(vector<complex<double> > &a, bool inv = 0) { // givin vector of x0, x1, ..., xn-1 returns corresponding y0, y1, ..., yn-1
    const int n = (int)a.size();
    if(n == 1) return a; // base case
    // wn = e^(2*pi*i/n);
    // e^(theta*i) = cos(theta) + i* sin(theta)
    // wn = e^((2*pi/n)*i) = cos(2*M_PI/n) + i*sin(2*M_PI/n)
    complex<double> wn, w;
    vector<complex<double> > aEven, aOdd, yEven, yOdd, y(n);

    if(inv) {
        wn = complex<double>(cos(-2*M_PI/n), sin(-2*M_PI/n));
    } else {
        wn = complex<double>(cos(2*M_PI/n), sin(2*M_PI/n));
    }
    w = complex<double>(1.0, 0.0);

    for(int i = 0; i < n; ++i) {
        if(i&1) {
            aOdd.push_back(a[i]);
        } else {
            aEven.push_back(a[i]);
        }
    }

    yEven = recursive_fft(aEven, inv), yOdd = recursive_fft(aOdd, inv);

    for(int k = 0; k < n/2; ++k) {
        y[k] = yEven[k] + w*yOdd[k];
        y[k+n/2] = yEven[k] - w*yOdd[k];
        w *= wn;
    }

    return y;
}


void poly_mul(vector<complex<double> > &a, vector<complex<double> > &b) {
    int n = a.size();
    vector<complex<double> > ya, yb, yc(n), c(n);

    ya = recursive_fft(a, 0);
    yb = recursive_fft(b, 0);

    for (int i = 0; i < n; ++i)
        yc[i] = ya[i] * yb[i];

    c = recursive_fft(yc, 1); //finds inv of yc

    for (int i = 0; i < (n-1); ++i)
        cout << int(round(c[i].real()/n)) << " ";
}

int main() {

    int n, coefficient;
    cin >> n;
    int nxtP2 = 1;
    while (nxtP2 < n) {
        nxtP2 <<= 1;
    }

    vector<complex<double> > a(2*nxtP2), b(2*nxtP2), c(2*nxtP2);

    for(int i = 0; i < 2*nxtP2; ++i) {
        a[i] = complex<double>(0, 0);
        b[i] = complex<double>(0, 0);
        c[i] = complex<double>(0, 0);
    }

    for(int i = 0; i < n; ++i){
        cin >> coefficient;
        a[i] = complex<double>(coefficient, 0);
    }

    for(int i = 0; i < n; ++i){
        cin >> coefficient;
        b[i] = complex<double>(coefficient, 0);
    }
    poly_mul(a, b);

}
