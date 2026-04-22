#include <stdio.h>

// Iterative function
long long factorialIterative(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

// Recursive function
long long factorialRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorialRecursive(n - 1);
}

int main() {
    int n, choice;
    long long result;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Handle invalid input
    if (n < 0) {
        printf("Factorial not defined for negative numbers.\n");
        return 0;
    }

    printf("\nChoose method:\n");
    printf("1. Iterative\n");
    printf("2. Recursive\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        result = factorialIterative(n);
        printf("Factorial (Iterative) = %lld\n", result);
    }
    else if (choice == 2) {
        result = factorialRecursive(n);
        printf("Factorial (Recursive) = %lld\n", result);
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
