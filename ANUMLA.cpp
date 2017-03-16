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

int a[20], b[1<<16], c[1<<16];

int main()
{
	int t, i, j, k, x, y, z, n, m, lim;
	sci(t);
	while (t--) {
		sci(n);
		lim = 1<<n;
		for (i = 0; i < lim; ++i) {
			sci(b[i]);
		}
		sort(b, b+lim);

		multiset <int> se;
		x = y = z = 0;
		for (i = 1; i < lim; ++i) {
			k = -1;
			if (!se.empty()) {
				k = *se.begin();
			}
			if (b[i] == k) {
				se.erase(se.begin());
			} else {	
				a[x++] = b[i];
				z = y;
				for (j = 0; j < z; ++j) {
					c[y] = c[j] + b[i];
					se.insert(c[y++]);
				}
				c[y++] = b[i];
			}
		}

		for (i = 0; i < x; ++i) {
			printf("%d ", a[i]);
		} printf("\n");
	}

	return 0;
}
