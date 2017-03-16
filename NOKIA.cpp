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

ll rec(ll i, ll j)
{
	if (i+1 == j) {
		return 0;
	}
	ll n, m, x, y;
	n = j-i+1;
	x = i + n/2;
	y = n-1;
	return y + rec(i, x) + rec(x, j);
}

int main()
{
	ll t, n, m, mx, mn;
	scl(t);
	while (t--) {
		scl(n); scl(m);
		mn = rec(0, n+1);
		mx = n + (n * (n + 1)) / 2;
		if (m < mn) {
			cout << -1 << endl;
		} else if (m >= mn && m <= mx) {
			cout << 0 << endl;
		} else {
			cout << m-mx << endl;
		}
	}

	return 0;
}
