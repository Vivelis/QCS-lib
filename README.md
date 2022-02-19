# stacks-queues
Code for easy startup with queues and stacks in C

## doc :
[documentation](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/19868-les-piles-et-les-files)

## Stack :
```c
// my_stack.c
```
```c
void put_on_stack(my_stack_t *stack, char *content);
```
```c
my_stack_t *init_stack(void);
```
```c
void free_stack(my_stack_t *stack);
```

## Queue :
```c
// my_queue.c
```
```c
int put_on_queue(my_queue_t *queue, void *content);
```
```c
void *put_out_queue(my_queue_t *queue);
```
```c
my_queue_t *init_queue(void);
```
```c
void free_queue(my_queue_t *queue);
```