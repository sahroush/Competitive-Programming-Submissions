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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 1010;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
int a[maxn];
int b[maxn];

int dp[maxn][maxn];



int32_t main(){
    migmig;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= m ; i ++)
		cin >> b[i];
	for(int i = 0 ; i <= n ; i ++)
		for(int j = 0 ; j <= m ; j ++){
			if(i == 0 or j == 0){
				dp[i][j] = i + j;
				continue;
			}
			dp[i][j] = min({dp[i - 1][j] + 1 , dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i]!=b[j])});
		}
	cout << dp[n][m];
    return(0);
}
