#include<bits/stdc++.h>
using namespace std;

typedef complex<double> point;
const double EPS = 1e-9;
const double _inf = 1/0.0;
#define X real()
#define Y imag()
#define vec(a,b) 	((b) - (a))
#define cross(a,b) 	((conj(a) * (b)).imag())

struct cmp {
    point about;
    cmp(point c) {
        about = c;
    }
    bool operator()(const pair<point, int> &p, const pair<point, int> &q) const {
        double cr = cross(vec(about, p.first), vec(about, q.first));
        if (abs(cr) < EPS) {
            return make_pair(p.first.Y, p.first.X) < make_pair(q.first.Y, q.first.X);
        }
        return cr < 0;
    }
};

void sortCCW(vector<pair<point, int> > &pts) {
    point bl(_inf, _inf);
    for(int i = 0; i < (int)pts.size(); i++) {
        if(make_pair(pts[i].first.Y, pts[i].first.X) < make_pair(bl.Y, bl.X)) {
            bl = pts[i].first;
        }
    }
    sort(pts.begin(), pts.end(), cmp(bl));
}

int main() {
    int n, m, p, q;
    scanf("%d %d", &n, &m);
    double x, y;
    vector<pair<point, int> > vp;
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        vp.push_back({point(x, y), i+1});
    }
    sortCCW(vp);
    int id[100005];
    for(int i = 0; i < n; i++) {
        id[vp[i].second] = i;
    }
    point pr = vp[1].first, bl = vp[0].first, cr;
    double area[n] = {};
    for(int i = 2; i < n; i++) {
        cr = vp[i].first;
        area[i] += abs(cross(vec(bl,pr), vec(bl, cr)))/2+area[i-1];
        swap(pr, cr);
    }
    double maxi = 0;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &p, &q);
        int minid = id[p], maxid = id[q];
        if(maxid < minid) {
            swap(minid, maxid);
        }
        if(minid+1 == maxid) {
            continue;
        }
        double res = area[maxid]-area[minid]-abs(cross(vec(vp[minid].first, bl), vec(vp[maxid].first, bl)))/2;
        res = min(res, area[n-1]-res);
        maxi = max(maxi, res);
    }

    printf("%.9f\n", maxi);
}
