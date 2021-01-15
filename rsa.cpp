#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define li long int

int x, y, n, t, i, flag_int;
long int e[50], d[50], temp[50], j, m[50], en[50];
char msg[100];


int prime(long int pr)
{
  int i;
  j = sqrt(pr);
  for(i = 2; i <= j; i++)
  {
   if(pr % i == 0)
     return 0;
  }
  return 1;
}

void encrypt()
{
  long int pt, ct, key = e[0], k, len;
  i = 0;
  len = strlen(msg);
  while(i != len)
  {
    pt = m[i];
    pt = pt - 96;
    k = 1;
    for(j = 0; j < key; j++)
    {
     k = k * pt;
     k = k % n;
    }
   temp[i] = k;
   ct = k + 96;
   en[i] = ct;
   i++;
  }
  en[i] = -1;
  printf("\n\nEncrypted message: \n");
  for(i = 0; en[i] != -1; i++)
    printf("%c", en[i]);
}

long int test(long int a)
{
  long int k = 1;
  while(1)
  {
    k = k + t;
    if(k % a == 0)
     return(k / a);
  }
}

void encryption_key()
{
  int k;
  k = 0;
  for(i = 2; i < t; i++)
  {
    if(t % i == 0)
     continue;
    flag_int = prime(i);
    if(flag_int == 1 && i != x && i != y)
    {
     e[k] = i;
     flag_int = test(e[k]);
    if(flag_int > 0)
    {
     d[k] = flag_int;
     k++;
    }
   if(k == 99)
    break;
   }
 }
}

void decrypt()
{
  long int pt, ct, key = d[0], k;
  i = 0;
  while(en[i] != -1)
  {
    ct = temp[i];
    k = 1;
    for(j = 0; j < key; j++)
    {
      k = k * ct;
      k = k % n;
    }
   pt = k + 96;
   m[i] = pt;
   i++;
  }
  m[i] = -1;
  printf("\n\nDecrypted message:\n");
  for(i = 0; m[i] != -1; i++)
   printf("%c", m[i]);
  printf("\n");
}

int main()
{
  printf("\nEnter first prime number: \n");
  scanf("%d", &x);
  flag_int = prime(x);
  if(flag_int == 0)
  {
    printf("\nINVALID INPUT\n");
    exit(0);
  }
  printf("\nEnter second prime number\n");
  scanf("%d", &y);
  flag_int = prime(y);

  printf("\nEnter your message: \n");

  scanf("%s",msg);
  for(i = 0; msg[i] != NULL; i++)
    m[i] = msg[i];
  n = x * y;
  t = (x-1) * (y-1);
  encryption_key();
  cout << "\nValue of e and d are:\n";
  cout << e[0] << " " << d[i] << endl;
    
  encrypt();
  decrypt();
  return 0;
}
