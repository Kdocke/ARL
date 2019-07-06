//���㻹��ɹ��
/*
����������
		 �й��о������"�����������ɹ��"��ĳ�˴�1990��1��1����ʼ"�����������ɹ��" ��
	����������Ժ��ĳһ������"����"����"ɹ��"��
*/

/**
 * ������
 * 		��������ɽ�������̷�Ϊ3����
 * 		(1)�����1990��1��1�տ�ʼ��ָ�����ڹ�������
 * 		(2)����"����"��"ɹ��"������Ϊ5�죬���Խ����������ȥ����5
 * 		(3)���������ж�������"����"������"ɹ��",������Ϊ1,2,3�����ڴ��㣬������ɹ�� 
 * @author Kdocke
 * @version v1.0
 */
#include<stdio.h>
/*�������ڽṹ��*/
typedef struct date {
	int year;
	int month;
	int day;
}DATE; 
int countDay(DATE); 	//�������� 
int runYear(int); 	//��������
int main()
{
	DATE today;		//ָ������ 
	int totalDay;		//ָ�����ھ���1990��1��1�յ������� 
	int result;		//totalDay��5ȡ��Ľ��
	
	/*����ָ�����ڣ������꣬�£���*/
	printf("������ָ�����ڣ������꣬�£��� �磺1999 1 31\n");
	scanf("%d%d%d",&today.year,&today.month,&today.day);
	
	/*���ָ�����ھ���1990��1��1�յ�������*/ 
	totalDay = countDay(today);
	
	/*����%5,�ж�������㻹��ɹ��*/
	result = totalDay%5;
	if(result>=1 && result<=3)
		printf("�������");
	else
		printf("����ɹ��"); 
 } 
 
/*�ж��Ƿ�Ϊ���꣬�Ƿ���1���񷵻�0*/
int runYear(int year)
{
	if(year%4==0 && year%100!=0 || year%400==0) //������
		return 1;
	else
		return 0; 
 } 
 
/*����ָ�����ڵ�1990��1��1�յ�����*/
int countDay(DATE currentDay)
{
	int perMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};		//ÿ����������
	
	int totalDay=0,year,i;
	
	/*���ָ������֮ǰ��ÿһ����������ۼ�*/
	for(year=1990;year<currentDay.year;year++)
	{
		if(runYear(year))
			totalDay += 366;
		else
			totalDay += 365;
	 } 
	 
	/*���Ϊ���꣬��2�·���29��*/
	if(runYear(currentDay.year))
		perMonth[2] = 29;
		
	/*�������ڵ������ۼӵ�totalDay��*/ 
	for(i=0;i<currentDay.month;i++)
		totalDay += perMonth[i];
	
	/*�������ڵ������ۼӵ�totalDay��*/
	totalDay += currentDay.day;
	
	/*����������*/
	return totalDay; 
}
