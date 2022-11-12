#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 5e5 + 10;
const ll mod = 998244353;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n, k;
int l[maxn], r[maxn];
int dp[maxn];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
    for(int i = 1 ; i <= k ; i ++)
       cin >> l[i] >> r[i];
    dp[1] = 1;
    for(int i = 1 ; i <= n ; i ++){
        dp[i] = (dp[i] + dp[i - 1])%mod;
        if(i == 2)dp[i] = (mod - 1 + dp[i])%mod;
        for(int j = 1 ; j <= k ; j ++)
            dp[i + l[j]] = (dp[i + l[j]] + dp[i])%mod,
            dp[i + r[j] + 1] = (dp[i + r[j] + 1] + mod - dp[i])%mod;
    }
    cout << dp[n];
	return(0);
}
