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

string s;
int n;
int nxt[maxn] , prv[maxn];

int32_t main(){
    migmig
    cin >> s;
    for(int i = 0 ; i < s.size() ; i ++)
        prv[i] = i-1 , nxt[i] = i + 1;
    int cur = 0;
    while(1){
        int ans = -1;
        for(int i = nxt[0] ; i < s.size()-1 ; i = nxt[i]){
            if(s[prv[i]] != s[nxt[i]]){
                ans = i;
                break;
            }
        }
        if(ans == -1){
            if(cur == 0)
                dokme("Second")
            else
                dokme("First")
        }
        nxt[prv[ans]] = nxt[ans];
        prv[nxt[ans]] = prv[ans];
        cur = 1 - cur;
    }
    return(0);
}