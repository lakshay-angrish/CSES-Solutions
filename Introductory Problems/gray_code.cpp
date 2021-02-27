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
typedef vector<pair<ll, ll> > vp;
typedef pair<ll, ll> pr;
typedef tuple<ll, ll, ll> ti;

#define FOR(i, a, b) for (ll i = (a), _b = (b); i < _b; i++)
#define FORD(i, b, a) for (ll i = (b), _a = (a); i > _a; i--)
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
	if (a > b)	return gcd(b, a);
    if (a == 0) return b;

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

int ceil_index(vi& v, int l, int r, int k) {
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		if (v[m] >= k)	r = m;
		else		l = m;
	}
	int ans = v[l] >= k ? l : r;

	if (ans < 0 || ans >= v.size())	return -1;
	return ans;
}

vs code(ll n) {
	if (n == 0)	return {};
	if (n == 1)	return {"0", "1"};
	if (n == 2)	return {"00", "01", "11", "10"};

	vs sub = code(n - 1);
	vs res;
	for (auto c: sub) {
		res.pb("0" + c);
	}
	for (auto it = sub.rbegin(); it != sub.rend(); it++) {
		res.pb("1" + *it);
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t, n, m, k, q, x, y;
	string s;
	bool flag;

	cin >> n;
	vs v = code(n);

	for (auto s: v)	cout << s << '\n';

    return 0;
}