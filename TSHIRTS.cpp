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

ll dp[1<<11][101], mark[101][11];
ll lim, n;

ll toint(const string &s) 
{ 
	stringstream ss; 
	ss << s; 
	ll x; 
	ss >> x; 
	return x; 
}

ll rec(ll bit, ll id)
{	
	if (id == 101) {
		if (bit == lim) return 1ll;
		else return 0ll;
	}
	if (dp[bit][id] != -1) return dp[bit][id];
	ll ans = 0ll;
	ans = rec(bit, id+1);
	for (ll i = 0; i < 10; ++i) {
		if (mark[id][i] == 1 && !(bit&(1<<i)))
			ans += rec(bit|(1<<i), id+1);
		ans %= MOD;
	}
	return dp[bit][id] = ans;
}

int main()
{
	ll t, m, i, j, k;
	string ss, tmp;
	scl(t);
	while (t--) {
		memset(dp, -1, sizeof(dp));
		memset(mark, 0, sizeof(mark));
		scl(n);
		getchar();
		lim = (1<<n)-1;
		for(i = 0; i < n; ++i) {
            		getline(cin,ss);
            		stringstream s (ss);
            		while(s>>tmp) {
                		mark[toint(tmp)][i] = 1;
			}
        	}
		cout << rec(0, 1) << endl;
	}

	return 0;
}
