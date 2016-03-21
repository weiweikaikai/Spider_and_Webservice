/*************************************************************************
    > File Name: debug_cgi.c
    > Author: WK
    > Mail:18402927708@163.com 
    > Created Time: Tue 05 Jan 2016 02:39:37 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc,char* argv[])
{
	int content_length = -1;
	char method[1024];
	char query_string[1024];
	char post_data[4096];
	memset(method,'\0',sizeof(method));
	memset(query_string,'\0',sizeof(query_string));
	memset(post_data,'\0',sizeof(post_data));
    
	printf("<html>\n");
	printf("\t<h>hello world</h>\n");
	printf("<p>method: %s<br/>",method);

	strcpy(method,getenv("REQUEST_METHOD"));
	if(strcasecmp("GET",method) == 0)
	{
		strcpy(query_string,getenv("QUERY_STRING"));
		printf("query_string: %s</p><br>",query_string);
	}
	else if(strcasecmp("POST",method) == 0)
	{
		content_length = atoi(getenv("CONTENT_LENGTH"));
		int i=0;
		for(;i<content_legth;++i)
		{
			read(0,&post_data[i],1);
		}
		post_data[i]='\0';
		printf("post data :%s</p><br/>",post_data);
	}else
	{
       return 1;
	}
    
	printf("</html>\n");
return  0;
}

