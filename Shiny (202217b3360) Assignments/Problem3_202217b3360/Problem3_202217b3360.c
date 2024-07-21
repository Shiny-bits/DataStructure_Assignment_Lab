#include <stdio.h>

void push(void);
void pop(void);
void display(void);

int stack[100], choice, n, top = -1, x, i;

int main() {
    printf("\nEnter the size of STACK [MAX=100]: ");
    scanf("%d", &n);
    printf("\n\tSTACK OPERATIONS USING ARRAY");
    printf("\n\t----------------------------");
    printf("\n\t1. PUSH\n\t2. POP\n\t3. DISPLAY\n\t4. EXIT");
    do {
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\tEXITING PROGRAM\n");
                break;
            default:
                printf("\n\tPlease Enter a Valid Choice (1/2/3/4)");
        }
    } while (choice != 4);
    return 0;
}

void push() {
    if (top >= n - 1) {
        printf("\n\tSTACK is Overflow");
    } else {
        printf("Enter a value to be pushed: ");
        scanf("%d", &x);
        stack[++top] = x;
    }
}

void pop() {
    if (top < 0) {
        printf("\n\tStack is Underflow");
    } else {
        printf("\n\tThe popped element is %d", stack[top--]);
    }
}

void display() {
    if (top >= 0) {
        printf("\nThe elements in STACK:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    } else {
        printf("\nThe STACK is empty");
    }
}
