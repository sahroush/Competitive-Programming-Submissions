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

int n;
int p[maxn] , cur;
int ans[maxn];
int cyc[maxn];
int order[maxn];
vector < int > adj[maxn];
bool mark[maxn];
set < int > st;

void dfs1(int v = 1){
    if(mark[v]){
        cyc[v] = 1;
        while(order[cur]!=v)
            cyc[order[cur--]] = 1;
        return;
    }
    mark[v] = 1;
    order[++cur] = v;
    dfs1(p[v]);
}

void dfs(int v){
    set < int > st;
    for(auto u : adj[v]){
        if(ans[u] == -1)
            dfs(u);
        st.insert(ans[u]);
    }
    int mn = 0;
    for(;;mn++)
        if(!st.count(mn)){
            ans[v] = mn;
            break;
        }
}

bool chk(int v , int val){
    ans[v] = val;
    int pos = p[v];
    set < int > st;
    while(pos!=v){
        st.clear();
        for(auto u : adj[pos])
            st.insert(ans[u]);
        int mn = 0;
        for(;;mn++)
            if(!st.count(mn)){
                ans[pos] = mn;
                break;
            }
        pos = p[pos];
    }
    st.clear();
    for(auto u : adj[pos])
            st.insert(ans[u]);
    int mn = 0;
        for(;;mn++)
            if(!st.count(mn))
                return(mn == val);
}

int main(){
    migmig
    cin >> n;
    for(int i = 1; i <= n ; i ++)
        cin >> p[i] , adj[p[i]].pb(i);
    ms(ans , -1);
    dfs1();
    cur = 0;
    for(int i = 1 ; i <= n ; i ++)
        if(!cyc[i])dfs(i);
        else cur = i;
    for(auto u : adj[cur])
        if(!cyc[u])
            st.insert(ans[u]);
    int a = -1;
    int b = -1;
    int cnt = 0;
    for(;;cnt++){
        if(st.count(cnt))continue;
        if(a==-1)a = cnt;
        else{
            b = cnt;
            break;
        }
    }
    bool oke = 0;
    oke |= chk(cur , a);
    oke |= chk(cur , b);
    cout << ((oke)?"POSSIBLE" : "IMPOSSIBLE");
    return(0);
}