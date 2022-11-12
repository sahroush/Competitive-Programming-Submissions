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

const ll maxn  = 3100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s;
string t;
int dp[maxn][maxn];
int par[maxn][maxn];

int32_t main(){
    migmig
    cin >> s;
    cin >> t;
    int n = s.size() , m = t.size();
    s = "." + s;
    t = '.' + t;
    pii mx = {0 , 0};
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= m ; j ++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1]+1;
                par[i][j] = 3;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                par[i][j] = 2;
            }
            else{
                dp[i][j] = dp[i][j-1];
                par[i][j] = 1;
            }
            if(dp[i][j] > dp[mx.first][mx.second])
                mx = {i , j};
        }
    }
    string ans = "";
    while(mx!=pii(0 , 0)){
        auto [f , s] = mx;
        if(par[f][s] == 3){
            ans = t[s] + ans;
        }
        int bz = par[f][s]>=2;
        s -= par[f][s]%2;
        f -= bz;
        mx = {f , s};
        if(par[f][s] == 0)
            break;
    }
    cout << ans;
    return(0);
}