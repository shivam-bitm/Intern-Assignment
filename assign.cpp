#include <iostream>
#include <cstdio>
#define MOD 1000000007
#define lli long long int
using namespace std;
void multiply(lli F[2][2], lli M[2][2]);
void pow(lli F[2][2], lli n);
lli solve(lli n)
{
  lli F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  if (n == 1)
    return 2;
  if (n == 2)
    return 3;
  pow(F, n-2);
  return (F[0][0]*3+F[0][1]*2)%MOD;
}


void pow(lli F[2][2], lli n)
{
  if( n == 0 || n == 1)
      return;
  lli M[2][2] = {{1,1},{1,0}};
 
  pow(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}

void multiply(lli F[2][2], lli M[2][2])
{
  lli x =  ((F[0][0]*M[0][0])%MOD + (F[0][1]*M[1][0])%MOD)%MOD;
  lli y =  ((F[0][0]*M[0][1])%MOD + (F[0][1]*M[1][1])%MOD)%MOD;
  lli z =  ((F[1][0]*M[0][0])%MOD + (F[1][1]*M[1][0])%MOD)%MOD;
  lli w =  ((F[1][0]*M[0][1])%MOD + (F[1][1]*M[1][1])%MOD)%MOD;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

int main()
{
	freopen("input.txt","r",stdin);
	lli T;
	cin >> T;
	while(T--)
	{
		lli num;
		cin >> num;
		cout << solve(num) << endl;
	}
	return 0;
}