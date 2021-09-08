/*
Sample Input
2
10 8 12 13 15 13 13 16 9
11 18 24 21 23 23 23 13 15
17 33 21 23 27 26 27 19 4
22 18 30 30 24 16 26 21 21
5
98329921
12345
800348
14
873645
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
4
0
1
10
100
Sample Output
Case 1:
Cheapest base(s) for number 98329921: 24
Cheapest base(s) for number 12345: 13 31
Cheapest base(s) for number 800348: 31
Cheapest base(s) for number 14: 13
Cheapest base(s) for number 873645: 22
Case 2:
Cheapest base(s) for number 0: 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36
Cheapest base(s) for number 1: 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36
Cheapest base(s) for number 10: 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
26 27 28 29 30 31 32 33 34 35 36
Cheapest base(s) for number 100: 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
26 27 28 29 30 31 32 33 34 35 36
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int re,n,in1,in2,c=1,cost[36]={'\n'};
	int cn1;
	cin>>in1; //ù��° ��� ���� �Ҳ��� �Է�; 
	while(in1--) 
	{
		cout<<"Case "<<c<<" :"<<endl; //���̽� ���; 
		for(int i=0;i<36;i++)
		{
			cin>>cost[i]; //���� �Է�; 
		}
		cin>>n; //�׽�Ʈ�� ���� ��� �Է�; 
		while(n--)
		{
			cin>>in2; //���� �Է�; 
			int min=0,de[37]={'\n'};
			
			for(int i=2;i<=36;i++)
			{
				cn1=in2; //�Ź� 2 ~ 36�� �׽�Ʈ �ؾ��ؼ� ���� �ٲ�°� �����ϱ� ���� cs1�� ������ ���� ����; 
				int sum=0; //�� �� �Ҷ����� ���� 0���� �ʱ�ȭ ������� ������ ���� �� �� ����; 
				while(cn1>0) //�ϳ��ϳ��� ���� �׽�Ʈ; 
				{
					re=cn1%i; //���� ���; 
					sum=sum+cost[re]; //���� ����� ����; 
					cn1=cn1/i; //���� �������; 
				}
				if(min==0||sum<=min) //�ּҰ� ã��; 
				{
					min=sum;
					de[i]=sum;
				}
			}
			cout<<"Cheapest base(s) for number "<<in2<<":";
			
			for(int i=2;i<=36;i++)
			{
				if(de[i]==min)
				{
					cout<<" "<<i;
				}
			}
			cout<<endl;
		}
		c++;
	}
	
return 0;
}

