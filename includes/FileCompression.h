#ifndef FILECOMPRESSION_FILECOMPRESSION_H
#define FILECOMPRESSION_FILECOMPRESSION_H

const int is_unix;
int table_size = 0;

typedef struct {
    char character;
    int freq;
} Freq_Table;

typedef struct {
    char character;
    int freq;
    struct Huffman_Node *left;
    struct Huffman_Node *right;
} Huffman_Node;

int promptMenu();
void fileCompression();
Freq_Table* buildFreqTable(FILE*);
Huffman_Node *buildHuffmanTree(Freq_Table*);

#endif
