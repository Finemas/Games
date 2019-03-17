/* game guess the animal */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct TNode {
    char text[MAX];
    struct  TNode *yes, *no;
} TNODE;

TNODE *createNode(const char * text, TNODE *yes, TNODE *no) {
    TNODE *n = (TNODE*)malloc(sizeof(*n));
    strncpy(n->text, text, sizeof(n->text));
    n->yes = yes;
    n->no  = no;
    return n;
}

int isLeaf(TNODE *n) {
    return n->yes == NULL && n->no == NULL;
}

TNODE *initTree(void) {
    return createNode("Does it fly?",
                      createNode("bird", NULL, NULL),
                      createNode("fish", NULL, NULL)
    );
}

/** get whole input line
  * txt [out] read line without '\n'
  * max [in] length of txt
*/
void readLine(char * txt, int max) {
    int len;
    fgets(txt, max, stdin);
    len = strlen(txt);
    if (txt[len-1] == '\n')
        txt[len-1] = 0;
    else
        while (fgetc(stdin) != '\n') {}
}

#define MAXA 8

/** read answer - "yes", all other means "no" */
int positiveAns() {
    char ans[MAXA];
    readLine(ans, MAXA);
    return !strcasecmp(ans, "yes"); /* case insensitive string comparison */
}

void updateKnowledge(TNODE *p) {
    char newAnim[MAX], newQue[MAX];
    printf("Oh, I failed. Please update my knowledge base:\n" );
    printf("What is the animal?\n");
    readLine(newAnim, MAX);
    printf("What shall I ask to distinguish a %s and a %s?\n",
           newAnim, p->text);
    readLine(newQue, MAX);
    printf("Which answer applies to the %s?\n", newAnim);
    if (positiveAns()) {
        p->yes = createNode (newAnim, NULL, NULL);
        p->no  = createNode (p->text, NULL, NULL);
    }
    else {
        p->no  = createNode (newAnim, NULL, NULL);
        p->yes = createNode (p->text, NULL, NULL);
    }
    strncpy( p->text, newQue, sizeof(p->text));
}

/** free used dynamic memory recursively */
void deleteTree(TNODE * n) {
    if (! n)
        return;
    deleteTree(n->yes);
    deleteTree(n->no);
    free(n);
}

int main() {
    TNODE *root = initTree();
    for (;;) {
        TNODE *node = root;
        printf("Choose an animal. I will guess it.\n");
        while(! isLeaf(node)) {
            printf("%s\n", node->text);
            if (positiveAns())
                node = node->yes;
            else
                node = node->no;
        }
        printf("Is it %s?\n", node->text);
        if (! positiveAns())
            updateKnowledge(node);
        printf("Continue?\n");
        if (! positiveAns())
            break;
    }
    deleteTree(root);
    return EXIT_SUCCESS;
}

