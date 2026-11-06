#include <iostream>
# include <string>
using namespace std;
struct SV{
	string ten;
	string ma;
	float d1, d2, d3;
};
int main(){
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	SV* ds = new SV[n];
	for(int i = 0; i < n; i++){
		cout << "Nhap thong tin sinh vien thu" << i + 1 << ":" << endl;
		cin.ignore();
		cout << "Ho ten: ";
		getline(cin, (ds + i) -> ten);
		cout << "Msv: ";
		getline(cin, (ds + i) -> ma);
		cout << "Diem 1: ";
		cin >> (ds + i) -> d1;
		cout << "Diem 2: ";
		cin >> (ds + i) -> d2;
		cout << "Diem 3: ";
		cin >> (ds + i) -> d3;
	}
	cout <<"\n Danh sach sinh vien:\n";
	for(int i = 0; i < n; i++){
		cout << "Sinh vien" << i + 1 << " - Ho ten: " << (ds + i) -> ten << " - Msv: " << (ds + i) -> ma << " - Diem 1: " << (ds + i) -> d1 << " - Diem 2: " << (ds + i) -> d2 << " - Diem 3: " << (ds + i) -> d3 << endl;
	}
	delete[] ds;
	return 0;
}
