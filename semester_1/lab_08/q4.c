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

   

 	 

 

 

 

