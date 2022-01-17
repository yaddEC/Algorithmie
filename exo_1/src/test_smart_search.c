#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dataset.h"

void swap(PokemonDef* a, PokemonDef* b)
{
    PokemonDef temp = *b;
    *b       = *a;
    *a       = temp;
}


int partition(PokemonDef *list, int first, int last) {
  

  PokemonDef comparator = list[last];
  int temp = (first - 1);
  for (int i = first; i < last; i++) {
    if (strcmp(list[i].PokemonName,comparator.PokemonName)<=0) {   
        
      temp++;
      swap(&list[temp], &list[i]);
    }
  }
  swap(&list[temp + 1], &list[last]);
  return (temp + 1);
}



// Complexité de l'algorithme: ...
PokemonDef searchPokemonByName(const char* name)
{
    int first = 0;
    int last = datasetGetCount();
    int j = last/2;
    int k=0;

    while(strcmp(name,datasetGetValueAt(j).PokemonName)!=0)
    {
        if(k>15)
        {
            return (PokemonDef){0};
        }
        if(strcmp(name,datasetGetValueAt(j).PokemonName)>0)
        {
        first =j;
        }
        else
        {
            last = j;
        }
        j=(first+last)/2;
        k++;
    }
  
    return datasetGetValueAt(j);
}

#if 0
int comparePkDef(const void* a, const void* b)
{
    return strcmp(((const PokemonDef*)a)->PokemonName, ((const PokemonDef*)b)->PokemonName);
}

void sortFunc(PokemonDef* array, int size)
{
    qsort(array, size, sizeof(PokemonDef), comparePkDef);
}
#else

void sort_list(PokemonDef* list, int first, int last) {
  if (first < last) {

    int current = partition(list, first, last);
    sort_list(list, first, current - 1);
    sort_list(list, current + 1, last);
  }
}

void sortFunc(PokemonDef* array, int size)
{
     // TODO: (Part 1) Implémentez la fonction (sans bubble sort!)
    int first = 0;
    int last = datasetGetCount()-1;
    sort_list(array,first,last);
    
   
}
#endif

int main(int argc, char* argv[])
{
    // Parse command line
    int maxEntries = -1;
    int iterations = 10000;
    {
        if (argc >= 2)
            maxEntries = atoi(argv[1]);
        if (argc >= 3)
            iterations = atoi(argv[2]);
    }

    // Init dataset
    datasetCreate(maxEntries);
    
    // Sort dataset
    datasetSort(sortFunc);

    if (verifySearchFunction(searchPokemonByName, iterations) != 1)
        fprintf(stderr, "\e[31mFailure\e[0m\n");

    // Shutdown
    datasetDestroy();

    return 0;
}
