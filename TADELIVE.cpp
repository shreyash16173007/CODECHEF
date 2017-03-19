#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)

int a[100001], b[100001];
pii c[100001];

int main()
{
	int p, q, n, x, y, i, j, ans = 0;
	sci(n);
	sci(x);
	sci(y);
	for (i = 0; i < n; ++i) sci(a[i]);
	for (i = 0; i < n; ++i) sci(b[i]);
	for (i = 0; i < n; ++i) c[i] = mkp(abs(a[i]-b[i]), i);
	sort(c, c+n);

	p = q = 0;
	ans = 0;	
	for (i = n-1; i >= 0; --i) {
		p = c[i].second;
		if (a[p] > b[p]) {
			if (x) {
				ans += a[p];
				x--;
			} else {
				ans += b[p];
				y--;
			}
		} else {
			if (y) {
				ans += b[p];
				y--;
			} else {
				ans += a[p];
				x--;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
