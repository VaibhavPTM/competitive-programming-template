// Link : 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;        
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

template <typename A, typename B>
void dbg (vector<pair<A,B>> &ar) { 
	for(auto &i : ar) 
		cout << i.first << " " << i.second << endl;
}
template <typename A>
void dbg(vector<A> ar[], int n) { 
	for(int i = 0; i < n; i++) {
		cout << i << " --> "; {
		for(int j = 0; j < ar[i].size(); j++){
			cout << ar[i][j] << " "; 
		} 
		cout << endl; 
		}
	}
}

template <typename A>
void dbg (vector<A> &ar) { 
	for(A &i : ar)  
		cout << i << " "; 
	cout << endl; 
}
template <typename A>
void dbg (set<A> &ar) { 
	for(auto &i : ar)  
		cout << i << " "; 
	cout << endl; 
}
template <typename A>
void dbg (multiset<A> &ar) { 
	for(auto &i : ar)  
		cout << i << " "; 
	cout << endl; 
}

template <typename T>
void dbg(T t) { 
	cout << t << '\n';
}
template<typename T, typename... Args>
void dbg(T t, Args... args) {
	cout << t << " "; 
	dbg(args...);
}

template <typename A, typename B>
void dbg (map<A,B> &mp) { 
	for(auto i : mp) {
		cout << i.first << " -> ";
		dbg(i.second);
	}
}

template <typename A, typename B>
void dbg (unordered_map<A,B> &mp) { 
	for(auto i : mp) {
		cout << i.first << " -> ";
		dbg(i.second);
	}
}
