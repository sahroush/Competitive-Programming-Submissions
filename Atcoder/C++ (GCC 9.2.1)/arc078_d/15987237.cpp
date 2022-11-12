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

int n;
vector < int > adj[maxn];
int mat[maxn];
bool ok = 0;

void dfs(int v , int par = 0){
    for(auto u : adj[v])
        if(u!=par){
            dfs(u, v);
            if(mat[u] == 0 and mat[v] == 0){
                mat[u] = 1 , mat[v] = 1;
            }
        }
}

int main(){
    migmig
    cin >>  n;
    for(int i = 0 ; i < n- 1 ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1 ; i <= n ; i ++){
        if(adj[i].size()> 1 ){
            dfs(i);
            break;
        }
    }
    ok = 1;
    for(int i = 1 ; i <= n ; i ++){
        ok&=(mat[i]!=0);
    }
    if(n==2)dokme("Second");
    cout << ((!ok) ? "First" : "Second");
    return(0);
}