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

const ll maxn  = 3010;
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int dp[maxn][maxn];

int a;
int n , s;

int32_t main(){
    migmig;
	cin >> n >> s;
	dp[0][0] = 1;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a;
		for(int k = 0 ; k <= s ; k ++){
			dp[i][k] = dp[i - 1][k];
			dp[i][k] = (dp[i][k]*2)%mod;
			if(k - a >= 0){
				dp[i][k] = (dp[i][k] + dp[i-1][k - a])%mod;
			}
		}
	}
	cout << dp[n][s];
    return(0);
}
