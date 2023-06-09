#include<iostream>
using namespace std;
class cqueue {
private:
	int* arr;
	int size;
	int rear;
	int front;
	int elem_count;
public:
	cqueue(int size) {
		this->size = size;
		elem_count = 0;
		arr = new int[size];
		rear = -1;
		front = -1;
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}
	bool isEmpty() {
		if (rear == -1 && front == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isFull() {
		if ((rear + 1) % size == front) {
			return true;
		}
		else {
			return false;
		}
	}
	void c_Enqueue(int val) {

		if (isFull()) {
			cout << "it,s oversize" << endl;
			return;
		}
		else if (isEmpty()) {
			rear = 0;
			front = 0;
			arr[rear] = val;
			elem_count++;
		}
		else {
			rear = (rear + 1) % size;
			arr[rear] = val;
			elem_count++;
		}
	}
	void c_Dequeue() {
		if (isEmpty()) {
			cout << "no element in queue" << endl;
		}
		else if (rear == front) {
			arr[front] = 0;
			rear = -1;
			front = -1;
			elem_count--;
		}
		else {
			arr[front] = 0;
			front = (front + 1) % size;
			elem_count--;
		}
	}
	int count() {
		return elem_count;
	}
	void display() {
		if (isEmpty()) {
			cout << "you don,t have any elements" << endl;
			return;
		}
		else {
			int count = 0;
			int i = front;
			while (count < elem_count) {
				cout << "element at index " << i << "with value " << arr[i] << endl;
				i = (i + 1) % size;
				count++;

			}
		}
	}
};
int main() {
	cqueue q1(5);
	q1.c_Enqueue(1);
	q1.c_Enqueue(2);
	q1.c_Enqueue(3);
	q1.c_Enqueue(4);
	q1.c_Enqueue(5);
	q1.c_Enqueue(5);
	q1.c_Enqueue(5);
	q1.c_Enqueue(5);
	q1.display();
	cout << "--------------------------------------------------------------------------\n" ;
	q1.c_Dequeue();
	q1.c_Dequeue();
	q1.c_Dequeue();
	q1.display();

		return 0;
}
