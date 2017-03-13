#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

ll arr[100001][32], val[100001][32];

int main()
{
	ll n, i, j, k, x, y, z, a, b, c;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> x;
		for (j = 0; j < 32; ++j) {
			val[i][j] = arr[i][j] = x&1;
			arr[i][j] += arr[i-1][j];
			x /= 2;
		}
		if (i == 0) continue;
	}
/*
	for (i = 1; i <= n; ++i) {
		for (j = 0; j < 3; ++j) {
			cout << arr[i][j] << " ";
		} cout << endl;
	}
*/
	ll ans = 0;
	for (i = 1; i <= n; ++i) {
		y = 1;
		for (j = 0; j < 32; ++j) {
			if (val[i][j] == 1) {
				ans += (arr[n][j] - arr[i][j]) * y;
			}
			y <<= 1;
		}
	}
	cout << ans << endl;

	return 0;
}
