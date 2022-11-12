//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
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

#define sz(x) int(x.size())

int n;
vector < ll > v[3];

ll one(){
	int a = 1, b = 2;
	if(sz(v[0])%2)a = 0;
	if(!a and sz(v[1])%2)b = 1;
	ll res = 1e18;
	for(auto x : v[a]){
		if(x > v[b].back())res = min(res , x - v[b].back());
		else{
			auto it = lower_bound(v[b].begin() , v[b].end() , x);
			res = min(res , *it - x);
			if(*it != v[b][0]){
				it--;
				res = min(res , abs(x - *it));
			}
		}
	}
	return res;
}

ll two(){
	int a = 1, b = 2;
	if(sz(v[0])%2)a = 0;
	if(!a and sz(v[1])%2)b = 1;
	ll res = 1e18;
	int c = 0;
	for(int i = 0 ; i < 3 ; i ++)if(sz(v[i])%2 == 0)c = i;
	if(sz(v[c]) < 2)return res;
	ll ans = 1e18;
	for(auto x : v[a]){
		if(x > v[c].back())res = min(res , x - v[c].back());
		else{
			auto it = lower_bound(v[c].begin() , v[c].end() , x);
			res = min(res , *it - x);
			if(*it != v[c][0]){
				it--;
				res = min(res , abs(x - *it));
			}
		}
	}
	for(auto x : v[b]){
		if(x > v[c].back())ans = min(ans , x - v[c].back());
		else{
			auto it = lower_bound(v[c].begin() , v[c].end() , x);
			ans = min(ans , *it - x);
			if(*it != v[c][0]){
				it--;
				ans = min(ans , abs(x - *it));
			}
		}
	}
	return res + ans;
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(ll i = 0 , a ; i < 2*n ; i ++){
		char c;
		cin >> a >> c;
		if(c == 'R')v[0].pb(a);
		if(c == 'G')v[1].pb(a);
		if(c == 'B')v[2].pb(a);
	}
	if(sz(v[0])%2 == 0 and sz(v[1])%2 == 0)
		dokme(0);
	for(int i = 0 ; i < 3 ; i ++)sort(v[i].begin() , v[i].end());
	cout << min(two() , one());
	return(0);
}
