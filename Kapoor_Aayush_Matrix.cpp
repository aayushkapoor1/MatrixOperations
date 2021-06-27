//Aayush Kapoor - ICS3U - Ms. Culum
/* The purpose of this assignment is to read in two matrices then
add, subtract, or multiply two matrices if they have the correct dimensions. */
#include <stdio.h>
#include <stdlib.h>

int main(){

    //Creates pointer to the file
    FILE *fptr;
    FILE *fptrOut;

    //Declaring variables
    int matrixARow;
    int matrixACol;
    int matrixBRow;
    int matrixBCol;
    int matrixCRow = 0;
    int matrixCCol = 0;
    bool properOperator = false;
    char inputtedOperator;

     //Open files
    fptr = fopen("matrixIn.txt", "r");
    fptrOut = fopen("matrixOut.txt", "w");


    //Error checking
    if (fptr == NULL || fptrOut == NULL){
        printf("File was not opened.");
        return 1;
    }

    //For Matrix A
    //Reads in matrix A dimensions
    fscanf(fptr, "%d", &matrixARow);
    fscanf(fptr, "%d", &matrixACol);
    //Declares matrix A
    int matrixA[matrixARow][matrixACol];

    int fillerA = 0;

    //Reads in Matrix A
    for (int i = 0; i < matrixARow; i++){
        for (int j = 0; j < matrixACol; j++){
            fscanf(fptr, "%d", &fillerA);
            matrixA[i][j]= fillerA;
        }
    }

    //For Matrix B
    fscanf(fptr, "%d", &matrixBRow);
    fscanf(fptr, "%d", &matrixBCol);

    //Initalize matrices B and the matrix resulting from the multiplication of matrix A and B
    int matrixB[matrixBRow][matrixBCol];
    int matrixProduct[matrixARow][matrixBCol];


    int fillerB = 0;

    //Reads in Matrix B
    for (int q = 0; q < matrixBRow; q++){
        for (int r = 0; r < matrixBCol; r++){
            fscanf(fptr, "%d", &fillerB);
            matrixB[q][r]= fillerB;
        }
    }

    //Printing Matrix A
    printf("The first matrix is %dx%d.\n", matrixARow, matrixACol);
    for (int i = 0; i < matrixARow; i++){
        for (int j = 0; j < matrixACol; j++){
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    //Printing Matrix B
    printf("The second matrix is %dx%d.\n", matrixBRow, matrixBCol);
    for (int q = 0; q < matrixBRow; q++){
        for (int r = 0; r < matrixBCol; r++){
            printf("%d ", matrixB[q][r]);
        }
        printf("\n");
    }

    //Loops through code until the user inputs a proper operator
    while (!properOperator){
        fflush(stdin);
        printf("What operator would you like to do to the two matrices. Addition(a), subtraction(s) or multiplication(m): ");
        //Scans user input
        scanf("%c", &inputtedOperator);
        //Declares the output matrix of addition or subtraction
        int matrixC[matrixCRow][matrixCCol];

        //Switch statement for user's input
        switch(inputtedOperator){
            //Runs code if user wants to add matrices
            case 'a':   //Changes value of bool to exit while loop
                        properOperator = true;
                        //Checks if the matrices have correct dimensions
                        if (matrixARow != matrixBRow || matrixACol != matrixBCol){
                            printf("You are not able to add matrices A and B together, since they do not have the same dimensions.\n");
                            break;
                        }
                        printf("You are able to add matrices A and B together. \n\n");

                        //Printing Matrix A
                        for (int i = 0; i < matrixARow; i++){
                            for (int j = 0; j < matrixACol; j++){
                                printf("%d ", matrixA[i][j]);
                            }
                            printf("\n");
                        }

                        printf("+ \n");

                        //Printing Matrix B
                        for (int q = 0; q < matrixBRow; q++){
                            for (int r = 0; r < matrixBCol; r++){
                                printf("%d ", matrixB[q][r]);
                            }
                            printf("\n");
                        }

                        for (int j = 0; j < matrixACol; j++){
                                printf("__");
                        }
                        printf("\n");


                        //Adds the matrices and prints to screen
                        for (int i = 0; i < matrixARow; i++){
                            for (int j = 0; j < matrixACol; j++){
                                matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
                                printf("%d ", matrixC[i][j]);
                            }
                            printf("\n");
                        }

                        //Adds the matrices and prints to textfile
                        for (int i = 0; i < matrixARow; i++){
                              for (int j = 0; j < matrixACol; j++){
                                matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
                                fprintf(fptrOut, "%d ", matrixC[i][j]);
                              }
                              fprintf(fptrOut, "\n");
                        }

                        break;

            case 's':   //Changes value of bool to exit while loop
                        properOperator = true;
                        //Checks if the matrices have correct dimensions
                        if (matrixARow != matrixBRow || matrixACol!= matrixBCol){
                            printf("You are not able to subtract matrices A and B together, since they do not have the same dimensions.\n");
                            break;
                        }
                        //Subtracts the matrices together and prints to screen
                        printf("You are able to subtract matrices A and B together. \n");

                        //Printing Matrix A
                        for (int i = 0; i < matrixARow; i++){
                            for (int j = 0; j < matrixACol; j++){
                                printf("%d ", matrixA[i][j]);
                            }
                            printf("\n");
                        }

                        printf("- \n");

                        //Printing Matrix B
                        for (int q = 0; q < matrixBRow; q++){
                            for (int r = 0; r < matrixBCol; r++){
                                printf("%d ", matrixB[q][r]);
                            }
                            printf("\n");
                        }

                        for (int j = 0; j < matrixACol; j++){
                                printf("__");
                        }
                        printf("\n");

                        //Subtracts the matrices together and prints to screen
                        for (int i = 0; i < matrixARow; i++){
                            for (int j = 0; j < matrixACol; j++){
                                matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
                                printf("%d ", matrixC[i][j]);
                            }
                            printf("\n");
                        }
                        //Subtracts the together and prints to textfile
                        for (int i = 0; i < matrixARow; i++){
                              for (int j = 0; j < matrixACol; j++){
                                matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
                                fprintf(fptrOut, "%d ", matrixC[i][j]);
                              }
                              fprintf(fptrOut, "\n");
                        }

                        break;

            case 'm':   //Changes value of bool to exit while loop
                        properOperator = true;
                        //Checks if the matrices have correct dimensions
                        if (matrixACol != matrixBRow) {
                            printf("You are not able to multiply matrices A and B together, since they do not have the correct dimensions.\n");
                            break;
                        }
                        //Multiplies the matrices together
                        for(int i = 0; i < matrixARow; i++) {
                            for(int j = 0; j < matrixBCol; j++) {
                                int val = 0;

                                for(int k = 0; k<matrixACol; k++) {
                                    val += matrixA[i][k] * matrixB[k][j];
                                }

                                matrixProduct[i][j] = val;
                            }
                        }


                        //Printing Matrix A
                        for (int i = 0; i < matrixARow; i++){
                            for (int j = 0; j < matrixACol; j++){
                                printf("%d ", matrixA[i][j]);
                            }
                            printf("\n");
                        }

                        printf("x \n");

                        //Printing Matrix B
                        for (int q = 0; q < matrixBRow; q++){
                            for (int r = 0; r < matrixBCol; r++){
                                printf("%d ", matrixB[q][r]);
                            }
                            printf("\n");
                        }

                        for (int j = 0; j < matrixBCol; j++){
                                printf("__");
                        }
                        printf("\n");


                        //Prints matrix to screen
                        for(int i = 0; i < matrixARow; i++){
                            for(int j = 0; j< matrixBCol; j++){
                                printf("%d ", matrixProduct[i][j]);
                            }
                            printf("\n");
                        }

                        //Prints to textfile
                        for(int i = 0; i < matrixARow; i++){
                            for(int j = 0; j< matrixBCol; j++){
                                fprintf(fptrOut, "%d ", matrixProduct[i][j]);
                            }
                            fprintf(fptrOut, "\n");
                        }

                        break;

            default:    //Prints error message
                        printf("Invalid operator %c was entered. Please try again. \n", inputtedOperator);
                        break;
        }
    }

    //Closes and saves textfiles
    fclose(fptr);
    fclose(fptrOut);

    return 0;
}
