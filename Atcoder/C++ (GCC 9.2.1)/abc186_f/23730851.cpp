#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n, m, k, fen[maxn];
vector < pii > r, q;
vector < int > row[maxn] , col[maxn];

void add(int pos){
	for(pos += 5 ; pos < maxn ; pos += pos & -pos)
		fen[pos]++;
}

int get(int pos, int res = 0){
	for(pos += 5 ; pos ; pos -= pos & -pos)
		res += fen[pos];
	return res;
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= k ; i ++){
		int x, y;
		cin >> x >> y;
		row[x].pb(y);
		col[y].pb(x);
	}
	for(int i = 1 ; i <= n ; i ++)
		row[i].pb(m + 1);
	for(int i = 1 ; i <= m ; i ++)
		col[i].pb(n + 1);
	for(int i = 0 ; i <= maxn ; i ++)
		sort(row[i].begin(), row[i].end()),
		sort(col[i].begin(), col[i].end());
	ll ans = 1;
	for(int i = 2 ; i < col[1][0] ; i ++)
		row[i][0]--, ans += row[i][0];
	for(int i = 2 ; i < row[1][0] ; i ++)
		col[i][0] --, q.pb({i, col[i][0]});
	row[1][0] = 0;
	for(int i = col[1][0] ; i <= n ; i ++)
		row[i][0] = 0;
	sort(q.begin(), q.end());
	for(int i = 1 ; i <= n ; i ++)
		r.pb({row[i][0], i});
	sort(r.begin(), r.end());
	int p = 0;
	for(int i = 0 ; i < (int)r.size() ; i ++){
		while(p < (int)q.size() and q[p].first <= r[i].first){
			ans += get(q[p].second);
			p++;
		}
		add(r[i].second);
	}
	while(p < (int)q.size()){
		ans += get(q[p].second);
		p++;
	}
	cout << ans;
	return(0);
}
