#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii; 
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
 
const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7; 
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x, exit(0)
#define ms(x, y) memset(x, y, sizeof x) 
 
int n, h[maxn];
bool mark[maxn]; 
 
bool chk(int x)
{
ms(mark, 0);
int life = x;
for (int i = 1; i <= n; i++)
{
if (life)
mark[i] = 1, life--;
if (x >= h[i])
life = max(life, x - h[i]), mark[i] = 1;
}
life = x;
for (int i = n; i >= 1; i--)
{
if (life)
mark[i] = 1, life--;
if (x >= h[i])
life = max(life, x - h[i]), mark[i]=1;
}
for (int i = 1; i <= n; i++)
if (!mark[i]) return 0;
return 1;
} 
 
int32_t main()
{
cin.tie(0)->sync_with_stdio(0);
cin >> n;
for (int i = 1; i <= n; i++)
cin >> h[i];
int l = 0, r = maxn;
while (r - l > 1)
{
int mid = (l + r) >> 1;
if (chk(mid))
r = mid;
else
l = mid;
}
cout << r;
return (0);
}