//*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
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

ll x , n , a[maxn];

vector < ll > X;
ll dp[2];

void calc(ll x , vector < ll > &v){
	int cur = n - 1;
	v.clear();
	v.resize(n);
	while(x){
		while(x < a[cur])cur--;
		while(x >= a[cur])
			v[cur] = x / a[cur] , x%=a[cur];
	}
}

int32_t main(){
    migmig;
	cin >> n >> x;
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	calc(x , X);
	dp[0] = 1;
	for(int i = 0 ; i < n ; i ++){
		ll pd[] = {dp[0] , dp[1]};
		ms(dp , 0);
		ll K = 0;
		if(i == n-1) K = 5e18;
		else K = a[i+1]/a[i];
		for(int j = 0 ; j < 2 ; j ++)
			for(int k = 0; k < 2 ; k ++){
				ll x = K * k - X[i] - j;
				if(0 <= x and x < K)
					dp[k] += pd[j];
				x = X[i] + j - K * k;
				if(0 < x and x < K)
					dp[k] += pd[j];
			}
	}
	cout << dp[0];
    return(0);	
}
