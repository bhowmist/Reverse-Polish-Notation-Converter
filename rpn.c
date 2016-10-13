/*Infix to Reverse Polish Notation Converter*/

#include <stdio.h>
#include <string.h>

/*stack declaration*/
char stack[256];
int top=-1;

/*stack functions*/
int push(char data);        
char pop();


char s[]="";
int j;
char data;                   

/*function declaration*/
int priority(char c);
char *RPN(char *inp, int l);



/*main function*/
void main()
{
    char name[100];
    /*accept user input*/
    printf ("Enter the expression(only lowercase is accepted): ");
    scanf ("%s",name);

    int i;
    int len;
    len=strlen(name);

    /*iterate through input*/
    for (i=0;i<len;i++)
      {
            /* lowercase and valid operator check*/
            if (check_lower(name[i])==0)
               {
                    return;
               }
      }

    //call to converter function
    char *res=RPN(name,len);
    printf ("RPN : %s\n",res);
}    
    


/*lowercase check function*/
int check_lower(Char){
      if (Char>=97 && Char<=122)
      {
             return 1;
      }
      else if (Char>=65 && Char<=90)
      { 
             printf ("Only lowercase is accepted, '%c' is not lowercase!\n", Char);
             return 0;
      }
      //invalid operator
      else if (check_operator(Char)==0)
      {
           printf ("Invalid Character : '%c'\n",Char);
           return 0;
      }
      else
      { return 1;}
}


/*operator check function*/
int check_operator(expr)
{
     if(expr=='+'||expr=='-'||expr=='*'||expr=='/'||expr=='^') 
     {
       return 1;
     }
     else if(expr=='(' || expr==')')
     {
       return 2;
     }
     return 0;
}


/*push data into the stack*/
int push(char data)                   
{
     if (top==255)
     {
        return 0;
     }
     else
      {
        top+=1;
        stack[top]=data;
      }
}


/*pop data from the stack*/
char pop()
{
   char val;                       
   if (top==-1)
       {return;}
   val=(stack[top]);               
   top-=1;
   return val;
}


/*precdence of operators*/
int priority(char c)
{
     if (c=='^'){ return 1;}
     else if (c=='/'){return 2;}
     else if (c=='*'){return 3;}
     else if (c=='-'){return 4;}
     else if (c=='+'){return 5;}
     else { return 0;}
}



/*infix to RPN converter*/
char *RPN(char *inp, int l)
{
  for(j=0;j<l;j++)
   {
    //incoming symbol is an operator
    if(inp[j]=='+'||inp[j]=='-'||inp[j]=='*'||inp[j]=='/'||inp[j]=='^')
      {
        if(check_operator(stack[top])==1)
           {
             while ((check_operator(stack[top])==1) && ((priority(inp[j])>=priority(stack[top]))))
                {
                   data=pop();
                   strncat(s,&data,1);             
                }
            }
            push(inp[j]);
      }     
        
     //incoiming symbol is right parantheses
     else if(inp[j]==')')
       {
         while (stack[top]!='(')
              {
                  data=pop();
                  strncat(s,&data,1);                
               }
             pop();
       }
      //incoiming symbol is left parantheses
      else if(inp[j]=='(')
              {  push(inp[j]);}

      //incoming symbol is an operand
      else
             { 
                strncat(s,&inp[j],1);
             } 
     }

     while (top!=-1)
     {
           data=pop();
           strncat(s,&data,1);                     
      }
     return s; 
}















          
    
