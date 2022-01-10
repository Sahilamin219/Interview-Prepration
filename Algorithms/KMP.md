# KMP (Knuth Morris Pratt) Pattern Searching Algorithm

### Used For  : Searching for every occurrence of a pattern inside Text

Given :   1. A Text String of length N
          2. A Pattern String of length M

Return : Starting indexes where pattern is found .

Time Complexity of brute force : O(N*M) [ e.g. search pattern at every element inside Text ]
  
Time Complexity of KMP : O(N + M) in worst case 
                    {    O(N) for particularly in KMP search + 
                O(M) for building in LPS array   }

LPS : Longest Prefix Suffix 

Idea : 

    Just Like we create a DP table to store states and optimize recursive solutions,Here, we use the LPS array for the same .
    LPS array is our Look Up Table .
    What does LPS tell us about a string ?
    LPS stores ( for i-th index ) the length of the prefix which is also the suffix  for the string formed till i-th index e.g. for S[:i+1] .

### How Does it Help  ?  
      
    As LPS gives us the length of a prefix which is also a suffix . So it can be said if one substring of length 'x' matches in the Text string
    at i-th position, then that could be said for the string forming from S[ i : i+x+1 ] has a certain repetition .

    That repetition is nothing but the same prefix string of length LPS[x] as because it's also the suffix of S[ i: i+x+1] string .

    So if Unmatch is found on i+x+1 ( S[i+x+1] position ) then we don't need to again go back to i+1 th position unlike brute force position … 
    in fact we never go back in the Text string .. we continue comparing from the Pattern[ LPS[x] ] character .

    Again if unmatched is found .. we continue comparing from 

    Pattern[ LPS[ LPS[x] -1 ] ]  

    and so on until LPS[ LPS[ LPS[x] -1 ] ] … becomes 0 .

### Code Below :-

    text = "ABABDABACDABABCABAB"
    pattern = "ABABCABAB"

    #compute LPS
    …
    # Do KMP search 


