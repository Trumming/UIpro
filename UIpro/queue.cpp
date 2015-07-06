/**
  ******************************************************************************
  * @file    queue.c
  * @author  Xu Chuanmin
  * @version V1.0
  * @date    15-06-2015
  * @brief   
  *         
  * @verbatim
*/

//extern void UartSendByte(unsigned char c);
//#define DebugInfoOutput(c)	{if(RET_INVALID != c)	UartSendByte(c);}	//the queue need to be send by polling or shorterrupt mode.
////DebugInfoOutput(QueueExtract())
#include "stdafx.h"
#include "queue.h"

#define RET_ERR		((unsigned char)1)
#define RET_SUCCESS ((unsigned char)0)

/*
 *@brief 
 *@param
 *@retval 
 *@note
*/
static unsigned char IsQueueHasEnoughFreeSize(Queue *pQueue,unsigned short size)
{
	unsigned char ret_val = RET_ERR;
	unsigned short FreeSize = 0;

	if(pQueue->Index_in >= pQueue->Index_out)
		FreeSize = QUEUE_SIZE - (pQueue->Index_in - pQueue->Index_out);
	else
		FreeSize = pQueue->Index_out - pQueue->Index_in;

	if(FreeSize > size)
		ret_val = RET_SUCCESS;

	return ret_val;
}
/*
 *@brief 
 *@param
 *@retval 
 *@note
*/
unsigned char IsQueueEmpty(Queue *pQueue)
{
	return (pQueue->Index_in == pQueue->Index_out) ? RET_SUCCESS:RET_ERR;
}
/*
 *@brief 
 *@param
 *@retval 
 *@note
*/
unsigned char QueueInsert(Queue *pQueue,const unsigned char c)
{
	unsigned char ret_val = RET_ERR;
	if(RET_SUCCESS == IsQueueHasEnoughFreeSize(pQueue,1))
	{
		pQueue->Buffer[pQueue->Index_in++] = c;

#if(QUEUE_SIZE != 255)
		if(QUEUE_SIZE < pQueue->Index_in)
			pQueue->Index_in = 0;
#endif	

		ret_val = RET_SUCCESS;
	}
	return ret_val;
}
/*
 *@brief 
 *@param
 *@retval 
 *@note
*/
unsigned char QueueInsertEx(Queue *pQueue,const unsigned char *pSrc,unsigned char Size)
{
	unsigned char i = 0, ret_val = RET_ERR;
	if(RET_SUCCESS == IsQueueHasEnoughFreeSize(pQueue,Size))
	{
		while(Size--)
		{
			pQueue->Buffer[pQueue->Index_in++] = *(pSrc + (i++));

#if(QUEUE_SIZE != 255)
			if(QUEUE_SIZE < pQueue->Index_in)
				pQueue->Index_in = 0;
#endif	
		}
		ret_val = RET_SUCCESS;
	}
	return ret_val;
}
/*
 *@brief 
 *@param
 *@retval 
 *@note
*/
unsigned char QueueExtract(Queue *pQueue)
{
	//unsigned char ret_val = RET_INVALID;
	//if(RET_ERR == IsQueueEmpty(pQueue))
	//{
		//ret_val = pQueue->Buffer[pQueue->Index_out++];
	unsigned char ret_val = pQueue->Buffer[pQueue->Index_out++];
#if(QUEUE_SIZE != 255)
		if(QUEUE_SIZE < pQueue->Index_out)
			pQueue->Index_out = 0;
#endif
	//}
	return ret_val;
}
/*
 *@brief 
 *@param
 *@retval 
 *@note	总感觉这个函数会有问题
*/
static unsigned char QueueExtractEx(Queue *pQueue,unsigned char *pSrc,unsigned char size)
{
	unsigned char i = 0,ret_val = RET_SUCCESS;
	while((size--) && (RET_ERR == IsQueueEmpty(pQueue)))
	{
		*(pSrc + (i++)) = pQueue->Buffer[pQueue->Index_out++];

#if QUEUE_SIZE != 255
		if(QUEUE_SIZE < pQueue->Index_out)
			pQueue->Index_out = 0;
#endif
	}
	if(size)
		ret_val = RET_ERR;
	return ret_val;
}
/*
 *@brief	字符串以中间为轴，两边交换
 *@param
 *@retval 
 *@note
*/
void SwapString(unsigned char *pSrc,unsigned char len)
{
	unsigned char c;  
	unsigned char i = 0, times = len/2;

	for(;i < times;i++)
	{
		c = *(pSrc + i);
		*(pSrc + i) = *(pSrc + len - 1 - i);
		*(pSrc + len - 1 - i) = c;
	}
}
/*
 *@brief 
 *@param
 *@retval 
 *@note
*/
unsigned int strlenDiy(const unsigned char *pSrc)
{
	unsigned int ret_val = 0;
	while(*(pSrc + (ret_val++)));
	return ret_val;
}
/*
 *@brief 
 *@param
 *@retval 
 *@note
*/
/*
void DebugInfoPrintf(const char *format,...)
{
	unsigned char index = 0;
	unsigned char c_content, c_start = *(format + (index++));

	va_list ap;
	va_start(ap,format);

	while(c_start)
	{    
		if('%' == c_start)
		{
			c_content = *(format + (index++));
			switch(c_content)
			{
			case 's':
				{
					const unsigned char *pVar = va_arg(ap,const unsigned char *);
					QueueInsertEx(&DebugSendInfoQueue,pVar,strlen(pVar));
				}
				break;

			case 'd':
				{  
					unsigned int Var = va_arg(ap,unsigned int);
					unsigned char str[12],length=0;
					do
					{
						str[length++] = Var%10 + '0';
						Var = Var/10;
					}while(Var && (length < 12));
					SwapString(str,length);
					QueueInsertEx(&DebugSendInfoQueue,str,length);
				}
				break;

			case 'x':
				{  
					unsigned int Var = va_arg(ap,unsigned int);
					unsigned char str[10],length=0;
					do
					{
						if(Var%16 < 10)
							str[length++] = Var%16 + '0';
						else
							str[length++] = Var%16 - 10 + 'A';			  
						Var = Var/16;
					}while(Var && (length < 12));
					SwapString(str,length);
					QueueInsertEx(&DebugSendInfoQueue,str,length);
				}
				break;

			default:
				QueueInsert(&DebugSendInfoQueue,c_start);
				QueueInsert(&DebugSendInfoQueue,c_content);
				break;
			}
		}
		else
		{
			QueueInsert(&DebugSendInfoQueue,c_start);
		}
		c_start = *(format + (index++));
	}
	va_end(ap);
}
*/
