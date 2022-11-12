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
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt"adj[i], "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , ok = 1;
ll a[maxn];
vector < int > adj[maxn];
ll dp[maxn];

ll dfs(int v , int par = 0){
    if(adj[v].size() == 1)
        return(a[v]);
    ll sum =0 ;
    for(auto u : adj[v])
        if(u!=par){
            ll x = dfs(u , v);
            if(x > a[v])
                ok = 0;
            sum += x;
        }
    if(sum < a[v] or sum > 2*a[v])
        ok = 0;
    if(par == 0 and sum!= 2 * a[v])
        ok = 0;
    return(2 * a[v] - sum);
}

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(n == 2){
        dokme(((a[1] == a[2]) ? "YES" : "NO" ));
    }
    for(int i = 1 ; i <= n ; i ++){
        if(adj[i].size() > 1){
            dfs(i);break;}
    }
    cout << ((ok) ? "YES" : "NO");
    return(0);
}