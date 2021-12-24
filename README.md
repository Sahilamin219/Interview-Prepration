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
