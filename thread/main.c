#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

const int stock_init = 20;

typedef struct store
{
    int stock;
    pthread_t thread_store;
    pthread_t *thread_client;
    pthread_mutex_t mutex_stock;
    pthread_cond_t cond_stock;
    pthread_cond_t cond_client;
} store_t;

typedef struct client
{
    struct client *next;
    char *state;
} s_client;

struct store *store;
struct client *client;

void *checkst(void *arg)
{
    s_client *tmp;
    while (1)
    {
        tmp = client;

        while (tmp != NULL)
        {
            if (tmp->state = "wait")
            {
                tmp->state = "Unwait";
                pthread_cond_signal(&store->cond_stock);
            }
            tmp = tmp->next;
        }
    }
    return (0);
}

int generation(int max)
{
    return ((rand() % max) + 1);
}

void *fthreadRestock(void *arg)
{
    printf("thread stock\n");
    while (1)
    {
        pthread_mutex_lock(&store->mutex_stock);
        pthread_cond_wait(&store->cond_stock, &store->mutex_stock);
        printf("Remplissage du stock \n");
        store->stock = stock_init;
        pthread_cond_signal(&store->cond_client);
        pthread_mutex_unlock(&store->mutex_stock);
    }
    return (0);
}

void *fthreadClient(void *arg)
{
    printf("thread client\n");
    int numeroclient = (int)arg;
    int achat;
    int nombreachat;
    int i = 0;
    s_client *newclient;
    s_client *tmp;
    tmp = client;
    newclient = malloc(sizeof(s_client));
    if (tmp == NULL)
    {
        tmp = newclient;
    }
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newclient;
    }
    nombreachat = generation(5);
    while (i < nombreachat)
    {
        achat = generation(10);
        pthread_mutex_lock(&store->mutex_stock);
        if (store->stock < achat)
        {
            newclient->state = "wait";
            printf("Client %d en etat %s\n",numeroclient,newclient->state);
            pthread_cond_wait(&store->cond_client, &store->mutex_stock);
            printf("client %d Unwait\n", numeroclient);
        }
        store->stock = store->stock - achat;
        printf("Le client %d effectue son %d achat sur %d il prend %d au stock\n", numeroclient, i + 1, nombreachat, achat);
        printf("stock restant %d\n", store->stock);
        i++;
        pthread_mutex_unlock(&store->mutex_stock);
    }
    return (0);
}

int main(int argc, char **argv)
{
    int i = 0;
    int CR = 0;
    void *nclient = 0;
    store = malloc(sizeof(store_t));
    store->thread_client = malloc(sizeof(pthread_t));
    store->stock = 0;
    client = malloc(sizeof(s_client));
    pthread_mutex_init(&store->mutex_stock, NULL);
    pthread_cond_init(&store->cond_client, NULL);
    pthread_cond_init(&store->cond_stock, NULL);
    CR = pthread_create(&store->thread_store, NULL, fthreadRestock, NULL);
    pthread_t checkstate;
    pthread_create(&checkstate, NULL, checkst, NULL);
    if (!CR)
    {
        while (i < 3)
        {
            nclient++;
            pthread_t clienthread;
            pthread_create(&clienthread, NULL, fthreadClient, nclient);
            store->thread_client[i] = clienthread;
            i++;
        }
        i = 0;
        while (i < 3)
        {
            pthread_join(store->thread_client[i], 0);
            i++;
        }
        pthread_join(store->thread_store, NULL);
    }
    return (0);
}