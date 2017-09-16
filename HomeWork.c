#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void FirtstMenu(void);
int checkPrimeNumber(int n);

void SecondMenu(void);
int checkAmstrongNumber(int number);

int LastMenu(void);

int main(void)
{
	int a;

	printf("1. 두 정수 사이의 소수 \n2. Prime Number와 Armstrong Number 확인하기 \n3. 수가 되는 두 소수의 합 구하기\n");
	printf("원하시는 메뉴를 선택하세요: ");
	scanf("%d", &a);

	if(a==1) FirtstMenu();
	else if(a==2) SecondMenu();
	else if(a==3) LastMenu();
	else{
		printf("메뉴가 존재하지 않습니다.\n");
		exit(0);
	}

	return 0;
}
void FirtstMenu(void)
{
	int n1, n2, i, flag;

	printf("Enter two positive integers: ");
	scanf("%d, %d", &n1, &n2);

	printf("Prime numbers between %d and %d are: ", n1, n2);

	for(i=n1+1;i<n2;++i)
	{
		flag=checkPrimeNumber(i);
		if(flag==1) printf("%d ", i);
	}
}

int checkPrimeNumber(int n)
{
	int j, flag=1;
	for(j=2;j<=n/2;++j)
	{
		if(n%j==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}

void SecondMenu(void)
{
	int n, flag;

	printf("Enter a positive integer : ");
	scanf("%d", &n);

	flag = checkPrimeNumber(n);
	if(flag == 1)
		printf("%d is a prime number. \n", n);
	else
		printf("%d is not a prime number. \n", n);

	flag = checkAmstrongNumber(n);
	if(flag == 1)
		printf("%d is an Amstrong number. \n", n);
	else
		printf("%d is not an Amstrong number. \n", n);
}

int checkAmstrongNumber(int number)
{
	int originalNumber, remainder, result=0, n=0, flag = 0;

	originalNumber=number;
	while(originalNumber != 0)
	{
		originalNumber /= 10;
		n++;
	}

	originalNumber=number;
	while(originalNumber != 0)
	{
		remainder = originalNumber%10;
		result += pow(remainder, n);
		originalNumber /= 10;
	}

	originalNumber=number;
	if (originalNumber == result) return (flag=1);
	return flag;
}

int LastMenu(void)
{
	int n, i, flag = 0;
	printf("Enter a positive integer : ");
	scanf("%d", &n);
	for(i = 2; i <= n/2; ++i)
	{
		if(checkPrimeNumber(i) == 1)
		{
			if(checkPrimeNumber(n-i) == 1)
			{
				printf("%d = %d + %d\n", n, i, n-i);
				flag = 1;
			}
		}
	}
	if(flag == 0)
	 printf("%d cannot be expressed as the sum of two prime numbers.", n);

	return 0;
}