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

multiset <ll> se1, se2, se;
multiset <ll> :: iterator it;

int main()
{
	ll n, i, j, k, x, y, a, b;
	scl(n);
	for (i = 0; i < n; ++i) {
		scl(x);
		se.insert(x);
	}

	a = 0;
	for (i = 31; i >= 0; --i) {
		for (it = se.begin(); it != se.end(); ++it) {
			if ((*it)&(1<<i)) {
				se1.insert(*it);
			}
		}
		if (se1.size() > 1) {
			a |= (1<<i);
			se.clear();
			for (it = se1.begin(); it != se1.end(); ++it) {
				se.insert(*it);
			}
		}
		se1.clear();
	}
	printf("%lld\n", a);

	return 0;
}
