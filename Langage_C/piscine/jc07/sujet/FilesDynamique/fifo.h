typedef struct list
{
    int elt;
    struct list *next;
}s_list;

typedef struct fifo
 {
    int  size;
    s_list     *tail;
    s_list     *head;
 }s_fifo;
 
void push(s_fifo *fifo, int element);
int size(s_fifo *fifo);
int is_empty(s_fifo *fifo);
s_fifo *init_fifo(void);
void  print(s_fifo *fifo);
void pop(s_fifo *fifo);
int head(s_fifo *fifo);
void clear(s_fifo *fifo);
void destroy(s_fifo *fifo);