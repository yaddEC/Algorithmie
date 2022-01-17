#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dataset.h"

// Complexité de l'algorithme: O(n)
PokemonDef searchPokemonByName(const char* name)
{
    int i=0;
    PokemonDef temp = datasetGetValueAt(i);
    while(strcmp(name,temp.PokemonName)!=0)
    {
    if(i>datasetGetCount()+1)
    {
        return (PokemonDef){0};
    }
    i++;
    temp = datasetGetValueAt(i);
    }
    return temp;
}

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

    if (verifySearchFunction(searchPokemonByName, iterations) != 1)
        fprintf(stderr, "\e[31mFailure\e[0m\n");

    // Shutdown
    datasetDestroy();

    return 0;
}