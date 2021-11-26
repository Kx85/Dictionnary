typedef struct word {
    const char* key;
    int value;

} word;

typedef struct dictionnary {
    int len;
    int cap;
    word* w;
} dictionnary, *p_dictionnary;


void dictionnaryUsage();
int readDicFile(p_dictionnary d, char* s_dicFile);

p_dictionnary createNewDictionnary();
void freeDictionnary(p_dictionnary d);

int findWord(p_dictionnary d, const char* key);
void addWord (p_dictionnary d, const char* key, int value);
void updateWord(p_dictionnary d, const char* key, int value);
void incWordValue(p_dictionnary d, const char* key);

void displayDictionnary(p_dictionnary d);
