#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 110;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
ll ans = 0;

struct Dinic {
    #define MAXN 100010
    int n = 0, m = 0, turn = 0;
    vector < int > a, b, h, mark, pos, adj[MAXN];
    vector < int64_t > c, d;
    queue < int > q;
    void add_edge(int u, int v, int64_t w = 1) {
        u--, v--;
        adj[u].push_back(m);
        adj[v].push_back(m);
        a.push_back(u);
        b.push_back(v);
        c.push_back(w);
        m++;
        n = max(n, max(u, v) + 1);
    }
    void bfs(int v) {
        mark[v] = turn;
        int l = 0, r = 0;
        pos[r++] = v;
        h[v] = 0;
        while (l < r) {
            int v = pos[l++];
            for (int w: adj[v]) {
                if (a[w] == v and mark[b[w]] ^ turn and c[w] - d[w] > 0) {
                    mark[b[w]] = turn, h[b[w]] = h[v] + 1;
                    pos[r++] = b[w];
                }
                if (b[w] == v and mark[a[w]] ^ turn and d[w] > 0) {
                    mark[a[w]] = turn, h[a[w]] = h[v] + 1;
                    pos[r++] = a[w];
                }
            }
        }
    }
    int64_t pump(int v, int source, int sink, int64_t cap = (1LL << 62)) {
        int64_t ans = 0;
        if (v == sink)
            return cap;
        if (v == source)
            turn++, bfs(v), fill(pos.begin(), pos.end(), 0);
        mark[v] = turn;
        for (; pos[v] < int(adj[v].size()); pos[v]++) {
            int w = adj[v][pos[v]];
            if (a[w] == v) {
                if (c[w] - d[w] == 0) continue;
                if (h[b[w]] ^ (h[v] + 1)) continue;
                int64_t res = pump(b[w], source, sink, min(cap, c[w] - d[w]));
                ans += res;
                cap -= res;
                d[w] += res;
            }
            if (b[w] == v) {
                if (d[w] == 0) continue;
                if (h[a[w]] ^ (h[v] + 1)) continue;
                int64_t res = pump(a[w], source, sink, min(cap, d[w]));
                ans += res;
                cap -= res;
                d[w] -= res;
            }
        }
        return ans;
    }
    int tidy(int v, int ti = 0){
		mark[v] = ++ti;
		for(auto w : adj[v]){
			if(a[w] == v){
				if(mark[b[w]] == 0)ti = tidy(b[w], ti);
			}
			if(b[w] == v){
				if(mark[a[w]] == 0)ti = tidy(a[w], ti);
			}
			if(mark[a[w]] > mark[b[w]])swap(a[w], b[w]);
		}
		return ti;
	}
    int64_t solve(int source, int sink) {
        source--, sink--;
        int64_t ans = 0;
        d.resize(m), fill(d.begin(), d.end(), 0);
        mark.resize(n), fill(mark.begin(), mark.end(), 0);
        //tidy(source);
        fill(mark.begin(), mark.end(), 0);
        h.resize(n);
        pos.resize(n);
        while (int64_t pumped = pump(source, source, sink))
            ans += pumped;
        return ans;
    }
};

Dinic flow;

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i], ans += max(a[i], 0);
	for(int i = 1 ; i <= n ; i ++)
		for(int j = i * 2 ; j <= n ; j += i){
			flow.add_edge(i, j, 1e18);
		}
	for(int i = 1 ; i <= n ; i ++){
		if(a[i] < 0){
			flow.add_edge(n + 1 , i , -a[i]);
		}
		if(a[i] > 0){
			flow.add_edge(i , n + 2 , a[i]);
		}
	}
	cout << ans - flow.solve(n + 1 , n + 2) << endl;
	//for(int i = 0 ; i < flow.m ; i ++)
		//cout << flow.a[i] << ' ' << flow.b[i] << ' ' << flow.c[i] << endl;
	return(0);
}
