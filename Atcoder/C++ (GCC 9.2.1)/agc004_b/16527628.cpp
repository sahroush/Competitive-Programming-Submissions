/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
int type[maxn];
string s;
set < int > adj[maxn][2];
queue < int > q;
set < int > st;

bool bad(int v){
    return(adj[v][0].size() == 0 or adj[v][1].size() == 0);
}

void remove(int v){
    st.erase(v);
    for(auto u : adj[v][0]){
        adj[u][type[v]].erase(v);
        if(st.count(u) and bad(u))
            q.push(u);
    }
    for(auto u : adj[v][1]){
        adj[u][type[v]].erase(v);
        if(st.count(u) and bad(u))
            q.push(u);
    }
}

int32_t main(){
    migmig
    cin >> n >> m;
    cin >> s;
    int cnt = 1;
    for(auto i : s)
        type[cnt++] = (i=='A');
    for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u][type[v]].insert(v);
        adj[v][type[u]].insert(u);
    }
    for(int i = 1 ; i <= n ; i ++)
        st.insert(i);
    for(int i = 1 ; i <= n;  i ++)
        if(bad(i))
            q.push(i);
    while(q.size()){
        int v = q.front();
        q.pop();
        remove(v);
    }
    cout << (st.size()?"Yes" : "No");
    return(0);
}