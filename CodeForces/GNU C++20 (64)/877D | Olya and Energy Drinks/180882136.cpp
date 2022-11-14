#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
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
 
int n, m, k;
string s[maxn];
int a1, a2, b1, b2;
set < int > R[maxn], C[maxn];
int dist[maxn][maxn];
queue <pii> q;
vector < int > trash;
int nl[maxn][maxn], nr[maxn][maxn],
 nu[maxn][maxn], nd[maxn][maxn];
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n >> m >> k;
 for(int i = 1 ; i <= n ; i ++)
  cin >> s[i], s[i] = '*' + s[i];
 ms(nl, -1);
 ms(nr, -1);
 ms(nu, -1);
 ms(nd, -1);
 for(int i = 1 ; i <= n ; i ++)
  for(int jl = 1, jr = m ; jl <= m ; jl ++, jr --){
   nl[i][jl] = jl;
   if(~nl[i][jl-1])nl[i][jl] = max(jl-k, nl[i][jl-1]);
   if(s[i][jl] == '#')nl[i][jl] = -1;
   nr[i][jr] = jr;
   if(~nr[i][jr+1])nr[i][jr] = min(jr+k, nr[i][jr+1]);
   if(s[i][jr] == '#')nr[i][jr] = -1;
  }
 for(int i = 1 ; i <= n ; i ++)
  for(int jl = 1, jr = m ; jl <= m ; jl ++, jr --){
   nl[i][jl] = jl;
   if(~nl[i][jl-1])nl[i][jl] = max(jl-k, nl[i][jl-1]);
   if(s[i][jl] == '#')nl[i][jl] = -1;
   nr[i][jr] = jr;
   if(~nr[i][jr+1])nr[i][jr] = min(jr+k, nr[i][jr+1]);
   if(s[i][jr] == '#')nr[i][jr] = -1;
  }
 for(int i = 1 ; i <= m ; i ++)
  for(int ju = 1, jd = n ; ju <= n ; ju ++, jd --){
   nu[ju][i] = ju;
   if(~nu[ju-1][i])nu[ju][i] = max(ju-k, nu[ju-1][i]);
   if(s[ju][i] == '#')nu[ju][i] = -1;
   nd[jd][i] = jd;
   if(~nd[jd+1][i])nd[jd][i] = min(jd+k, nd[jd+1][i]);
   if(s[jd][i] == '#')nd[jd][i] = -1;
  }
 cin >> a1 >> a2 >> b1 >> b2;
 for(int i = 1 ; i <= n ; i ++)
  for(int j = 1 ; j <= m ; j ++)if(s[i][j]!='#')
   R[i].insert(j);
 for(int i = 1 ; i <= m ; i ++)
  for(int j = 1 ; j <= n ; j ++)if(s[j][i]!='#')
   C[i].insert(j);
 ms(dist, -1);
 dist[a1][a2] = 0;
 R[a1].erase(a2);
 C[a2].erase(a1);
 q.push({a1, a2});
 while(!q.empty()){
  auto [x, y] = q.front();
  q.pop();
  auto l = R[x].lower_bound(nl[x][y]);
  auto r = R[x].upper_bound(nr[x][y]);
  for(; l != r ; ++l){
   dist[x][*l] = dist[x][y] + 1;
   q.push({x, *l});
   C[*l].erase(x);
   trash.pb(*l);
  }
  for(auto v : trash) 
   R[x].erase(v);
  trash.clear();
  l = C[y].lower_bound(nu[x][y]);
  r = C[y].upper_bound(nd[x][y]);
  for(; l != r ; ++l){
   dist[*l][y] = dist[x][y] + 1;
   q.push({*l, y});
   R[*l].erase(y);
   trash.pb(*l);
  }
  for(auto v : trash) 
   C[y].erase(v);
  trash.clear();
 }
 cout << dist[b1][b2];
 return(0);
}