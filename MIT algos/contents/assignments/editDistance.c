/**************************************************
 *  6.046, Fall 2005.   Problem 7-1
 *
 *  C program to compute Edit Distance 
 *
 **************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Operation Costs
#define MOVE_COST 0
#define REPLACE_COST 4
#define INSERT_COST 3
#define DELETE_COST 2


// Operation Types
typedef enum {initial, right, insert, delete, replace, final} opType;
char* opStrings[] = {"initial", "right", "insert", "delete", "replace", "final"};


// Recovers and prints out the edits necessary to change x into y.
static void recoverEdits(char* x, int m,
			 char* y, int n,
			 int** d, opType** opPerformed);


// Computes the edit distance between x and y
static void computeEditDistance(char* x, int m,
				char* y, int n) {


  // In this dynamic program, d[i][j] stores the edit distance between 
  //   the string x[i..m-1] and y[j..n-1].  
  // NOTE! C arrays start indexing at 0.
  
  int** d;
  opType** opPerformed;          // store operations for reconstructing the answer
  opType opDone;
  int i, j;

  d = (int**)malloc((m+1)*sizeof(int*));
  assert(d != NULL);
  opPerformed = (opType**)malloc((m+1)*sizeof(opType*));
  assert(opPerformed != NULL);
  
  for (i = 0; i <= m; i++) {
    d[i] = (int*)malloc((n+1)*sizeof(int));
    assert(d[i] != NULL);
    opPerformed[i] = (opType*)malloc((n+1)*sizeof(opType));
    assert(opPerformed[i] != NULL);
  }


  // Initialize the base cases.

  // x[m] and y[n] are both null strings. Edit distance between them is 0.
  d[m][n] = 0;
  opPerformed[m][n] = final;
  
  for (i = 0; i < m; i++) {
    // To convert x[i..m-1] to the null string y[n], delete all (m-i)
    //   remaining characters in x.
    d[i][n] = DELETE_COST*(m-i);
    opPerformed[i][n] = delete;
  }

  for (j = 0; j < n; j++) {
    // To convert x[m] (the null string) into  y[j..n-1], insert
    //   the missing n-j characters.
    d[m][j] = INSERT_COST*(n-j);
    opPerformed[m][j] = insert;
  }


  // Start at d[m][n] and loop backwards
  for (i = m-1; i >=0; i--) {
    for (j = n-1; j >= 0; j--) {
      int costForReplaceOrMove;
      int costForInsert;
      int costForDelete;
      int minValue;

      // Compute d[i][j] as the minimum of 4 terms:

      // If x[i] == y[j], we could move right.
      //  Otherwise, we can replace x[i] with y[j] and
      //   increment i and j.
      costForReplaceOrMove = d[i+1][j+1] + REPLACE_COST*(x[i] != y[j]) + MOVE_COST*(x[i] == y[j]);

      // If we insert a character into x to match y[j], then
      //   we increment j by 1
      costForInsert = d[i][j+1] + INSERT_COST;

      // If we delete a character in x, then we
      //  increment i by 1.
      costForDelete = d[i+1][j] + DELETE_COST;


      // Of the above operations, find one that gives us
      //  a minimum cost.

      minValue = costForReplaceOrMove;
      if (x[i] != y[j]){
	opDone = replace;
      }
      else {
	opDone = right;
      }

      if (minValue > costForInsert) {
	minValue = costForInsert;
	opDone = insert;
      }
      
      if (minValue > costForDelete) {
	minValue = costForDelete;
	opDone = delete;
      }

      d[i][j] = minValue;
      opPerformed[i][j] = opDone;
    }
  }

  // Final answer
  printf("Edit Distance =  %d\n", d[0][0]);

  // Recover operations / print out answer only if the strings aren't too long.
  if ((m < 75) && (n < 75)) {
    recoverEdits(x, m, y, n, d, opPerformed);
  }
  

  for (i = 0; i <= m; i++) {
    free(d[i]);
    free(opPerformed[i]);
  }
  free(d);
  free(opPerformed);
}	


static void recoverEdits(char* x, int m,
			 char* y, int n,
			 int** d, opType** opPerformed) {
  int i = 0;   
  int j = 0;
  int k = 0;
  int a;
  int opDone;
  int costSoFar = 0;
  int stepCost = 0;
  char* newString;

  newString = (char*)malloc(sizeof(char) * (m + n));

  // Rather than implementing a string object for x that allows us
  //  constant-time inserts and deletes at the cursor, 
  //  we are just going to have two copies of the string.

  //  newString[0..k] stores everything before the cursor that we have
  //   changed, and x[i..m-1]  will store all the parts after the cursor that
  //    are still the same.

  strncpy(newString, x, m);

  printf("\n");
  printf("( i,  j):  %8s |    c | Total |  z \n", "Oper");
  printf("---------------------------------------------------------------------\n");
  printf("(%2d, %2d):  %8s | %4d | %4d  | ", i, j, "initial", costSoFar, stepCost);
  printf("*%s\n", x);
    
  while (opPerformed[i][j] != final) {

    opDone = opPerformed[i][j];
    switch(opDone) {
    case right:
      newString[k] = x[i];
      i++;
      j++;
      stepCost = MOVE_COST;
      break;
    case replace:
      newString[k] = y[j];
      i++;
      j++;
      stepCost = REPLACE_COST;
      break;
    case insert:
      newString[k] = y[j];
      j++;
      stepCost = INSERT_COST;
      break;	
    case delete:
      i++;
      stepCost = DELETE_COST;
      break;
    default:  // We should never a follow a pointer to initial or final.
      printf("ERROR.\n");
      exit(1);
      break;
    }

    if (opDone != delete) {
      k++;
    }

    costSoFar += stepCost; 
    printf("(%2d, %2d):  %8s | %4d | %4d  | ", i, j, opStrings[opDone], costSoFar, stepCost); // newString);

    // Print the prefix we have generated so far.
    for (a = 0; a < k; a++) {
      printf("%c", newString[a]);
    }

    // Print the cursor
    printf("*");

    // Print the rest of the string (the part of x that we haven't looked at so far)
    for (a = i; a < m; a++) {
      printf("%c", x[a]);
    }
    printf("\n");
  }
  free(newString);
}


#define MAX_LENGTH 1000

int main(int argc, char* argv[]) {

  FILE* f;
  int inputLength = 0;
  int outputLength = 0;
  int i;
  char inputString[MAX_LENGTH];
  char outputString[MAX_LENGTH];

  // Make sure we have enough arguments
  if (argc <= 1) {
    printf("Usage: <input file>\n");
    return 0;
  }

  // Open the file
  f = fopen(argv[1], "r");
  assert(f != NULL);

  // Read in the input string
  fscanf(f, "%d\n", &inputLength);
  assert(inputLength < MAX_LENGTH);
  for (i = 0; i < inputLength; i++) {
    fscanf(f, "%c", &inputString[i]);
  }
  inputString[inputLength] = '\0';

  assert(strlen(inputString) == inputLength);

  // Read in the desired output string
  fscanf(f, "%d\n", &outputLength);
  assert(outputLength < MAX_LENGTH);
  for (i = 0; i < outputLength; i++) {
    fscanf(f, "%c", &outputString[i]);
  }
  outputString[outputLength] = '\0';

  assert(strlen(outputString) == outputLength);

  //  printf("x: %s\n", inputString);
  //  printf("y: %s\n", outputString);
  
  computeEditDistance(inputString, inputLength,
		      outputString, outputLength);

  // Close the file
  fclose(f);

  return 0;
}
