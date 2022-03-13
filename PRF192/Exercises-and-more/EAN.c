/****************************************************************
(〃￣︶￣)人(￣︶￣〃))
Referring code made by SFMSupersanta.
Program: EAN
version #
////////////////////////////////////////////////////////////////
Design and code a function named EAN that receives an 
International Standard Book Number (ISBN) and returns the 
equivalent European Article Number (EAN).  The ISBN consists 
of up to 10 digits.  The equivalent EAN consists of 13 digits 
where the leftmost 3 digits are 978 and the rightmost digit is
a check digit.  The remaining 9 digits are the same as the 
corresponding ISBN digits.  For example,

 ISBN:    321197186
          ||||||||
 EAN: 9780321197184 
The statement

 printf("??\n", EAN( 321197186 ));

where ?? is to be replaced by the appropriate conversion 
specifier, displays

 9780321197184 

The check digit for an EAN is the digit that adds to the weighted
sum of the other digits to produce a total that is divisible by 10. 
The weighted sum is from the left:
the sum of the 1st, 3rd, etc. digits (excluding the check digit), plus
the sum of the 2nd, 4th, etc. digits each multiplied by 3.
That is,

                          EAN 978032119718?
                                          |
                           check digit is ?

   9  7  8  0  3  2  1  1  9  7  1  8
 x 1  3  1  3  1  3  1  3  1  3  1  3
 = 9 21  8  0  3  6  1  3  9 21  1 24 = 106
 remainder after division by 10           6 A 
 check digit is difference 10 - A         4

 Therefore, the EAN is        9780321197184

****************************************************************/

#include <stdio.h>
#include <stdlib.h>

void clear_buffer (void);

long long getInt(char msg[], long long min, long long max) ;

int check_digit(long long ean);

int main()
{
    long long isbn = getInt ("Enter the ISBN:", 0, 9999999999);
    long long EAN = 9780000000000 + isbn;
    printf ("EAN: %lld\n", (EAN - (EAN % 10)) + check_digit (EAN));
    return 0;
}

int check_digit(long long ean)
{
    ean /= 10;
    int sum = 0;  
    for(int i = 0; i < 13;i++)
    {
        if(i % 2 == 0) 
        {
            sum += (ean % 10) * 3;
            ean /= 10;
        }
        else
        {
            sum += ean % 10;
            ean /= 10;
        }
    }
    return 10-(sum%10);
}

 /* clear empties input buffer */ 
 void clear_buffer (void)
 {
     char c;
     while ((c=getchar()) != '\n'&&c!=EOF);
 }

 long long getInt(char msg[], long long min, long long max) 
{
     char val[20];           //input value
     long long intval;
     int count,rc;      //int value and count value
     while(1)
     {
         printf("%s", msg);
         count = 0;
         rc =0;
         fgets(val,20,stdin);

         if(val[0]!='\n')
         {
             if(0<max&&0>min) if(val[0]=='0' && val[1] == '\n') return 0;
             for(int i=0; i< 20; i++) 
             {
                 if(val[i]=='\n') rc = 1;
             } 
             if(rc==0) clear_buffer();
             char *ovf;

             intval = strtoll(val,&ovf,10);
             
 
             if(intval<=0) count++;

             long long intvaldup = intval;
 
             while(intvaldup!=0)
             {
                 intvaldup/=10;
                 count++;
             }

             if (val[count] != '\n')  printf("**Trailing Character(s)**\n");
             else if(min<intval&&intval<max)
             {
                 return intval;
             }else printf("**OUT OF RANGE**\n");
         } else printf("**No input**\n");
     }
 }
