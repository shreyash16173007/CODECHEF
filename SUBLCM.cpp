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

//vector <int> fac[1000001];
int fac[1000001][20];
int p[1000001], len[1000001];
int mark[1000001];

void sieve()
{
	int i, j;
	for (i = 2; i <= 1000000; ++i) {
		if (p[i] == 0) {
			for (j = i; j <= 1000000; j += i) {
				fac[j][len[j]++] = i;
				p[j] = 1;
			}
		}
	}
}

int main()
{
	sieve();
	
	int t, n, m, i, j, k, a, b, c, x, y, z;
	sci(t);
	while (t--) {
		sci(n);
		for (i = 0; i < n; ++i) {
			sci(p[i]);
		}

		x = 0;
		a = 0;
		memset(mark, 0, sizeof(mark));
		for (i = 0; i < n; ++i) {
			//cout << i << " : " ;
			for (j = 0; j < len[p[i]];) {
				if (mark[fac[p[i]][j]] == 0) {
					mark[fac[p[i]][j]] = 1;
					//cout << fac[p[i]][j] << " ";
					++j;
				} else {
					while (mark[fac[p[i]][j]]) {
						for (k = 0; k < len[p[a]]; ++k) {
							mark[fac[p[a]][k]] = 0;
						}	
						a++;
					}
				}
			}
			//cout << a << endl;
			if (i-a+1 > x) {
				x = i-a+1;
			}
		}

		if (x < 2) printf("-1\n");
		else printf("%d\n", x);
	}

	return 0;
}
