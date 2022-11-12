#include <bits/stdc++.h> 

using namespace std;

const int maxn = 3010;

bool win[maxn];

#define pb push_back

int n, a[maxn];
vector < int > adj[maxn];

bool solve(int v, int p = 0){
  win[v] = 0;
  for(int u : adj[v])if(u ^ p)
    solve(u , v), win[v] |= !win[u] && (a[v] > a[u]);
  return win[v];
}

int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n;
 for(int i = 1 ; i <= n ; i ++)
   cin >> a[i];
 for(int i = 1 , u , v ; i < n ; i ++)
   cin >> u >> v , adj[u].pb(v) , adj[v].pb(u);
 int ans = 0;
 for(int i = 1 ; i <= n ; i ++)if(solve(i))
   cout << i << ' ';
 return 0;
}