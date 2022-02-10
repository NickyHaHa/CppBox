#include <stdio.h>
#include <stdlib.h>

#define SUCCESS         0
#define ERR_BASE        0
#define ERR_DUPLICATE   ERR_BASE-1
#define ERR_NOT_FOUND   ERR_BASE-2
#define ERR_OUT_OF_MEM  ERR_BASE-3

struct dlist {
    int element;
    struct dlist *next, *prev;
};

struct dlist *g_head = NULL, *g_tail = NULL;

int add(int element)
{
    struct dlist *node = malloc(sizeof(struct dlist));
    if(node == NULL)return ERR_OUT_OF_MEM;

    node->element = element;

    // No head, so make new node be first and assign tail on it
    if(g_head == NULL)
    {
        node->next = NULL;
        node->prev = NULL;
        // printf(" %d ", node->element);
        g_head = node;
        g_tail = g_head;
    }

    // Else compare with node element and put it on right pos
    // And check if duplication occurred
    else
    {
        // Only one node
        if(g_head == g_tail)
        {
            if(g_head->element < node->element)
            {
                g_head->next = node;
                node->prev = g_head;
                node->next = NULL;
                g_tail = node;
            }
            else if(g_head->element == element)
            {
                free(node);
                return ERR_DUPLICATE;
            }
            else
            {
                node->prev = NULL;
                node->next = g_head;
                g_head->prev = node;
                g_head = node;
            }
        }
        else
        {
            // Insert before head
            if(g_head->element > node->element)
            {
                node->prev = NULL;
                node->next = g_head;
                g_head->prev = node;
                g_head = node;
            }

            // Insert in middle or after tail
            else
            {
                struct dlist *ptr;
                ptr = g_head;

                int isLast = 1;
                while(ptr)
                {
                    if(ptr->element == element)
                    {
                        free(node);
                        return ERR_DUPLICATE;
                    }
                    if(ptr->next)
                    {
                        if(ptr->element < node->element && node->element < ptr->next->element)
                        {
                            isLast = 0;
                            break;
                        }
                    }
                    ptr = ptr->next;
                }
                
                if(!isLast)
                {
                    node->prev = ptr;
                    node->next = ptr->next;
                    ptr->next->prev = node;
                    ptr->next = node;
                }
                else
                {
                    node->prev = g_tail;
                    node->next = NULL;
                    g_tail->next = node;
                    g_tail = node;
                }
            }
        }
    }
    return SUCCESS;
}

int del(int element)
{
    struct dlist *ptr;

    if(g_head == NULL)return ERR_NOT_FOUND;
    else if(g_head == g_tail)
    {
        if(g_head->element == element)
        {
            free(g_head);
            g_head = NULL;
            g_tail = NULL;
        }        
    }
    // Delete head or tail or middle 
    else if(g_head->element == element)
    {
        ptr = g_head;
        g_head->next->prev = NULL;
        g_head = g_head->next;
        free(ptr);
    }
    else if(g_tail->element == element)
    {
        ptr = g_tail;
        g_tail->prev->next = NULL;
        g_tail = g_tail->prev;
        free(ptr);
    }
    else
    {
        ptr = g_head;
        int isNotFound = 1;
        while(ptr)
        {
            if(ptr->element == element)
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(ptr);
                isNotFound = 0;
                break;
            }
            ptr = ptr->next;
        }

        if(isNotFound)return ERR_NOT_FOUND;
    }
    return SUCCESS;
}

void clean()
{
    struct dlist *ptr;
    while(g_head)
    {   
        ptr = g_head;
        g_head = g_head->next;
        free(ptr);
    }
    g_tail = g_head;
    printf("All memory release...\n");
}

void dump()
{
    struct dlist *ptr;
    ptr = g_head;

    if(ptr == NULL)
    {
        printf("Empty linked list...\n");
        return;
    }

    printf("From head:");
    while(ptr)
    {
        printf(" %d", ptr->element);
        ptr = ptr->next;
    }
    printf("\n");

    ptr = g_tail;
    printf("From tail:");
    while (ptr)
    {
        printf(" %d", ptr->element);
        ptr = ptr->prev;
    }
    printf("\n");
}

int main()
{
    if(add(3) == SUCCESS)printf("add 3: PASS\n");
    if(add(7) == SUCCESS)printf("add 7: PASS\n");
    if(add(5) == SUCCESS)printf("add 5: PASS\n");
    if(add(1) == SUCCESS)printf("add 1: PASS\n");
    if(add(9) == SUCCESS)printf("add 9: PASS\n");
    if(add(3) == ERR_DUPLICATE)printf("add 3: PASS\n");
    if(add(4) == SUCCESS)printf("add 4: PASS\n");
    if(add(5) == ERR_DUPLICATE)printf("add 5: PASS\n");
    if(add(6) == SUCCESS)printf("add 6: PASS\n");

    if(del(5) == SUCCESS)printf("del 5: PASS\n");
    if(del(3) == SUCCESS)printf("del 3: PASS\n");
    if(del(7) == SUCCESS)printf("del 7: PASS\n");

    dump();

    if(del(11) == ERR_NOT_FOUND)printf("del 11: PASS\n");
    if(del(7) == ERR_NOT_FOUND)printf("del 7: PASS\n");

    clean();
    dump();

    if(add(6) == SUCCESS)printf("add 6: PASS\n");

    dump();
    return 0;
}
