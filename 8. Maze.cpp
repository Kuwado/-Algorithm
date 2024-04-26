#include <bits/stdc++.h> 
using namespace std;
#define N 1000
int n, m, r, c; 
int a[N][N];
int dp[N][N];
int locRow[4] = {-1 , 0, 1, 0};
int locCol[4] = {0, 1, 0, -1};
int ans = 0;

queue< pair<int, int> > q;


void input() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> m >> r >> c;
	q.push({r, c});
	dp[r][c] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) dp[i][j] = -1;
			else dp[i][j] = 0;
		}
	}
	a[r][c] = 1; 
}

void calculate() {
	while (!q.empty()) {
		pair<int, int> currentLoc = q.front();
    	q.pop();
    	for (int i = 0; i < 4; i++) {
			int x = currentLoc.first + locRow[i];
			int y = currentLoc.second + locCol[i];
			if(a[x][y] == 0) {
				q.push({x, y});
				dp[x][y] = dp[currentLoc.first][currentLoc.second] + 1;
				a[x][y] = 1;
				if (x == 1 | y == 1 | x == n | y == m) {
					ans = dp[x][y] + 1;
					return;
				}
			}
		}
	}
	ans = -1; 
}

int main() {
	input();
	calculate();
	cout << ans << endl;
} 

