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

 

 

