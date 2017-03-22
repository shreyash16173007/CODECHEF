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

ll cost1[100001], cost2[100001], ans[200001];

int main()
{
	ll n, m, p, q, i, j, k, a, b, c, x, y, z;
	scl(n);
	a = b = m = 0;
	for (i = 0; i < n; ++i) {
		scl(x); scl(y);
		if (x == 1) {
			cost1[++a] = y;
		} else {
			cost2[++b] = y;
		}
		m += x;
	}
	sort(cost1+1, cost1+a+1, greater<ll>());
	sort(cost2+1, cost2+b+1, greater<ll>());
	//for (i = 1; i <= a; ++i) cost1[i] += cost1[i-1];
	//for (i = 1; i <= b; ++i) cost2[i] += cost2[i-1];

	p = q = 0;
	for (i = 2; i <= m; i += 2) {
		x = y = 0;
		if (p+2 <= a) {
			z = 1;
			x = cost1[p+1] + cost1[p+2];
		} else if (p+1 <= a) {
			z = 2;
			x = cost1[p+1];
		}
		if (q+1 <= b) {
			y = cost2[q+1];
		}
		if (x > y) {
			ans[i] = ans[i-2] + x;
			if (z == 1) p += 2;
			else p += 1;
		} else {
			ans[i] = ans[i-2] + y;
			q += 1;
		}
	} 
	p = q = 0;
	if (a > 0) {
		ans[1] = cost1[1];
		p = 1;
	}
	for (i = 3; i <= m; i += 2) {
		x = y = 0;
		if (p+2 <= a) {
			z = 1;
			x = cost1[p+1] + cost1[p+2];
		} else if (p+1 <= a) {
			z = 2;
			x = cost1[p+1];
		}
		if (q+1 <= b) {
			y = cost2[q+1];
		}
		if (x > y) {
			ans[i] = ans[i-2] + x;
			if (z == 1) p += 2;
			else p += 1;
		} else {
			ans[i] = ans[i-2] + y;
			q += 1;
		}
	}
	for (i = 1; i <= m; ++i) {
		printf("%lld ", ans[i]);
	}
	cout << endl;

	return 0;
}
