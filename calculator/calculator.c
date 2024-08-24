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
	char* start = input;

	while(isdigit(*input)) {
		length++;
		input++;
	}  
	char* num = (char*)malloc(length + 1);
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

int main(void) {
	int res = 1;
	char* str = "1111";
	res = take_int(str);
	printf("Testing, %d\n", res);
	return 0;
}
