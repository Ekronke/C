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

int take_int(char* input) {
	int length = 0;
	int result = 0;
	char* start = input;

	while(isdigit(*input)) {
		length++;
		input++;
	}  
	char* num = malloc(length + 1);
	char* num_ptr = num;
	input = start;

	while(isdigit(*input)) {
		*num_ptr = *input; 
		num_ptr++;
		input++;
	} 
	*num_ptr = '\0';
	result = atoi(num);
	free(num);

	return result;
}

Token lexer(char* input) {
	Token token;
	if (isdigit(*input)) {
		int result = take_int(input);
		token.data = result;
		token.type = TOKEN_NUM;
	} else {
		switch(*input) {
			case ('+'):
				token.type = TOKEN_ADD;
				break;
			case ('-'):
				token.type = TOKEN_SUB;
				break;
			case ('/'):
				token.type = TOKEN_DIV;
				break;
			case ('*'):
				token.type = TOKEN_MULT;
				break;
			case ('('):
				token.type = TOKEN_PAR;
				break;
			case (')'):
				token.type = TOKEN_PAR;
				break;
			default:
				token.type = TOKEN_ERR;
				break;
		}
	}
	return token;
}

int main(void) {
	int i = 0;
	int j = 0;
	Token tokenArr[1024];
	char* str = malloc(1024);
    fgets(str, 1024, stdin);
	char* str_ptr = str;

	while(*str_ptr != '\0' & *str_ptr != '\n') {
		Token token = lexer(str_ptr);
		tokenArr[i] = token;
		if (token.type == TOKEN_NUM) {
			str_ptr = str_ptr + token.data;
		} else {
			str_ptr++;
		}
		i++;
	}
	free(str);


	return 0;
}
