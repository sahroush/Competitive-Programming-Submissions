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

int sz[maxn] , par[maxn];
int n;
ll a[maxn];
vector < int > srt;

bool cmp(int i , int j){
    return(a[i] > a[j]);
}

ll ans = 0;

int getpar(int v){
    return((v == par[v]) ? v : par[v] = getpar(par[v]));
}

ll merge(int x , int y){
    if(a[y] < a[x])
        return(0);
    x = getpar(x) , y = getpar(y);
    ll ans = sz[y];
    if(sz[x] < sz[y])
        swap(x , y);
    sz[x] += sz[y];
    par[y] = x;
    return(ans);
}

int32_t main(){
    migmig
    cin >> n ;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i],srt.pb(i);
    sort(srt.begin() , srt.end() , cmp);
    for(int i : srt){
        sz[i] = 1;
        par[i] = i;
        ll val = 1;
        val += merge(i , i + 1);
        val *= (merge(i , i - 1)+1);
        ans += val*a[i];
    }
    cout << ans;
    return(0);
}