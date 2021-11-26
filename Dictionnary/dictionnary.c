#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "dictionnary.h"
#include "common.h"

void dictionnaryUsage()
{
	printf("ERREUR!\n");
}

int readDicFile(p_dictionnary d, char* s_dicFile)
{
	FILE* fp;
	char* buffer = (char*)malloc((__MAX_INPUT_SIZE__ + 1) * sizeof(char));
	char* filename = s_dicFile;
	char* key = NULL;
	char* end = NULL;


	errno_t errorCode = fopen_s(&fp, filename, "r");
	if (errorCode == 0)
	{
		printf("The file '%s' was opened\n", filename);
	}
	else
	{
		printf("The file '%s' was not opened\n", filename);
		return errorCode;
	}

	while (fgets(buffer, (__MAX_INPUT_SIZE__ + 1), fp)) {

		if (strlen(buffer) != 0) {
			key = (char*)malloc(strlen(buffer) + 1);
			strncpy_s(key, strlen(buffer) + 1, buffer, strlen(buffer));
			key[strcspn(key,  "\n")] = '\0';											// delete any newline fetched from fgets

			while (isspace((unsigned char)*key)) key++;									// Trim leading space

			char* ptr = strchr(key, '#');
			int index = ptr - key;

			if (*key != 0 && index != 0)												// All spaces or start with '#'?
				end = key + strlen(key) - 1;
				while (end > key && isspace((unsigned char)*end)) end--;				// Trim trailing space
				
				end[1] = '\0';															// Write new null terminator character
				addWord(d, key, 0);
		}
	}
	key = NULL;
	
	free(key);
	fclose(fp);

	return 0;
}

p_dictionnary createNewDictionnary()
{
	dictionnary d = { 0, 1, malloc(sizeof(word)) };
	p_dictionnary p_d = malloc(sizeof(dictionnary));
	*p_d = d;

	return p_d;
}

void freeDictionnary(p_dictionnary d)
{
	for (int i = 0; i < d->len; i++) {
		free(d->w[i].key);
	}
	free(d->w);
	free(d);
}

int findWord(p_dictionnary d, const char* key)
{
	for (int i = 0; i < d->len; i++) {
		if (strcmp(d->w[i].key, key) == 0) {
			return i;
		}
	}

	return -1;
}

void addWord(p_dictionnary d, const char* key, int value)
{

	if (d->len == d->cap) {
		d->cap *= 2;
		d->w = realloc(d->w, d->cap * sizeof(word));
	}

	d->w[d->len].key = _strdup(key);
	d->w[d->len].value = value;
	d->len++;
}

void updateWord(p_dictionnary d, const char* key, int value)
{
	int i = findWord(d, key);
	if (i != -1) {
		d->w[i].value = value;
	}
}

void incWordValue(p_dictionnary d, const char* key)
{
	int i = findWord(d, key);
	if (i != -1) {
		int value = d->w[i].value;
		updateWord(d, key, ++value);
	}
}

void displayDictionnary(p_dictionnary d)
{

	
	for (int i = 0; i < d->len; i++) {
		word w = d->w[i];
		if (w.value > 0)
			printf("%i %s\n", w.value, w.key);
	}
}
