class Node {
public :
	int data; 
	Node* left, * right;
	
	Node() {
		data = 0 ; 
		left = right = NULL; 
	}

};

class BST {

public :
	Node *root; 
	BST() {
		root = NULL; 
	}

	Node* insert(Node* parent, int value) {
		if (parent == NULL) {
			Node* newNode = new Node();
			newNode->data = value; 
			parent = newNode; 
		}
		else if (parent->data > value) {
			parent->left = insert(parent->left, value);
		}
		else {
			parent->right =  insert(parent->right, value);
		}
		return parent;
	}

	void insert(int value) {
		root = insert(root , value);
	}

	void preorder(Node* parent) {
		if (parent == NULL)return; 

		cout << parent->data << " ";

		preorder(parent->left);
		preorder(parent->right);	
	}

	void inorder(Node* parent) {
		if (parent == NULL)return;

		

		inorder(parent->left);
		cout << parent->data << " ";
		inorder(parent->right);
	}
	void postorder(Node* parent) {
		if (parent == NULL)return;



		postorder(parent->left);
		postorder(parent->right);
		cout << parent->data << " ";

	}

	Node* findMin(Node* parent) {
		if (parent == NULL)
			return NULL;
		else if (parent->left == NULL)
			return parent;
		else
			return findMin(parent->left);
	}
	Node* findMax(Node* parent) {
		if (parent == NULL)
			return NULL;
		else if (parent->right == NULL)
			return parent;
		else
			return findMin(parent->right);
	}
};