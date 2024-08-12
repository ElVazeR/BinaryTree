#include <iostream>
#include <set> // Библиотека, хранящая в себе реализацию бинарного дерева (класс set)
#include <exception>
template <typename ANY>
class BinaryTree {

private:
	struct Node {
		ANY value = ANY();
		Node* left = nullptr;
		Node* right = nullptr;
	};
	Node* root;

	void insert(ANY value, Node* node) {
		if (value < node->value) {
			if (node->left == nullptr) {
				node->left = new Node;
				node->left->value = value;
			}
			else {
				insert(value, node->left);
			}
			return;
		}
		if (value > node->value) {
			if (node->right == nullptr) {
				node->right = new Node;
				node->right->value = value;
			}
			else {
				insert(value, node->right);
			}
			return;
		}
		//	throw std::exception("element already exists"); 
	}

	void delete_node(Node* node) {

		if (node != nullptr) {
			delete_node(node->left);
			delete_node(node->right);
			delete node;
		}
	}

	void print(Node* node) {
		if (node != nullptr) {
			print(node->left);
			std::cout << node->value << ' ';
			print(node->right);
		}
	}
public:
	BinaryTree() : root(nullptr) {};
	~BinaryTree() {
		delete_node(root);
	};

	void insert(ANY value) {
		if (root == nullptr) {
			root = new Node;
			root->value = value;
			return;
		}
		insert(value, root);

	}
	void print() {
		print(root);
		std::cout << std::endl;
	}
};








int main() {
	setlocale(0, "Russian");

	// Класс set
	/*
	std::set<int> set1;
	set1.insert(30);
	set1.insert(50);
	set1.insert(20);
	set1.insert(40);
	set1.erase(40);
	set1.insert(50); // не добавляется, т.к. уже есть данный узел уже есть.
	std::cout<< "size: " << set1.size() << std::endl;

	//std::set<int>::iterator it = set1.begin();

	//for (auto el : set1) // цикл forEach позволяет получить только от начала до конца. Не можем менять элементы коллекции.
	//for (std::set<int>::const_iterator it = set1.cbegin(); it != set1.cend(); ++it)

	for (auto el : set1)
		std::cout << el << ' ';
	std::cout << std::endl;
	*/


	BinaryTree<int> bt;
	bt.insert(70);
	bt.insert(40);
	bt.insert(100);
	bt.insert(30);
	bt.insert(50);
	bt.insert(90);
	bt.insert(35);

	bt.print();

	return 0;
}