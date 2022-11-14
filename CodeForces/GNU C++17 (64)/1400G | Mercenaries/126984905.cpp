#include <bits/stdc++.h>
 
using namespace std;
using namespace chrono;
 
const int maxn = 3e5 + 10;
const int mod = 998244353;
const uint32_t seed = steady_clock::now().time_since_epoch().count();
 
mt19937 rng(seed);
 
typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
 
#define endl '\n'
#define ms(x, y) memset(x, y, sizeof x)
#define dokme(x) cout << x, exit(0)
#define pb push_back
ll pw(ll a,ll b,ll m=mod){ll r=1;while(b){if(b&1)r=r*a%m;if(b>>=1)a=a*a%m;}return r;}
 
int n, m;
int l[maxn], r[maxn];
int cnt[maxn];
int s[maxn], t[maxn];
ll fact[maxn], inv[maxn];
int ans[maxn][45];
unordered_set < int > vert;
 
ll C(int r, int n){
    if(r > n or r < 0)return 0;
    return fact[n] * inv[r] % mod * inv[n - r] % mod;
}  
 
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++){
        cin >> l[i] >> r[i];
        cnt[l[i]] ++, cnt[r[i] + 1] --;
    }
    for(int i = 0 ; i < m ; i ++){
        cin >> s[i] >> t[i];
    }
    fact[0] = inv[0] = 1;
    for(int i = 1 ; i < maxn ; i ++)
        fact[i] = fact[i - 1] * i % mod, inv[i] = pw(fact[i], mod - 2), cnt[i] += cnt[i - 1];
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 0 ; j <= 2 * m ; j ++)
            ans[i][j] = (ans[i - 1][j] + C(i - j , cnt[i] - j)) % mod;
    int sum = 0;
    for(int i = 0 ; i < (1 << m) ; i ++){
        vert.clear();
        for(int j = 0 ; j < m ; j ++)if((1 << j) & i){
            vert.insert(s[j]), vert.insert(t[j]);
        }
        int sl = 1, sr = n, sz = vert.size();
        for(auto v : vert)
            sl = max(sl , l[v]), sr = min(sr, r[v]);
        if(sl > sr)continue;
        int res = (ans[sr][sz] + mod - ans[sl - 1][sz])%mod;
        sum = (sum + ((__builtin_popcount(i) & 1) ? -res : res))%mod;
        sum = (sum + mod)%mod;
    }
    cout << sum;
    return 0;
}
                               