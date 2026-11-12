/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int minDiff(Node *root, int k) {

int ans = INT_MAX;

while(root != NULL) {
    ans = min(ans, abs(root->data - k));
    
    
    if (ans == 0)
    return 0;
    
    
    if (k < root->data)
    root = root->left;
    
    else
    root = root->right;
}

return ans;
    }
};
