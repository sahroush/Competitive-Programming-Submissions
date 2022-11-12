#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;//AmShZ
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int h , w , k;
int white[20][2000];

bool chk(int msk , int last , int cur){
    int lr = 0;
    for(int i = 0 ; i < h ; i ++){
        if(msk>>i&1 or i == h-1){
            int cnt = white[i+ 1][cur+1] - white[i+1][last] + white[lr][last] - white[lr][cur+1];
            if(cnt > k){
                return(0);
            }
            lr= i+1;
        }
    }
    return(1);
}

int solve(int last ,int msk ){
    if(chk(msk , last , w - 1)){
        return(0);
    }
    if(!chk(msk , last ,last)){
        return(1e9);
    }
    int cur = last;
    for(int i =  (1 << 15)  ; i > 0 ; i>>=1){
        if(cur + i >= w){
            continue;
        }
        if(!chk(msk , last , cur + i)){
            continue;
        }
        cur+=i;
    }
    return(solve(cur + 1 , msk) + 1);
}

int main(){
    migmig
    cin >> h >> w >> k;
    for(int i = 0 ; i < h ; i ++){
        string s;
        cin >> s;
        for(int j = 0 ; j < w ; j ++){
            white[i+1][j+1] = (s[j] == '1');
        }
    }
    for(int i = 0 ; i <= h; i ++){
        for(int j = 1 ; j <= w ; j ++ ){
            white[i][j]+=white[i][j-1];
        }
    }
    for(int j = 0 ; j <= w ; j ++){
        for(int i = 1 ; i <= h ; i ++ ){
            white[i][j]+=white[i - 1][j];
        }
    }
    int ans= 1e9;
    for(int i = 0 ; i < (1 << (h-1)) ; i ++){
        int res = solve(0 , i) + __builtin_popcount(i);
        ans =min(ans , res);
    }
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
