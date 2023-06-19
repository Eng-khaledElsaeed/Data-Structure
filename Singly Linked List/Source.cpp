#include<iostream>
using namespace std;
class node {
private:
	
public:
	int data;
	node* next;
	int key;
	node() {
		this->data = 0;
		this->next = NULL;
		this->key = 0;
	}
	node(int key, int value) {
		this->key = key;
		this->data = value;
	}
};
class singleLinkedLst {
private:
	node* head;
public:
	singleLinkedLst() {
		this->head = NULL;
	}
	singleLinkedLst(node* new_node) {
		this->head = new_node;
	}
	node* isExist(int key) {
		node* ptr = head;
		node* temp = NULL;
		while (ptr != NULL)
		{
			if (ptr->key == key) {
				cout << "this node key aready exist" << endl;
				temp = ptr;
			}

			ptr = ptr->next;
		}
		return temp;
	};
	void append(node* n) {
		if (isExist(n->key) != NULL) {
			cout << "this element key aready exist by value" << isExist(n->key)->data << endl;
		}
		else {
			if (head == NULL) {
				head = n;
				cout << "node has been appended succssefuly" << endl;
			}
			else {
				node* ptr = head;
				while (ptr->next != NULL) {
					ptr = ptr->next;
				}
				ptr->next = n;
			}
		}
	}
	void prappend(node* n) {
		if (isExist(n->key) != NULL) {
			cout << "this element key aready exist by value" << isExist(n->key)->data << endl;
		}
		else {
			if (head == NULL) {
				head = n;
				cout << "node has been appended succssefuly" << endl;
			}
			else {
				n->next = head;
				head = n;
				cout << "node has been appended succssefuly" << endl;
			}
		}
	}
	void inserNodeAt_k(int k, node* n) {
		node* targetNode = isExist(k);
		if (targetNode != NULL) {
			if (targetNode->next == NULL) {
				targetNode->next = n;
			}
			else {
				n->next = targetNode->next;
				targetNode->next = n;
			}
		}
	}
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
			while (ptr!=NULL)
			{
				cout << "node key -> " << ptr->key << "node data -> " << ptr->data << endl;
				ptr = ptr->next;
			}
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