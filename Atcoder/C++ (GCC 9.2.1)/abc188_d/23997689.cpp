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

ll n , p;
ll a[maxn], b[maxn], c[maxn];

map < ll , ll > mp;

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> p;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] >> b[i] >> c[i];
	for(int i = 1 ; i <= n ; i ++)
		mp[a[i]]+=c[i] , mp[b[i] + 1] -= c[i];
	ll ans = 0, sum = 0, l = 0;
	for(auto [r , val] : mp){
		ans += min(p , sum) * (r - l);
		sum += val;
		l = r;
	}
	cout << ans;
	return(0);
}
