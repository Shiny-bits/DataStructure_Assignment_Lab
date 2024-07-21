#include <stdio.h>

#define MAX_NODE 15

char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};

int right_child(int index) {
    if (index > 0 && (2 * index + 1) <= MAX_NODE) 
        return 2 * index + 1; 
    return -1; 
}

int left_child(int index) { 
    if (index > 0 && (2 * index) <= MAX_NODE) 
        return 2 * index; 
    return -1; 
}

void preorder(int index) { 
    if (index > 0 && tree[index] != '\0') { 
        printf("%c ", tree[index]); 
        preorder(left_child(index)); 
        preorder(right_child(index)); 
    } 
}

void postorder(int index) { 
    if (index > 0 && tree[index] != '\0') { 
        postorder(left_child(index)); 
        postorder(right_child(index)); 
        printf("%c ", tree[index]); 
    } 
}

void inorder(int index) { 
    if (index > 0 && tree[index] != '\0') { 
        inorder(left_child(index)); 
        printf("%c ", tree[index]); 
        inorder(right_child(index)); 
    } 
}

int main() { 
    printf("Preorder:\n"); 
    preorder(1); 
    printf("\nPostorder:\n"); 
    postorder(1); 
    printf("\nInorder:\n"); 
    inorder(1); 
    printf("\n"); 
    
#ifdef _WIN32
    system("timeout /t 7 >nul");
#else
    system("sleep 7");
#endif
    return 0; 
}
