# Big-O-Analysis
Analyze the running times of six functions.

# Assignment

### Requirements
For each of the functions described in questions 1 to 6 you are to:

A. Modify the function to count the number of operations performed when the function executes. Some questions will specify whether this is for the worst or best case. See the section on counting operations below for more detail.

B. Determine a detailed cost function for the function. This function should be written in the form wnx + yn + z where w, x, y and z are real numbers and n is a variable referring to the size of the function's input. If necessary, you should adapt this format to include other terms such as log2(n).

C. Identify (one of) the barometer operations for the function.

D. Identify the O notation running time of the function.

Questions 3 and 5 have additional or different requirements. There is a detailed example after the sixth question.

### Counting Operations
If the function's return type is void it should be modified to return the count of its operations. Otherwise, if the function already has a return value, the count should be assigned to an integer reference parameter. This reference parameter should always be the last parameter in the function's parameter list. When counting operations follow these rules - make sure you read them carefully (and follow them).

1. An executable statement (a line of code that ends in a semi-colon) or a condition (that controls an if statement or while loop) counts as one operation regardless of its complexity – see exceptions 2 and 5. Examples: x = 4; int w = x + y + z; (x < a && x < b || x < c) all count as single operations.
  
2. Exception to 1 – if a statement includes a function call that does not run in constant time its operation count should be the number of operations performed by that function call. This only applies to questions 5 and 6.

3. Note to 1 and 2 – statements that include the output operator (<<) follow rule 1 not rule 2. That is, an output statement that uses cout counts as a single operation regardless of its complexity. If it also includes unrelated function calls then rule 2 applies.

4. One execution of an if statement or while loop condition counts as one operation. Make sure that you count conditions that result in false as well as true – so don't forget to include the terminating comparison for while loops. Note that there are no for loops in any of the functions as this allowed me to simplify these instructions somewhat.
5. Return statements should not be included in the operation count.

## Question 1

This function prints the Cartesian product of its input array with itself.

```
// PARAM: arr is array to print the Cartesian product of, n is size of arr
void cartesianProduct(int arr[], int n)
{
       int i = 0;
       while (i < n) {
              int j = 0;
              while (j < n) {
                     cout << "{" << arr[i] << "," << arr[j] << "}";
                     j++;  
                     cout << " ";
              }

              cout << endl;
              i++;
       }
}
```
#### Notes
1. The function should be modified to return the operation count as an integer

## Question 2

This function prints a triangle of numbers (which doesn't look very pretty if the numbers have more than one digit).

```
void triangle(int x)
{
       int i = 0;
       while (i < x) {
              int j = 0;
              while (j <= i) {
                     cout << j << " ";
                     j++;
              }

              cout << endl;
              i++;
       }

       while (i > 0) {
              i--;
              int j = 0;
              while (j <= i) {
                     cout << j << " ";
                     j++;
              }
              cout << endl;
       }
}
```

### Notes
1. The function should be modified to return the operation count as an integer

## Question 3

This function returns a vector which contains the contents of its input array with any duplicates removed.

```
// PARAM: arr is array from which duplicates are to be removed, n is size of arr
vector<int> removeDuplicates(int arr[], int n)
{
       vector<int> result;
       int i = 0;
       while (i < n) {
              int iResult = 0;
              bool duplicate = false;

              while (iResult < (int)result.size() && !duplicate) { //note 4
                     if (arr[i] == result[iResult]) {
                           duplicate = true;
                     }

                     iResult++;
              }

              if (!duplicate) {
                     result.push_back(arr[i]); //note 4
              }

              i++;
       }
       return result;
}
```
### Notes
1. The function should be modified to include an integer reference parameter the value of which should be set to the operation count
2. Answer questions B, C and D of the General Requirements for both the worst-case and best-case running times of the function, and
3. Describe, and give examples of input that constitutes the best and worst case for the algorithm
4. The size and push_back methods of a vector run in constant time, therefore lines that include calls to these methods still only count as a single operation as per rule 1

## Question 4

This function returns an array in dynamic memory that represents the matrix that is the result of multiplying the matrix (array) parameter by itself.

```
// PRE: m represents a square matrix of size rows * rows
// PARAM: rows represents the number of both rows and columns
// POST: Returns a pointer to an array (matrix) of the same size as m
// NOTE: values are indexed r0c0,r0c1,…,r0cn-1,r1c0,…
int* matrixSelfMultiply(int* m, int rows)
{
       // Create result array
       int columns = rows;
       int* result = new int[rows * columns];
       int r = 0;

       while (r < rows) {
              int c = 0;
              while (c < columns) { //columns = rows
                     int next = 0;
                     int iNext = 0;

                     while (iNext < rows) {
                           next += m[rcIndex(r, iNext, columns)] * m[rcIndex(iNext, c, columns)];
                           iNext++;
                     }

                     result[rcIndex(r, c, columns)] = next;
                     c++;
              }
              r++;
       }
       return result;
}
```
```
// Returns the index of a 1d array representing a matrix
// given row (r) and column (c) values
int rcIndex(int r, int c, int columns)
{
       return r * columns + c;
}
```
### Notes
1. he function should be modified to include an integer reference parameter the value of which should be set to the operation count
2. The input size is the number of rows of the matrix
3.Lines that include call(s) to the rcIndex function (which has a constant time complexity) still only count as a single operation as per rule 1

## Question 5

This function is a recursive version of selection sort.

```
// PARAM: arr is array to be sorted, n is size of array, i should initially = 0
void ssort(int arr[], int n, int i)
{
       if (i < n-1) {
              // Find and swap smallest remaining
              int next = i + 1;
              int smallest = i;

              while (next < n) {
                     if (arr[next] < arr[smallest]) {
                          smallest = next;
                     }
                     next++;
              }

              // Swap i with smallest
              int temp = arr[i];
              arr[i] = arr[smallest];
              arr[smallest] = temp;
              ssort(arr, n, i + 1);
       }
}
```
### Notes
1. The function should be modified to return the operation count as an integer
2. Answer questions B, C and D of the General Requirements for the best-case running time of the function
3. Answer questions C and D (not B) for the worst-case running time of the function
4. Describe, and give an example of input that constitutes the best and worst case for the algorithm
5. Do not count the actual call to a recursive function as an operation – that is you must include the number of operations performed by the recursive call as per rule 2, but the call itself does not count as an operation

## Question 6

This function prints a pattern.

```
// PRE: n is a power of 2 greater than zero.
// PRE: Initial call should be to i = 0
// e.g. pattern(8, 0)
void pattern(int n, int i)
{
       if (n > 0) {
              pattern(n/2, i);
              // Print i spaces
              cout << string(i, ' '); // NOTE: counts as ONE operation

              // A loop to print n asterisks, each one followed by a space
              int ast = 0;
              while (ast < n) {
                     cout << "* ";
                     ast++;
              }

              cout << endl;
              i += n;
              pattern(n / 2, i);
       }
}
```
### Notes
1. The function should be modified to return the operation count as an integer
2. Note the cost of printing the spaces stated in a comment
3. Do not count the actual call to a recursive function as an operation – that is you must include the number of operations performed by the recursive call as per rule 2, but the call itself does not count as an operation
