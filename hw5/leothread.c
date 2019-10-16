#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int N;

typedef struct
{
    int Tnum;
    int level;
} node;

int leonardo_num(int x)
{
    if (x == 0 || x == 1)
        return 1;
    else
        return leonardo_num(x - 1) + leonardo_num(x - 2) + 1;
}

void *thread(void *vargp)
{
    node* m_node = (node*) vargp;
    node* children = malloc(sizeof(node) * 2);
    children[0].Tnum = m_node->Tnum + 1;
    children[0].level = m_node->level - 1;
    children[1].Tnum = leonardo_num(m_node->level - 1) + 1 + m_node->Tnum;
    children[1].level = m_node->level - 2;
    if (children[1].level == 0)
        children[1].level = 1;

    if (m_node->level > 1)
    {
        printf("(%d\n", m_node->Tnum);
        pthread_t tid[2];
        pthread_create(tid, NULL, thread, children);
        pthread_create(tid + 1, NULL, thread, children + 1);
        pthread_join(*(tid), NULL);
   	pthread_join(*(tid + 1), NULL);
        printf("%d)\n", m_node->Tnum);
    } else
    {
        printf("[%d]\n", m_node->Tnum);
    }

    free(children);
    return NULL;
}

int main(int argc, const char* argv[])
{
    N = atoi(argv[1]);
    node root;
    root.Tnum = 0;
    root.level = N;
    if (N >= 1)
        thread(&root);
    return 0;
}
