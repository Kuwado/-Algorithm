#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100001

int T, N, C;
int X[MAX_N];

// Hàm kiểm tra xem có nhiều hơn C phần tử con thỏa mãn dis >= mid hay không
bool check(int mid) {
    int currentX = X[1];
    int count = 1;
    for (int i = 2; i <= N; i++) {
        if (X[i] - currentX >= mid) {
            currentX = X[i];
            count++;
        }
    }
    return count >= C;
}

int binarySearch(int left, int right) {
    int ans = -1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> C;
        for (int i = 1; i <= N; i++) {
            cin >> X[i];
        }
        sort(X + 1, X + N + 1);
        int result = binarySearch(0, X[N] - X[1]);
        cout << result << endl;
    }
    return 0;
}

