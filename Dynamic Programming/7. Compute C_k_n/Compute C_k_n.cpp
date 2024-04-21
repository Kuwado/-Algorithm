#include <bits/stdc++.h> 
using namespace std;
#define K 1001 
#define m 1000000007
#define h 10000000000000
int k, n; 
unsigned long long dp[K];

void input() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> k >> n;
}

void calculate() {
	dp[1] = n;
	for (int i = 2; i <= k; i++) {
		 dp[i] = (dp[i-1] * (n-i+1) / i) % m;
		 cout << dp[i] << endl;
	}
}

int main() {
	input();
	calculate();
	cout << dp[k] % m << endl;
} 

