#include<iostream>
#include<stdlib.h>
#include<ctype.h> 
#include<string.h>
#include<conio.h>
using namespace std;

#define SIZE 100
char Operator[SIZE];
char postfix[SIZE]; 
int top=-1;
int val,ele,overflow,underflow=0;

void push(char item)
{
	if(top >= SIZE-1)
	{
		cout<<"\nStack Overflow.";
	}
	else
    {
		Operator[++top] = item;
	}
}

char pop() {
	if(top <0)
	{
		cout<<"stack under flow: invalid infix expression";
		getchar();
		exit(1);
	}
	else
	{   char item;
		item = Operator[top--];
		return(item);
	}
}

int precedence(char symbol)
{
	if(symbol == '^')
		return 3;
	else if(symbol == '*' || symbol == '/')
		return 2;
	else if(symbol == '+' || symbol == '-')
		return 1;
	else
		return 0;
}

int is_operator(char symbol) {
    int op=precedence(symbol);
	if(op==1||op==2||op==3||op==0)
		return 1;
	else
	    return 0;
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');
	strcat(infix_exp,")");

	i=0; 
	j=0;
	item=infix_exp[i];
	while(item != '\0')
	{
		if(item == '(')
			push(item);
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp [j] = item;
			j++;
		}
		else if(is_operator(item) == 1) 
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x; 
				j++;
				x = pop();                 
			}
			push(x);
			push(item);
		}
		else 
            if(item == ')')   
		    {   x = pop();        
			    while(x != '(')   {
				    postfix_exp[j] = x;
				    j++;
				    x = pop();
			    }
		    }

		i++;
		item = infix_exp[i];
	}
	if(top>0)
	{
		cout<<"\nInvalid infix Expression.\n";
		getchar();
		exit(1);
	}
	if(top>0)
	{
		cout<<"\nInvalid infix Expression.\n";
		getchar();
		exit(1);
	}
	postfix_exp[j] = '\0';
}


int main()
{
    char infix[100];
	cout<<"Enter the regular expression...\n";
	gets(infix);
	InfixToPostfix(infix,postfix);                
    cout<<"Postfix Expression: ";
	puts(postfix);               
	return 0;
}
