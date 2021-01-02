#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
typedef struct WordNode
{
    char *word;
    int count;
    struct WordNode *next;
    int alphabetical;
} words;

words *createWordNode (char *in)
{
    words *newWordNode = malloc (sizeof (words));
    if (NULL != newWordNode) {
        newWordNode->word = (char *) malloc ((strlen (in)) + 1);
        strcpy (newWordNode->word, in);
        newWordNode->word[strlen (in)] = '\0';
        newWordNode->count = 1;
        newWordNode->alphabetical = (int) *in;
        newWordNode->next = NULL;
    }
    return newWordNode;
}

void sortList(struct WordNode *wordListHead) {
    int swapped, i; 
    struct WordNode *ptr1; 
    struct WordNode *lptr = NULL; 
  
    if (wordListHead == NULL) 
        return; 
    do
    { 
        swapped = 0; 
        ptr1 = wordListHead; 
        while (ptr1->next != lptr) 
        { 
            if (ptr1->alphabetical > ptr1->next->alphabetical) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped);
}

void swap(struct WordNode *a, struct WordNode *b) 
{ 
    char *wordtmp = a->word;
    int counttmp = a->count;
    int alphabeticaltmp = a->alphabetical; 
    a->word = b->word; 
    b->word = wordtmp; 
    a->count = b->count;
    b->count = counttmp;
    a->alphabetical = b-> alphabetical;
    b->alphabetical = alphabeticaltmp;
} 

words *addWord (char *in, words **wordListHead)
{
    /* handle EMPTY list */
    if (!*wordListHead) {
        return *wordListHead = createWordNode (in);
    }

    words *temp = *wordListHead;

    // search if word already exist, if so, add
    while (temp->next != NULL) {
        if (strcmp (temp->word, in) == 0) {
            temp->count += 1;
            return *wordListHead;
        }
        else
            temp = temp->next;
    }
    words *newWord = createWordNode (in);
    // insert at tail
    if (NULL != newWord) {
        temp->next = newWord; 
    }
    return newWord;
}

void printWordList (struct WordNode *wordListHead) {
    while (wordListHead != NULL) {
        printf ("%s %d \n", wordListHead->word, wordListHead->count);
        wordListHead = wordListHead->next;
    }
}

int main (int argc, char *argv[]) {

    words *mywords = NULL;
    char *delim = " \t\n,:;'\".?!#$-><(){}[]|\\/*&^%@!~+=_";

    FILE *input;

    char *filename = argv[1];

    if (argc < 2) {
        fprintf (stderr, "Usage: %s article.txt\n",
                argv[0]);
        return 1;
    }

    int character = 0, k = 0;
    bool isWord = true;
    char thisword[100];
    int totalFiles = argc - 1;
    while (totalFiles != 0) {
        input = fopen (argv[totalFiles], "r");
        while ((character = fgetc (input)) != EOF) {
            if (strchr (delim, character)) {
                if (isWord == true) {
                    isWord = false;
                    thisword[k] = '\0';
                    addWord (thisword, &mywords);
                    k = 0;
                }
            } else { 
                isWord = true;
                thisword[k++] = tolower (character);
            }
        }
        totalFiles -= 1;
    }

    sortList(mywords);
    printWordList(mywords);

    return 0;
}

