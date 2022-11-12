//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5+10;
const int lg = 17;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , q , z , u , v , x , y;
int p[maxn] , par[lg+1][maxn] , sz[maxn] , h[maxn] , val[maxn];

int getpar(int v){
	return ((p[v]) ? p[v] = getpar(p[v]) : v);
}

int lca(int u , int v){
	if(h[u] < h[v])swap(u , v);
	for(int i = lg ; i >= 0 ; i --)
		if(h[par[i][u]] >= h[v])u = par[i][u];
	if(u == v)return u;
	for(int i = lg ; i >= 0 ; i --)
		if(par[i][u] ^ par[i][v])u = par[i][u] , v = par[i][v];
	return par[0][v];
}

void dfs(int v){
	if(v == 0)return;
	if(h[v] != -1)return;
	dfs(par[0][v]);
	h[v] = h[par[0][v]] + 1;
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)sz[i] = 1;
	for(int i = 1 ; i <= m ; i ++){
		cin >> u >> v;
		u = getpar(u) , v = getpar(v);
		if(u == v)continue;
		par[0][v] = par[0][u] = ++n;
		val[n] = i;
		sz[n] = sz[u] + sz[v];
		p[u] = p[v] = n;
	}
	for(int j = 1 ; j <= lg ; j ++)
		for(int i = 1 ; i <= n ; i ++)
			par[j][i] = par[j-1][par[j-1][i]];
	ms(h , -1);
	val[0] = sz[0] = 1e9;
	for(int i = 1 ; i <= n ; i ++)dfs(i);
	cin >> q;
	while(q --){
		cin >> u >> v >> z;
		int lc = lca(u, v);
		if(sz[lc] < z){
			for(int i = lg ; i >= 0 ; i --)if(sz[par[i][lc]] < z)
				lc = par[i][lc];
			cout << val[par[0][lc]] << endl;
		}
		else{
			int l = 0 , r = m;
			while(r - l > 1){
				int mid = (l + r) / 2;
				x = u  , y = v;
				for(int i = lg ; i >= 0 ; i --)
					if(val[par[i][x]] <= mid) x = par[i][x];
				for(int i = lg ; i >= 0 ; i --)
					if(val[par[i][y]] <= mid) y = par[i][y];
				if(sz[x] + sz[y] >= z) r = mid;
				else l = mid;
			}
			cout << r << endl;
		}
	}
	return(0);
}
