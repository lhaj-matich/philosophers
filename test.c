#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define CORE_NUM 8

int j = 0;
pthread_mutex_t mutex;
    
void    *counter(void *args)
{
    pthread_mutex_lock(&mutex);
    while (j < 1000000)
    {
        printf("%d\n", j);
        j++;
    }
    pthread_mutex_unlock(&mutex);
    return (NULL);
}

int main(void)
{

    pthread_t *threadgroup;
    int i;

    i = 0;
    threadgroup = (pthread_t *)malloc(sizeof(pthread_t) * CORE_NUM);
    if (!threadgroup)
        return (0);
    pthread_mutex_init(&mutex, NULL);
    while (i < CORE_NUM)
    {
        pthread_create(&threadgroup[i],NULL, counter, NULL);
        i++;
    }
    i = 0;
    while (i < CORE_NUM)
    {
        pthread_join(threadgroup[i], NULL);
        i++;
    }
    return (0);
}