#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2e5+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k , a[maxn];
int b[maxn];
int prt[maxn];

bool chk(){
    bool oke = 1;
    for(int i = 1 ; i <= n ; i ++){
        if(a[i]!=prt[i])
            oke = 0;
        a[i] = prt[i];
    }
    return(oke);
}

void solve(){
    ms(prt , 0);
    for(int i = 1 ; i <= n ; i ++){
        prt[max(0 , i-a[i])]++;
        prt[min(200005 , i+a[i]+1)]--;
    }
    for(int i = 1 ; i <= n ; i ++)
        prt[i] = prt[i-1]+prt[i];
}

int main(){
    migmig
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = 0; i < k ; i ++){
        solve();
        if(chk())break;
    }
    for(int i = 1 ; i <= n ; i ++)cout << a[i] << ' ';
    return(0);
}