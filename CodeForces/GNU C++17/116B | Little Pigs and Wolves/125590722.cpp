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
 
int n, m;
string s[maxn];
 
struct hopcroft{ //0 based
    int n , m; // size of each side
    int ans;
    vector < int > mu , mv; // u is matched with mu[u] and v with mv[v], -1 if not matched
    vector < vector < int > > adj;
    vector < int > layer;
    hopcroft(int n, int m):
        n(n) , m(m), ans(0),
        mu(n , -1) , mv(m , -1),
        adj(n) , layer(n){}
    void add_edge(int u, int v){
        adj[u].push_back(v);
        if(mu[u] == -1 and mv[v] == -1)
            ans ++ , mu[u] = v , mv[v] = u;
    }
    void bfs(){
        queue <int> q;
        for(int u = 0; u < n; u ++){
            if(mu[u] == -1) q.push(u), layer[u] = 0;
            else layer[u] = -1;
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto v: adj[u]) if(mv[v] != -1 and layer[mv[v]] == -1){
                layer[mv[v]] = layer[u] + 1;
                q.push(mv[v]);
            }
        }
    }
    bool dfs(int u){
        for(auto v: adj[u]) if(mv[v] == -1){
            mu[u] = v, mv[v] = u;
            return(1);
        }
        for(auto v: adj[u]) if(layer[mv[v]] == layer[u] + 1 and dfs(mv[v])){
            mu[u] = v, mv[v] = u;
            return(1);
        }
        return(0);
    }
    int solve(){ // O( sqrt(V) * E )
        while(true){
            bfs();
            int augment = 0;
            for(int u = 0; u < n; u ++)
                if(mu[u] == -1)
                    augment += dfs(u);
            if(!augment)
                break;
            ans += augment;
        }
        return(ans);
    }
};
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n >> m;
 hopcroft g(n * m, n * m);
 for(int i = 0 ; i < n ; i ++)
  cin >> s[i];
 for(int i = 0 ; i < n ; i ++){
  for(int j = 0 ; j < m ; j ++)if(s[i][j] == 'W'){
   if(i){
    if(s[i - 1][j] == 'P')g.add_edge(i * m + j, (i - 1) * m + j);
   }
   if(i + 1 < n){
    if(s[i + 1][j] == 'P')g.add_edge(i * m + j, (i + 1) * m + j);
   }
   if(j){
    if(s[i][j - 1] == 'P')g.add_edge(i * m + j, i * m + j - 1);
   }
   if(j + 1 < m){
    if(s[i][j + 1] == 'P')g.add_edge(i * m + j, i * m + j + 1);
   }
  }
 }
 cout << g.solve();
 return(0);
}