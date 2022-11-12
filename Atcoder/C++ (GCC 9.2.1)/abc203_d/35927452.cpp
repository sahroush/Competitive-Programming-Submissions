#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

// debugging template
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// end of debug template

// typedefs
const int BIT_SIZE = 16;
typedef long long         (ll );
typedef long double       (ldb);
typedef pair<int, int>    (pii);
typedef pair<ll, ll>      (pll);
typedef vector<int>       (vi );
typedef vector<ll>        (vll);
typedef set<int>          (si );
typedef set<ll>           (sl );
typedef multiset<int>     (msi);
typedef multiset<ll>      (msl);
typedef bitset<BIT_SIZE>  (bs );

// macros
#define fast_io            ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define st_find(x, l)       ((x).find((l)) != (x).end())
#define done               return 0
#define print_arr(x)       for(int i = 0 ; i < sizeof((x)) / sizeof((x)[0]) ; i ++) {cout<<(x)[i]<<' ';} cout<<'\n';
#define get_arr(x)         for(int i = 0 ; i < sizeof((x)) / sizeof((x)[0]) ; i ++) { cin>>(x)[i];}
#define print_vec(x)       for(int i = 0 ; i < (x).size() ; i ++) { cout<<(x)[i]<<' '; } cout<<'\n';
#define FOR(i, s, n)       for(int (i) = (s) ; (i) < (n) ; (i) ++)
#define ROF(i, n, s)        for(int (i) = (n-1); (i) >= (s); (i)--)
#define all(x)             (x).begin() , (x).end()
#define gap                ' '
#define F                  first
#define S                  second
#define pb                 push_back

inline long long power(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long c = power(a, b / 2);
    return c * c * (b & 1 ? a : 1);
}

ll nextINT() {
    ll x ; cin>>x; return x;
}

// things for the problem
// constrains
const int mod = 1e9 + 7;
const int N = 800  + 18;

int n,k; int a[N][N];
int dp[N][N];

bool check(int x) {  //aya chizi darim ke med <= x bashe ya na
    FOR(i,1,n+1) {
        FOR(j,1,n+1) {
            dp[i][j] = (a[i][j] > x ? 1 : -1) + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    for(int i = k ; i <= n ; i ++){
        for(int j = k ; j <= n ; j ++){
            if(dp[i][j] - dp[i-k][j] - dp[i][j-k] + dp[i-k][j-k] <= 0)
                return 1;
        }
    }
    return 0;
}

int main() {
    fast_io
    cin>>n>>k;FOR(i,1,n+1) {FOR(j,1,n+1) {cin>>a[i][j];}}
    int l = -5 , r = 1e9 + 1;
    while(r-l > 1) {
        int mid = (r + l) /2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << l+1;
    done;   
}