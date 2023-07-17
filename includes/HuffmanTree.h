#include "FrequencyTable.h"

#ifndef FILECOMPRESSION_HUFFMANTREE_H
#define FILECOMPRESSION_HUFFMANTREE_H

typedef struct {
    char character;
    int freq;
    struct Huffman_Node *left;
    struct Huffman_Node *right;
} Huffman_Node;

Huffman_Node *buildHuffmanTree(Freq_Table*);

#endif