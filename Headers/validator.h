
 #include<stdlib.h>
 
 /* clear empties input buffer */ 
 void clear_buffer (void)
 {
     char c;
     while ((c=getchar()) != '\n'&&c!=EOF);
 }

//even val
int getEven(char arr[],int min, int max)
{
    char val[20];           //input value
    int intval,count,rc;      //int value and count value
    while(1)
    {
        printf("%s", arr);
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
            intval = atoi(val);

            //printf("%d\n", intval);

            if(intval<=0) count++;

            while(intval!=0)
            {
                intval/=10;
                count++;
            }

            //printf("%d\n", count);

            intval = atoi(val);
            if (val[count] != '\n')  printf("**Trailing Character(s)**\n");
            else if(min<intval&&intval<max)
            {
                if(intval%2==0) return intval;
                else printf("**Not an even number**\n");
            }else printf("**OUT OF RANGE**\n");
        } else printf("**No input**\n");
    }
}

long long getInt(char msg[], long long min, long long max) 
{
     long long value, rc;
     int keeptrying = 1;
     char excess;

     do 
     {
         printf("%s ", msg);
         rc = scanf("%lld%c", &value, &excess);
         if (rc == 0) 
         {
             printf("**No input accepted!**\n\n");
             clear_buffer();
         } 
         else if (excess != '\n') 
         {
             printf("**Trailing characters!**\n\n"); 
             clear_buffer();
         } 
         else if (value < min || value > max) 
         {
             printf("**Out of range!**\n\n");
         } 
         else
             keeptrying = 0;
         } 
     while (keeptrying == 1);
     
     return value;
 }

 double getDouble(char msg[], double min, double max) 
{
     double value, rc;
     int keeptrying = 1;
     char excess;

     do 
     {
         printf("%s ", msg);
         rc = scanf("%lf%c", &value, &excess);
         if (rc == 0) 
         {
             printf("**No input accepted!**\n\n");
             clear_buffer();
         } 
         else if (excess != '\n') 
         {
             printf("**Trailing characters!**\n\n"); 
             clear_buffer();
         } 
         else if (value < min || value > max) 
         {
             printf("**Out of range!**\n\n");
         } 
         else
             keeptrying = 0;
     } 
     while (keeptrying == 1);
     
     return value;
 }

 char getChar(char msg[], char limit[])
 {

     int keeptrying = 0;
     char value;
     do
     {
        printf("%s", msg);
        value = getchar();
        {
            for(int i=0; limit[i]!='\0' ; i++)
            {
                if(value == limit[i])
                {
                    if(getchar() == '\n') keeptrying = 1;
                }
            }
            if(keeptrying==0) 
            {
                clear_buffer();
                printf("**Invalid character(s)!**\n");
            }
        }
     } while (keeptrying == 0);

     return value;
 }