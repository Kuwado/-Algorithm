#include <bits/stdc++.h> 
using namespace std;

const int MOD = 1e9 + 7;
int n, k1, k2;
int a[1001]; // 1 = đi làm, 0 = nghỉ
int ans = 0;
int workDay, workRemain;

void input() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> k1 >> k2;
}

// Kiểm tra hợp lệ
bool checkValid(int i, int j) {
	// Nếu là ngày đầu tiên thì nghỉ hay đi làm đều đúng
	if (i == 1) return true; 
	// Nếu không phải ngày đầu
	else { 
		// TH nghỉ làm
		if (j == 0) {
			// Nếu hôm qua đã nghỉ -> hôm nay phải đi làm
			if (a[i-1] == 0 ) return false; 
			else { 
				// Nếu hôm trước đi làm nhưng chưa đủ kpi tối thiểu
				if (workDay < k1 ) return false; 
			}
		}
		// TH đi làm
		else {
			// Nếu hôm qua đã đi làm và kpi đã đạt tối đa
			if (a[i-1] == 1){
				if (workDay >= k2) return false;
			}
			else  // Nếu bắt đầu work mới nhưng thời gian con lại không đủ kpi tối thiểu
				if (n-i+1 < k1) return false; 
		}
		return true;
	}
}

void TRY(int k) {
		// Xét trạng thái làm và nghỉ
		for (int i = 0; i <= 1; i++){
			if(checkValid(k, i)){
				int pre = workDay;
				a[k] = i;
				if (i == 1) workDay++;
				else workDay = 0;
				// Nếu đã xét hết lịch => +1
				if (k == n) ans++;
				else  
				TRY(k+1);
				workDay = pre;
			}
		}
}

int main() {
	input();
	TRY(1);
	cout << ans << endl;
} 

