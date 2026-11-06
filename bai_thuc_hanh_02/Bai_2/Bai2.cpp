#include <iostream>
using namespace std;
int main(){
	int hang, cot;
	cout << "Nhap so hang: ";
	cin >> hang;
	cout << "Nhap so cot: ";
	cin >> cot;
	float** arr = new float*[hang];
	for(int i = 0; i < hang; i++){
		arr[i] = new float[cot];
	}
	cout <<"Nhap cac phan tu mang 2 chieu:\n";
	for(int i = 0; i < hang; i++){
		for(int j = 0; j < cot; j++){
			cout <<"arr[" << i << "][" << j << "] = ";
			cin >> *(*(arr + i) + j);
		}
	}
	cout <<"Mang 2 chieu vua nhap:\n";
	for(int i = 0; i < hang; i++){
		for(int j = 0; j < cot; j++){
			cout << *(*(arr + i) + j) << " ";
		}
		cout << endl;
	}
	for(int i = 0; i < hang; i++){
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}
