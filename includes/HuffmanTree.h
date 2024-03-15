#include "FrequencyTable.h"

#ifndef FILECOMPRESSION_HUFFMANTREE_H
#define FILECOMPRESSION_HUFFMANTREE_H

typedef struct {
    char character;
    int freq;
    struct Huffman_Node *left;
    struct Huffman_Node *right;
} HuffmanNode;

typedef struct {
  int size;
  int capacity;
  HuffmanNode **nodes;
} PriorityQueue;

PriorityQueue *createPriorityQueue();
void destroyPriorityQueue(PriorityQueue *queue);
void enqueue(PriorityQueue *queue, HuffmanNode *node);
HuffmanNode *pop(PriorityQueue *queue);
void heapifyUp(PriorityQueue *queue, int index);
void heapifyDown(PriorityQueue *queue, int index);
void swap(PriorityQueue *queue, int index1, int index2);
HuffmanNode *buildHuffmanTree(Freq_Table*);
HuffmanNode *createHuffmanNode(char, int);

#endif