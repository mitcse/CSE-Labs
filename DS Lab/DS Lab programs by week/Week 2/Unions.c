#include<stdio.h>

typedef union
{
  int u;
  float m;
} UN;

typedef struct
{
  int a;
  float b;
  struct
  {
    int y;
    float c;
  } inner;
} OUTER;

typedef struct
{
  int g;
  union
  {
    int d;
    float x;
  } uninstruct;
} STRUCTOVERUN;

int main()
{
  printf("The size of the standalone union (having int and float) is %d\n", sizeof(UN));
  printf("The size of nested structures (outer having int and float) and inner having int and float) is %d\n", sizeof(OUTER));
  printf("The size of structure (having int) with a union inside it (having int and float) is %d\n", sizeof(STRUCTOVERUN));
  STRUCTOVERUN s2;
  OUTER s1;
  UN u1;
  u1.u = 2;
  u1.m = 3.0;
  printf("Standalone union values (one will return garbage) %d %f\n", u1.u, u1.m); 
  s1.a = 4;
  s1.b = 6.0;
  s1.inner.y = 30;
  s1.inner.c = 9.0;
  printf("Nested structure \n %f %d \n %f %d\n", s1.b, s1.a, s1.inner.c, s1.inner.y);
  s2.g = 60;
  s2.uninstruct.d = 10;
  s2.uninstruct.x = 3;
  printf("Structure variable : %d\n Inner union has int %d and float %f where one will show garbage\n", s2.g, s2.uninstruct.d, s2.uninstruct.x);
  return 0;
}
