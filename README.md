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
