#include<iostream>
using namespace std;
class node {
private:

public:
	int data;
	int key;
	node* next;
	node() {
		data = 0;
		key = 0;
		next = NULL;
	}
	node(int key, int data) {
		this->data = data;
		this->key = key;
	}
};


class circuleLinkedList {
private:
	node* head;
public:
	circuleLinkedList() {
		this->head = NULL;
	}
	circuleLinkedList(node* n) {
		this->head = n;
	}

	node* isExist(int key) {
		node* ptr = head;
		node* temp = NULL;
		while (ptr != head) {
			if (ptr->key == key) {
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	}

	void appendNode(node* n) {
		if (isExist(n->key) != NULL) {
			cout << "this element aready exist\n";
		}
		else {
			if (head == NULL) {
				head = n;
				n->next = head;
			}
			else {
				node* ptr = head;
				while (ptr->next != head) {
					ptr = ptr->next;
				}
				ptr->next = n;
				n->next = head;
			}
		}
	}

	void preappend(node* n) {
		if (isExist(n->key) != NULL) {
			cout << "this element aready exist\n";
		}
		else {
			if (head == NULL) {
				head = n;
			}
			else {
				n->next = head;
				head = n;
			}
		}
	}

	void insertinto(int key, node* n) {
		if (head == NULL) {
			cout << "linked list aready empty\n";
		}
		else {
			if (isExist(key) != NULL) {
				node* targetNode = isExist(key);
				if (isExist(n->key) != NULL) {
					cout << "this element key aready exist" << endl;
				}
				else {
					if (targetNode->next == head) {
						n->next = head;
						targetNode->next = n;
					}
					else {
						n->next = targetNode->next;
						targetNode->next = n;
					}
					n->next = targetNode->next;
					targetNode->next = n;
				}
			}
			else {
				cout << "this key not exist\n";
			}
		}
	}

	void deleteNodeByKey(int k) {
		if (head == NULL) {
			cout << "your linked list aready are empty!\n";
		}
		else {
			if (isExist(k) != NULL) {
				node* deleteNode = isExist(k);
				if (deleteNode == head) {
					head = deleteNode->next;
				}
				else if (deleteNode->next == head) {
					node* temp = head;
					while (temp->next != deleteNode)
					{
						temp = temp->next;
					}
					temp->next = head;
				}
				else {
					node* prevptr = head;
					node* curptr = head->next;
					while (curptr != head) {
						if (curptr == deleteNode) {
							prevptr->next = curptr->next;
						}
						else {
							curptr = curptr->next;
							prevptr = prevptr->next;
						}
					}
				}
			}
			else {
				cout << "this node key not exist in linked list;\n";
			}
		}
	};



	void updateNodeByKey(int key, int data) {
		if (head == NULL) {
			cout << "your linked list are empty!" << endl;
		}
		else {
			if (isExist(key) != NULL) {
				node* updateNode = isExist(key);
				updateNode->data = data;
				cout << "node data updated successuflly\n";
			}
			else {
				cout << "this elemet by key " << key << "not exist" << endl;
			}
		}
	}

	void printLinkedList() {
		if (head == NULL) {
			cout << "linked list are empty" << endl;
		}
		else {
			node* ptr = head;
			while (ptr != head)
			{
				cout << "node key -> " << ptr->key << "node data -> " << ptr->data << endl;
				ptr = ptr->next;
			}
		}
	}
};

int main(){
	circuleLinkedList c;
	node* n1 = new node(0, 15);
	node* n2 = new node(1, 30);
	node* n3 = new node(2, 45);
	node* n4 = new node(3, 60);
	node* n5 = new node(4, 75);
	node* n6 = new node(5, 90);
	c.appendNode(n1);
	c.appendNode(n2);
	c.appendNode(n3);
	c.appendNode(n4);
	c.appendNode(n5);
	c.appendNode(n6);
	c.printLinkedList();

	return 0;
}