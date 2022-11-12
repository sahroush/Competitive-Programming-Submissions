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

#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector <int> adj[maxn];
int dp[maxn][2];

void dfs(int v = 1 , int par = 0){
    dp[v][1] = dp[v][0] = 1;
    for(auto u : adj[v])if(u!=par)
        dfs(u , v) ,
        dp[v][1] = (dp[v][1] * dp[u][0])%mod,
        dp[v][0] = (dp[v][0] * (dp[u][1] + dp[u][0])%mod)%mod;
}

int32_t main(){
    migmig
    cin >> n;
    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    cout << (dp[1][0] + dp[1][1])%mod;
    return(0);
}