#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Tsize 50//�����������С
#define Qsize 20
int
parse_query_string(char* url, struct query_parameter** out)
{
	/* TODO */
	int len=strlen(url);
	int counts=0; //���������ڵ���һ�ŷ��ظò���
	int i=0;
	for(;i<len;i++)
    {
        if(url[i]=='?')
            break;
    }
    if(i==len)
	  return -1;
    
    *out==(struct query_parameter*)malloc(sizeof(struct query_parameter)*Qsize);
    i++;//iָ���һ����ѯԪ��
    int j;
    char * temp;
    while(i<=len)
    {
        while(i<=len && url[i]!='&')
        {
            j=0;
            temp=(char*)malloc(sizeof(char)*Tsize);
            while(i<len  && url[i]!='=')
            {
                temp[j]=url[i];
                i++;
                j++;
            }
            i++;
            temp[j]='\0';
            (*out)[counts].name=temp;

            j=0;
            temp=(char*)malloc(sizeof(char)*Tsize);
            while(i<len  && url[i]!='&')
            {
                temp[j]=url[i];
                i++;
                j++;
            }
            i++;
            temp[j]='\0';
            (*out)[counts].value=temp;
            counts++;
        }
    }
    return counts;
}
