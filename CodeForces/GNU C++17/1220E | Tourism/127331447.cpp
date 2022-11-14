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
 
int n, m, s, d[maxn];
ll w[maxn], x[maxn];
vector < int > adj[maxn];
bool safe[maxn], gone[maxn];
queue < int > q;
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n >> m;
 for(int i = 1 ; i <= n ; i ++)
  cin >> w[i], safe[i] = 1;
 for(int i = 1 ; i <= m ; i ++){
  int u, v;
  cin >> u >> v;
  adj[u].pb(v), adj[v].pb(u);
  d[u] ++, d[v] ++;
 }
 cin >> s, d[s] += mod;
 for(int i = 1 ; i <= n ; i ++)if(d[i] == 1){
  q.push(i);
 }
 while(q.size()){
  int v = q.front();
  q.pop();
  x[v] += w[v];
  d[v] = 0;
  safe[v] = 0;
  for(int u : adj[v]){
   x[u] = max(x[u] , x[v]);
   if(!gone[u]){
    d[u] --;
    if(d[u] == 1)q.push(u);
   }
  }
 }
 ll ans = 0;
 for(int i = 1 ; i <= n ; i ++)if(safe[i])ans += w[i];
 cout << ans + *max_element(x , x + maxn);
 return(0);
}