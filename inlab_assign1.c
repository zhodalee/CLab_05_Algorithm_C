/******************************************************************************

HANDS-ON LAB #5: Data Structures and Algorithm
In-lab Assignment #1

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint8_t * const buffer;
    int head;
    int tail;
    const int maxlen;
} ring_bbuf_t;

int pushMethod(ring_bbuf_t *bfr, uint8_t data) {
    int cntr;
    
    cntr = bfr->head + 1;
    if (cntr >= bfr->maxlen) {
        cntr = 0;
    }
    if (cntr == bfr->tail) {
        return -1;
    }
    
    bfr->buffer[bfr->head] = data;
    bfr->head = cntr;
    
    return 0;
}

int popMethod(ring_bbuf_t *bfr, uint8_t *data) {
    int cntr;
    
    if (bfr->head == bfr->tail) {
        return -1;
    }
    cntr = bfr->tail + 1;
    if (cntr >= bfr->maxlen) {
        cntr = 0;
    }
    
    *data = bfr->buffer[bfr->tail];
    bfr->tail = cntr;
    
    return 0;
}

void printMethod(ring_bbuf_t *bfr) {
    // Only size-1 is used. 1 is reserved space.
    for (int i = 0; i < bfr->maxlen-1; i++)
    {
        printf("buffer[%d] = %d\t\t", i, bfr->buffer[i]);
    }
    printf("\n");
}

int main()
{
    const int cbfr_size = 3; // Only size-1 is used. 1 is reserved space.
    uint8_t data[cbfr_size]; 
    //uint8_t data[] = { 11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
    //uint8_t data[] = { 10,11,12,13,14,15,16,17 };
    int cbfr_head = 0;
    int cbfr_tail = 0;
    
    uint8_t pop_data = 0;
    uint8_t push_data = 88;
    
    /* Initialize Ring Buffer */
    ring_bbuf_t c_bfr = {
        &data[0],
        cbfr_head,
        cbfr_tail,
        cbfr_size
    };
    printf("Before push:\n");
    printMethod(&c_bfr);
    /*---------------------------------*/
    if (pushMethod(&c_bfr, push_data)) {
        printf("Out of space in ring buffer.\n");
        return -1;
    }
    printf("\n");
    printf("After push:\n");
    printMethod(&c_bfr);
    
    /*---------------------------------*/
    if (popMethod(&c_bfr, &pop_data)) {
        printf("Ring buffer is empty.\n");
        return -1;
    }
    
    /*---------------------------------*/
    printf("\n");
    printf("Push data:\t%d\n", push_data);
    printf("Pop data:\t%d\n", pop_data);

    return 0;
}
