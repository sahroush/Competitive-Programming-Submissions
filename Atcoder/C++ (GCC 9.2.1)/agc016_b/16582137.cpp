/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 900;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s[maxn];
int dist[maxn][maxn];
queue < pii > q,q2;
int w , h , k;
int dx [] = {1 , -1 , 0 , 0};
int dy [] = {0 , 0 , 1 , -1};
bool mark[maxn][maxn];

void bfs1(){
    while(!q.empty()){
        q2.push(q.front());
        auto v = q.front();
        q.pop();
        int x = v.first , y = v.second;
        if(x == 0 or y == 0 or x == w-1 or y == h-1){
            cout << 1;
            exit(0);
        }
        if(dist[x][y] == k)
            continue;
        for(int i = 0 ; i < 4 ; i ++){
            if(s[x + dx[i]][y + dy[i]] == '.' and dist[x + dx[i]][y + dy[i]] > dist[x][y] + 1){
                dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
                q.push({x + dx[i] , y + dy[i]});
            }
        }
    }
}

void bfs2(){
    int ans = 1e9;
    while(!q2.empty()){
        auto [x , y] = q2.front();
        q2.pop();
        int val = min(min(x , h - x - 1) , min(y , w - y - 1));
        ans = min(ans , (val+k-1)/k);
    }
    cout << ans+1;
}

int32_t main(){
    migmig
    ms(dist , 63);
    cin >> h >> w >> k;
    for(int i = 0 ; i < h ; i ++){
        cin >> s[i];
        for(int j = 0 ; j < w ; j ++)
            if(s[i][j] == 'S')
                q.push({i , j}),
                dist[i][j] = 0;
    }
    bfs1();
    bfs2();
    return(0);
}