#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char** argv) {
    int32_t canari = 2;
    char buf[BUF_SIZE];


    printf("sizeof(buffer) : %ld - @argc : %p - @canari : %p - @buf : %p\n",
           sizeof(buf), &argc, &canari, buf);
    printf("@buf[0] : %p - @buf[%d] %p\n",&buf[0],BUF_SIZE-1,&buf[BUF_SIZE-1]);
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <str>\n", argv[0]);
        exit(1);
    }
    
    printf("Before formating: canari: [%p] = %d\n", &canari, canari);

    strncpy(buf, argv[1], sizeof(buf));
    // There a user is able to read/write the stack, for example the canary
    // "canari"
    printf("%s\n",argv[1]);
    printf(argv[1]);
    printf("\n");

    printf("After formating: canari: [%p] = %d\n", &canari, canari);

    return (0);
}