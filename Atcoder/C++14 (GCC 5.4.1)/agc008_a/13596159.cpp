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

ll n;
ll prt[5000][3];
string s;
ll ans;

int main(){
    migmig
    cin >> n;
    cin >> s;
    for(ll i = 0 ; i < n; i ++){
        if(i){
            prt[i][0] = prt[i-1][0];
            prt[i][1] = prt[i-1][1];
            prt[i][2] = prt[i-1][2];
        }
        if(s[i] == 'R'){
            prt[i][0]++;
        }
        if(s[i] == 'G'){
            prt[i][1]++;
        }
        if(s[i] == 'B'){
            prt[i][2]++;
        }
    }
    for(ll i = 0 ; i < s.size() ; i ++){
        for(ll j = i+2 ; j < s.size() ; j ++){
            if(s[i] != s[j]){
                if(s[i] != 'R' and s[j] != 'R'){
                    ans+=prt[j][0] - prt[i][0];
                }
                if(s[i] != 'G' and s[j] != 'G'){
                    ans+=prt[j][1] - prt[i][1];
                }
                if(s[i] != 'B' and s[j] != 'B'){
                    ans+=prt[j][2] - prt[i][2];
                }
                if((i + j)%2 == 0){
                    if(s[(i + j)/2] != s[i] and s[(i + j)/2]!=s[j]){
                        ans--;
                    }
                }
            }
        }
    }
    cout << ans;


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
