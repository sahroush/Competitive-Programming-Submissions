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
deque < int > dq;
bool mark[maxn];
vector < int > adj[maxn];

bool addb(){
    int v = dq.back();
    for(auto u : adj[v])
        if(!mark[u]){
            mark[u] = 1,
            dq.pb(u);
            return(1);
        }
    return(0);
}
bool addf(){
    int v = dq.front();
    for(auto u : adj[v])
        if(!mark[u]){
            mark[u] = 1,
            dq.push_front(u);
            return(1);
        }
    return(0);
}
bool done(){
    if(addb())
        return(0);
    if(addf())
        return(0);
    return(1);
}

void make(){
    dq.pb(1), mark[1] = 1;
    while(!done())
        continue;
}

int32_t main(){
    migmig
    cin >> n >> m;
    for(int i = 0; i < m ; i ++){
        int u , v;
        cin >> u >> v,
        adj[u].pb(v),
        adj[v].pb(u);
    }
    make();
    cout << dq.size() << endl;
    for(int i : dq)
        cout << i << ' ';
    return(0);
}