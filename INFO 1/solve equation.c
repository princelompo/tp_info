#include<stdio.h>
#include<math.h>
main ()

{

    printf("\n");
    printf(" \t LET'S SOLVE THE SECOND DEGREE EQUATION ax^2+bx+c=0 \n");
    printf("\n");

    double a, b, c, x1, x2, delta ;
    double im,real;

    printf("     Enter the value of a : ");
    scanf("%lf",&a);
    printf("     Enter the value of b : ");
    scanf("%lf",&b);
    printf("     Enter the value of c : ");
    scanf("%lf",&c);
    printf("\n");

    delta=b*b-4*a*c ;
    printf("    delta = %lf \n",delta);
    printf("\n");

       if(a==0 && b==0 && c==0){
           printf("    The equation has an infinity of solutions. \n ");
         }
       if(a==0){
                if( b==0 && c!=0){
                    printf("    The equation has not a solution. \n ");
                }
                if(b!=0 && c==0){
                    printf("   The solution is : x = 0.0000000 \n");
                }
                if(b!=0 && c!=0){
                    printf("    The solution is x = %lf \n",-c/b);
                }
            }
       if(a!=0){
                if(delta==0){
                    printf("    The equation has a double solution : x1 = x2 = %lf \n", -b/(2*a));
                  }
                if(delta>0){
                    printf("    The equation has two solutions : x1 = %lf  and  x2 = %lf \n", (-b-sqrt(delta))/(2*a), (-b+sqrt(delta))/(2*a));
                  }
                if(delta<0){
                    im=sqrt(-delta)/(2*a);
                    real=-b/(2*a);
                    if(real==0){
                       printf("    The equation has two complexes conjugate solutions : x1 = %lfi  and  x2 = - %lfi \n",im,im);
                      }
                    else{
                       printf("    The equation has two complexes conjugate solutions : x1 =%lf + %lfi  and  x2 =%lf - %lfi \n", real,im,real,im);
                      }
                    }

            }
            printf("\n");




            system("pause");


}














