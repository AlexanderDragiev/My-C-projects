#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



   bool* eratosthenes(int n)
   {
        bool* sieve = (bool*)malloc((n + 1) * sizeof(bool));
        memset(sieve, false, (n + 1) * sizeof(bool));

        for(int i = 2; i * i <= n; i++)
        {
            if(!sieve[i])
            {
                for(int j = i * i; j <= n; j += i)
                {
                    sieve[j] = true;
                }    
            }
        }

        return sieve;
   }

   void print_numbers(bool *sieve, int n)
   {
        for(int i = 2; i <= n; i++)
        {
            if(!sieve[i])
            {
                printf("%d ", i);
            }
        }

        printf("\n");
   }

   int main()
   {
        int n;
        scanf("%d", &n);

        bool *sieve = eratosthenes(n);
        print_numbers(sieve, n);

        return EXIT_SUCCESS;
   }
