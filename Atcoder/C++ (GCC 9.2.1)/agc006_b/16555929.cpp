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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll ans = 5e18;
ll a[maxn];
ll mn[maxn];
ll x;
int n;

ll sum(){
    ll sum = 0;
    for(int i = 0 ; i < n ; i ++)
        sum += mn[i];
    return(sum);
}

int32_t main(){
    migmig
    cin >> n >> x;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i] , mn[i] = a[i];
    ans = sum();
    for(ll i = 0 ; i < n ; i ++){
        ans = min(ans , sum() + x*i);
        for(int j = 0 ; j < n ; j ++)   
            mn[j] = min(mn[j], a[((j-i-1)+n)%n]);
    }
    cout << ans;
    return(0);
}