//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5+10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , q , u , v , x , y , z;
int par[maxn] , sz[maxn] , ti[maxn];
vector < pii > hist[maxn];

int getpar(int v){
	return ((par[v]) ? getpar(par[v]) : v);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)sz[i] = 1 , hist[i].pb({0 , 1}) , ti[i] = m+1;
	for(int i = 1 ; i <= m ; i ++){
		cin >> u >> v;
		if((u = getpar(u)) == (v = getpar(v)))continue;
		if(sz[v] < sz[u])swap(u , v);
		sz[v] += sz[u] , par[u] = v, ti[u] = i;
		hist[v].pb({i , sz[v]});
	}
	cin >> q;
	while(q --){
		cin >> u >> v >> z;
		int l = 0 , r = m;
		while(r - l > 1){
			int mid = (l + r) / 2;
			x = u , y = v;
			while(ti[x] <= mid) x = par[x];
			while(ti[y] <= mid) y = par[y];
			int val = prev(lower_bound(hist[x].begin() , hist[x].end() , pii(mid , m+1)))->second;
			if(x ^ y)
				val+= prev(lower_bound(hist[y].begin() , hist[y].end() , pii(mid , m+1)))->second;
			if(val >= z)r = mid;
			else l = mid;
		}
		cout << r << endl;
	}
	return(0);
}
