#include "../includes/FrequencyTable.h"

int table_size = 0;

Freq_Table *buildFreqTable(FILE *fptr) {

  printf("\nBuilding frequency table...\n");

  table_size = 100;
  Freq_Table *freq_table = malloc(table_size * sizeof(Freq_Table));
  int num_found = 0;
  char read;
  while ((read = fgetc(fptr)) != EOF)
  {
    int found = 0;
    for (int i = 0; i < table_size; i++)
    {
      if (freq_table[i].character == read)
      {
        found = 1;
        freq_table[i].freq++;
        break;
      }
    }

    if (!found)
    {
      if (num_found >= table_size)
      {
        table_size += 10;
        freq_table = realloc(freq_table, table_size * sizeof(Freq_Table));
        if (freq_table == NULL)
        {
          perror("realloc");
          exit(EXIT_FAILURE);
        }
      }
      freq_table[num_found].character = read;
      freq_table[num_found].freq = 1;
      num_found++;
    }
  }

  Freq_Table *tmp = freq_table + num_found;
  free(tmp);

  table_size = num_found;
  return (table_size != 0) ? freq_table : NULL;

}