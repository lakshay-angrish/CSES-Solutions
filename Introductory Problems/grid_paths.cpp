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

ll cnt = 0;

void countPaths(vvi& board, int x, int y, int n, string& s, int idx) {
	if (idx == s.size()) {
		cnt++;
		return;
	}

	if (board[6][0] == 1)	return;

    bool left 	= 	y > 0 		&& board[x][y - 1] == 0;
    bool right 	= 	y < n - 1 	&& board[x][y + 1] == 0;
    bool down 	= 	x < n - 1 	&& board[x + 1][y] == 0;
    bool up 	= 	x > 0 		&& board[x - 1][y] == 0;

    if (!up && !down && right && left) {
        return;
    }
	if (!right && !left && up && down) {
		return;
	}

	switch (s[idx]) {
		case 'R':
			if (!right)	return;
			board[x][y + 1] = 1;
			countPaths(board, x, y + 1, n, s, idx + 1);
			board[x][y + 1] = 0;
			return;

		case 'D':
			if (!down)	return;
			board[x + 1][y] = 1;
			countPaths(board, x + 1, y, n, s, idx + 1);
			board[x + 1][y] = 0;
			return;

		case 'L':
			if (!left)	return;
			board[x][y - 1] = 1;
			countPaths(board, x, y - 1, n, s, idx + 1);
			board[x][y - 1] = 0;
			return;

		case 'U':
			if (!up)	return;
			board[x - 1][y] = 1;
			countPaths(board, x - 1, y, n, s, idx + 1);
			board[x - 1][y] = 0;
			return;

		default:
			if (right) {
				board[x][y + 1] = 1;
				countPaths(board, x, y + 1, n, s, idx + 1);
				board[x][y + 1] = 0;
			}

			if (down) {
				board[x + 1][y] = 1;
				countPaths(board, x + 1, y, n, s, idx + 1);
				board[x + 1][y] = 0;
			}

			if (left) {
				board[x][y - 1] = 1;
				countPaths(board, x, y - 1, n, s, idx + 1);
				board[x][y - 1] = 0;
			}

			if (up) {
				board[x - 1][y] = 1;
				countPaths(board, x - 1, y, n, s, idx + 1);
				board[x - 1][y] = 0;
			}
			return;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, m, k, q, x, y;
    string s;
    bool flag;

	cin >> s;
	n = 7;

	vvi board(n, vi(n, 0));
	board[0][0] = 1;

	countPaths(board, 0, 0, n, s, 0);

	print(cnt);

    return 0;
}
