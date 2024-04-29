#include <bits/stdc++.h> 
using namespace std;
#define N 1000001
int n;
int a[N];
int dp[N];

void input() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

void calculate() {
	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		if (dp[i-1] < 0) {
			dp[i] = a[i];
		}
		else {
			dp[i] = dp[i-1] + a[i];
		}
	}
}

int main() {
	input();
	calculate();
	sort(dp+1, dp+n+1);
	cout << dp[n] << endl;
} 

