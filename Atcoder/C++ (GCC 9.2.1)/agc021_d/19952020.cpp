//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

const int maxn = 1e5 + 10;
const int sq = 100;
const int inf = 2e9;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)

vector < int > adj[maxn], radj[maxn];
vector < pii > vec[maxn];
bool nt[maxn] , c[maxn];
int n , m , q , d[maxn];

int solve(int v){
	for(int i = 1 ; i < v ; i ++)
		d[i] = -inf;
	d[v] = 0;
	for(int i = v - 1;  i >= 1 ; i --)
		for(auto u : adj[i])
			if(u <= v)
				d[i] = max(d[i] , d[u] + 1);
	int ans = -1;
	for(int i = 1 ; i <= v ; i ++)
		if(!nt[i])
			ans = max(ans , d[i]);
	return(ans);
}

vector < pii > vc;
void prep(){
	for(int i = 1 ; i <= n ; i ++){
		vc.clear();
		vc.pb({0 , i});
		for(auto u : radj[i])
			for(auto x : vec[u])
				vc.pb({-x.first - 1 , x.second});
		sort(vc.begin() , vc.end());
		for(auto x : vc){
			if(c[x.second])continue;
			vec[i].pb({-x.first , x.second});
			if(vec[i].size() == sq)break;
			c[x.second] = 1;			
		}
		for(auto x : vec[i])
			c[x.second] = 0;
	}
}

int32_t main(){
    migmig;
	cin >> n >> m >> q;
	for(int i = 0 ; i < m ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v) , radj[v].pb(u);
	}
	prep();
	for(int i =1 ; i <= q ; i ++){
		int u , v;
		cin >> u >> v;
		vector < int > cur;
		for(int j = 0 ; j < v ; j ++){
			int x;
			cin >> x;
			cur.pb(x);
			nt[x] = 1;
		}
		if(v >= sq){
			cout << solve(u) << endl;
			for(auto x : cur)
				nt[x] = 0;
			continue;
		}
		int ans = -1;
		for(auto x : vec[u]){
			if(nt[x.second])continue;
			ans = x.first;
			break;
		}
		if(ans == -1){
			cout << solve(u) << endl;
			for(int x : cur)
				nt[x] = 0;
			continue;
		}
		cout << ans << endl;
		for(int x : cur)
			nt[x] = 0;
	}
    return(0);
}
