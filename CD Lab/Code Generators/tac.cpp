#include <iostream>
#include <ctype.h>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

int main() {
	int i=0;
	//stack<string> s;
	char tac[] = "a=b+c";
	int n= strlen(tac);
	char word[10];
	int j=0;
	while(isalpha(tac[i])) {
		word[j++] = tac[i++];
		//cout<<"\nMove r"<<s.size()-1<<","<<ch;
	}
	word[j] = '\0';
	char temp[10];
	strcpy(temp, word);
	//s.push(word);
	if(tac[i]!='=') {
		cout<<"Not three address code";
		exit(0);
	}
	i++;
	j=0;
	while(isalpha(tac[i])) {
		word[j++] = tac[i++];
	}
	word[j] = '\0';
	//s.push(word);
	cout<<"\nMove r0"<<","<<word;
	char op = ' ';
	if(!isalpha(tac[i])) op = tac[i++];
	j=0;
	while(isalpha(tac[i])) {
		word[j++] = tac[i++];
	}
	word[j] = '\0';
	//s.push(word);
	cout<<"\nMove r1"<<","<<word;
	if(op!=' ') {
		switch(op) {
			case '+' : {
				cout<<"\nadd r0 r1";
				break;
			}
			case '-' : {
				cout<<"\nsub r0 r1";
				break;
			}
			case '*' : {
				cout<<"\nmul r0 r1";
				break;
			}
			case '/' : {
				cout<<"\ndiv r0 r1";
				break;
			}
			default : {
				cout<<"Not three address code";
				exit(0);
			}

		}
	}

	//word2 = s.top();
	cout<<"\nMove "<<temp<<",r0  ";
	return 0;
}
