#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<ll, ll>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)

ll mark[2001][50];

int main()
{
	int i, j, n, k, x, y, ans = 0;
	string str;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> str;
		for (j = 0; j < n; ++j) {
			if (str[j] == '1') {
				x = j / 50;
				y = j % 50;
				mark[i][x] |= (1LL<<y);
			}
		}
	}	

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (i == j) continue;
			x = j / 50;
			y = j % 50;
			if (mark[i][x] & (1LL<<y)) continue;	
			for (y = 0; y < 50; ++y) {
				if (mark[i][y] & mark[j][y]) {
					ans++;
					break;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
