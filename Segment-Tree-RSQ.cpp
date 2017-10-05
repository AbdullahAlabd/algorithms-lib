#include <bits/stdc++.h>
using namespace std;

// Range Sum Query (with lazy propagation)
struct SegmentTree{	// 1-based DS.

	static const int N = 1<<17; //lowest power of 2 >= number of elements in input array.
	int sTree[N<<1|1], lazy[N<<1|1]; //number of nodes = 2*N - 1, we add one to cross out index zero
	vector<int> array; //input array;

	SegmentTree(vector<int> in) { //in is 1-based.
	    array = in;
	    array.resize(N+1, 0); //where N+1 is always greater than in.size().
	    array[0] = 0;
		build(1,1,N);
	}

	void build(int node, int b, int e) { // O(n)
		if(b == e)
			sTree[node] = array[b];
		else {
			int mid = (b + e) >> 1;
			build(node<<1,b,mid);
			build(node<<1|1,mid+1,e);
			sTree[node] = sTree[node<<1]+sTree[node<<1|1];
		}
	}


	void update_point(int index, int val) {	// O(log n)
		index += N - 1;
		sTree[index] += val; //add value to point.
		while(index){
			index >>= 1;
			sTree[index] = sTree[index<<1] + sTree[index<<1|1];
		}
	}


	void update_range(int i, int j, int val){ // O(log n)
		update_range(1,1,N,i,j,val);
	}

	void update_range(int node, int b, int e, int i, int j, int val){
		if(i > e || j < b)
			return;
		if(b >= i && e <= j) {
			sTree[node] += (e-b+1)*val; // add value over range.
			lazy[node] += val;
		}
		else {
			int mid = (b + e) >> 1;
			propagate(node, b, mid, e);
			update_range(node<<1,b,mid,i,j,val);
			update_range(node<<1|1,mid+1,e,i,j,val);
			sTree[node] = sTree[node<<1] + sTree[node<<1|1];
		}
	}

	void propagate(int node, int b, int mid, int e) {
		lazy[node<<1] += lazy[node];
		lazy[node<<1|1] += lazy[node];
		sTree[node<<1] += (mid-b+1)*lazy[node];
		sTree[node<<1|1] += (e-mid)*lazy[node];
		lazy[node] = 0;
	}

	int query(int i, int j){
		return query(1,1,N,i,j);
	}

	int query(int node, int b, int e, int i, int j){ // O(log n)
		if(i>e || j<b)
			return 0;
		if(b >= i && e <= j)
			return sTree[node];
		int mid = (b + e) >> 1;
		propagate(node, b, mid, e);
		int q1 = query(node<<1,b,mid,i,j);
		int q2 = query(node<<1|1,mid+1,e,i,j);
		return q1 + q2;
	}
};

int main() {
    int n ;
    cin >> n;
    vector<int> in(n+1);
    for(int i = 1; i <= n; i++)
        cin >> in[i];
    SegmentTree sg(in);
    int q, qq, l, r, val;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> qq;
        if(qq){
            cin >> l >> r >> val; //update;
            sg.update_range(l, r, val);
        }else{
            cin >> l >> r; // get
            cout<<sg.query(l, r)<<endl;
        }
    }
}
