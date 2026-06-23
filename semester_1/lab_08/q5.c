//QUESTON 5: 

#include<stdio.h> int main() 

{     int n; 

    printf("enter a num \n");     scanf("%d", &n);     printf("\n\n");     for(int uptriangle = 1 ; uptriangle <= n ; uptriangle++) 

    { 

        for(int s = 1; s <= n-uptriangle; s++) 

        { 

            printf(" "); 

        } 

        for(int star = 1 ; star <= uptriangle*2 -1; star++) 

        {             printf("*"); 

                 } 

        printf("\n"); 

    } 

    for(int downtri = 1; downtri <=n-1 ; downtri++) 

    { 

        for( int s=1 ; s <= downtri  ; s++) 

        {             printf(" "); 

        } 

         

        for( int star = 1 ; star <= ( (n - downtri)*2 -1 ) ; star++)         { 

            printf("*"); 

        } 

        printf("\n"); 

    } 

 

} 

 

 

