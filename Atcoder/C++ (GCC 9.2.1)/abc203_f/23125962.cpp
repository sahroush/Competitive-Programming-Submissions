//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#pragma GCC optimize("Ofast")
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

int n , k;
int a[maxn];
int l[maxn];
int dp[maxn][35];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i ++)
		for(l[i] = l[i - 1] ; a[l[i]] * 2 <= a[i] ; l[i]++)continue;
	ms(dp , 63);
	dp[0][0] = 0;
	for(int i = 1 ; i <= n ; i ++){
		dp[i][0] = i;
		for(int j = 1 ; j <= 30 ; j ++){
			dp[i][j] = dp[l[i] - 1][j - 1];
			dp[i][j] = min(dp[i][j] , dp[i - 1][j] + 1);
		}
	}
	for(int i = 0 ; i <= 30 ; i ++)if(dp[n][i] <= k){
		cout << i << ' ' << dp[n][i];
		return 0;
	}
	
	return(0);
}
