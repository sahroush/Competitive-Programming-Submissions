#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 3e5 + 100;
const ll mod = 1e9+7;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
int q;
int a, b;
int xr[maxn];
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 for(int i = 1 ; i < maxn ; i ++)
  xr[i] = xr[i - 1] ^ i;
 while(q --){
  cin >> a >> b;
  int ans = a;
  if((xr[a - 1]  ^ b) != a){
   if(xr[a - 1] == b)cout << ans << endl;
   else cout << ans + 1 << endl;
  }
 else cout << ans + 2 << endl;
 }
 return(0);
}