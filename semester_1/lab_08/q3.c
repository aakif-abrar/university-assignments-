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

 

  

 	 

 

 

 

 

 

