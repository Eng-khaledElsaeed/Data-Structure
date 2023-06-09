#include<iostream>
using namespace std;
class stack
{
public:
	int* arr;
	int top;
	int size;
	//constructor
	stack(int size) {
		this->size = size;
		arr = new int[size];
		top = -1;
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	};
	bool isFull() {
		return(top == size - 1) ? true : false;
	}
	bool isEmpty() {
		return(top == -1)? true : false;
	}
	void push(int value) {
		if (isFull()) {
			cout << "stack overflow" << endl;
		}
		else {
			top++;
			arr[top] = value;
			cout << "successfully add " << value << "at index" << top<<endl;
		}
	}
	int pop() {
		if (isEmpty()) {
			cout << "stack underflow" << endl;
		}
		else {
			cout << "successfully delete " << arr[top] << "at index " << top << endl;
			arr[top] = 0;
			top--;
		}
	}
	bool isFound(int val) {
		for (int i = 0; i <= top; i++) {
			return(arr[i] == val) ? true : false;
		}
	}
	int count() {
		return(top + 1);
	}
	int value_at_position(int pos) {
		if (isEmpty()) {
			return 0;
		}
		else {
			if (pos > top) {
				cout << "out of index"<<endl;
			}
			else {
				cout << arr[pos];
			}
		}
	}
	~stack() {
		delete[] arr;
	}



private:

};
void main() {

}