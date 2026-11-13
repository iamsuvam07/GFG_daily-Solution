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
    vector<int> findCommon(Node* r1, Node* r2) {

vector<int> ans;

stack<Node*> s1, s2;

while (r1 || r2 || !s1.empty() || !s2.empty()) {
    while (r1) {
        s1.push(r1);
        r1 =r1->left;
    }
    
    while(r2) {
        s2.push(r2);
        r2 = r2->left;
        
    }
    
    if (s1.empty() || s2.empty())
    break;
    
    Node* top1 = s1.top();
    Node* top2 = s2.top();
    
    if (top1->data == top2->data) {
        ans.push_back(top1->data);
        
        
        r1 = top1->right;
        r2 =top2->right;
        
        s1.pop();
        s2.pop();
        
        
    }
    
    else if (top1->data < top2->data) {
        s1.pop();
        r1 = top1->right;
    }
    else {
        s2.pop();
        r2 = top2->right;
    }
}


return ans;
    }
};