class Node {
public: 
	int data; 
	Node* next;
};

class LinkedList {

public: 
	Node* head; 

	LinkedList() {
		head = NULL;
	}

	bool isEmpty() {
		return head == NULL; 
	}


	void insertNode(int value) {
		Node* newnode = new Node ; 
		newnode->data = value;

		if (isEmpty()) {
			newnode->next = NULL;
			head = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
	}

	void diplayItems() {
		Node* temp = head; 

		while (temp != NULL) {
			cout << temp->data << " "; 
			temp = temp->next;
		}
	}
	bool findItem(int item) {
		bool flag = false; 

		Node* temp = head ; 

		while (temp != NULL)
		{
			if (temp->data == item)flag = true; 
			temp = temp->next;
		}

		return flag; 
	}

	void insertBefore(int pos, int value) {

		if (findItem(pos)) {
			Node* newNode = new Node;
			newNode->data = value;

			Node* temp = head;
			while (temp != NULL && temp->next->data != pos) {
				temp = temp->next;
			}

			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	
};