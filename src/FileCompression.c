#include "../includes/FileCompression.h"

#if defined(__unix__) || defined(__APPLE__)
    const int is_unix = 1;
#else
    const int is_unix = 0;
#endif

int main() {
    if (is_unix)
        system("clear");
    else
        system("cls");

    printf("Welcome to the file compression program!\n");

    while (1) {
        int action = promptMenu();
        if (action == 1) { // Compress a file
            fileCompression();
        }
        else if (action == 2) { // Decompress a file

        }
        else { // Exit program
            printf("\nGoodbye!!!\n");
            exit(EXIT_SUCCESS);
        }
    }
}

int promptMenu() {
    while (1) {
        printf("\nMenu:\n");
        printf("1. Compress a file.\n2. Decompress a file.\n3. Exit program\n\nAction (enter the number): ");

        char input[10];
        int action;
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%d", &action) != 1) {
            printf("\nDidn't provide a number :( - Try again.\n");
            sleep(2);
            continue;
        }

        if (action < 1 || action > 3) {
            printf("\nDidn't provide a valid action :( - Try again.\n");
            sleep(2);
            continue;
        }

        return action;
    }
}

void fileCompression() {
    // Get file to compress
    printf("\nEnter a file to compress: ");
    char file_name[100];
    fgets(file_name, sizeof(file_name), stdin);
    file_name[strlen(file_name) - 1] = '\0';

    // Open file pointer to read
    FILE *fptr = fopen(file_name, "r");
    if (fptr == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Build frequency table
    Freq_Table *freq_table = buildFreqTable(fptr);
    fclose(fptr);
    if (freq_table == NULL) {
        printf("Provided empty file...\n");
        return;
    }

    // Build Huffman tree
    HuffmanNode *tree = buildHuffmanTree(freq_table);
    free(freq_table);

    // TODO Generate Huffman codes
    
    // TODO Encode file
    // TODO Padding
    // TODO Write compressed file
}