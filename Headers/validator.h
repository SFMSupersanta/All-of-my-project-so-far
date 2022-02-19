
 /* clear empties input buffer */ 
 void clear_buffer (void)
 {
     char c;
     while ((c=getchar()) != '\n'&&c!=EOF);
 }

long long getInt(char msg[], long long min, long long max) 
{
     long long value, rc;
     int keeptrying = 1;
     char excess;

     do 
     {
         printf("%s ", msg);
         printf("in the range [%lld,%lld] : ", min, max);
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
         printf("in the range [%.6g,%.6g] : ", min, max);
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
     int count=0;
     while(limit[count] != '\0') count++; 
     int keeptrying = 1;
     do
     {
        char value = getchar();
        {
            for(int i=0; i<count; i++)
            {
                if(value == limit[i])
                {
                    keeptrying==0;
                }
                if(keeptrying==0)
                {
                    if(getchar() != '\n') keeptrying=1;
                    clear_buffer();
                }
            }
        }
     } while (keeptrying == 1);
 }