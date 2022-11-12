//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , q;
pii e[maxn];
int x[maxn] , y[maxn] , z[maxn] , l[maxn] , r[maxn] , par[maxn] , sz[maxn];
vector < int > mid[maxn];

int getpar(int v){
	return ((par[v]) ? par[v] = getpar(par[v]) : v);
}

void merge(int u , int v){
	if((u = getpar(u)) == (v = getpar(v)))return;
	par[u] = v;
	sz[v] += sz[u];
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i ++)
		cin >> e[i].first >> e[i].second;
	cin >> q;
	for(int i = 1  ; i <= q ; i ++)
		cin >> x[i] >> y[i] >> z[i],
		l[i] = 0 , r[i] = m;
	for(int i = 0 ; i < 17 ; i ++){
		for(int j = 1 ; j <= q ; j ++)	
			mid[(l[j] + r[j]) >> 1].pb(j);
		for(int j = 1 ; j <= n ; j ++)par[j] = 0 , sz[j] = 1;
		for(int j = 1 ; j <= m ; j ++){
			merge(e[j].first , e[j].second);
			for(auto p : mid[j]){
				if(getpar(x[p]) == getpar(y[p]))
					((sz[getpar(x[p])] >= z[p]) ? r[p] = j : l[p] = j);
				else
					((sz[getpar(x[p])] + sz[getpar(y[p])] >= z[p]) ? r[p] = j : l[p] = j);
			}
			mid[j].clear();
		}
	}
	for(int i = 1 ; i <= q ; i ++)cout << r[i] << endl;
	return(0);
}
