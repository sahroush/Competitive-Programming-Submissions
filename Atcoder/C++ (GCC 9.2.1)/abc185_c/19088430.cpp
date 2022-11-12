/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
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
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int r1 , r2 , c1 , c2;

int32_t main(){
    migmig;
	cin >> r1 >> c1 >> r2 >> c2;
    int r = r2 - r1, c = c2 - c1;
    int ans = 3;
    if(!r && !c) ans = 0;
    else if(r == c || r == -c || abs(r) + abs(c) <= 3) ans = 1;
    else if((r ^ c ^ 1) & 1 || abs(r + c) <= 3 || abs(r - c) <= 3 || abs(r) + abs(c) <= 6) ans = 2;
    cout << ans << endl;
    return(0);
}
