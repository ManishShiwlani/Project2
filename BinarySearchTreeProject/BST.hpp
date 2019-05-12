#ifndef __BST_HPP__
#define __BST_HPP__
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

template<class T>
class BST {
	struct node {
		T data;
		node *left;
		node *right;
	};

private:
	node *root;

public:
	BST() {
		root = NULL;
	}

	bool isEmpty() {
		return root == NULL;
	}

	void print() {
		cout << endl;
		root->data.printHeaders();
		inorder(root);
		cout << endl;
	}

	void inorder(node *p) {
		if (p != NULL) {
			if (p->left) inorder(p->left);
			p->data.print();
			if (p->right) inorder(p->right);
		}
		else return;
	};

	void write(ofstream &file) {
		preorder(root, file);
	}

	void preorder(node *p, ofstream &file) {
		if (p != NULL) {
			p->data.printRaw(file);
			if (p->left) preorder(p->left, file);
			if (p->right) preorder(p->right, file);
		}
		else {
			return;
		}
	}

	void insert(T d) {
		node *t = new node;
		node *parent;
		t->data = d;
		t->left = NULL;
		t->right = NULL;
		parent = NULL;

		if (isEmpty()) {
			root = t;
		}
		else {
			node *curr = root;

			while (curr) {
				parent = curr;
				if (t->data > curr->data) curr = curr->right;
				else curr = curr->left;
			}

			if (t->data < parent->data) {
				parent->left = t;
			}
			else {
				parent->right = t;
			}
		}
	};

	static node *successor(node *node) {
		struct node *current = node;

		while (current->left != NULL) {
			current = current->left;
		}

		return current;
	}

	static node *remove(node *base, T data) {

		if (base == NULL) return base;

		if (data < base->data) base->left = remove(base->left, data);

		else if (data > base->data) base->right = remove(base->right, data);

	
		else {

			// Node with only one child or no child
			if (base->left == NULL) {
				struct node *temp = base->right;
				free(base);
				return temp;
			}
			else if (base->right == NULL) {
				struct node *temp = base->left;
				free(base);
				return temp;
			}

			// Node with two children
			node *temp = successor(base->right);
			base->data = temp->data;
			base->right = remove(base->right, temp->data);
		}

		return base;
	};

	void removeItem(T d) {
		remove(root, d);
	};

	void search(T d) {
		bool found = false;
		cout << endl;
		if (isEmpty()) {
			cout << " This Tree is empty! " << endl;
		}
		node *curr;
		node *parent;
		curr = root;
		parent = (node *)NULL;
		while (curr != NULL) {
			if (curr->data == d) {
				found = true;
				curr->data.printHeaders();
				curr->data.print();
				break;
			}
			else {
				parent = curr;
				if (d > curr->data) curr = curr->right;
				else curr = curr->left;
			}
		}
		if (!found) {
			cout << " Data not found! " << endl;
		}

		cout << endl;
	}
};

#endif
