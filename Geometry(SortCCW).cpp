
#include<bits/stdc++.h>
using namespace std;

typedef complex<double> point;
const double EPS = 1e-9;
const double _inf = 1/0.0;
#define X real()
#define Y imag()
#define vec(a,b) 	((b) - (a))
#define cross(a,b) 	((conj(a) * (b)).imag())

struct cmp { //sort CCW.
    point about;
    cmp(point c) {
        about = c;
    }
    bool operator()(const point &p, const point &q) const {
        double cr = cross(vec(about, p), vec(about, q));
        if (abs(cr) < EPS) {
            return make_pair(p.Y, p.X) < make_pair(q.Y, q.X);
        }
        return cr > 0; // or < for CW
    }
};

void sortCCW(vector<point> &pts) {
    point bl(_inf, _inf);
    for(int i = 0; i < (int)pts.size(); i++) {
        if(make_pair(pts[i].Y, pts[i].X) < make_pair(bl.Y, bl.X)) {
            bl = pts[i];
        }
    }
    sort(pts.begin(), pts.end(), cmp(bl));
}

int main() {
    int n;
    scanf("%d", &n);
    double x, y;
    vector<point> vp;
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        vp.push_back(point(x, y));
    }
    sortCCW(vp);
    for(int i = 0; i < n; i++) {
        cout << vp[i] << endl;
    }
}
