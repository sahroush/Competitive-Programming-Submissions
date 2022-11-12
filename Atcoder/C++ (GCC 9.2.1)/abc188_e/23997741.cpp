#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
ll a[maxn], mx[maxn], dout[maxn];

queue < int > q;

vector < int > in[maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= m ; i ++){
		int u , v;
		cin >> u >> v;
		dout[u] ++ , in[v].pb(u);
	}
	for(int i = 1 ; i <= n ; i ++)if(dout[i] == 0)q.push(i);
	for(int i = 1 ; i <= n ; i ++)mx[i] = -1e17;
	ll ans = -1e17;
	while(q.size()){
		int v = q.front();
		ans = max(ans , mx[v] - a[v]);
		mx[v] = max(mx[v] , a[v]);
		q.pop();
		for(auto u : in[v]){
			dout[u] --;
			mx[u] = max(mx[u], mx[v]);
			if(dout[u] == 0)q.push(u);
		}
	}
	cout << ans;
	return(0);
}
