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

pii arr[100001], brr[100001];
map <int, int> mp;

int BIT[100001];

void insert(int x, int val)
{
	for (; x <= 100000; x += (x&-x)) {
		BIT[x] += val;
	}	
}

int query(int x)
{
	int sum = 0;
	for (; x > 0; x -= (x&-x)) {
		sum += BIT[x];
	}
	return sum;
}

int main()
{
	int n, i, j, k, x, y, z;
	ll ans = 0;

	sci(n);
	for (i = 0; i < n; ++i) {
		sci(arr[i].first);
		sci(arr[i].second);
		brr[i] = mkp(arr[i].second, arr[i].first);
	}

	sort(brr, brr+n);
	for (i = 1; i <= n; ++i) {
		mp[brr[i-1].first] = i;
	}

	sort(arr, arr+n);
	for (i = 0; i < n; ++i) {
		x = mp[arr[i].second];
		ans += (query(n) - query(x));
		insert(x, 1);
	}

	cout << ans << endl;

	return 0;
}
