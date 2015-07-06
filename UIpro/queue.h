
#pragma  once

#ifdef EXTERN
	#undef EXTERN
	#define EXTERN  extern
#else
	#define EXTERN 
#endif

#define QUEUE_SIZE 512	//the maximum length of Queue Buffer is 255!

typedef struct _Queue
{
	unsigned char Buffer[QUEUE_SIZE];   
	unsigned short Index_in;      //queue head index
	unsigned short Index_out;     //queue tail index
}Queue;


EXTERN unsigned char IsQueueEmpty(Queue *pQueue);

EXTERN unsigned char QueueInsert(Queue *pQueue,const unsigned char c);

EXTERN unsigned char QueueInsertEx(Queue *pQueue,const unsigned char *pSrc,unsigned char Size);

EXTERN unsigned char QueueExtract(Queue *pQueue);

EXTERN void SwapString(unsigned char *pSrc,unsigned char len);

EXTERN unsigned int strlenDiy(const unsigned char *pSrc);

