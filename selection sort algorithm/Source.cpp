#include<iostream>
using namespace std;

class sorting {
private:
	int* arr;
	int size;
public:
	sorting(int size, int* arr) {
		this->arr = arr;
		this->size = size;
	}

	void selectionSort() {
		for (int i = 0; i < size - 1; i++) {
			int min = i;

			for (int j = i + 1; j < size; j++) {
				if (arr[j] < arr[min]) {
					min = j;
				}
			}
			if (min != i) {
				int temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}
		}
	};

	void insertionSorted() {
		int i, j, key=0;
		for (i = 1; i < size; i++) {
			key = arr[i];
			j = i - 1;
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}

	void bubleSort() {
		for (int i = 0; i < size - 1; i++) {
			bool flag = false;
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					flag = true;
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
			if (flag == false) {
				break;
			}
		}
	}

	void displayArray() {
		cout << "Sorted Array: \n";
		for (int i = 0; i < size; i++) {
			cout <<"element index "<<i<<" ==> "<< arr[i] <<endl;
		}
		cout << endl;
	}

};

int main() {
	int arr1[7] = { 5,9,35,76,57,24,24 };
	int size = sizeof(arr1) / sizeof(arr1[0]);

	sorting s(size, arr1);
	s.bubleSort();
	s.displayArray();

	return 0;
}
