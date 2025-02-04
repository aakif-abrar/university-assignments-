//LAB TASK 8 QUESTION 1: 

 

# include <stdio.h> int main(){ 

 	int begin = 0;  	int end = 0;  	int count = 0;  	int j = 0; 

 	printf("Enter the start of range: ");  	scanf("%d",&begin); 

 	printf("Enter the End of range:");  	scanf("%d",&end); 

 	for(int i = begin;i <= end; i++){ 

 	 	j = 2;  	 	count = 0; 

 	 	while(j<=i/2){  	 	 	if(i%j == 0){ 

 	 	 	 	count =1;  	 	 	 	break;  	 	 	}j++; 

 	 	 	 

 	 	 	 	 

 	 	}if (count == 0) { 

         	printf("%d\t", i); 

     	} 	 

 	 	 

} 

 	 

 	 

return 0; 

} 

 

 

//QUESTION 2 : 
# include <stdio.h> int main(){ 

 	int num= 0; 

 	printf("Enter the number: "); 

 	scanf("%d",&num); 

 	for(int i = num; i > 0;i--){ 

 	 	for(int j = 0; j < num;j++){ 

 	 	 	if (i%2!=0){  	 	 	 	printf("%d\t",i); 

 	 	 	} 

 	 	} 

 	} 

return 0; 	 

} 

  

 

 

 

 

 

 

//Question 3: 

#include <stdio.h> 

 

int main() {     int matrix[3][3]; 

     

    printf("Enter the elements of the 3x3 matrix:\n");     for (int row = 0; row < 3; row++) {         for (int column = 0; column < 3; column++) {             scanf("%d", &matrix[row][column]); 

        } 

    } 

 

    for (int row = 0; row < 3; row++) {         int minElement = matrix[row][0];         int minColumn = 0; 

 

        for (int column = 1; column < 3; column++) {             if (matrix[row][column] < minElement) {                 minElement = matrix[row][column];                 minColumn = column; 

            } 

        } 

 

        int isSaddlePoint = 1; 

 

        for (int k = 0; k < 3; k++) { 

            if (matrix[k][minColumn] > minElement) {                 isSaddlePoint = 0; 

                break; 

            } 

        } 

 

        if (isSaddlePoint) { 

            printf("Saddle point found: %d at position [%d][%d]\n", minElement, row, minColumn); 

        } 

    } 

 

    return 0; 

} 

 

  

 	 

 

 

 

 

 

//QUESTION 4: 

# include <stdio.h> int main(){ 

 	int arr1[3][3], arr2[3][3],arr3[3][3];  	printf("Enter the data in the array 1: ");  	for(int i = 0; i < 3; i++){  	 	for(int j = 0; j < 3; j++){ 

 	 	 	scanf("%d",&arr1[i][j]); 

 	 	} 

 	} 

 	printf("Enter the data in the array 2: ");  	for(int i = 0; i < 3; i++){ 

 	 	for(int j = 0; j < 3; j++){ 

 	 	 	scanf("%d",&arr2[i][j]); 

 	 	} 

 	} 	 

 	 

 	for (int i = 0; i < 3; i++) {      	for (int j = 0; j < 3; j++) { 

            arr3[i][j] = 0; 

        } 

    } 

 	 

   	for (int i = 0; i < 3; i++) { 

        for (int j = 0; j < 3; j++) {             for (int k = 0; k < 3; k++) {                 arr3[i][j] += arr1[i][k] * arr2[k][j]; 

            } 

        } 

    } 	 	 

 	  	 	 

 for(int i = 0; i < 3; i++){   for(int j = 0; j < 3; j++){ 

 	 	 	printf("%d\t",arr3[i][j]); 

 	 	} 

 	 	printf("\n"); 

 	} 

return 0; 	 	 

} 

   

 	 

 

 

 

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

 

 

