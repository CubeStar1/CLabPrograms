#include <stdio.h>

int main() {
    int a[10][10], b[10][10], c[10][10], m, n, i, j, k, choice;

    printf("Enter the number of rows and columns: ");
    scanf("%d%d",&m, &n );


    printf("Enter values for matrix A\n");
    for(i =0; i<m; i++) {
        for(j=0; j<n; j++) {
            printf("Enter element %d of row %d :", j+1, i+1);
            scanf("%d", &a[i][j]);

        }
        printf("\n");
    }

    printf("Enter values for matrix B\n");
    for(i =0; i<m; i++) {
        for(j=0; j<n; j++) {
            printf("Enter element %d of row %d :", j+1, i+1);
            scanf("%d", &b[i][j]);

        }
        printf("\n");
    }


    while(1) {
        printf("Choose the Matrix operation:\n 1. A+B\n 2. A-B\n 3. A*B\n 4. Tr(A), Tr(B)\n 5. Sum(A), Sum(B)\n 6. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Matrix Addition\n");
            for(i=0; i<m; i++) {
                for(j=0; j<n; j++) {
                    c[i][j] = a[i][j] +b[i][j];
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
        }

        else if(choice == 2){
            printf("Matrix Subtraction\n");
            for(i=0; i<m; i++) {
                for(j=0; j<n; j++) {
                    c[i][j] = a[i][j] - b[i][j];
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
        }

        else if(choice ==3) {
            printf("Matrix Multiplication\n");
            for(i=0; i<m; i++) {
                for(j=0; j<n; j++){
                    for(k=0; k<m; k++) {
                        c[i][j] = a[i][k] + b[k][j];
                    }
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
        }

        else if(choice == 4) {
            int traceA;
            int traceB;
            traceA = 0;
            traceB = 0;
            for(i =0; i<m; i++) {
                traceA += a[i][i];
                traceB += b[i][i];
            }
            printf("The trace of Matrix A is %d and Matrix B is %d \n", traceA, traceB);
        }

        else if(choice == 6) {
            printf("Exiting Program....\n");
            break;
        }

        else {
            printf("Invalid Choice\n");
            printf("Exiting Program....\n");
            break;
        }
    }
}
