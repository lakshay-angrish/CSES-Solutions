#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> ti;

using namespace __gnu_pbds;
template <class T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define FOR(i, a, b) for (ll i = (a), _b = (b); i < _b; i++)
#define FORD(i, b, a) for (ll i = (b), _a = (a); i > _a; i--)
#define pb push_back

#define vout(v)               \
	do {                      \
		for (auto i : v)      \
			cout << i << ' '; \
		cout << '\n';         \
	} while (false)

#define matout(mat)               \
	do {                          \
		for (auto i : mat) {      \
			for (auto j : i)      \
				cout << j << ' '; \
			cout << '\n';         \
		}                         \
	} while (false)

#define vin(v)        \
	for (auto &i : v) \
	cin >> i

#define matin(mat)          \
	do {                    \
		for (auto &i : mat) \
			vin(i);         \
	} while (false)

ld PI = 3.141592653589793238;
ll M = 1e9 + 7;

ll gcd(ll a, ll b) {
	if (a > b)
		return gcd(b, a);
	if (a == 0)
		return b;

	return gcd(b % a, a);
}

ll power(ll x, ll y) {
	if (y == 0)
		return 1;

	ll p = power(x, y / 2) % M;
	p = (p * p) % M;

	return y % 2 ? (x * p) % M : p;
}

bool is_prime(ll n) {
	if (n == 2)
		return true;
	if (n < 2)
		return false;
	if (n % 2 == 0)
		return false;

	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0)
			return false;
	}

	return true;
}

bool is_palindrome(string s) {
	return equal(s.rbegin(), s.rend(), s.begin());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	ll t, n, m, k, q, x, y;
	string s;
	bool flag;
 
	cin >> n >> k;
	vpll v;
	FOR (i, 0, n) {
		cin >> x >> y;
		v.push_back({x, y});
	}

	sort(v.begin(), v.end(), [](const pll& p1, const pll& p2) {
		return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
	});
 
	multiset<ll> st;
	FOR (i, 0, k)	st.insert(0);

	m = 0;

	for (auto p: v) {
		auto it = st.upper_bound(p.first);
		if (it == st.begin())	continue;
		--it;

		st.erase(it);
		st.insert(p.second);
		m++;
	}

	cout << m << '\n';
 
	return 0;
}