#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int binarySearch(int num, int arr[], int size) {
    int left = 0;
    int right = size - 1;
    int index = -1;
    while (left <= right) {
        int mid = trunc(left + (right - left) / 2);
        if (arr[mid] == num) {
            index = mid;
            break;  // Added break statement to exit the loop when element is found
        }
        else if (arr[mid] < num) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return index;
}


int main() {
	int arr[5] = { 50,48,23,97,45 };
	int num;
	int size = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, size);
	cout << "Enter your search element : ";
	cin >> num;
	int output=binarySearch(num, arr, size);
	if (output > -1) {
		cout << "element found at index : " << output << endl;
	}
	else {
		cout << "element not found at array" << endl;
	}
	return 0;
}