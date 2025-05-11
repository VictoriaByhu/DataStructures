#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct Node
{
	int code;
	string name;
	double price;
	Node* left;
	Node* right;

	Node(int c, const string n, double p)
		: code(c), name(n), price(p), left(nullptr), right(nullptr) {
	}
};

Node* insert(Node* root, int code, string name, double price)
{
	if (root == nullptr) return new Node (code, name, price);

	if (code < root->code)
		root->left = insert(root->left, code, name, price);
	else if (code > root->code)
		root->right = insert(root->right, code, name, price);

	return root;
}

void calculateSumAndCount(Node* root, double& sum, int& count) {
	if (!root) return;

	calculateSumAndCount(root->left, sum, count);

	sum += root->price;
	count++;

	calculateSumAndCount(root->right, sum, count);
}

void inorder(Node* root) {
	if (root != 0) {
		inorder(root->left);
		cout << root->code << " " << root->name << " " << root->price << endl;
		inorder(root->right);
	}
}
void countNodesPerLevel(Node* root) {
	if (!root) return;

	queue<Node*> q;
	q.push(root);

	int level = 0;

	while (!q.empty()) {
		int levelSize = q.size(); // к≥льк≥сть вузл≥в на поточному р≥вн≥
		cout << "Level " << level << ": " << levelSize << " node(-s)\n";

		for (int i = 0; i < levelSize; ++i) {
			Node* current = q.front();
			q.pop();

			if (current->left) q.push(current->left);
			if (current->right) q.push(current->right);
		}

		level++;
	}
}

void deleteSubtree(Node*& root) {
	if (!root) return;
	deleteSubtree(root->left);
	deleteSubtree(root->right);
	delete root;
	root = nullptr;
}

void deleteByCode(Node*& root, int code) {
	if (!root) return;
	if (code < root->code)
		deleteByCode(root->left, code);
	else if (code > root->code)
		deleteByCode(root->right, code);
	else 
		deleteSubtree(root); // «найдено Ч видал€Їмо п≥ддерево
		
}

void freeTree(Node*& root) {
	deleteSubtree(root);
}


int main()
{
	Node* root = nullptr;
	string line;

	ifstream file("C:\\Users\\User\\Desktop\\uni\\data structures and algorithms\\lab_work_9\\task\\data.txt");
	if (!file) 
	{
		cout << "Error\n";
		return 1;
	}

	while (getline(file, line))
	{
		istringstream iss(line);
		int code;
		string name;
		double price;
		iss >> code >> name >> price;

		root = insert(root, code, name, price);
	}

	file.close();

	double totalSum = 0;
	int count = 0;
	calculateSumAndCount(root, totalSum, count);

	double averagePrice = totalSum / count;
	cout << "Average price: " << averagePrice << endl;
	
	inorder(root);
	cout << endl; 

	countNodesPerLevel(root);
	cout << endl;

	int searchCode;
	cout << "\nEnter code to delete: ";
	cin >> searchCode;
	deleteByCode(root, searchCode);

	inorder(root);
	cout << endl;

	freeTree(root);

	return 0;
}
