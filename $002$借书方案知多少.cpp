//借书方案知多少
/*
问题描述：
		小明有5本新书，要借给A、B、C这3位小朋友，若每人每次只能借一本，
	则可以有多少种不同的借法？
*/

/**
 * 穷举循环
 * @author Kdocke
 * @version v1.0
 */ 
/*
#include<stdio.h>
main()
{
	int a,b,c,i=0; //a,b,c分别用来记录3个人所选新书编号，i用来记录有效借阅次数
	printf("A,B,C三人所选书号分别是：\n");
	for(a=1;a<=5;a++) //用来控制A借阅图书的编号 
	{
		for(b=1;b<=5;b++) //用来控制B借阅图书的编号 
		{
			for(c=1;c<=5;c++) //用来控制C借阅图书的编号 
			{
				if(a!=b && a!=c && b!=c) //用来控制有效借阅的组合 
				{
					printf("A:%2d B:%2d C:%2d	",a,b,c); 
					i++;
					if(i%4==0) printf("\n"); //每行最多输出4种组合 
				}
			}
		}
	}
	printf("共有%2d种有效借阅方法\n",i); //输出有效借阅次数的总和 
 } 
*/

/**
 * 增加条件约束，提高效率 
 * @author Kdocke
 * @version v2.0
 */
#include<stdio.h>
main()
{
	int a,b,c,i=0;
	printf("A,B,C三人所选书号分别是：\n");
	for(a=1;a<=5;a++)
		for(b=1;b<=5;b++)
			for(c=1;c<=5&&a!=b;c++) //增加条件判断
				if(a!=c && b!=c)
				{
					printf("A:%2d B:%2d C:%2d	",a,b,c); 
					i++;
					if(i%4==0) printf("\n");
				 } 
	
	printf("共有%2d种有效借阅方法\n",i);			
 } 
