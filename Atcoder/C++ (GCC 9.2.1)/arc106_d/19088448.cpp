/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
ll a[maxn] , b[maxn];

int par[maxn];
ll sum[maxn];

int getpar(int v){
	return((v == par[v]) ? v : par[v] = getpar(par[v]));
}

void merge(int u , int v){
	v = getpar(v) , u = getpar(u);
	if(v == u)return;
	par[v] = u , sum[u] += sum[v];
}

int32_t main(){
    migmig;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , par[i] = i;
	for(int i = 1 ; i <= n ; i ++)
		cin >> b[i] , sum[i] = a[i] - b[i];
	for(int i = 1 ; i <= m ; i ++){
		int u , v;
		cin >> u >> v;
		merge(u , v);
	}
	for(int i = 1 ; i <= n ; i ++)
		sum[0] += abs(sum[getpar(i)]);
	if(sum[0] == 0)
		dokme("Yes");
	dokme("No");
    return(0);
}
