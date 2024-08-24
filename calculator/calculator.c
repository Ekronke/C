#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	TOKEN_ERR,
	TOKEN_PAR,
	TOKEN_DIV,
	TOKEN_MULT,
	TOKEN_ADD,
	TOKEN_SUB,
	TOKEN_NUM
} TokenType;

typedef struct {
	TokenType type;
	union {
		int value;
	} data;
} Token;

// Token lexer(char* input) {
// 	Token token;
// 	if (isdigit(*input)) {
// 		int num = take_int(input);
// 		token.data = num;
// 		token.type = TOKEN_NUM;
// 	} else {
// 		switch(*input) {
// 			case ('+'):
// 				token 
// 			
// 				break;
// 				
// 		}
// 	}
// }

int take_int(char* input) {
	int length = 0;
	int result = 0;

	while(isdigit(*input)) {
		length++;
		input++;
	}  
	char* num = (char*)malloc(length + 1);
	input = input - length;
	length = 0;

	while(isdigit(*input)) {
		length++;
		*num = *input;
		num++;
	} 
	*num = '\0';
	num = num - length;
	result = atoi(num);
	
	

	return result;
}

