/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
  public:
  
 
      int solve(Node* root, int &ans, int &leafCount) {
          if (root == NULL)
              return 0;

          if (root->left == NULL && root->right == NULL) {
              leafCount++;
              return root->data;
          }

          int left = solve(root->left, ans, leafCount);
          int right = solve(root->right, ans, leafCount);

          if (root->left != NULL && root->right != NULL) {
              ans = max(ans, left + right + root->data);

              return root->data + max(left, right);
          }

          if (root->left != NULL)
              return root->data + left;

          return root->data + right;
      }

      int maxPathSum(Node *root) {
          if (root == NULL)
              return -1;

          int ans = INT_MIN;
          int leafCount = 0;

          solve(root, ans, leafCount);

          if (leafCount < 2)
              return -1;
              
              
        return ans;
        
    }
};