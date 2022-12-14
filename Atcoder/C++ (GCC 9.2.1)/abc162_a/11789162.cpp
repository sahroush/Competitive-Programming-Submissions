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

int n , x , y;
int dist[3000][3000];
int cnt[maxn];

int main(){
    migmig
    cin >> n >> x >> y;
    ms(dist , 63);
    for(int i = 1 ; i <= n ; i ++){
        for(int j = i ; j <= n ; j ++){
            dist[i][j] = j - i;
        }
    }
    for(int i = 1 ; i <= n ; i ++){
        for(int j = i+1 ; j <= n ; j ++){
            dist[i][j] = min(dist[i][j] , dist[i][x] + dist[y][j] + 1);
            dist[i][j] = min(dist[i][j] , dist[x][i] + dist[y][j] + 1);
            dist[i][j] = min(dist[i][j] , dist[i][x] + dist[j][y] + 1);
            dist[i][j] = min(dist[i][j] , dist[x][i] + dist[j][y] + 1);
            dist[i][j] = min(dist[i][j] , dist[i][y] + dist[x][j] + 1);
            dist[i][j] = min(dist[i][j] , dist[i][y] + dist[j][x] + 1);
            dist[i][j] = min(dist[i][j] , dist[y][i] + dist[x][j] + 1);
            dist[i][j] = min(dist[i][j] , dist[y][i] + dist[j][x] + 1);
            cnt[dist[i][j]]++;
        }
    }
    for(int i = 1 ; i < n ; i ++){
        cout << cnt[i] << endl;
    }

    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u p??ajtal m??ak jach t??aj meyajilo'ob le castigadas tumen ch'aik descansos.
