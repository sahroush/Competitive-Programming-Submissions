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

const ll maxn  = 2e5+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s , ans;
int dp[maxn][27];

int32_t main(){
    migmig
    cin >> s;
    int n = s.size();
    for(int i = 0 ; i < 26 ; i ++)
        dp[n][i] = 1;
    for(int i = n-1 ; i >= 0 ; i --){
        int mn = n;
        for(int j = 0 ; j < 26 ; j ++) mn = min(mn , dp[i+1][j]);
        for(int j = 0 ; j < 26 ; j ++) dp[i][j] = min(mn + 1 , dp[i+1][j]);
        if(mn == dp[i + 1][s[i] - 'a'])dp[i][s[i] - 'a'] = mn + 1;
    }
    for(int i = 0 ; i <= n; i ++){
        int mn = n, anss = 0;
        for(int j = 0 ; j < 26 ; j ++)
            if(dp[i][j] < mn)
                mn = dp[i][j] , anss = j;
        ans += char(anss + 'a');
        if(mn == 1)
            break;
        while(s[i]!=char(anss + 'a'))i++;
    }
    cout << ans;
    return(0);
}