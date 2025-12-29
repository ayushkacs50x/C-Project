#include <stdio.h>

int main() {
    int choice;
    float a, b;

    printf("Simple Calculator\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    if (choice == 1)
        printf("Result = %.2f\n", a + b);
    else if (choice == 2)
        printf("Result = %.2f\n", a - b);
    else if (choice == 3)
        printf("Result = %.2f\n", a * b);
    else if (choice == 4) {
        if (b == 0)
            printf("Error: Division by zero\n");
        else
            printf("Result = %.2f\n", a / b);
    } else
        printf("Invalid choice\n");

    return 0;
}
