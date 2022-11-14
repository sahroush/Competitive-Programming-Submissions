#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 14;
const ll mod = 1e9+7;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
int n;
int a[maxn], b[maxn][maxn], c[maxn][1 << maxn];
int f[1 << maxn];
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n;
 for(int i = 0 ; i < n ; i ++)
  cin >> a[i];
 for(int i = 0 ; i < n ; i ++)
  for(int j = 0 ; j < n ; j ++)
   b[i][j] = a[i] * pw(a[i] + a[j], mod - 2) % mod;
 for(int i = 0 ; i < n ; i ++)
  for(int j = 0 ; j < (1 << n) ; j ++){
   c[i][j] = 1;
   for(int k = 0 ; k < n ; k ++)if(j & (1 << k)){
    c[i][j] = c[i][j] * 1ll * b[i][k] % mod;
   }
  }
 uint32_t ans = 0;
 for(int i = 1 ; i < (1 << n) ; i ++){
  for(int j = (i - 1) & i ; j ; j = (j - 1) & i){
   int v = f[j];
   for(int k = 0 ; k < n ; k ++)if(j & (1 << k))
    v = v * 1ll * c[k][i ^ j] % mod;
   (f[i]+=v)%=mod;
  }
  f[i] = (mod - f[i] + 1)%mod;
  int v = 1;
  for(int k = 0 ; k < n ; k ++)if(i & (1 << k))
   v = v * 1ll * c[k][((1 << n) - 1) ^ i] % mod;
  ans = (ans + f[i] * 1ll * v % mod * __builtin_popcount(i))%mod;
 }
 cout << ans;
 return(0);
}