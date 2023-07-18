#include <stdio.h>

#define SIZE 10

int search(int H[], int key);
int hash(int key);
int nearestPrime();
int primeHash(int key);
int dhash(int H[], int key);
void insert(int H[], int key);

int search(int H[], int key) {
    int index = hash(key);
    int i = 0;

    while (H[(index + i * primeHash(index)) % SIZE] != key) {
        i++;
        if (H[(index + i * primeHash(index)) % SIZE] == 0)
            return -1;
    }

    return (index + i * primeHash(index)) % SIZE;
}

int hash(int key) {
    return key % SIZE;
}

int nearestPrime() {
    int i, j, isPrime;

    for (i = SIZE; i >= 2; i--)
        {
        isPrime = 1;

        for (j = 2; j < i; j++)
            {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
         }
        if (isPrime)
            return i;
    }

    return 2;  // If no prime is found, return 2 as the default value
}

int primeHash(int key) {
    return nearestPrime() - (key % SIZE);
}

int dhash(int H[], int key) {
    int index = hash(key);
    int i = 0;

    while (H[(index + i * primeHash(index)) % SIZE] != 0) {
        i++;
    }

    return (index + i * primeHash(index)) % SIZE;
}

void insert(int H[], int key) {
    int index = hash(key);

    if (H[index] != 0) {
        index = dhash(H, key);
    }

    H[index] = key;
}

int main() {
    int HT[SIZE] = {0}, n, x;

    printf("Hash Table before insertion: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", HT[i]);
    }
    printf("\n");

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the element: ");
        scanf("%d", &x);
        insert(HT, x);
    }

    printf("Hash Table after insertion: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", HT[i]);
    }

    return 0;
}
