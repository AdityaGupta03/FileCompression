#include "../includes/HuffmanTree.h"

HuffmanNode *buildHuffmanTree(Freq_Table *freq_table) {
  printf("\nBuilding Huffman tree...\n");

  // Create a priority queue
  PriorityQueue *pq = createPriorityQueue(table_size);

  // Add all characters to the priority queue
  for (int i = 0; i < table_size; i++) {
    HuffmanNode *node = createHuffmanNode(freq_table[i].character, freq_table[i].freq);
    enqueue(pq, node);
  }

  // Build the Huffman tree
  while (pq->size > 1) {
    HuffmanNode *left = dequeue(pq);
    HuffmanNode *right = dequeue(pq);
    HuffmanNode *parent = createHuffmanNode('\0', left->freq + right->freq);
    parent->left = left;
    parent->right = right;
    enqueue(pq, parent);
  }

  // Get the head of the Huffman tree
  HuffmanNode *head = pop(pq);
  destroyPriorityQueue(pq);

  return head;
}

HuffmanNode *createHuffmanNode(char character, int freq) {
  HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
  node->character = character;
  node->freq = freq;
  node->left = NULL;
  node->right = NULL;
  return node;
}