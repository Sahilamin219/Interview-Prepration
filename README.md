# Coding-Interview-Prepration
For Re-visting week topics

# Sorting in cpp
default sort function is quick sort
in arrays if you want to use it is like as follows 

      #include <iostream>
      #include <cstdlib>
      using namespace std;

      int compare(const void* a, const void* b)
      {
        const int* x = (int*) a;
        const int* y = (int*) b;

        if (*x > *y)
          return 1;
        else if (*x < *y)
          return -1;

        return 0;
      }

      int main()
      {
        const int num = 10;
        int arr[num] = {9,4,19,2,7,9,5,15,23,3};

        cout << "Before sorting" << endl;
        for (int i=0; i<num; i++)
          cout << arr[i] << " ";

        qsort(arr,num,sizeof(int),compare);
        cout << endl << endl;
        cout << "After sorting" << endl;

        for (int i=0; i<num; i++)
          cout << arr[i] << " ";

        return 0;
      }
## for stable sort 
Just use **stable_sort(v.begin(), v.end()) ;** It uses merge sort and if extra space is not available time complexity changes to n(log(n*n)) ;
## For using merge between two arrays 
Its does not sort the function ..it just merge two arrays, and using coustom sort1 function.. its keeps increaing index of one array until condition is satisfied otherwise another array's index is incremented .

    int solve(vector<int>& piles) {
        vector<int> a={-2, 3, -1, 13, -5, 6}, b(2*piles.size());
        merge(piles.begin(),piles.end(), a.begin(), a.end(), b.begin(), );
    }

    struct sort1 {
        bool operator()(const long& a, const long& b) const
        {
            return a < b;
        }
    };
    int solve(vector<int>& piles) {
        vector<int> a={-2, 3, -1, 13, -5, 6}, b(2*piles.size());
        merge(piles.begin(),piles.end(), a.begin(), a.end(), b.begin(), sort1());
    }

# OS 

fork() will create a new child process identical to the parent. So everything you run in the code after that will be run by both processes — very useful if you have for instance a server, and you want to handle multiple requests.

### constant space starting of LL loop
      Distance traveled by fast pointer = 2 * (Distance traveled 
                                               by slow pointer)

      (m + n*x + k) = 2*(m + n*y + k)

      Note that before meeting the point shown above, fast
      was moving at twice speed.

      x -->  Number of complete cyclic rounds made by 
             fast pointer before they meet first time

      y -->  Number of complete cyclic rounds made by 
             slow pointer before they meet first time

      From the above equation, we can conclude below 

          m + k = (x-2y)*n

      Which means m+k is a multiple of n.

So if we start moving both pointers again at the same speed such that one pointer (say slow) begins from the head node of the linked list and other pointers (say fast) begins from the meeting point. When the slow pointer reaches the beginning of the loop (has made m steps), the fast pointer would have made also moved m steps as they are now moving the same pace. Since m+k is a multiple of n and fast starts from k, they would meet at the beginning. Can they meet before also? No, because the slow pointer enters the cycle first time after m steps.




# Finding minimum height of binary tree with given inorder and level-order traversals

The inorder and levelorder traversals for a binary tree along with the total number of nodes is given in a function definition, we have to calculate the minimum height of binary tree for the given inputs.
<i>The minimum possible height of a binary tree is log2(n+1), where n is the number of nodes. </i>

yes, you can do that without even constructing the tree.
for that use two queue.
see given below code for better understanding.

            void **buildTree**(int inorder[], int levelOrder[], int i, int j,int n)
            {
                queue<int>q1,q2;
                q1.push(levelOrder[0]);
                int k = 1,height = 0;
                while(!q1.empty() || !q2.empty()){
                    if(!q1.empty()) height++;
                    while(!q1.empty()){
                        int val = q1.front();
                        for(int i = 0;i<n;++i){
                            if(inorder[i] == val) break;
                        }
                        if(i>0 && inorder[i-1] !=-1 && k<n)
                            q2.push(levelOrder[k++]);
                        if(i<n-1 && inorder[i+1] !=-1 && k<n) 
                            q2.push(levelOrder[k++]);
                        inorder[i] = -1;
                        q1.pop();
                    }
                    if(!q2.empty()) height++;
                    while(!q2.empty()){
                        int val = q2.front();
                        for(int i = 0;i<n;++i){
                            if(inorder[i] == val) break;
                        }
                        if(i>0 && inorder[i-1] !=-1 && k<n)  
                            q1.push(levelOrder[k++]);
                        if(i<n-1 && inorder[i+1] !=-1 && k<n) 
                            q1.push(levelOrder[k++]);
                        inorder[i] = -1;
                        q2.pop();
                    }
                }
             cout<<height<<endl;
            }
            
            
![Screenshot from 2021-12-27 16-42-10](https://user-images.githubusercontent.com/48405411/147466513-e149f927-2758-4a39-8c5d-875aa94bec91.png)




### 267. Palindrome Permutation II
Problem:

Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].

<b>
Hint:
If a palindromic permutation exists, we just need to generate the first half of the string.
Thoughts:
</b>

            public class Solution {
                public List<String> generatePalindromes(String s) {
                    int[] cha = new int [256]; 
                    for (int i = 0; i < s.length(); i ++) {
                        cha[s.charAt(i)] += 1;
                    }
                    List<String> result = new LinkedList<String>();
                    boolean odd = false;
                    int oddIndex = 0;
                    for (int i = 0; i < 256; i ++) {
                        if (cha[i] % 2 == 1) {
                            if (odd == true) {
                                return result;
                            }
                            oddIndex = i;
                            odd = true;
                        }
                    }

                    String base = "";
                    if (odd == true) {
                        base = (char)oddIndex + "";
                        cha[oddIndex] -= 1;
                    }
                    process(base, cha, s.length(), result);
                    return result;
                }
                private void process(String base, int[] cha, int n, List<String> result) {
                    if (base.length() == n) {
                        result.add(base);
                        return;
                    }
                    for (int i = 0; i < cha.length; i ++) {
                        if (cha[i] > 0) {
                            cha[i] -= 2;
                            process((char)i + base + (char)i, cha, n, result);
                            cha[i] += 2;
                        }
                    }
                }
            }

132. Palindrome Partitioning II -> DP Approach 
133. Unique permutation , only one time swap, sort it and pass for same element
