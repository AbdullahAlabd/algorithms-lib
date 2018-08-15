//For clarification:
//https://codeforces.com/blog/entry/11080
#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ordered_set<int>  s;
	s.insert(1); 
	s.insert(4);
	cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
	cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based)
}
