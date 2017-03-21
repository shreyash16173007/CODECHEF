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

ll cost[11], wt[11];

int main()
{
	ll t, n, i, j, k, a, b, c, lim;
	scl(t);
	while (t--) {
		scl(n); scl(k);
		for (i = 0; i < n; ++i) {
			scl(cost[i]);
			scl(wt[i]);
		}
		c = 0;
		lim = 1<<n;
		for (i = 1; i < lim; ++i) {
			a = b = 0;
			for (j = 0; j < n; ++j) {
				if (i&(1<<j)) {
					a += cost[j];
					b += wt[j];
				}
			}
			if (a <= k) {
				c = max(c, b);
			}
		}
		printf("%lld\n", c);
	}

	return 0;
}
