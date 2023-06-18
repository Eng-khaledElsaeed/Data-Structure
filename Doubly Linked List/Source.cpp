#include<iostream>
using namespace std;
class node {
public:
	node* privious;
	node* next;
	int data;
	int key;
	node() {
		this->privious = NULL;
		this->next = NULL;
		this->data = 0;
		this->key = 0;
	}
	node(int data,int key) {
		this->privious = NULL;
		this->next = NULL;
		this->data = data;
		this->key = key;
	}
};
class Doubly_linkedlist {
private:
	node* head;
public:
	Doubly_linkedlist() {
		this->head = NULL;
	};
	Doubly_linkedlist(node* n) {
		this->head = n;
	};
	node* isExist(int k) {
		node* ptr = head;
		node* temp = NULL;
		while (ptr != NULL) {
			if (ptr->key == k) {
				//			cout << "this node actually exist in doublly linked list";
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	};
	void append(node* n) {
		if (isExist(n->key) != NULL) {
			cout << "this element key aready exist" << endl;
		}
		else {
			if (head == NULL) {
				head = n;
			}
			else {
				node* ptr = head;
				while (ptr != NULL) {
					ptr = ptr->next;
				}
				ptr->next = n;
				n->privious = ptr;
			}
		}
	};
	void preappend(node* n) {
		if (isExist(n->key) != NULL) {
			cout << "this element key aready exist" << endl;
		}
		else {
			if (head == NULL) {
				head = n;
			}
			else {
				n->next = head;
				head->privious = n;
				head = n;
			}
		}
	}
	void insertNode(node* n,int key) {
		if (isExist(n->key) != NULL) {
			cout << "this element key aready exist" << endl;
		}
		else {
			node* targetNode = isExist(key);
			if (targetNode->next == NULL) {
				targetNode->next = n;
				n->privious = targetNode;
			}
			else {
				n->privious = targetNode;
				n->next = targetNode->next;
				targetNode->next->privious = n;
				targetNode->next = n;
			}
		}
	}
	void deleteNodeByKey(int k) {
		if (head == NULL) {
			cout << "linkedlist aready empty" << endl;
		}
		else 
		if (isExist(k)!=NULL) {
			node* deleteNode = isExist(k);
			if (deleteNode->next == NULL) {

			}
		}
		else {
			cout << "this node key not exist\n";
		}
	}

};
int main() {



	return 0;
}


















/*

	void deleteNodeByKey(int k) {
		node* targetNode = isExist(k);
		if (head == NULL) {
			cout << "linkedlist aready empty" << endl;
		}
		else if (head != NULL) {
			if (head->key == k) {
				head = head->next;
				cout << "node unlinked to linkedlist \n";
			}
			else {
				node* temp = NULL;
				node* prevptr = head;
				node* currptr = head->next;
				while (currptr != NULL)
				{
					if (currptr->key == k) {
						temp = currptr;
						currptr = NULL;
					}
					else {
						prevptr = prevptr->next;
						currptr = currptr->next;
					}
				}
				if (temp != NULL) {
					prevptr->next = temp->next;
					cout << "node unlinked to linkedlist \n";
				}
				else {
					cout << "node with key value unfound \n";
				}
			}
		}
	}
	void updateNode(int key, int data) {
		node* targetNode = isExist(key);
		if (isExist(key) != NULL) {
			targetNode->data = data;
		}
		else {
			cout << "this elemet by key " << key << "not exist" << endl;
		}
	}
	void printing() {
		if (head == NULL) {
			cout << "single linked list are empty\n";
		}
		else {
			node* ptr = head;
			while (ptr->next != NULL)
			{
				cout << "node key -> " << ptr->key << "node data -> " << ptr->data << endl;
				ptr = ptr->next;
			}
			cout << "node key -> " << ptr->key << "node data -> " << ptr->data << endl;
		}
	}
};



int main() {
	singleLinkedLst s;
	node* n1 = new node(0, 15);
	node* n2 = new node(1, 30);
	node* n3 = new node(2, 45);
	node* n4 = new node(3, 60);
	node* n5 = new node(4, 75);
	node* n6 = new node(5, 90);
	s.append(n1);
	s.append(n2);
	s.append(n3);
	s.append(n4);
	s.append(n5);
	s.append(n6);
	s.printing();

	return 0;
}


*/