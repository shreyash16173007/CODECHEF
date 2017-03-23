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

map <pii, int> arr, pri;

int main()
{
	int n, m, i, j, k, a, b, c, d, x, y, z;
	sci(n);
	sci(m);
	for (i = 0; i < n; ++i) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (pri.find(mkp(a, b)) == pri.end()) {
			arr[mkp(a, b)] = c;
			pri[mkp(a, b)] = d;
		}
		if (d >= pri[mkp(a, b)]) {
			pri[mkp(a, b)] = d;
			arr[mkp(a, b)] = c;
		}
	}

	while (m--) {
		sci(a); sci(b);
		printf("%d\n", arr[mkp(a, b)]);
	}

	return 0;
}
