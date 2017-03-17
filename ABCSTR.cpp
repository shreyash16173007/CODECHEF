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

map <pll, ll> mp;

char str[1000011];

int main()
{
	ll i, j, k, ans, a, b, c;
	pll tmp;
	scanf("%s", str);

	ans = 0ll;
	a = b = c = 0ll;
	mp[mkp(0,0)] = 1;
	for (i = 0; str[i]; ++i) {
		if (str[i] == 'A') a++;
		else if (str[i] == 'B') b++;
		else c++;
		tmp = mkp(a-b, a-c);
		ans += mp[tmp];
		mp[tmp]++;
	}

	printf("%lld\n", ans);

	return 0;
}
