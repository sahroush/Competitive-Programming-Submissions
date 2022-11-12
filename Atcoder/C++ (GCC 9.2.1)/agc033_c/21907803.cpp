/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 310;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int dp[maxn][maxn][maxn];

int n , k;
string s;

int Dp(int l , int r , int k){
	if(k < 0)return(-1e9);
	if(l > r)return(0);
	if(l == r)return(1);
	if(dp[l][r][k] != -1)
		return(dp[l][r][k]);
	if(s[l] == s[r])
		return(dp[l][r][k] = max({Dp(l + 1 , r - 1 , k) + 2 , Dp(l + 1 , r , k) , Dp(l , r - 1 , k)}));
	return(dp[l][r][k] = max({Dp(l + 1 , r - 1 , k - 1) + 2 , Dp(l + 1 , r , k) , Dp(l , r - 1 , k)}));
}

int32_t main(){
	migmig;
	cin >> s >> k;
	ms(dp , -1);
	n = s.size();
	cout << Dp(0 , n - 1 , k);
	return(0);
}