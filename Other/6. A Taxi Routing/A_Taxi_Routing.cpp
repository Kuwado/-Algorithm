#include <bits/stdc++.h> 
using namespace std;

int checkPhone = 1; 
int totalCall = 0;
// Map lưu trữ thông tin của các number -> pair chứa số lần gọi và thời gian gọi
map< string, pair<int, int> >Phones;

struct Call {
	string fNumber;
	string tNumber;
	string date;
	string fTime;
	string eTime;
}; 

// Kiểm tra số điện thoại hợp lệ (0-9)
bool checkValid(const string& number) {
	for (int i = 0; i < number.length(); i++) {
		if (!isdigit(number[i])) {
			return false;
		}
	}
	return true;
}

// Tính thời gian trong 1 cuộc gọi
int countTime(string fTime, string eTime) {
	int h = 10*(eTime[0] - fTime[0]) + eTime[1] - fTime[1];
	int m = 10*(eTime[3] - fTime[3]) + eTime[4] - fTime[4];
	int s = 10*(eTime[6] - fTime[6]) + eTime[7] - fTime[7];
	return h*3600 + m*60 + s;
} 

void input() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	string line;
	while(getline(cin, line)) {
		if (line == "#") {
			break;
		}
		else{
			stringstream ss(line);
			Call call;
			ss >> line >> call.fNumber >> call.tNumber >> call.date >> call.fTime >> call.eTime;
			if (!checkValid(call.fNumber) || !checkValid(call.tNumber)) checkPhone = 0; // Nếu có sdt không hợp lệ
			else {
				totalCall++;
				int time = countTime(call.fTime, call.eTime);
				// Nếu sdt chưa tồn tại trong map 
				if (Phones.find(call.fNumber) == Phones.end()){
					Phones.insert({call.fNumber, {1, time}}); 
				}
				// Nếu đã tồn tại
				else {
					Phones[call.fNumber].first++;
					Phones[call.fNumber].second += time;
				}
			}
		}
	}
}

void doQuery() {
	input();
	string line;
	string query;
	string number;
	while(getline(cin, line) && line != "#") {
		stringstream ss(line);
		ss >> query ;
		if (query == "?check_phone_number") cout << checkPhone <<endl;
		else if (query == "?number_total_calls") cout << totalCall <<endl;
		else {
			ss >> number;
			if (query == "?number_calls_from") cout << Phones[number].first << endl;
			else cout << Phones[number].second << endl;
		}
	}
}

int main() {
	doQuery();
} 

