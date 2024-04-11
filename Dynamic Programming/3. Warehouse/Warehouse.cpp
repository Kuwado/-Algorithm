#include<bits/stdc++.h>
using namespace std;

#define N_MAX 1000
#define T_MAX 100

int N, T, D;
int a[N_MAX+1], t[N_MAX+1];
int dp[N_MAX+1][T_MAX+1];

void input() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> N >> T >> D;
	for ( int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for ( int i = 1; i <= N; i++) {
		cin >> t[i];
	}
} 

void calculate() {
	for( int i = 1; i <= N; i++) {
		for ( int k = 1; k <= T; k++) {
			if (k < t[i]){
				dp[i][k] = 0;
			}
			else {
				for ( int j = max(i-D, 0); j <= i-1; j++) {
					dp[i][k] = max(dp[j][k-t[i]] + a[i], dp[i][k]);
				}
			}
		}
	}
}

int main() {
	input();
	calculate();
	int ans = INT_MIN;
	for (int i = 1; i <= N; i++) {
	    ans = max(ans, dp[i][T]); 
	}
	cout << ans << endl; 
}

