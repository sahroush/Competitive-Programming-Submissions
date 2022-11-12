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

int n;
int a[maxn];

int32_t main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    sort(a , a + n);
    if(a[n-1] - a[0] > 1)
        dokme("No");
    for(int i = 1 ; i < n ; i ++)
        a[i]-=a[0];
    int cnt[] = {1 , 0 };
    for(int i = 1 ; i < n ; i ++)
        cnt[a[i]]++;
    if(cnt[0] == n){
        if(a[0] == n-1)
            dokme("Yes");
        if(a[0]*2 <= n)
            dokme("Yes");
        dokme("No");
    }
    n--;
    if(cnt[0]+1 <= a[n]+a[0])
        if(cnt[0]+cnt[1]/2 >= a[n]+a[0])
            dokme("Yes");
    dokme("No");
    return(0);
}