#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 5e3 + 100;
const ll mod = 1e9+7;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
int n, a, b, k, sum;
int dp[maxn], ps[maxn];
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n >> a >> b >> k;
 dp[a] = 1;
 for(int i = 1 ; i <= k ; i ++){
  for(int j = 1 ; j <= n ; j ++){
   int dist = abs(b - j);
   if(dist == 1)
    continue;
   ps[max(1, j - dist + 1)] = (ps[max(1, j - dist + 1)] + dp[j]) % mod;
   ps[j] = (ps[j] - dp[j] + mod) % mod;
   ps[j + 1] = (ps[j + 1] + dp[j]) % mod;
   ps[j + dist] = (ps[j + dist] - dp[j] + mod) % mod;
  }
  for(int j = 1 ; j <= n ; j ++) 
   ps[j] = (ps[j] + ps[j - 1]) % mod;
  swap(dp, ps);
  ms(ps, 0);
 }
 for(int i = 1 ; i <= n ; i ++) 
  sum = (sum + dp[i]) % mod;
 cout << sum;
 return(0);
}