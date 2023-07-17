#include "../includes/FrequencyTable.h"

int table_size = 0;

Freq_Table* buildFreqTable(FILE *fptr) {

    printf("\nBuilding frequency table...\n");

    Freq_Table *freq_table = NULL;
    char read;
    while ((read = fgetc(fptr)) != EOF) {
        int found = 0;
        for (int i = 0; i < table_size; i++) {
            if (freq_table[i].character == read) {
                found = 1;
                freq_table[i].freq++;
                break;
            }
        }

        if (!found) {
            table_size++;
            freq_table = realloc(freq_table, table_size * sizeof(Freq_Table));
            if (freq_table == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }

            freq_table[table_size - 1].character = read;
            freq_table[table_size - 1].freq = 1;
        }
    }

    return (table_size != 0) ? freq_table : NULL;

}