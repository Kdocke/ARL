//抓交通肇事犯
/*
问题描述：
		一辆卡车违反交通规则，撞人后逃跑。现场有三人目击该事件，但都没有记住车牌号，
	只记下车牌号的一些特征。甲说：牌照的前两位数字是相同的；乙说：牌照的后两位数是相同的，
	但与前两位不同；丙是数学家，他说：四位的车号刚好是一个整数的平方。
	请根据以上线索求出车牌号。
*/ 

/**
 * 穷举法 
 * @author Kdocke
 * @version v1.0
 */
/*
#include<stdio.h>
int main()
{
	int i,j,k,temp;	//i代表前两位车牌号数字，j代表后两位车牌号数字，k代表车牌号
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=9;j++)	//穷举前两位和后两位车牌数字 
		{
			if(i!=j)	//判断前两位数字和后两位数字是否不同 
			{
				k = 1000*i+100*i+10*j+j;	//组成四位车牌号k
				for(temp=31;temp<=99;temp++)
				{
					if(temp*temp == k)
					{
						printf("车牌号为：%d",k);
					}
				 } 
			}
		}
	 } 
 }
*/

/**
 * 增加标识，减少循环 
 * @author Kdocke
 * @version v2.0
 */ 
#include<stdio.h>
int main()
{
	int i,j,k,temp,flag=0;
	for(i=0;i<=9;i++)
	{
		if(flag) break;	//判断标识 
		for(j=0;j<=9;j++)
		{
			if(flag) break;
			if(i!=j)
			{
				k = 1000*i+100*i+10*j+j;
				for(temp=31;temp<=99;temp++)
				{
					if(temp*temp == k)
					{
						printf("车牌号为：%d",k);
						flag = 1;
						break;
					}
				 } 
			}
		}
	 } 
 } 
