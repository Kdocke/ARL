//最佳存款方案
/*
问题描述： 
		假设一年整存零取的月息为0.63%。现在某人手里有一笔钱，
	他打算在今后的5年中的每年年底取出1000元，到第5年时刚好取完，
	请算出他存钱时应存入多少?
*/

/**
 * 分析：
 * 		由后向前推算：
 * 		则，第5年年初存款数 = 1000/(1+12*0.0063)
 * 		    ... 
 * @author Kdocke
 * @version v1.0
 */
#include<stdio.h>
int main()
{
	int i;
	double money = 0.0;
	for(i=0;i<5;i++)
	{
		money = (money+1000.0)/(1+12*0.0063);
	}
	printf("应存入的钱数为:%0.2f\n",money);
 } 
