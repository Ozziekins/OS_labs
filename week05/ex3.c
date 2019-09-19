#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define n 100000

int count = 0;
char buffer[n]; /* shared fixed-size buffer */
int producer_sleep = 0;
int consumer_sleep = 0;

void *producer(void *ptr)
{
  while(1)
  {
    while (producer_sleep) {
      if(consumer_sleep) {
        printf("RACE CONDITION!! EVERYONE ASLEEP! ZZZZ\n");
        exit(1);
      }
    }
    /* puts information into the buffer */
    buffer[count] = 'p';
    count = count + 1;
    if(count >= n)
      producer_sleep = 1;

    consumer_sleep = 0;
  }
}

void *consumer(void *ptr)
{
  while(1)
  {
    while(consumer_sleep) {
      if(producer_sleep) {
        printf("RACE CONDITION!! EVERYONE ASLEEP! ZZZZ\n");
        exit(1);
      }
    }

    /* takes information from the buffer */
    buffer[count] = 'c';
    count = count - 1;

    if(count <= 0)
      consumer_sleep = 1;

    producer_sleep = 0;
  }
}


int main()
{
  pthread_t thread_pid;
  pthread_t thread_cid;
  pthread_create(&thread_pid, NULL, producer, NULL);
  pthread_create(&thread_cid, NULL, consumer, NULL);

  pthread_join(thread_pid, NULL);
  pthread_join(thread_cid, NULL);

  return 0;
}