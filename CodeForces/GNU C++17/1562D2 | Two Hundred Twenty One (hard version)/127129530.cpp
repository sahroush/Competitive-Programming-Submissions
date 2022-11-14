#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 6e5 + 10;
const ll mod = 1e9+7;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
int t;
int n, q;
string s;
int ps[maxn], a[maxn];
int ans[maxn];
int l[maxn], r[maxn];
vector < int > qu[maxn], pos[maxn], of[maxn];
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> t;
 while(t --){
  cin >> n >> q >> s;
  fill(ps, ps + n + 10, 0);
  fill(a, a + n + 10, 0);
  for(int i = -n ; i <= n ; i ++)
   pos[i + n].clear(), of[i + n].clear();
  s = "7" + s;
  for(int i = 1 ; i <= n ; i ++){
   if((i & 1) ^ (s[i] == '+'))a[i] = -1;
   else a[i] = 1;
  }
  for(int i = 1 ; i <= n ; i ++){
   ps[i] = ps[i - 1] + a[i];
  }
  for(int i = 0 ; i < q ; i ++){
   qu[i].clear();
   cin >> l[i] >> r[i];
   int sum = ps[r[i]] - ps[l[i] - 1];
   if(sum == 0){
    ans[i] = 0;
    continue;
   }
   if(sum & 1){
    ans[i] = 1;
    int x;
    if(sum > 0){
     x = (sum + 1) / 2;
    }
    else{
     x = (sum - 1) / 2;
    } 
    of[x + ps[l[i] - 1] + n].pb(i);
    continue;
   }
   ans[i] = 2;
   sum /= 2;
   of[ps[r[i]] + n].pb(i);
   of[sum + ps[l[i] - 1] + n].pb(i);
  }
 
  for(int i = 1 ; i <= n ; i ++){
   pos[ps[i] + n].pb(i);
  }
  for(int i = -n ; i <= n ; i ++){
   for(int x : of[i + n]){
    qu[x].pb(*lower_bound(pos[i + n].begin(), pos[i + n].end(), l[x]));
   }
  }
  for(int i = 0 ; i < q ; i ++){
   cout << ans[i] << endl;
   if(ans[i]){
    for(int x : qu[i]){
     cout << x <<  ' ';
    }
    cout << endl;
   }
  }
 }
 return(0);
}