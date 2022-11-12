/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2000;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}


int dx[] = {0 , 0, 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

int w , h;
int n , m;

int mark[maxn][maxn];

struct tr{
	int x , y , d;
	tr(int a , int b , int c):
		x(a) , y(b) , d(c){}
};

queue < tr > q;

int32_t main(){
    migmig;
    cin >> h >> w;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++){
		int x , y;
		cin >> y >> x;
		for(int j = 0 ; j < 4 ; j ++ )
			q.push({x , y , j});
	}
	for(int i = 0 ; i < m ; i ++){
		int x , y;
		cin >> y >> x;
		mark[x][y] = -1;
	}
    while(!q.empty()){
		auto v = q.front();
		q.pop();
		int x = v.x , y = v.y;
		int d = v.d;
		if(x < 0 or x > w)continue;
		if(y < 0 or y > h)continue;
		if(mark[x][y] == -1)continue;
		if(mark[x][y] & (1 << d))continue;
		mark[x][y]|=(1 << d);
		q.push({x + dx[d] , y + dy[d] , d});
	}
	int ans = 0;
	for(int i = 1 ; i <= w; i ++ )
		for(int j = 1 ; j <= h ; j ++)
			ans += (mark[i][j] > 0);
	cout << ans;
    return(0);
}
