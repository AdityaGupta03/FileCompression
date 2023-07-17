#include "FileCompression.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {

    printf("Welcome to the file compression program!\n");
    while (1) {
        int action = prompt_menu();
        if (action == 1) {

        }
        else if (action == 2) {

        }
        else {
            printf("\nGoodbye!!!\n");
            exit(EXIT_SUCCESS);
        }
    }

}

int prompt_menu() {

    while (1) {
        printf("\nMenu:\n");
        printf("1. Compress a file.\n2. Decompress a file.\n3. Exit program\n\nAction: ");

        char input[10];
        int action;
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%d", &action) != 1) {
            printf("Didn't provide a number :( - Try again.\n");
            sleep(1);
            continue;
        }

        if (action < 1 || action > 3) {
            printf("Didn't provide a valid action :( - Try again.\n");
            sleep(1);
            continue;
        }

        return action;
    }

}