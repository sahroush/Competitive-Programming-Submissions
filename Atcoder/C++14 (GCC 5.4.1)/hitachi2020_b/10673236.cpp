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


vector<vector<int> > connect;
vector<int> visited;
int n;

void dfs(int start,int c){
	stack<int> st;
	st.push(start);
	while(!st.empty()){
		int k = st.top();
		visited[k] = c;
		st.pop();
		for(int i=0;i<connect[k].size();++i){
			int tmp = connect[k][i];
			if(visited[tmp]==-1){
				st.push(tmp);
			}
		}
	}
}

int main(){
    migmig
	int m,k;
	cin >> n >> m >> k;
	connect.resize(n);
	visited.resize(n);
	vector<int> friends(n,0);
	vector<int> block(n,0);
	vector<int> cs;
	for(int i=0;i<m;++i){
		int s,t;
		cin >> s >> t;
		connect[s-1].push_back(t-1);
		connect[t-1].push_back(s-1);
		friends[s-1]++;
		friends[t-1]++;
	}
	int c = 0;
	for(int i=0;i<n;++i)visited[i] = -1;
	for(int i=0;i<n;++i){
		if(visited[i] == -1){
			dfs(i,c);
			c++;
		}
	}
	cs.resize(c,0);
	for(int i=0;i<n;++i){
		cs[visited[i]]++;
	}
	for(int i=0;i<k;++i){
		int s,t;
		cin >> s >> t;
		if(visited[s-1]==visited[t-1]){
			block[s-1]++;
			block[t-1]++;
		}
	}
	for(int i=0;i<n;++i){
		cout << cs[visited[i]] - 1 - friends[i] - block[i];
		if(i!=n-1)cout << " ";
	}
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
