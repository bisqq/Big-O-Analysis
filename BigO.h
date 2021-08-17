#pragma once
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;


//================================================================================================
// Q1
//================================================================================================

// PARAM: arr is array to print the Cartesian product of, n is size of arr
int cartesianProduct(int arr[], int n)
{
    int count = 0;

    int i = 0;// const
    count++;
    while (i < n) {// O(n), n times(0 ... n) // const
        count++;
        int j = 0;//n
        count++;
        while (j < n) { // O(n^2) //n //n*n
            count++;
            cout << "{" << arr[i] << "," << arr[j] << "}";// barometer operation //n*n
            count++;
            j++;//n*n
            count++;
            cout << " ";//n*n
            count++;
        }
        count++;
        cout << endl;//n
        count++;
        i++;//n
        count++;
    }
    count++;

    return count;// not part of operation count
}


//================================================================================================
// Q2
//================================================================================================


int triangle(int x) // x = 5
{
    int count = 0;

    int i = 0; // const
    count++;
    while (i < x) {// const // loops n times,  O(n) 0 ... n
        count++;
        int j = 0;//n
        count++;
        while (j <= i) { // O(n) //n // runs (n(n+1) / 2) * 3, 3 operations in the inner loop including the condition
            count++;
            cout << j << " ";// barometer operation
            count++;
            j++;
            count++;
        }
        count++;

        cout << endl;//n
        count++;
        i++;//n
        count++;
    }
    count++;

    while (i > 0) {// const // loops n times going backwards, O(n) n ... 1
        count++;
        i--;//n
        count++;
        int j = 0;//n
        count++;
        while (j <= i) {  // O(n) //n // runs (n(n+1) / 2) * 3, 3 operations in the inner loop including the condition
            count++;
            cout << j << " ";
            count++;
            j++;
            count++;
        }
        count++;
        cout << endl;//n
        count++;
    }
    count++;

    return count;// not part of operation count
}

//================================================================================================
// Q3
//================================================================================================

vector<int> removeDuplicates(int arr[], int n, int& operations)
{

    vector<int> result; //1
    operations++;
    int i = 0; //1
    operations++;
    while (i < n) {// O(n) // n 
        operations++;
        int iResult = 0; //n
        operations++;
        bool duplicate = false; //n
        operations++;

        // O(n) times worst cast // O(1) best case
        while (iResult < (int)result.size() && !duplicate) { //note 4 // loop n * (n+1)
            operations++;
            if (arr[i] == result[iResult]) {
                duplicate = true;
                operations++;
            }
            operations++;

            iResult++;// barometer operation //n(n) = n^2
            operations++;;
        }
        operations++;

        if (!duplicate) {//!duplicate means if(true) //n
            result.push_back(arr[i]); //note 4 //n
            operations++;
        }
        operations++;

        i++;//n
        operations++;
    }
    operations++;

    return result;// not part of operation count
}

//================================================================================================
// Q4
//================================================================================================


// Returns the index of a 1d array representing a matrix
// given row (r) and column (c) values
int rcIndex(int r, int c, int columns)
{
    return r * columns + c;
}

// PRE: m represents a square matrix of size rows * rows
// PARAM: rows represents the number of both rows and columns
// POST: Returns a pointer to an array (matrix) of the same size as m
// NOTE: values are indexed r0c0,r0c1,…,r0cn-1,r1c0,…
int* matrixSelfMultiply(int* m, int rows, int& operations)
{
    // Create result array
    int columns = rows; //const
    operations++;
    int* result = new int[rows * columns];//const
    operations++;
    int r = 0;//const
    operations++;

    //4 consts

    while (r < rows) {// O(n) //const // n times
        operations++;
        int c = 0;//n
        operations++;
        while (c < columns) {//n //columns = rows // O(n^2) // 6n^2 //n*n
            operations++;
            int next = 0;//n*n
            operations++;
            int iNext = 0;//n*n
            operations++;

            while (iNext < rows) {//n*n // O(n^3) // 3n^3 //n*n*n
                operations++;
                next += m[rcIndex(r, iNext, columns)] * m[rcIndex(iNext, c, columns)];//n*n*n
                operations++;
                iNext++;//n*n*n
                operations++;
            }
            operations++;

            result[rcIndex(r, c, columns)] = next;//n*n
            operations++;
            c++;//n*n
            operations++;
        }
        operations++;
        r++;//n
        operations++;
    }
    operations++;

    return result;// not part of operation count
}

//================================================================================================
// Q5
//================================================================================================


// PARAM: arr is array to be sorted, n is size of array, i should initially = 0
int ssort(int arr[], int n, int i)
{
    int count = 0;

    count++;
    if (i < n - 1) { //runs from 0...n-2
        // Find and swap smallest remaining
        int next = i + 1;// this is where n+1 comes from for the loop
        count++;
        int smallest = i;
        count++;

        while (next < n) { //O(n^2)
            count++;
            if (arr[next] < arr[smallest]) {
                  smallest = next;//never hits for best case
                count++;
            }
            count++;
            next++;
            count++;
        }
        count++;

        // Swap i with smallest
        int temp = arr[i];
        count++;
        arr[i] = arr[smallest];
        count++;
        arr[smallest] = temp;
        count++;
        count += ssort(arr, n, i + 1);
    
    }

    return count;// not part of operation count
}

//================================================================================================
// Q6
//================================================================================================


// PRE: n is a power of 2 greater than zero.
// PRE: Initial call should be to i = 0
// e.g. pattern(8, 0)
int pattern(int n, int i)
{
    int count = 0;

    // 6 consts in the if and the terminating if total of 7
    // so we get 7(2n-1) because since every input is a power of 2, that means 7 * (1 + 2 + 4 + 8 + 10 + ... + 2n-1)
   
    if (n > 0) {// 1 operation from the if statment 
        count += pattern(n / 2, i);
        // Print i spaces
        cout << string(i, ' '); // NOTE: counts as ONE operation
        count++;

        // A loop to print n asterisks, each one followed by a space
        int ast = 0;
        count++;

        // 3n comes from the three operations within the while loop including the condition
        // n+1 iterations
        // 3n(n+1)
        // 2^n = n -> log_2_(n) = n
        // 3n * ((2 ^ log_2_(n)) + 1) ->  3n * (log_2_(n) + 1)
        while (ast < n) {
            count++;
            cout << "* ";
            count++;
            ast++;
            count++;
        }
        count++;

        cout << endl;
        count++;
        i += n;
        count++;
        count += pattern(n / 2, i);
    }
    count++;

    return count;// not part of operation count
}