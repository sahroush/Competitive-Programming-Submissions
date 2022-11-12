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

#define int ll
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

int n , p;
string s;
int a[maxn];
map < int , int > mp;

int32_t main(){
    migmig
    cin >> n >> p;
    cin >> s;
    if(p == 2 or p == 5){
        ll ans = 0;
        for(int i = 0 ; i< n ; i ++)
            if((s[i] - '0')%p == 0)
                ans += i + 1;
        dokme(ans);
    }
    ll ans = 0;
    ll cur = 1;
    ll boz = 0;
    mp[0]++;
    for(int i = n - 1 ; i >= 0 ; i --){
        boz = (boz + cur * (s[i] - '0'))%p;
        cur = (cur*10) % p;
        mp[boz]++;
    }
    for(auto [f , s] : mp)
        ans += s * (s - 1) / 2;
    cout << ans;
    return(0);
}