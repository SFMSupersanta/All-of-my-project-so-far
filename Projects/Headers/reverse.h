// required lib : stdio.h stdlib.h
// caution : Renember to free memory afer pointer return function

void reverseInt (int arr[], int size) 
{
    int temp;
    for (int i = 0; i < size / 2; i++)
    { 
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

//
int * PreverseInt (int arr[], int size)
{ 
    int *returnarr = (int *)malloc(size * sizeof(int) + 1 );
    for (int i = size - 1; i >= 0; i--)
    { 
        *returnarr = arr[i];
        returnarr ++;
    }
    return returnarr - size;
}

void reverseStr (char str[])
{ 
    char temp;
    for (int i = 0; i < strlen (str) / 2; i++)
    { 
        temp = str[i];
        str[i] = str[strlen (str) - 1 - i];
        str[strlen (str) - 1 - i] = temp;
    }
}

char * PreverseStr (char str[]) 
{
    int size = strlen (str);
    char *returnstr = (char *)malloc ((size + 1) * sizeof(char));
    for (int i = size - 1; i >= 0 ; i--)
    { 
        returnstr[size - i - 1] = str[i];
    }
    returnstr[size] = '\0';

    return returnstr ;
}