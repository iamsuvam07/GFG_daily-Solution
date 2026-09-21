/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        // code her
                if (root1 == NULL && root2 == NULL)
                    return true;

                if (root1 == NULL || root2 == NULL)
                    return false;

                queue<Node*> q1, q2;
                q1.push(root1);
                q2.push(root2);

                while (!q1.empty() && !q2.empty()) {

                    int n1 = q1.size();
                    int n2 = q2.size();

                    if (n1 != n2)
                        return false;

                    vector<int> v1, v2;

                    for (int i = 0; i < n1; i++) {
                        Node* temp = q1.front();
                        q1.pop();

                        v1.push_back(temp->data);

                        if (temp->left)
                            q1.push(temp->left);

                        if (temp->right)
                            q1.push(temp->right);
                    }

                    for (int i = 0; i < n2; i++) {
                        Node* temp = q2.front();
                        q2.pop();

                        v2.push_back(temp->data);

                        if (temp->left)
                            q2.push(temp->left);

                        if (temp->right)
                            q2.push(temp->right);
                    }

                    sort(v1.begin(), v1.end());
                    sort(v2.begin(), v2.end());

                    if (v1 != v2)
                        return false;
                }

                return q1.empty() && q2.empty();
        
    }
};
