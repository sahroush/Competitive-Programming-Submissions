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

ll x , y;
map <ll , ll> mp;
     
ll solve(ll y , ll x){
	if(mp.count(y))
		return mp[y];
	if(x >= y)
		return x - y;
	if(y & 1)
		mp[y] = min(solve(y - 1 , x) , solve(y + 1 , x)) + 1;
	else
		mp[y] = min(solve(y >> 1 , x) + 1 , y - x);
	return mp[y];
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> x >> y;
	cout << solve(y , x);
	return(0);
}
