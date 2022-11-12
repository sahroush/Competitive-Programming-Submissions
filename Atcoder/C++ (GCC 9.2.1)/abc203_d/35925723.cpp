#include <algorithm>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <math.h>
#include <vector>
#include <stack>
#include <list>
#include <ios>
#include <set>
#define TxtIO         freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define fast_io       ios::sync_with_stdio(0);cin.tie(0)
#define all(x)        (x).begin() , (x).end()
#define FOR(i,x)        for(int (i)=0;(i)<(x);(i)++)
#define std           using namespace std;
#define ll            long long int
#define ld            long double
#define pb(x)         push_back(x)
#define start         int main()
#define done          return 0
#define S             second
#define F             first
std;
const int N = 8e2 + 10;
int n,k;
int arr[N][N];

struct tablesum{
	int ps[N][N];
	void clear(){//hamaro 0 kon
		memset(ps, 0, sizeof ps);
	}
	void add(int x, int y, int z){ //khune tu satre x va sootoone y ro += z kon
		ps[x][y] += z;
	}
	void calc(){//bia partial sum 2d hesab kon
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= n ; j ++){
				ps[i][j] += ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
			}
		}
	}
	int get(int x1, int y1, int x2, int y2){ //jame mostatili ke bala chapesh (x1, y1) va payin rastesh (x2, y2) e ro bede
		return ps[x2][y2] - ps[x2][y1] - ps[x1][y2] + ps[x1][y1];
	}
}table;

bool check(int x) {
	table.clear();
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			table.add(i, j, (arr[i][j] <= x ? -1 : 1));
	table.calc();
	for(int i = k ; i <= n ; i ++)
		for(int j = k ; j <= n ; j ++)
			if(table.get(i - k , j - k , i, j) <= 0)
				return true;
	return false;
}
start {
    cin>>n>>k;
    for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			cin >> arr[i][j];
    int l = -1 , r = 1e9+1;
    while(r - l > 1)  {
        int mid = (r+l)>>1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
    done;
}