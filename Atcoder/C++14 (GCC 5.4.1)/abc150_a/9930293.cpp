#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =40;
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

int mx = 0 , h , w;
int dist[maxn][maxn];
bool mark[maxn][maxn];
string s[maxn];
queue < pii > q;

void solve(int x ,int y){
    ms(mark , 0);
    dist[x][y] = 0;
    mark[x][y] = 1;
    q.push(pii (x , y));
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        if(s[cur.first][cur.second] == '#') continue;
        mx = max(mx , dist[cur.first][cur.second]);
        if(cur.first < h - 1 and !mark[cur.first + 1][cur.second]){
            mark[cur.first + 1][cur.second] = 1;
            dist[cur.first + 1][cur.second] = dist[cur.first ][cur.second] + 1;
            q.push(pii(cur.first + 1 , cur.second));
        }
        if(cur.first > 0 and !mark[cur.first - 1][cur.second]){
            mark[cur.first - 1][cur.second] = 1;
            dist[cur.first - 1][cur.second] = dist[cur.first ][cur.second] + 1;
            q.push(pii(cur.first - 1 , cur.second));
        }

        if(cur.second < w - 1 and !mark[cur.first ][cur.second+1]){
            mark[cur.first ][cur.second+1] = 1;
            dist[cur.first ][cur.second+1] = dist[cur.first ][cur.second] + 1;
            q.push(pii(cur.first  , cur.second+1));
        }

        if(cur.second >0  and !mark[cur.first ][cur.second-1]){
            mark[cur.first][cur.second-1] = 1;
            dist[cur.first][cur.second-1] = dist[cur.first ][cur.second] + 1;
            q.push(pii(cur.first , cur.second-1));
        }

    }
}

int main(){
    migmig
    cin >> h >> w;
    for (int i = 0 ; i < h ; i ++){
        cin >> s[i];
    }
    for (int i = 0 ; i < h ; i ++){
        for (int j = 0 ; j < w ; j ++){
            solve( i  , j);
        }
    }
    cout << mx;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
