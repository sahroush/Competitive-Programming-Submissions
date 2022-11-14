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
 
int n , a , b;
 
struct dsu{
 int par[maxn];
 
 int getpar(int v){
  return par[v] ? par[v] = getpar(par[v]) : v;
 }
 
 void merge(int u, int v){
  if((u = getpar(u)) == (v = getpar(v)))return;
  par[u] = v;
 }
}t1, t2;
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n >> a >> b;
 for(int i = 1 ; i <= a ; i ++){
  int u, v;
  cin >> u >> v;
  t1.merge(u , v);
 }
 for(int i = 1 ; i <= b ; i ++){
  int u, v;
  cin >> u >> v;
  t2.merge(u , v);
 }
 vector < pii > ans;
 for(int i = 1 ; i <= n ; i ++){
  for(int j = 1 ; j <= n ; j ++){
   if(t1.getpar(i) ^ t1.getpar(j))if(t2.getpar(i) ^ t2.getpar(j)){
    ans.pb({i,  j});
    t1.merge(i , j);
    t2.merge(i , j);
   }
  }
 }
 cout << ans.size() << endl;
 for(auto [u,  v] : ans)
  cout << u << ' ' << v << endl;
 return(0);
}