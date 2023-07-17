#include <stdlib.h>
#include <stdio.h>

#ifndef FILECOMPRESSION_FREQUENCYTABLE_H
#define FILECOMPRESSION_FREQUENCYTABLE_H

extern int table_size;

typedef struct {
    char character;
    int freq;
} Freq_Table;

Freq_Table* buildFreqTable(FILE*);

#endif