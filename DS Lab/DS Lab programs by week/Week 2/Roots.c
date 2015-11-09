#include<stdio.h>
#include<math.h>

void getdata(float *a, float *b, float *c)
{
  printf("Enter the values of a, b, c: ");
  scanf("%f %f %f", a, b, c);
}


void print_roots(float *p, float *q, int flag)
{
  if(flag == 1)
  {
    printf("There is one root: %f\n", *p);
  }
 
  else if (flag ==2)
  {
    printf("Roots are imaginary: \n");
    printf("%f + i%f\n%f - i%f\n", *p, *q, *p, *q);
  }

  else if(flag ==3)
  {
    printf("There are 2 roots: %f, %f\n", *p, *q);
  }
}

int quadratic(float *a, float *b, float *c, float *r1, float *r2)
{
  float det;
  det = (*b)*(*b)- 4*(*a)*(*c);
  
  int flag;
  if(det==0)
  {
    *r1 = (-1*(*b))/(2*(*a));
    *r2 = 0;
    flag = 1;
  }
  else if (det<0)
  {
    det = -1 * det;
    *r1 = (-1*(*b))/(2*(*a));
    *r2 = sqrt(det)/(2*(*a));
    flag = 2;
  }
  
  else
  {
    *r1 = (-1*(*b)+sqrt(det))/(2*(*a));
    *r2 = (-1*(*b)-sqrt(det))/(2*(*a));
    flag = 3;
  }
 
  return flag;

}

int main()
{
  float r1, r2, a, b, c;
  int flag;
  getdata(&a, &b, &c);
  flag = quadratic(&a, &b, &c, &r1, &r2);
  print_roots(&r1, &r2, flag);
  return 0;
}
