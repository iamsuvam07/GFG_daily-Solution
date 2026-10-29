class Solution {
  public:
    int minComputation(vector<int> &files) {
       
       
       
       
               priority_queue<int, vector<int>, greater<int>> pq;

               for (int file : files) {
                   pq.push(file);
               }

               int totalCost = 0;

               while (pq.size() > 1) {
                   int x = pq.top();
                   pq.pop();

                   int y = pq.top();
                   pq.pop();

                   int merged = x + y;

                   totalCost += merged;

                   pq.push(merged);
               }

               return totalCost;
         
        
    }
};