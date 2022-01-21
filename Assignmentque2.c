#include <climits>

// Returns subtree sum of given subtree.
int subtreeSum(TreeNode<int> *root, int &maxSum) {
	if (root == NULL) {
		// Subtree sum for an empty subtree will be 0.
		return 0;
	}

	// Get left subtree sum.
	int leftSum = subtreeSum(root->left, maxSum);

	// Get right subtree sum.
	int rightSum = subtreeSum(root->right, maxSum);

	// Get current node dataue.
	int currNode = root->data;

	// Subtree sum of given subtree.
	int curSum = leftSum + rightSum + currNode;

	// If current subtree sum is greater than the largest subtree sum, then update the maximum sum of the subtree.
	if (curSum > maxSum) {
		maxSum = curSum;
	}
	// Return the current subtree sum.
	return curSum;
}

int largestSubtreeSum(TreeNode<int> *root) {
	// Intialise a variable to store the largest subtree sum.
	int maxSum = INT_MIN;

	// Get the largest subtree sum.
	subtreeSum(root, maxSum);

	// Return the largest subtree sum.
	return maxSum;
}
