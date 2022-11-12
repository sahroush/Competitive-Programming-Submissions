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
typedef pair<ll  ,ll > pii;

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

ll n;

ll ans = 0;

int32_t main(){
    migmig;
	cin >> n;
	ll x = n;
	for(ll i = 2 ; i * i <= n ; i ++){
		if(x%i)continue;
		int cnt = 0;
		int lst = 0;
		while(x%i == 0){
			x/=i;
			cnt++;
			if(cnt > lst){
				ans ++ , lst = cnt , cnt = 0;
			}
		}
	}
	if(x > 1)ans++;
	cout << ans;


    return(0);
}
