#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<int, int> > vp;
typedef pair<int, int> pr;
typedef tuple<int, int, int> ti;

#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i > _a; i--)
#define pb push_back

#define vout(v) do {					\
	for (auto i: v)	cout << i << ' ';	\
	cout << '\n';						\
} while (false)

#define matout(mat) do {					\
	for (auto i: mat) {						\
		for (auto j: i)	cout << j << ' ';	\
		cout << '\n';						\
	}										\
} while (false)

#define vin(v)  for (auto &i: v)    cin >> i

#define matin(mat) do {			\
	for (auto &i: mat)	vin(i);	\
} while (false)

ld pi = 3.141592653589793238;
ll M = 1e9 + 7;

ll gcd(ll a, ll b) {
    if (a == 0) return b;

    return gcd(b % a, a);
}

bool is_prime(ll n) {
    if (n == 2) return true;
    if (n < 2) return false;
    if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

bool is_palindrome(string s) {
    return equal(s.rbegin(), s.rend(), s.begin());
}

ll factor(ll n) {
	if (n % 2 == 0)	return 2;
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0)	return i;
	}
	return n;
}

int floor_index(vi& v, int l, int r, int k) {
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		if (v[m] <= k)	l = m;
		else			r = m;
	}
	return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, m, k, q, x, y;
    string s;
    bool flag;

	cin >> n >> m;
	vi a(n), b(m);

	vin(a);
	vin(b);

	multiset<int> set;
	for (auto i: a)	set.insert(i);

	FOR (i, 0, m) {
		auto it = set.lower_bound(b[i] + 1);

		if (it == set.begin())	cout << "-1\n";
		else {
			--it;
			cout << *it << '\n';
			set.erase(it);
		}
	}

    return 0;
}
