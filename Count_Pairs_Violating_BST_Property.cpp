/* BST Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  

      long long mergeCount(vector<int>& arr, vector<int>& temp,
                           int left, int mid, int right) {

          int i = left;
          int j = mid + 1;
          int k = left;

          long long count = 0;

          while (i <= mid && j <= right) {

              if (arr[i] <= arr[j]) {
                  temp[k++] = arr[i++];
              }
              else {
                  count += (mid - i + 1);
                  temp[k++] = arr[j++];
              }
          }

          while (i <= mid) {
              temp[k++] = arr[i++];
          }

          while (j <= right) {
              temp[k++] = arr[j++];
          }

          for (int p = left; p <= right; p++) {
              arr[p] = temp[p];
          }

          return count;
      }


      long long mergeSort(vector<int>& arr, vector<int>& temp,
                          int left, int right) {

          if (left >= right)
              return 0;

          int mid = left + (right - left) / 2;

          long long count = 0;

          count += mergeSort(arr, temp, left, mid);
          count += mergeSort(arr, temp, mid + 1, right);

          count += mergeCount(arr, temp, left, mid, right);

          return count;
      }


      void inorder(Node* root, vector<int>& arr) {

          if (root == nullptr)
              return;

          inorder(root->left, arr);

          arr.push_back(root->data);

          inorder(root->right, arr);
      }


      int pairsViolatingBST(Node* root) {

          vector<int> arr;

          inorder(root, arr);

          int n = arr.size();

          if (n <= 1)
              return 0;

          vector<int> temp(n);

          return (int)mergeSort(arr, temp, 0, n - 1);
     
        
    }
};