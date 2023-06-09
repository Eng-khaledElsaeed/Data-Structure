#include<iostream>
using namespace std;
class queue {
private:
	int* arr;
	int size;
	int rear;
	int front;
public:
	//Constructor
	queue(int size) {
		this->size = size;
		rear = -1;
		front = -1;
		arr = new int[size];
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
		// return (rear == -1 && front == -1) ? true : false;
	}
	bool isFull() {
		if (rear == size - 1) {
			return true;
		}
		else {
			return false;
		}
	}
	void Enqueue(int value) {
		if (isFull()) {
			cout << "queue oversize" << endl;
			return;
		}
		else if(isEmpty()) {
			rear = 0;
			front = 0;
			arr[rear] = value;
		}
		else {
			rear++;
			arr[rear] = value;
		}
	}
	int Dequeue() {
		if (isEmpty()) {
			cout << "queue under size" << endl;
			return 0;
		}
		else if (rear != front) {
			cout << "element : " << arr[front] << endl;
			int value = arr[front];
			arr[front] = 0;
			front++;
			return value;
		}
		else {
			cout << "element : " << arr[front] << endl;
			int value = arr[front];
			arr[front] = 0;
			rear = -1;
			front = -1;
			return value;
		}
	}

	int count() {
		return (rear - front) + 1;
	}
	void display() {
		if (isEmpty()) {
			return;
		}
		else {
			for (int i = 0; i <= rear; i++) {
				if (i >= front) {
					cout << "queue element " << i << " :" << arr[i]<<endl;
				}
			}
		}
	}



	// Destructor
	~queue() {
		delete[] arr;
	}

};
int main() {
	queue q1(5);
	q1.Enqueue(5);
	q1.Enqueue(68);
	q1.Enqueue(29);
	q1.Enqueue(94);
	q1.display();
	q1.Dequeue();
	q1.display();
	cout<<q1.count();

	return 0;
}