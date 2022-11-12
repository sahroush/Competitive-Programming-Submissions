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

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
  cin >> n >> m;
  vector<vector<pair<int,int>>> g(n+1);
  for (int i = 1; i <= n; i++)
    g[i].push_back({i-1,0});
  for (int i =0; i < m; i++) {
    int l,r,x;
    cin >> l >> r >> x;
    l--;
    g[r].push_back({l,-x});
  }
  vector<int> d(n+1);
  bool change = true;
  while(change) {
    change = false;
    for (int i = n; i >= 0; i--) {
      for (auto& [u,to] : g[i]) {
        if (d[u] > d[i]+to) change = true;
        d[u] = min(d[i]+to,d[u]);
      }
    }
    for (int i = 0; i < n; i++) {
      if (d[i]+1<d[i+1])
        change = true;
      d[i+1] = min(d[i]+1,d[i+1]);
    }
  }
  string s;
  for (int i = 0; i < n; i++) {
    assert(d[i+1]-d[i] >= 0);
    assert(d[i+1]-d[i] <= 1);
    if (d[i+1] -d[i] == 0)
      cout << 0 << " ";
    else
      cout << 1 << ' ';
  }
	return(0);
}
