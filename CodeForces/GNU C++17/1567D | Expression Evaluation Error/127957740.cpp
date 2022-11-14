#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 3e6;
const ll mod = 1e9+7;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
ll n, s, q;
ll ans[maxn];
 
ll F(ll x){
 ll ans = 1;
 while(ans <= x){
  ans *= 10;
 }
 return ans / 10;
}
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> s >> n;
  for(int i = 1 ; i <= n ; i ++)
   ans[i] = 1;
  s -= n;
  for(int i = 1 ; i <= n ; i ++){
   s ++;
   ans[i] = 0;
   ans[i] = F(s);
   s -= F(s);
  }
  ans[1] += s;
  for(int i = 1 ; i <= n ; i ++)
   cout << ans[i] << ' ';
  cout << endl;
 }
 
 return(0);
}