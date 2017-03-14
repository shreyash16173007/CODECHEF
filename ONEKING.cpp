#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int>
	
set <int> se1, se2;
pii arr[100001];

int main()
{
	int t, n, i, j, a, b, x, y;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> arr[i].first >> arr[i].second;
		}
		sort(arr, arr+n);
		x = 0;
		for (i = 0; i < n; ++i) {
			if (se1.empty()) {
				se1.insert(arr[i].first);
				se2.insert(arr[i].second);
			} else {
				if (arr[i].first > *(se2.begin())) {
					x++;
					se1.clear();
					se2.clear();
				}
				se1.insert(arr[i].first);
				se2.insert(arr[i].second);
			}
		}
		if (!se1.empty()) {
			x++;
			se1.clear();
			se2.clear();
		}
		cout << x << endl;
	}	

	return 0;
}
