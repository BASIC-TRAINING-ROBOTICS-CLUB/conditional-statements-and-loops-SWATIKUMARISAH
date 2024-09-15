#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
int AND(int a, int b);
int OR(int a, int b);
int NOT(int a);
void replace_variables(char* expression, int values[]);
int evaluate_expression(char* expression);

int main() {
    char expression[100];   // String to store the expression
    int values[3];          // Array to store the values of A, B, and C

    // Input the logic expression
    printf("Enter a logical expression (e.g., (A AND B) OR (NOT C)): ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0;  // Remove the newline character

    // Input values for A, B, C
    printf("Enter value for A (1 for True, 0 for False): ");
    scanf("%d", &values[0]);

    printf("Enter value for B (1 for True, 0 for False): ");
    scanf("%d", &values[1]);

    printf("Enter value for C (1 for True, 0 for False): ");
    scanf("%d", &values[2]);

    // Replace variables A, B, C with their corresponding values
    replace_variables(expression, values);

    // Evaluate the expression
    int result = evaluate_expression(expression);
    
    // Output the result
    if (result != -1)
        printf("The result of the expression is: %d\n", result);
    else
        printf("Invalid expression!\n");

    return 0;
}

// Logical AND operation
int AND(int a, int b) {
    return a && b;
}

// Logical OR operation
int OR(int a, int b) {
    return a || b;
}

// Logical NOT operation
int NOT(int a) {
    return !a;
}

// Function to replace variables A, B, C in the expression with their values
void replace_variables(char* expression, int values[]) {
    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == 'A') {
            expression[i] = values[0] + '0';  // Replace A with its value
        } else if (expression[i] == 'B') {
            expression[i] = values[1] + '0';  // Replace B with its value
        } else if (expression[i] == 'C') {
            expression[i] = values[2] + '0';  // Replace C with its value
        }
    }
}

// Function to evaluate the logical expression
int evaluate_expression(char* expression) {
    // Temporary stack to store results
    int stack[100], top = -1;
    char *token;

    // Tokenize the expression by space
    token = strtok(expression, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            // Push values (0 or 1) to the stack
            stack[++top] = token[0] - '0';
        } else if (strcmp(token, "AND") == 0) {
            // Perform AND operation
            if (top < 1) return -1; // Invalid expression
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = AND(a, b);
        } else if (strcmp(token, "OR") == 0) {
            // Perform OR operation
            if (top < 1) return -1; // Invalid expression
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = OR(a, b);
        } else if (strcmp(token, "NOT") == 0) {
            // Perform NOT operation
            if (top < 0) return -1; // Invalid expression
            int a = stack[top--];
            stack[++top] = NOT(a);
        } else {
            return -1; // Invalid token
        }
        token = strtok(NULL, " ");
    }

    // The final result should be at the top of the stack
    if (top == 0)
        return stack[top];
    else
        return -1; // Invalid expression
}
