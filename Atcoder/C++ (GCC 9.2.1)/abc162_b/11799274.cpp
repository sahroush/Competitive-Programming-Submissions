#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}


int x , y , a , b ,c;
int p[maxn] , q[maxn] , r[maxn];
vector < ll > vec;
ll ans = 0;

int main(){
    migmig
    cin >> x >> y >> a >> b >> c;
    for(int i = 0 ; i < a ; i ++){
        cin >> p[i];
    }
    sort(p , p + a);
    reverse(p , p + a);
    for(int i = 0 ; i < b ; i ++){
        cin >> q[i];
    }
    sort(q , q + b);
    reverse(q , q + b);
    for(int i = 0 ; i < c ; i ++){
        cin >> r[i];
    }
    sort(r , r + c);
    reverse(r , r + c);
    for(int i = 0 ; i < x; i ++ ){
        vec.pb(p[i]);
    }
    for(int i = 0 ; i < y ; i ++){
        vec.pb(q[i]);
    }
    for(int i = 0 ; i < c ; i ++){
        vec.pb(r[i]);
    }
    sort(vec.begin() , vec.end());
    reverse(vec.begin() , vec.end());
    for(int i = 0 ; i < x+y ; i ++){
        ans+=vec[i];
    }
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
