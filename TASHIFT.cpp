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

string tmp, str;
int f[1000010];

void failure()
{
	int i, j, k, m;
	m = tmp.size();

	k = 0;
	f[1] = 0;
	for (i = 2; i <= m; ++i) {
		while (k != 0 && tmp[i-1] != tmp[k]) {
			k = f[k];
		}
		if (tmp[i-1] == tmp[k]) {
			k++;
		}
		f[i] = k;
	}
}

int match()
{
	int i, j, k, n, m;
	m = tmp.size();
	n = m+m;

	k = 0;
	m = 0;
	j = 0;
	for (i = 1; i <= n; ++i) {
		while (k != 0 && tmp[k] != str[i-1]) {
			k = f[k];
		}
		if (tmp[k] == str[i-1]) {
			k++;
		}
		if (k > m) {
			m = k;
			j = i-k;
		}
	}

	return j;
}

int main()
{
	int n;
	cin >> n >> tmp >> str;
	str += str;

	failure();	
	cout << match() << endl;

	return 0;
}
