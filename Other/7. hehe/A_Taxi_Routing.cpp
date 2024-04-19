#include <bits/stdc++.h> 
using namespace std;
#define N 100
#define getbit(a, n) ((a>>n)&1) 
#define onbit(a, n) {a = a | (1<<n);}
#define offbit(a, n) {a = a & (~(1<<n));}
int n;
int c[N][N];
int ans;
int res = INT_MAX;
int bit = 0;

void input() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < 2*n+1; i++) {
		for (int j = 0; j < 2*n+1; j++) {
			cin >> c[i][j];
		}
	}
}

void findWay(int k) {
	if (bit == (1<<(n+1))- 1) {
		ans += c[k][0];
		res = min(ans, res);
		ans -= c[k][0]; 
		return; 
	}
	for (int i = 1; i <= n; i++) {
		if (!getbit(bit, i)) {
			onbit(bit, i);
			ans += c[k][i] + c[i][i+n];
			if (ans < res) findWay(i+n);
			ans -= (c[k][i] + c[i][i+n]);
			offbit(bit, i);
		}
	}
}

int main() {
	input();
	onbit(bit, 0);
	findWay(0);
	cout << res << endl;
} 

