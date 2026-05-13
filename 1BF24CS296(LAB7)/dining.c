#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t chopstick[N];

void *philosopher(void *num)
{
    int id = *(int *)num;

    while(1)
    {
        // Thinking
        printf("Philosopher %d is THINKING\n", id);
        sleep(1);

        // Pick chopsticks
        printf("Philosopher %d wants to EAT\n", id);

        pthread_mutex_lock(&chopstick[id]);
        printf("Philosopher %d picked LEFT chopstick %d\n", id, id);

        pthread_mutex_lock(&chopstick[(id + 1) % N]);
        printf("Philosopher %d picked RIGHT chopstick %d\n",
               id, (id + 1) % N);

        // Eating
        printf("Philosopher %d is EATING\n", id);
        sleep(2);

        // Release chopsticks
        pthread_mutex_unlock(&chopstick[id]);
        pthread_mutex_unlock(&chopstick[(id + 1) % N]);

        printf("Philosopher %d released chopsticks\n", id);
    }
}

int main()
{
    pthread_t p[N];
    int id[N];

    // Initialize mutexes
    for(int i = 0; i < N; i++)
    {
        pthread_mutex_init(&chopstick[i], NULL);
    }

    // Create philosopher threads
    for(int i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&p[i], NULL, philosopher, &id[i]);
    }

    // Join threads
    for(int i = 0; i < N; i++)
    {
        pthread_join(p[i], NULL);
    }

    // Destroy mutexes
    for(int i = 0; i < N; i++)
    {
        pthread_mutex_destroy(&chopstick[i]);
    }

    return 0;
}
