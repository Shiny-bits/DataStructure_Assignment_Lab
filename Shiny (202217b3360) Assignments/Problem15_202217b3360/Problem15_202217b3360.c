#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char* key;
    char* value;
    struct node* next;
};

void initNode(struct node* n, char* k, char* v) {
    n->key = k;
    n->value = v;
    n->next = NULL;
}

struct hashMap {
    int size, capacity;
    struct node** table;
};

void createHashMap(struct hashMap* hm) {
    hm->capacity = 100;
    hm->size = 0;
    hm->table = (struct node**)malloc(sizeof(struct node*) * hm->capacity);
    for (int i = 0; i < hm->capacity; i++) {
        hm->table[i] = NULL;
    }
}

int computeHash(struct hashMap* hm, char* key) {
    int sum = 0;
    int multiplier = 31;
    for (int i = 0; i < strlen(key); i++) {
        sum = (sum * multiplier + key[i]) % hm->capacity;
    }
    return sum;
}

void add(struct hashMap* hm, char* key, char* value) {
    int index = computeHash(hm, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    initNode(newNode, key, value);

    if (hm->table[index] == NULL) {
        hm->table[index] = newNode;
    } else {
        newNode->next = hm->table[index];
        hm->table[index] = newNode;
    }
}

void removeNode(struct hashMap* hm, char* key) {
    int index = computeHash(hm, key);
    struct node* prev = NULL;
    struct node* curr = hm->table[index];

    while (curr != NULL) {
        if (strcmp(key, curr->key) == 0) {
            if (curr == hm->table[index]) {
                hm->table[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

char* find(struct hashMap* hm, char* key) {
    int index = computeHash(hm, key);
    struct node* bucket = hm->table[index];

    while (bucket != NULL) {
        if (strcmp(bucket->key, key) == 0) {
            return bucket->value;
        }
        bucket = bucket->next;
    }

    return "Oops! No data found.\n";
}

int main() {
    struct hashMap* hm = (struct hashMap*)malloc(sizeof(struct hashMap));
    createHashMap(hm);

    add(hm, "Yogaholic", "Anjali");
    add(hm, "pluto14", "Vartika");
    add(hm, "elite_Programmer", "Manish");
    add(hm, "GFG", "BITS");
    add(hm, "decentBoy", "Mayank");

    printf("%s\n", find(hm, "elite_Programmer"));
    printf("%s\n", find(hm, "Yogaholic"));
    printf("%s\n", find(hm, "pluto14"));
    printf("%s\n", find(hm, "decentBoy"));
    printf("%s\n", find(hm, "GFG"));
    printf("%s\n", find(hm, "randomKey"));

    printf("\nAfter deletion : \n");
    removeNode(hm, "decentBoy");
    printf("%s\n", find(hm, "decentBoy"));

    for (int i = 0; i < hm->capacity; i++) {
        struct node* current = hm->table[i];
        while (current != NULL) {
            struct node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hm->table);
    free(hm);

#ifdef _WIN32
    system("timeout /t 7 >nul");
#else
    system("sleep 7");
#endif
    return 0;
}
