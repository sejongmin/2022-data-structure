#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* makeNode(int size, TreeNode* lChild, TreeNode* rChild) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = size;
	node->left = lChild;
	node->right = rChild;

	return node;
}

void print(TreeNode* root) {
	printf("%d ", root->data);
	if (root->left != NULL)
		printf("%d ", root->left->data);
	if (root->right != NULL)
		printf("%d", root->right->data);
}

int main() {
	TreeNode* F4 = makeNode(70, NULL, NULL);
	TreeNode* F5 = makeNode(90, NULL, NULL);
	TreeNode* F7 = makeNode(130, NULL, NULL);
	TreeNode* F8 = makeNode(80, NULL, NULL);
	TreeNode* F6 = makeNode(120, F7, F8);
	TreeNode* F2 = makeNode(30, F4, F5);
	TreeNode* F3 = makeNode(50, NULL, F6);
	TreeNode* F1 = makeNode(20, F2, F3);


	int N;
	scanf("%d", &N);

	switch (N) {
	case 1:
		print(F1);
		break;
	case 2:
		print(F2);
		break;
	case 3:
		print(F3);
		break;
	case 4:
		print(F4);
		break;
	case 5:
		print(F5);
		break;
	case 6:
		print(F6);
		break;
	case 7:
		print(F7);
		break;
	case 8:
		print(F8);
		break;
	default:
		printf("-1");
		break;
	}

	return 0;
}