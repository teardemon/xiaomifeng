#ifndef IPFILTER_H
#define IPFILTER_H

#include <stdio.h>
#include <sys/types.h>

#define IP_LIST_LEN	65536

typedef struct _ipnode
{
	unsigned netlong;
	unsigned short mask;
	unsigned short region;
	struct _ipnode *next;
}IPNODE;

typedef struct
{
	struct _ipnode *ipnode;
}IPLIST;

extern IPLIST *iplist;

/*
 * 载入ip列表，将ip列表从文件读到内存中。该函数费时较长。
 * 返回值：     
 *              成功返回0；失败返回-1(失败时将list重新初始化,并不释放list)
 * 参数：
 *              pathname - ip列表文件
 *              list - ip列表头指针
 */
int iplist_load(const u_char *pathname);

/*
 * 初始化ip列表。
 * 参数：
 *              list - ip列表头指�
 *              listlen - ip列表的长度
 */
void iplist_init();

/*
 * 查找，确定给定ip是否在ip列表中。
 * 返回值：
 *              成功返回0；失败返回-1
 * 参数：
 *              iplist - ip列表头指针
 *              ip - p二进制网络字节序的待判定ip
 */
int iplist_search(unsigned long netlong);

/*
 * 卸载ip列表，释放ip所占内存。
 * 参数：       
 *              iplist - ip列表头指针
 */     
void iplist_destroy();

#endif  
