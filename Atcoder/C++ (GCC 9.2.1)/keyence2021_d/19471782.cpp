//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 5100;
const ll mod = 998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int a[maxn][maxn];
int dp[maxn][maxn];
int h , w , k;

int l[maxn][maxn];
int u[maxn][maxn];
int p3[maxn];

int32_t main(){
    migmig;
	cin >> h >> w >> k;
	for(int i = 0 ; i < k ; i ++){
		int x , y;
		char c;
		cin >> x >> y >> c;
		if(c == 'X')a[x][y] = 3;
		if(c == 'R')a[x][y] = 1;
		if(c == 'D')a[x][y] = 2;
	}
	p3[0] = 1;
	for(int i = 1 ; i < maxn ; i ++)
		p3[i] = (3LL * p3[i - 1])%mod;
	for(int i = 2 ; i <= h ; i ++){
		for(int j = 2 ; j <= w ; j ++){
			l[i][j] = l[i][j - 1] + (a[i][j - 1] == 0);
			u[i][j] = u[i - 1][j] + (a[i - 1][j] == 0);
		}
	}
	dp[1][1] = 1;
	for(int i = 1 ; i <= h ; i ++){
		for(int j = 1 ; j <= w ; j ++){
			if(i > 1){
				if(a[i-1][j] == 2){ // D
					dp[i][j] = (dp[i][j] + (dp[i - 1][j] * 1LL * p3[l[i][j]])%mod)%mod;
				}
				if(a[i - 1][j] == 3){ //X
					dp[i][j] = (dp[i][j] + (dp[i - 1][j] * 1LL * p3[l[i][j]])%mod)%mod;
				}
				if(a[i - 1][j] == 0){
					dp[i][j] = (dp[i][j] + (dp[i - 1][j] * 2LL * p3[l[i][j]])%mod)%mod;
				}
			}
			if(j > 1){
				if(a[i][j-1] == 1){ // R
					dp[i][j] = (dp[i][j] + (dp[i][j-1] * 1LL * p3[u[i][j]])%mod)%mod;
				}
				if(a[i][j - 1] == 3){ //X
					dp[i][j] = (dp[i][j] + (dp[i][j-1] * 1LL * p3[u[i][j]])%mod)%mod;
				}
				if(a[i][j - 1] == 0){
					dp[i][j] = (dp[i][j] + (dp[i][j-1] * 2LL * p3[u[i][j]])%mod)%mod;
				}
			}
		}
	}
	if(a[h][w] == 0)dp[h][w] = (dp[h][w] * 3LL)%mod;
	cout << dp[h][w];
    return(0);
}
