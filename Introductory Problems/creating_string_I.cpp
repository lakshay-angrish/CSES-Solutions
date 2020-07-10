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
#define print(v) cout << v << '\n'
 
#define pr_vec(v) do {					\
	for (auto i: v)	cout << i << ' ';	\
	cout << '\n';						\
} while (false)
 
#define pr_mat(mat) do {					\
	for (auto i: mat) {						\
		for (auto j: i)	cout << j << ' ';	\
		cout << '\n';						\
	}										\
} while (false)
 
#define vin(v)  for (auto &i: v)    cin >> i
 
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
 
vector<string> res;
 
void recur(unordered_map<char, int>& cnt, string& s, int size) {
	if (s.size() == size) {
		res.push_back(s);
		return;
	}
	for (auto i: cnt) {
		if (i.second > 0) {
			s.push_back(i.first);
			cnt[i.first]--;
			recur(cnt, s, size);
			s.pop_back();
			cnt[i.first]++;
		}
	}
}
 
void permute(string& s) {
	unordered_map<char, int> cnt;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i]]++;
	}
 
	string str("");
	recur(cnt, str, s.size());
 
	print(res.size());
	sort(res.begin(), res.end());
 
	for (auto i: res)	print(i);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t, n, m, k, q, x, y;
    string s;
    bool flag;
 
	cin >> s;
	permute(s);
 
    return 0;
}
