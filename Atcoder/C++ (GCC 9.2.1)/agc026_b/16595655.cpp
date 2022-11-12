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

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
int b[maxn];

set < pii > st;

int32_t main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
        cin >> b[i];
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i],st.insert({a[i] , i});
    int cnt = 0;
    int ans = 0;
    while(cnt!=n){
        int mx = (*st.rbegin()).second;
        st.erase((*st.rbegin()));
        if(a[mx] == b[mx]){
            cnt++;
            continue;
        }
        if(a[mx] < (a[(mx-1 + n)%n] + a[(mx+1)%n]))
            dokme(-1);
        if(b[mx] >= (a[(mx-1 + n)%n] + a[(mx+1)%n])){
            a[mx] -= b[mx];
            if(a[mx] < (a[(mx-1 + n)%n] + a[(mx+1)%n]))
                dokme(-1);
            ans += a[mx] / (a[(mx-1 + n)%n] + a[(mx+1)%n]);
            a[mx]%= (a[(mx-1 + n)%n] + a[(mx+1)%n]);
            a[mx]+=b[mx];
        }
        else{
            ans += a[mx] / (a[(mx-1 + n)%n] + a[(mx+1)%n]);
            a[mx]%= (a[(mx-1 + n)%n] + a[(mx+1)%n]);
        }
        st.insert({a[mx] , mx});
    }
    cout << ans;
    return(0);
}