#include<stdio.h>
#include<stdlib.h>
long gcd(long ,long );
long bit(long );
long power(long ,long ,long );
long pollard(long ,long );
long main()
{
	long n,B,b=2,k;
	printf("Enter a integer:\n");
	scanf("%ld",&n);
	B = n;
	printf("\n\n");
	while(b<=B)
	{
		k = pollard(n,b);
		if(k==0)
		{	
			if(b==B)
				k=n;
			else
			{
				b++;
				continue;
			}
		}
		printf("Factor : %ld\n",k);
		n = n/k;
		if(n == 1)
			break;
		B = n;
		b = 2;
	}
}
long gcd(long a,long b)
{
	long x;
	a = (a<0 ? -a : a);
	b = (b<0 ? -b : b);
	while(b != 0)
	{
		x = a%b;
		a = b;
		b = x;
	}
	return a;
}
long bit(long a)
{
	long b = 0;
	while(a != 0)
	{
		b++;
		a>>=1;
	}
	if(b == 0)
		b++;
	return b;
}
long power(long a,long b,long n)
{
	long k = bit(b),t,s=1;
	while(k != 0)
	{
		t = (b>>(k-1))&1;
		s=(s*s)%n;
		if(t == 1)
			s=(s*a)%n;
		k--;
	}
	return s;
}
long pollard(long n,long B)
{
	long d,i,j,a = 2;
	for(j=2;j<=B;j++)
		a = power(a,j,n);
	
	if(a == 0)
		return 2;
	d = gcd(a-1,n);
	
	if(d==1 || d==n)
		return 0;
	else
		return d;
}
