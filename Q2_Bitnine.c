/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag
{
  ADD,
  SUB,
  MUL,
  DIV,
  FIBO,
} TypeTag;

typedef struct Node
{
  TypeTag type;
} Node;

int
add (int a, int b)
{
  return a + b;
}

int
sub (int a, int b)
{
  return a - b;
}

int
mul (int a, int b)
{
  return a * b;
}

int
divv (int a, int b)
{
  return a / b;
}

int
fibo (int a, int b)
{
  if (a == 1)
    {
      return 0;
    }
  else if (a == 2)
    {
      return 1;
    }
  else
    {
      int fib[a];
      fib[0] = 0;
      fib[1] = 1;
      for (int i = 2; i < a; i++)
	{
	  fib[i] = fib[i - 1] + fib[i - 2];
	}
      return fib[a - 1];
    }
}

int (*makeFunc (TypeTag tag)) (int, int)
{
  switch (tag)
    {
    case ADD:
      return &add;
    case SUB:
      return &sub;
    case MUL:
      return &mul;
    case DIV:
      return &divv;
    case FIBO:
      return &fibo;
    }
}




int
main ()
{

  int add = (*makeFunc (ADD)) (10, 6);
  int mul = (*makeFunc (MUL)) (5, 4);
  int sub = (*makeFunc (SUB)) (add, mul);
  int fibo = (*makeFunc (FIBO)) (abs (sub), NULL);	// Get n-th from fibonacci numbers.

  printf ("-add %d\n", add);
  printf ("-mul %d\n", mul);
  printf ("-sub %d\n", sub);
  printf ("-fibo %d\n", fibo);


  return 0;
}
