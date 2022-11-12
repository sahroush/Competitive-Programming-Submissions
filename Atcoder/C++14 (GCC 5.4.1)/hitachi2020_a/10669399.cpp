#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =9e5+100;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m;
int mark[100];

int main(){
    migmig
    for (int i = 0 ; i < 100 ; i ++){
        mark[i] = -1;
    }
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++){
        int s , c;
        cin >> s >> c;
        s--;
        if(mark[s] == -1){
            mark[s] = c;
        }
        else if(c!=mark[s]){
            dokme(-1);
        }
    }
    if(mark[0] == -1){
        mark[0] = 1;
        if(n == 1){
            mark[0] = 0;
        }
    }
    if(mark[0] == 0 and n > 1){
        dokme(-1);
    }
    for (int i = 0 ; i < n ; i ++){
        if(mark[i] == -1){
            mark[i] = 0;
        }
        cout << mark[i];
    }

    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
