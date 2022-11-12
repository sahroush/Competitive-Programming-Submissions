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
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ld n;
int cnt[3];
ld dp[310][310][310];

int32_t main(){
    migmig
    cin >> n;
    for(int i = 0;  i < n ; i ++){
        int x;
        cin >> x;
        cnt[x-1]++;
    }
    for(int i = 0; i <= n ; i ++)
        for(int j = 0 ; j <= n-i ; j ++)
            for(int k = 0 ; k <= n-i-j ; k ++){
                int x = i + j + k;
                if(!x)continue;
                if(i) dp[i][j][k] += (dp[i - 1][j + 1][k] + n/ld(x)) * ld(i)/ld(x);
                if(j) dp[i][j][k] += (dp[i][j - 1][k + 1] + n/ld(x)) * ld(j)/ld(x);
                if(k) dp[i][j][k] += (dp[i][j][k - 1] + n/ld(x)) * ld(k)/ld(x);
            }
    cout << setprecision(14) << dp[cnt[2]][cnt[1]][cnt[0]];
    return(0);
}