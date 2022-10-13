// MidTerm - Programming Languages - Spencer Gayton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void array_accommodation(int* a, int size);
void swapNoNewVar(int x, int y);
void swapNewVar(int x, int y);
void print_array(int* a, int size);
void linear_search(int* a, int target, int size);
void bubble_sort(int* a, int size);

int main()
{
    int x, y, target;
    int *a;
    int size;

    int option;

    cout << R"(
Menu for Midterm Exam:
    1: Swap Function
    2: Reverse an Array Without Allocating Extra Space
    3: Recursive Function to Print Array Forwards then Backwards by Swapping Only 2 Statements
    4: Algorithm to count occurrences of each member of the array(complexity O(n)) and array(complexity 0(n^2))
    5: Loop with pointers to print an array
    6: Print Complexity Table
            )" << endl;
    cout << "Choose an Option" << endl;
    cin >> option;
    
    
    switch (option) {
        case 1: 
            cout << "Enter X and Y:" << endl;

            cin >> x >> y;

            cout << endl;

            swapNoNewVar(x, y);
            swapNewVar(x, y);
            break;
        //Array no extra space
        case 2:
            cout << "   Pseudocode for Reversing an Array without Allocating Extra Space" << endl;
            cout << R"(
                for(int i = 0; i < arrlen / 2; i++){
                swap(a[i],a[arrlen - 1 - i]);
                }                          
                               
                for(int i = 0, int j = size - 1; i < j; i++, j--){
                swap(a[i], a[j]);
                }
            )" << endl;
            break;
        //Array Forwards & Backwards
        case 3: 
            cout << "   Pseudocode for Printing Array Forwards then Backwards by Swapping Only 2 Statements" << endl;
            cout << R"(
                void print_forward_array(int a[], int index, int arrlen){                                  
                if(a[index] == arrlen - 1)
                cout << a[index], << endl;
                                                   
                    else {                                        
                    cout << a[index] << endl;
                        print_forward_array(a, index + 1, size);
                    }                                                                                  
                }
                                                   
                void print_backwards_array(int a[], int index, int arrlen){                                  
                if(a[index] == arrlen - 1){
                cout << a[index], << endl;
                    }                                                
                    else {
                        print_backwards_array(a, index + 1, size);
                    cout << a[index] << endl;
                    }                                                                                  
                }    
            )" << endl;
            break;
        //Linear and Bubble Sort
        case 4:
            printf("How many numbers do you want to enter? \n");
            printf("\n");

            scanf_s("%d", &size);

            a = (int*)calloc(size, sizeof(int));

            array_accommodation(a, size);

            printf("Enter target number to find in array: \n");
            scanf_s("%d", &target);

            bubble_sort(a, size);
            cout << endl << "Output from Complexity n^2" << endl;
            print_array(a, size);
            cout << endl << "Output from Complexity n" << endl;
            linear_search(a, target, size);
            break;


            bubble_sort(a, size);
            
            break;
        //Loop Array with pointers
        case 5: 
            break;
        //Complexity Table
        case 6:
            cout << R"(
            Complexity Table: 
                Algorithm:                              Time Complexity:
                Linear Search                           O(n)
                Binary Search                           O(log n)
                Bubble, Selection, Insertion Sort       O(n^2)
                Merge, Quick, Heap Sort                 O(n log n)
                Bucket Sort                             O(n + k)
                Radix Sort                              O(n k)
                Shell Sort                              O((n log n)^2)
            )" << endl;
            break;
        default:
            break;
    }

}

void array_accommodation(int* a, int size)
{
    int i;
    printf("Please enter %d numbers in a row: ", size);

    for (i = 0; i < size; i++)
        scanf_s("%d", &a[i]);



}

void swapNoNewVar(int x, int y) {
    cout << "Without Using a New Variable: x becomes x+y -> y becomes x-y -> x becomes x-y" << endl;
    cout << "Original: " << x << " and " << y << endl;

    x = x + y;
    y = x - y;
    x = x - y;
    
    cout << "Output: " << x << " and " << y << endl << endl;
}

void swapNewVar(int x, int y) {
    cout << "Using a New Variable: z will hold y -> y then holds x -> x then holds z" << endl;
    cout << "Original: " << x << " and " << y << endl;

    int z;
    z = y;
    y = x;
    x = z;
    
    cout << "Output: " << x << " and " << y << endl << endl;
}

void print_array(int* a, int size)
{
    int i;

    printf("\nHere is your array: \n");
    for (i = 0; i < size; i++)
        printf("%d \n", a[i]);

}

void linear_search(int* a, int target, int size)
{
    int found = 0;
    int i;

    for (i = 0; i < size; i++) {
        if (a[i] == target) {
            found = 1;
            break;
        }

    }
    if (found == 1)
        printf("The target number is in the array at position %d. \n", i + 1);
    if (found == 0)
        printf("The target number is not in the array. \n");

}

void bubble_sort(int* a, int size){
    int i, j;
    int temp;
    for (j = 0; j < size - 1; j++)
        for (i = 0; i < size - 1; i++)
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }


}
