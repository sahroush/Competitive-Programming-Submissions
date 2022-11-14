#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;
 
const ll maxn =8e5+5;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);
 
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}
 
struct edge{
    int u , v , var;
    bool used = 0;
};
 
int n , m , start[maxn];
vector < int > var[maxn] , c[maxn];
bool is1[maxn] , isset[maxn] , ans[maxn];
vector < pii > adj[maxn];
vector < int > comp[maxn];
int cnt = 1;
bool mark[maxn];
vector <edge> vec[maxn];
map <pii , bool> mp[maxn];
queue <int> q;
 
bool chk(){
    for (int i = 1 ; i <= n ; i ++){
        bool f = 0;
        for (int j = 0 ; j < c[i].size() ; j ++){
            bool val = ans[abs(c[i][j])];
            if(c[i][j] < 0){
                val = !val;
            }
            f|=val;
        }
        if(!f){
            return(0);
        }
    }
    return(1);
}
 
void solve(int v){
    mark[v] = 1;
    for (auto u : adj[v]){
        if(!mark[u.first] and !isset[u.second]){
            isset[u.second] = 1;
            if(var[u.second][0] == u.first or var[u.second][1] == u.first){
                ans[u.second] = 1;
            }
            else{
                ans[u.second] = 0;
            }
            is1[u.first] = 1;
            solve (u.first);
        }
    }
}
 
void tag(int v){
    mark[v] = 1;
    for (auto u : adj[v]){
        edge e;
        e.u = u.first , e.v = v , e.var = u.second;
        if(!mp[v].count(pii(u.first ,u.second))){
            mp[v][pii(u.first , u.second)] = true;
            mp[u.first][pii(v , u.second)] = true;
            vec[cnt].pb(e);
        }
        if(!mark[u.first]){
            vec[cnt].back().used = 1;
            tag (u.first);
        }
    }
}
 
int main(){
    migmig
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++){
        int sz;
        cin >> sz;
        for (int j = 0 ; j < sz ; j ++){
            int inp;
            cin >> inp;
            c[i].pb(inp);
            if(inp > 0){
                var[inp].pb(i);
            }
            else{
                var[-inp].pb(-i);
            }
        }
    }
    for (int i = 1 ; i <= m ; i ++){
        if(var[i].size() == 0){
            isset[i] = 1;
            continue;
        }
        if(var[i].size() == 1){
            isset[i] = 1;
            if(var[i][0] > 0){
                ans[i] = 1;
            }
            is1[abs(var[i][0])] = 1;
            q.push(abs(var[i][0]));
        }
        else{
            if(var[i][0] > 0 and var[i][1] > 0){
                isset[i] = 1;
                ans[i] = 1;
                is1[var[i][0]] = is1[var[i][1]] = 1;
                q.push(var[i][0]);
                q.push(var[i][1]);
            }
            if(var[i][0] < 0 and var[i][1] < 0){
                isset[i] = 1;
                is1[-var[i][0]]  = 1;
                is1[-var[i][1]]  = 1;
                q.push(-var[i][0]);
                q.push(-var[i][1]);
            }
        }
    }
 
    for (int i = 1 ; i <= m ; i ++){
        if(!isset[i]){
            int u = abs(var[i][0]) , v = abs(var[i][1]);
            adj[u].pb(pii(v , i));
            adj[v].pb(pii(u , i));
        }
    }
 
    while(!q.empty()){
        int v = q.front();
        q.pop();
        mark[v] = 1;
        for (auto u : adj[v]){
            if(!mark[u.first] and !isset[u.second]){
                isset[u.second] = 1;
                if(var[u.second][0] == u.first or var[u.second][1] == u.first){
                    ans[u.second] = 1;
                }
                else{
                    ans[u.second] = 0;
                }
                is1[u.first] = 1;
                q.push(u.first);
            }
        }
    }
 
    ms(mark , 0);
    for (int i = 1 ; i <= n ; i ++){
        if(!mark[i] and !is1[i]){
            tag(i);
            cnt++;
        }
    }
 
    ms(mark , 0);
    for (int i = 1 ; i < cnt ; i ++){
        for (int j = 0 ; j < vec[i].size() ; j ++){
            if(vec[i][j].used==0){
                isset[vec[i][j].var] = 1;
                if(var[vec[i][j].var][0] == vec[i][j].v or var[vec[i][j].var][1] == vec[i][j].v){
                    ans[vec[i][j].var] = 1;
                }
                else{
                    //assert(var[vec[i][j].var][0] == -vec[i][j].v or var[vec[i][j].var][1] == -vec[i][j].v);
                    ans[vec[i][j].var] = 0;
                }
                is1[vec[i][j].v] = 1;
                //cout << vec[i][j].v << endl;
                solve(vec[i][j].v);
                break;
            }
        }
    }
 
 
 
    if(!chk()){
        cout << "NO";
        return(0);
    }
    cout << "YES" << endl;
    for (int i = 1 ; i <= m ; i ++){
        cout << ans[i];
    }
    return(0);
}