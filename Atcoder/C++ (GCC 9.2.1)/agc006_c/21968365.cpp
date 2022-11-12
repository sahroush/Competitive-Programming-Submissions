//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
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

int n, x[maxn], m , k, a[maxn], ind[maxn], d[maxn] , mark[maxn] , sz , num[maxn] , res[maxn];
vector < int > cyc[maxn];

void dfs(int v){
	mark[v] = 1, num[v] = cyc[sz].size(), res[v] = sz, cyc[sz].pb(v);
	if(!mark[ind[v]]) dfs(ind[v]);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)cin >> x[i] , ind[i] = i , d[i] = x[i] - x[i - 1];
	cin >> m >> k;
	for(int i = 1 ; i <= m ; i ++)cin >> a[i] , swap(ind[a[i]] , ind[a[i]+1]);
	for(int i = 1 ; i <= n ; i ++)if(!mark[ind[i]]) sz++, dfs(ind[i]);
	for(int i = 1 ; i <= n ; i ++)ind[i] = cyc[res[i]][(num[i]+k)%int(cyc[res[i]].size())];
	for(int ans = x[1] , i = 1 ; i <= n ; ans += d[ind[i+1]] , i++)cout << ans << endl;
	return(0);
}
