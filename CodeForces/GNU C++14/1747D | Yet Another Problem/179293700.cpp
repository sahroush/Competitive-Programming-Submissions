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
 
int n, q;
int a[maxn];
int l[maxn], r[maxn];
int ans[maxn];
int xr[maxn];
ll s[maxn];
vector < int > comp;
vector < int > mp[2][maxn];
 
int get(int x){
 return (lower_bound(comp.begin(), comp.end(), x) - comp.begin());
}
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 ms(ans, 63);
 cin >> n >> q;
 comp.pb(0);
 for(int i = 1 ; i <= n ; i ++)
  cin >> a[i], xr[i] = xr[i - 1] ^ a[i], comp.pb(xr[i]), s[i] = s[i - 1] + a[i];
 sort(comp.begin(), comp.end());
 comp.resize((unique(comp.begin(), comp.end())) - comp.begin());
 for(int i = 0 ; i <= n ; i ++){
  mp[i & 1][get(xr[i])].pb(i);
 }
 for(int i = 0 ; i <= n ; i ++)
  mp[i&1][get(xr[i])].pb(n + 1);
 for(int i = 1 ; i <= q ; i ++){
  cin >> l[i] >> r[i];
  if(xr[r[i]] ^ xr[l[i] - 1]){
   ans[i] = -1;
   continue;
  }
  if(s[r[i]] - s[l[i] - 1] == 0){
   ans[i] = 0;
   continue;
  }
  if((r[i] - l[i] + 1)&1){
   if(r[i] == l[i] and a[l[i]])
    ans[i] = -1;
   else
    ans[i] = 1;
  }
  else if((a[l[i]] == 0) or (a[r[i]] == 0))
   ans[i] = 1;
  if(ans[i] == ans[0]){
   if(mp[(l[i]&1)][get(xr[l[i] - 1])].size() and (*upper_bound(mp[(l[i]&1)][get(xr[l[i] - 1])].begin(), mp[(l[i]&1)][get(xr[l[i] - 1])].end(), l[i])) < r[i]){
    ans[i] = 2;
   }
   else
    ans[i] = -1;
 
  }
 }
 for(int i = 1 ; i <= q ; i ++)
  cout << ans[i] << endl;
 return(0);
}