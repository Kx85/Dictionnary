// Dictionnary.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "common.h"
#include "dictionnary.h"

char* getInput() {
    unsigned int len_max = __MAX_INPUT_SIZE__;
    unsigned int current_size = len_max;
    char* pStr = malloc(len_max);

    printf("Enter commande: \n");

    if (pStr != NULL)
    {
        int c = EOF;
        unsigned int i = 0;
        //accept user input until hit enter or end of file
        while ((c = getchar()) != '\n' && c != EOF)
        {
            pStr[i++] = (char)c;

            //if i reached maximize size then realloc size
            if (i == current_size)
            {
                current_size = i + len_max;
                pStr = realloc(pStr, current_size);
            }
        }

        pStr[i] = '\0';

    }

    return pStr;
}

void processWordcountCommand(char* context) {
    dictionnary* d = createNewDictionnary();
    char* ptr = NULL;
    char seps[] = " \n";
    int wordCount = 0;
    int error = 0;

    ptr = strtok_s(NULL, seps, &context);
    if (ptr == NULL) {
        dictionnaryUsage();
        return;
    }

    error = readDicFile(d, ptr);
    if (error != 0) {
        dictionnaryUsage();
        return;
    }

    ptr = strtok_s(NULL, seps, &context);
    if (ptr == NULL) {
        dictionnaryUsage();
        return;
    }

    while (ptr != NULL) {
        wordCount++;
        incWordValue(d, ptr);
        ptr = strtok_s(NULL, seps, &context);
    }

    displayDictionnary(d);
    printf("%i total word(s)\n\n", wordCount);
    freeDictionnary(d);
    //wordcount resources/dico.txt
}

int main()
{
    bool stopLoop = false;
    char *input,*context;

    while (!stopLoop) {

        input = getInput();
        char* ptr = strtok_s(input, " ", &context);

        if (ptr != NULL) {
            if (strcmp(ptr, __WORD_COUNT_COMMAND__) == 0) {
                processWordcountCommand(context);
            }
        }


    }
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.