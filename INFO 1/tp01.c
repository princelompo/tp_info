#include<stdio.h>
#include<math.h>
main()
{
 float a,b;
 char op;

 printf(" entrer la valeur de a : ");
 scanf("%f",&a);

 printf(" donner l'operation :");
 scanf(" %c",&op);

 printf(" entrer la valeur de b : ");
 scanf("%f",&b);

 switch(op)
      {
         case '+' : printf(" %.2f %c %.2f = %.2f \n",a,op,b,a+b);break;
         case '-' : printf(" %.2f %c %.2f = %.2f \n",a,op,b,a-b);break;
         case '*' : printf(" %.2f %c %.2f = %.2f \n",a,op,b,a*b);break;
         case '/' : if (b==0)
                   {
                       printf(" division par zéro impossible \n");
                   }
                     else
                   {
                     printf(" %.2f %c %.2f = %.2f \n",a,op,b,a/b);
                   }
                    break;
        default : printf(" operation invalide \n");



      }

    system(" pause");












}
