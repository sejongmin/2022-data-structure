#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

typedef struct TreeNode {
	int data, id;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* makeNode(int data, TreeNode* left, TreeNode* right, int id) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = left;
	node->right = right;
	node->id = id;

	return node;
}

int preOrder(TreeNode* root) {
	int cnt = root->data;
	if (root->left != NULL)
		cnt += preOrder(root->left);
	if (root->right != NULL)
		cnt += preOrder(root->right);
	return cnt;
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

TreeNode* findID(TreeNode* root, int id) {
	if (root->id == id)
		return root;

	if (root->left != NULL)
		if (findID(root->left, id) != NULL)
			return findID(root->left, id);
	if (root->right != NULL)
		if (findID(root->right, id) != NULL)
			return findID(root->right, id);
	return NULL;
}

int main() {
	int id = 8;
	TreeNode* F8 = makeNode(80, NULL, NULL, id--);
	TreeNode* F7 = makeNode(130, NULL, NULL, id--);
	TreeNode* F6 = makeNode(120, F7, F8, id--);
	TreeNode* F5 = makeNode(90, NULL, NULL, id--);
	TreeNode* F4 = makeNode(70, NULL, NULL, id--);
	TreeNode* F3 = makeNode(50, NULL, F6, id--);
	TreeNode* F2 = makeNode(30, F4, F5, id--);
	TreeNode* F1 = makeNode(20, F2, F3, id--);

	TreeNode* root = F1;

	int order, N;
	scanf("%d", &N);
	root = findID(root, N);

	if (root != NULL)
		printf("%d", preOrder(root));
	else
		printf("-1");

	return 0;
}