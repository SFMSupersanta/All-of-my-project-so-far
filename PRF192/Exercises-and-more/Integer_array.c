/****************************************************************
╰（‵□′）╯ I CAN'T BELIVE HOW THE TEACHER MADE US DO THIS
Referring code made by SFMSupersanta.
Program: practice
version #
////////////////////////////////////////////////////////////////
This is an exercise that the teacher made us do that have 8 
parts
read an array of numbers from a file and do these things:
- Total sum of non-prime 
- The most appeared numbers 
- The number and it's occurrences
- Sort only the elements of the array that is larger than total 
mean 
- Reverse the first half of the array
- Reverse only the elements of the array that is larger than 
total mean
- Replace each element of the array with the closest prime that 
is bigger than that number 
- Replace each element of the array with the reversed number 
(ex: 123 = 321)
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//swap function
void swap(int *a, int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}

//sort the ones that is bigger than total mean
void selectionsort(int arr[], int size)
{
    int mean = 0;
    for (int i=0; i<size; i++) mean +=  arr[i];
    mean /= size;

    for(int i = 0; i < size; i++)
    {
        if (arr[i] > mean)
        {
            int *jmin = &arr[i];
            for(int j = i+1; j < size; j++)
            {
                if (arr[j] > mean) if(arr[j] < *jmin) jmin = &arr[j];
            }
            swap(&arr[i], &*jmin);
        }
    }
}

//print out the occurences of each number
int mean_of_occurrences(int arr[], int count)
{
    // mask declareation
    int mask[count];
    int total_digit = 0;
    // set mask to 0
    for (int i = 0; i < count; i++) mask[i] = 0;
    // set the total number of occurrences to the mask
    for (int i = 0; i < count; i ++)
    {
        if (mask[i] == 0)            // Imclement the mask of that particular number
        {
            mask[i] ++;
            for (int j = i + 1; j < count; j++)
            {
                if(arr[j] == arr[i]) 
                {
                    mask[j] = -1;    // Set the mask of occurred number to -1
                    mask[i] ++;      // Imclement the mask of that particular number
                }
            }
        }
    }

    //print out the number and it's occurrences
    for (int i = 0; i < count; i++)
    {
        if (mask[i] != -1 ) 
        {
            printf("The number: %5d, the ammont of occurrence:%d\n", arr[i], mask[i]);
        }
    }
}

// This is identical to the last function, only to take the one that occur the most
int most_appeared(int arr[], int count)
{
    //mask declareation
    int mask[count], max = -1;
    for (int i = 0; i < count; i++) mask[i] = 0;
    for (int i = 0; i < count; i ++)
    {
        if (mask[i] == 0)
        {
            mask[i] ++;
            for (int j = i + 1; j < count; j++)
            {
                if(arr[j] == arr[i])
                {
                    mask[j] = -1;
                    mask[i] ++;
                }
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (mask[i] > max)
        {
            max = i;
        }
    }
    return max;
}

// Prime check
int pc(int i)
{
    if(i<2) return 1;
    for (int j = 2; j <= sqrt(i); j++)
    {
        if(i % j == 0)
        {
          return 1;
        }
    } return 0;
}

// This is tricky to understand but once you grap it, it'd rather simple
void reverse_first_half(int arr[], int size)   // To reverse the first half of the array
{
    for (int i = 1; i <= size/2/2; i++)
    { 
        swap (&arr[i - 1], &arr[(size / 2) - i]);
    }
}

// To reverse only the larger mean
void reverse_larger_mean(int arr[], int size)
{ 
    int mask [size], num_count = 0 /* To count numbers of larger than mean*/; 
    for (int i = 0; i < size; i++) mask[i] = -1;   // set mask to -1
    double mean = 0;               // var for mean caculation
    for (int i = 0; i < size; i++) mean += arr[i];
    mean /= size;                  // Mean caculation

    for (int i = 0; i < size; i++)   
    { 
        if (arr[i] > mean)         // Set mask to 0 for elements larger than mean
        {
            mask[i] = 0;
            num_count ++;         
        }
    } 
    int submask[num_count], n;    //create a submask for swapping
    for (int i = 0; i < size; i ++) if(mask[i] == 0) 
    {
        submask[n++] = i;         // Get the positions of number to swap
    }

    for (int i = 1; i <= num_count / 2; i ++)
    {
        swap (&arr[submask[i-1]], &arr[submask[num_count - i]]); 
        // Swap the number by it's position in the submask string
    }
}

// This is rather simple so I won't explain it
void replace_by_prime (int arr[], int size)  //To replace the elements by it's closest prime
{
    for (int i = 0; i < size; i++)
    {
        if (pc (arr[i]) != 0)
        {
            do
            {
                arr[i] ++;
            } while (pc (arr[i]) != 0);
            
        }
    }
}

// Same as the one above
int reverseInt(int number)     // function to reverse number    
{
    int reversed_num = 0;         
    while (number != 0)
    {
        reversed_num *= 10;
        reversed_num += number % 10;
        number /= 10;
    }
    return reversed_num;
}

void reverse_arr(int arr[], int size)    
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = reverseInt(arr[i]);  // To replace the element by it's reverse
    }
}

int main()
{
    FILE *fileP;                      // File pointer
    char filestr[] = "integers.txt";  // File name string
    fileP = fopen(filestr, "r");      // Assign the pointer to the file's address
    if(fileP != NULL)                 // If sucessfully open the file
    {    
        int arr[100], count = 0;      // Array for storing data and number of data
        do
        { 
            fscanf(fileP, "%d", &arr[count++]);
        } while (! feof(fileP));      // Get the data from the file

        printf ("\nnumber of integer: %d\n", count);  

        int total_of_not_prime = 0;
        for (int i = 0; i < count; i++)
        {
            if(pc (arr[i]) == 1)
            { 
                total_of_not_prime += arr[i];
            }
        }
        printf("\nTotal of not prime: %d\n", total_of_not_prime);

        int most_occurence = most_appeared(arr, count);

        printf ("\nmost appeared number in the file: %d\n\n", arr[most_occurence]);

        printf("Numbers and it's occurrences:\n");
        mean_of_occurrences (arr, count);

        selectionsort(arr, count);
        printf("\nSorted digits greater than mean array : ");
        for (int i = 0; i < count; i ++)
        {
            printf("%d ", arr[i]);
        }   printf("\n");

        reverse_first_half (arr, count);
        printf("\nReversed first half arr: ");
        for (int i = 0; i < count; i ++)
        {
            printf("%d ", arr[i]);
        }   printf("\n");

        reverse_larger_mean (arr, count);
        printf("\nReversed larger than mean elements: ");
        for (int i = 0; i < count; i ++)
        {
            printf("%d ", arr[i]);
        }   printf("\n");

        replace_by_prime (arr, count);
        printf("\nAfter replacing number by it's larger closest prime: ");
        for (int i = 0; i < count; i ++)
        {
            printf("%d ", arr[i]);
        }   printf("\n");

        reverse_arr (arr, count);
        printf("\nAfter replacing number by it's reverse: ");
        for (int i = 0; i < count; i ++)
        {
            printf("%d ", arr[i]);
        }   printf("\n");

        fclose (fileP);
    }
    else printf("Error opening file %s\n", filestr);  // If can't access the file
    return 0;
}