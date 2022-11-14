#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 310;
const ll mod = 1e9+7;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
#define sz(x) int(x.size())
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
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
 
int n;
int a[maxn], col[maxn], cnt, val[maxn];
vector < int > in[maxn], out[maxn], topo;
 
void sfd(int v){
 col[v] = cnt;
 for(auto u : in[v])if(col[u] == -1)
  sfd(u);
}
 
void dfs(int v){
 col[v] = -1;
 for(auto u : out[v])if(~col[u])
  dfs(u);
 topo.pb(v);
}
 
struct Dinic {
    #define MAXN 310
    int n = 0, m = 0;
    vector < int > a, b, h, pos, adj[MAXN];
    vector < int > c, d;
    queue < int > q;
    void add_edge(int u, int v, int w = 1) {
        //u--, v--;
        //cout << u << ' ' << v << ' ' << w << endl;
        adj[u].push_back(m);
        adj[v].push_back(m);
        a.push_back(u);
        b.push_back(v);
        c.push_back(w);
        m++;
        n = max(n, max(u, v) + 1);
    }
    bool bfs(int source, int sink, int C) {
                fill(h.begin(), h.end(), -1);
                h[source] = 0;
        int l = 0, r = 0;
        pos[r++] = source;
        while (l < r) {
            int v = pos[l++];
            for (int w: adj[v]) {
                if (a[w] == v and h[b[w]] == -1 and c[w] - d[w] >= C) {
                    h[b[w]] = h[v] + 1;
                    pos[r++] = b[w];
                }
                if (b[w] == v and h[a[w]] == -1 and d[w] >= C) {
                    h[a[w]] = h[v] + 1;
                    pos[r++] = a[w];
                }
            }
        }
        return h[sink] != -1;
    }
        bool pump(int v, int source, int sink, int cap) {
        if (v == sink)
            return 1;
        for (; pos[v] < int(adj[v].size()); pos[v]++) {
            int w = adj[v][pos[v]];
            if (a[w] == v) {
                if (c[w] - d[w] < cap) continue;
                if (h[b[w]] ^ (h[v] + 1)) continue;
                if(pump(b[w], source, sink, min(cap, c[w] - d[w]))){
                                        d[w] += cap;
                                        return 1;
                                }
            }
            if (b[w] == v) {
                if (d[w] < cap) continue;
                if (h[a[w]] ^ (h[v] + 1)) continue;
                if(pump(a[w], source, sink, min(cap, d[w]))){
                                        d[w] -= cap;
                                        return 1;
                                }
            }
        }
        return 0;
    }
    int solve(int source, int sink) {
        //source--, sink--;
        int ans = 0;
        d.resize(m), fill(d.begin(), d.end(), 0);
        h.resize(n);
        pos.resize(n);
        for(int C = (1 << 30) ; C ; C >>= 1)
                        while(bfs(source, sink, C)){
              //              cout << "diuck" << flush << endl;
                                fill(pos.begin(), pos.end(), 0);
                                while(pump(source, source, sink, C))
                                        ans += C;
                        }
        return ans;
    }
}dic;
 
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n;
    dic.n = n + 4;
 hopcroft g(n, n);
 for(int i = 0 ; i < n ; i ++){
  int k;
  for(cin >> k; k ; k --){
   int v;
   cin >> v;
   g.add_edge(i, v - 1);
  }
 }
 assert(g.solve() == n);
 for(int i = 0 ; i < n ; i ++)cin >> a[i];
 int ans = 0;
 for(int i = 0 ; i < n ; i ++){
  for(int v : g.adj[i])if(i ^ g.mv[v])
   dic.add_edge(i, g.mv[v], 1ll << 29);
 }
 for(int i = 0 ; i < n ; i ++)if(a[i] >= 0)
        dic.add_edge(i, n + 1, a[i]);
    for(int i = 0 ; i < n ; i ++)if(a[i] < 0)
        dic.add_edge(n, i, -a[i]), ans += a[i];
   // dokme(dic.solve(n, n + 1) << endl);
 cout << ans + dic.solve(n, n + 1);
 return(0);
}