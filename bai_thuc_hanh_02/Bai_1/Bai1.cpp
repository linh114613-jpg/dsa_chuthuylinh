#include <iostream>
using namespace std;
int main(){
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	float* arr = new float[n];
	cout << "Nhap cac phan tu cua mang:\n";
	for(int i = 0; i < n; i++){
		cout << "arr["<< i + 1 <<"] = ";
		cin >> arr[i];
	}
	cout << "Mang vua nhap: ";
	for(int i = 0; i < n; i++){
		cout << *(arr + i) << " ";
	}
	cout << endl;
	delete[] arr;
	return 0;
}
