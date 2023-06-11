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
};



int main() {


	return 0;
}