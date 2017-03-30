#include <iostream>
#include <ctype.h>
#include <stack>
#include <string.h>
#include <stdio.h>
using namespace std;

int main() {
	int i=0;
	char prefix[] = "-+1*234";
	int n= strlen(prefix);
	char postfix[n];
	for(i=0;i<n;i++) {
		postfix[i] = prefix[n-i-1];
	}
	printf("postfix: '%s'\n", postfix);
	stack<int> s;
	int first, second, temp;
	i=0;
	char ch = postfix[i];
	while(postfix[i]!='\0') {
		ch = postfix[i];
		if(isdigit(ch)) {
			s.push(ch-48);
			cout<<"\nmov r"<<s.size()-1<<","<<ch;
		}
		else {
			switch(ch) {
				case '+' : {
					second = s.top();
					s.pop();
					first = s.top();
					s.pop();
					cout<<"\nadd r"<<s.size()<<",r"<<s.size()+1;
					temp = first+second;
					s.push(temp);
					break;
				}
				case '-' : {
					second = s.top();
					s.pop();
					first = s.top();
					s.pop();
					cout<<"\nsub r"<<s.size()<<",r"<<s.size()+1;
					temp = second-first;
					s.push(temp);
					break;
				}
				case '*' : {
					second = s.top();
					s.pop();
					first = s.top();
					s.pop();
					cout<<"\nmul r"<<s.size()<<",r"<<s.size()+1;
					temp = first*second;
					s.push(temp);
					break;
				}
				case '/' : {
					second = s.top();
					s.pop();
					first = s.top();
					s.pop();
					cout<<"\ndiv r"<<s.size()<<",r"<<s.size()+1;
					temp = second/first;
					s.push(temp);
					break;
				}
			}
		}
		i++;
	}
	while(s.size()>0) {
		cout<<"\n"<<s.top()<<"\n";
		s.pop();
	}
}
