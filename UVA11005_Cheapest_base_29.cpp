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
	cin>>in1; //첫번째 몇번 실험 할껀지 입력; 
	while(in1--) 
	{
		cout<<"Case "<<c<<" :"<<endl; //케이스 출력; 
		for(int i=0;i<36;i++)
		{
			cin>>cost[i]; //가격 입력; 
		}
		cin>>n; //테스트할 정수 곗수 입력; 
		while(n--)
		{
			cin>>in2; //정수 입력; 
			int min=0,de[37]={'\n'};
			
			for(int i=2;i<=36;i++)
			{
				cn1=in2; //매번 2 ~ 36번 테스트 해야해서 값이 바뀌는걸 방지하기 위해 cs1에 정수의 값을 저장; 
				int sum=0; //매 번 할때마다 값을 0으로 초기화 시켜줘야 쓰레기 값이 안 들어가 있음; 
				while(cn1>0) //하나하나씩 가격 테스트; 
				{
					re=cn1%i; //가격 결과; 
					sum=sum+cost[re]; //가격 결과에 저장; 
					cn1=cn1/i; //다음 결과보기; 
				}
				if(min==0||sum<=min) //최소값 찾기; 
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

