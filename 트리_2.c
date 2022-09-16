#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

typedef struct TreeNode {
	int id, data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* makeNode(int id, int size, TreeNode* lChild, TreeNode* rChild) {

	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->id = id;
	node->data = size;
	node->left = lChild;
	node->right = rChild;

	return node;
}

void preOrder(TreeNode* root) {
	printf("%d ", root->data);
	if (root->left != NULL)
		preOrder(root->left);
	if (root->right != NULL)
		preOrder(root->right);
}

void inOrder(TreeNode* root) {
	if (root->left != NULL)
		inOrder(root->left);
	printf("%d ", root->data);
	if (root->right != NULL)
		inOrder(root->right);
}

void postOrder(TreeNode* root) {
	if (root->left != NULL)
		postOrder(root->left);
	if (root->right != NULL)
		postOrder(root->right);
	printf("%d ", root->data);
}

void print(TreeNode* root, int order) {
	if (order == 1) {
		preOrder(root);
	}
	else if (order == 2)
		inOrder(root);
	else
		postOrder(root);
}

TreeNode* findNodeId(TreeNode* root, int id) {

	if (root->id == id) {
		return root;
	}
	else {
		if (root->left != NULL)
			if (findNodeId(root->left, id) != NULL)
				return findNodeId(root->left, id);
		if (root->right != NULL)
			if (findNodeId(root->right, id) != NULL)
				return findNodeId(root->right, id);
		return NULL;
	}
}

int main() {
	TreeNode* F4 = makeNode(4, 70, NULL, NULL);
	TreeNode* F5 = makeNode(5, 90, NULL, NULL);
	TreeNode* F7 = makeNode(7, 130, NULL, NULL);
	TreeNode* F8 = makeNode(8, 80, NULL, NULL);
	TreeNode* F6 = makeNode(6, 120, F7, F8);
	TreeNode* F2 = makeNode(2, 30, F4, F5);
	TreeNode* F3 = makeNode(3, 50, NULL, F6);
	TreeNode* root = makeNode(1, 20, F2, F3);

	int order, id;
	scanf("%d %d", &order, &id);

	TreeNode* p = findNodeId(root, id);

	if (p == NULL)
		printf("-1");
	else {
		print(p, order);
	}

	return 0;
}