#include<iostream>
using namespace std;


void LinearSearch(int num, int arr[],int size) {
	int temp = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num) {
			cout << "this element exist at position " << i << endl;
			temp = 0;
			break;
		}
	}
	if (temp == -1) {
		cout << "this element not exist at array\n";
	}
};

int main() {
	int arr[5] = { 50,48,23,97,45 };
	int num;
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Enter your search element : ";
	cin >> num;
	LinearSearch(num, arr,size);
	return 0;
}