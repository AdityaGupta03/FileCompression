#include "../includes/HuffmanTree.h"

PriorityQueue *createPriorityQueue(int capacity) {
  if (capacity < 1) {
    fprintf(stderr, "Capacity must be greater than 0\n");
    return NULL;
  }

  PriorityQueue *queue = (PriorityQueue *)malloc(sizeof(PriorityQueue));

  if (queue == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  queue->size = 0;
  queue->capacity = capacity;
  queue->nodes =
      (HuffmanNode **)malloc(queue->capacity * sizeof(HuffmanNode *));

  if (queue->nodes == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  return queue;
}

void destroyPriorityQueue(PriorityQueue *queue) {
  free(queue->nodes);
  free(queue);
}

void enqueue(PriorityQueue *queue, HuffmanNode *node) {
  if (queue->size == queue->capacity) {
    queue->capacity *= 2;
    queue->nodes = (HuffmanNode **)realloc(
        queue->nodes, queue->capacity * sizeof(HuffmanNode *));

    if (queue->nodes == NULL) {
      perror("realloc");
      exit(EXIT_FAILURE);
    }
  }

  queue->nodes[queue->size] = node;
  queue->size++;
  heapifyUp(queue, queue->size - 1);
}

HuffmanNode *pop(PriorityQueue *queue) {
  if (queue->size == 0) {
    return NULL;
  }

  HuffmanNode *node = queue->nodes[0];
  queue->nodes[0] = queue->nodes[queue->size - 1];
  queue->size--;
  heapifyDown(queue, 0);
  return node;
}

void heapifyUp(PriorityQueue *queue, int index) {
  if (index == 0) {
    return;
  }

  int parent = (index - 1) / 2;

  if (queue->nodes[index]->freq < queue->nodes[parent]->freq) {
    swap(queue, index, parent);
    heapifyUp(queue, parent);
  }
}

void heapifyDown(PriorityQueue *queue, int index) {
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  int smallest = index;

  if (left < queue->size &&
      queue->nodes[left]->freq < queue->nodes[smallest]->freq) {
    smallest = left;
  }

  if (right < queue->size &&
      queue->nodes[right]->freq < queue->nodes[smallest]->freq) {
    smallest = right;
  }

  if (smallest != index) {
    swap(queue, index, smallest);
    heapifyDown(queue, smallest);
  }
}

void swap(PriorityQueue *queue, int index1, int index2) {
  HuffmanNode *temp = queue->nodes[index1];
  queue->nodes[index1] = queue->nodes[index2];
  queue->nodes[index2] = temp;
}
