#include<bits/stdc++.h>
using namespace std;

#define N 1000001

int n, L1, L2;
vector<int> a;
vector<long long> dp; 
deque <pair< long long, int> > dq;

void input() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> L1 >> L2;
    a.resize(n + 1);
    dp.resize(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> a[i]; 
	} 
} 

void pushPop(int i) {
	int l1 = i - L1;
	int l2 = i - L2;
	// => l2 -> l1
	if (l1 > 0) {
		// loai cac phan tu o duoi day ma be hon phan tu chuan bi push vao
		while(!dq.empty() && dp[l1] >= dq.back().first) {
			dq.pop_back();
		}
		dq.push_back(make_pair(dp[l1], l1)); 
	}
		
	if (l2 > 0){
		// loai cac phan tu o top ma out khoang can xet <=> index < l2 
		while(!dq.empty() && dq.front().second < l2){
			dq.pop_front();
		}
	}
}

long long calculate() {
	//while (!dq.empty()) dq.pop_back();
	for (int i = 1; i <= n; i++) {
		pushPop(i);
		dp[i] = 1ll*a[i];
		if(!dq.empty()){
			dp[i] += dq.front().first;
		}
	}
	long long ans = *max_element(dp.begin()+1, dp.end());
	return ans;
}

int main() {
	input();
	cout << calculate() << endl; 
}

