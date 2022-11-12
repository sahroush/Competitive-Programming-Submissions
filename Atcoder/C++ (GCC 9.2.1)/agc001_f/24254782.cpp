#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;
const int sq = 1000;

#define endl '\n'
#define pb push_back
#define ms(x , y) memset(x , y , sizeof x)
#define dokme(x) cout << x , exit(0)

int n, k;
int a[maxn];
int p[maxn];

struct linkedlist{
	int nxt[sq * 2 + 10], val[sq * 2 + 10], sz, l = 1 , mx;
	void insert(int x){
		sz ++;
		val[sz] = x;
		mx = max(mx , x);
		if(sz == 1)
			return;
		if(x - val[l] < k){
			nxt[sz] = l;
			l = sz;
			return;
		}
		int cur = l;
		while(nxt[cur] and x - val[nxt[cur]] >= k){
			cur = nxt[cur];
		}
		nxt[sz] = nxt[cur] , nxt[cur] = sz;
	}
	void add(int x){
		sz ++ ;
		val[sz] = x;
		mx = max(mx , x);
		if(sz == 1)return;
		nxt[sz - 1] = sz;
	}
	vector < int > clear(){
		vector < int > ans;
		int cur = l;
		while(cur){
			ans.pb(val[cur]);
			cur = nxt[cur];
		}
		l = 1 , sz = 0 , ms(val , 0) , ms(nxt , 0) , mx = 0;
		return ans;
	}	
};

struct DS{
	linkedlist a[sq * 2 + 10];
	int sz , cnt;
	void rebuild(){
		vector < int > ans;
		for(int i = 1 ; i <= sz ; i ++){
			vector < int > bz = a[i].clear();
			for(auto x : bz)ans.pb(x);
		}
		cnt = 0 , sz = 1;
		for(int x : ans){
			if(cnt == sq) cnt = 0 , sz ++;
			a[sz].add(x);
			cnt ++;
		}
		cnt = 0;
	}
	void insert(int x){
		int cur = 1;
		while(cur <= sz and x - a[cur].mx >= k)
			cur ++;
		if(cur > sz)
			sz ++;
		a[cur].insert(x);
		cnt ++;
		if(cnt == sq)rebuild();
	}
	vector < int > solve(){
		vector < int > ans;
		ans.pb(-1);
		for(int i = 1 ; i <= sz ; i ++){
			vector < int > bz = a[i].clear();
			for(auto x : bz)ans.pb(x);
		}
		return ans;
	}
}ds;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , p[a[i]] = i;
	for(int i = n ; i >= 1 ; i --)
		ds.insert(p[i]);
	vector < int > res = ds.solve();
	for(int i = 1 ; i <= n ; i ++)
		a[res[i]] = i;
	for(int i = 1 ; i <= n ; i ++)
		cout << a[i] << endl;
	return(0);
}
