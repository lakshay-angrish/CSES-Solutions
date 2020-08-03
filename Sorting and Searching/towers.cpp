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

bool compare(pr p1, pr p2) {
	return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, m, k, q, x, y, z;
    string s;
    bool flag;

	multiset<int> st;

	cin >> n;
	vi v(n);
	vin(v);

	FOR (i, 0, n) {
		auto it = st.upper_bound(v[i]);
		if (it != st.end())	st.erase(it);
		st.insert(v[i]);
	}

	cout << st.size() << '\n';

    return 0;
}

