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
 
int n, q;
int a[maxn], b[maxn];
ll ps[maxn], mn[maxn], mx[maxn];
 
#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)
 
void build(int v = 1, int l = 1, int r = n + 1){
 if(r - l == 1){
  mn[v] = mx[v] = ps[l];
  return; 
 }
 build(lc, l, mid);
 build(rc, mid, r);
 mx[v] = max(mx[lc], mx[rc]);
 mn[v] = min(mn[lc], mn[rc]);
}
 
ll Min(int L, int R, int v = 1 , int l = 1 , int r = n + 1){
 if(r <= L or R <= l)
  return 1e18;
 if(L <= l and r <= R)
  return mn[v];
 return min(Min(L, R, lc, l, mid), Min(L, R, rc, mid, r));
}
 
ll Max(int L, int R, int v = 1 , int l = 1 , int r = n + 1){
 if(r <= L or R <= l)
  return -1e18;
 if(L <= l and r <= R)
  return mx[v];
 return max(Max(L, R, lc, l, mid), Max(L, R, rc, mid, r));
}
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n >> q;
 for(int i = 1 ; i <= n ; i ++)
  cin >> a[i];
 for(int i = 1 ; i <= n ; i ++)
  cin >> b[i];
 for(int i = 1 ; i <= n ; i ++)
  ps[i] = b[i] - a[i], ps[i] += ps[i - 1];
 build();
 while(q --){
  int l, r;
  cin >> l >> r;
  if(ps[r] - ps[l - 1] != 0){
   cout << -1 << endl;
   continue;
  }
  if(Min(l , r + 1) - ps[l - 1] < 0){
   cout << -1 << endl;
   continue;
  }
  cout << Max(l, r + 1) - ps[l - 1] << endl;
 } 
 return(0);
}