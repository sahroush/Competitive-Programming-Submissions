#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 3e6;
const ll mod = 1e9+7;
 
#define pb push_back
#define endline '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
 
ll dp[100005];
ll summ[100005];
 
int main()
{
    ll n,k;
    cin >> n >> k;
 
    summ[0]=1;
    for (ll i = 0; i < k; i++)
    {
  summ[i] = i;
        dp[i]=1;
    }
 
    for (ll i = k; i <=100000; i++)
    {
        dp[i]=(dp[i-1]+dp[i-k])%mod;
        summ[i]=(summ[i-1]+dp[i])%mod;
    }
 
    while(n--)
    {
        ll a,b;
        cin >> a >> b;
        cout << (summ[b]-summ[a - 1] + mod)%mod << endline;
    }
 
    return 0;
}