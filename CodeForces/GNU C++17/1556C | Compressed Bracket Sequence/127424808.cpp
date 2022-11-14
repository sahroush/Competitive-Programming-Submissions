#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 1010;
const ll mod = 1e9+7;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
ll n, a[maxn], ans;
vector < pii > stk;
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n;
 for(int i = 1 ; i <= n ; i ++){
  cin >> a[i];
 }
 stk.pb({0, 0});
 ll cur = 0;
 for(int i = 1 ; i + 1 <= n ; i +=2){
  cur += a[i] - a[i + 1];
  ans += min(a[i + 1], cur + a[i + 1] - stk[0].first);
        while(stk.size() and stk.back().first > cur)
   ans += stk.back().second, stk.pop_back();
        if(stk.size() and stk.back().first == cur)
   ans += stk.back().second, stk.back().second++;
  else
   stk.pb({cur, !stk.empty()});
 }
 cout << ans;
 return(0);
}