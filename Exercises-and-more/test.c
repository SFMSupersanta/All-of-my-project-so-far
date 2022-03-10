#include <stdio.h>
#include <stdlib.h>


int main() {	

	int arr[7];
	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &arr[i]);
	}
	int mask[7] = {0};

	//first mask eliminaton
	for (int i = 0; i < 7; i++)
	{ 
		if(arr[i]<10) mask [i] = -1;
	}

	//second mask eliminaton and count
	for (int i = 0; i < 7; i++)
	{ 
		if(mask[i]==0)
		{ 
			mask[i] ++;
			for (int j = i+1; j < 7; j++)
			{ 
				if(mask[j]==0)
				{
					if(arr[j]==arr[i]) 
					{
						mask[i] ++;
						mask[j] = -1;
					}
				}
			}
		}
	}
	
	for(int i = 0; i < 7; i++)
	{ 
		if(mask[i]>0) printf("%d", arr[i]);
	}

    return(0);
}
/*
1
3
5
7
12
12
12

1
3
5
7
9
1
2

10
10
1
2
3
12
12

*/