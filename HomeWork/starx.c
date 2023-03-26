/*
#include <stdio.h>

int main_diamond(void) {
	printf("크기를 정하세요(홀수만 가능) : ");
	int num;
	scanf_s("%d", &num);
	int renum = (num - 1) / 2;

	if (num % 2 == 1) {
		for (int i = 0; i <= renum; i++) {
			for (int j = 0; j < i; j++) {
				printf(" ");
			}
			printf("*");
			for (int k = i; k < num - i - 2; k++) {
				printf(" ");

			}
			if (i < renum) {
				printf("*");
			}
			printf("\n");
		}
		for (int i = renum; i > 0; i--) { // i는 5,4,3,2,1
			for (int j = 1; j < i; j++) {
				printf(" ");
			}
			printf("*");
			for (int k = 0; k < num - 2 * i; k++) {
				printf(" ");
			}
			printf("*");
			printf("\n");
		}
	}
	else {
		printf("홀수가 아니므로 불가능합니다.");
	}
	

}


*SSSSSSSSS*
S*SSSSSSS*
SS*SSSSS*
SSS*SSS*
SSSS*S*
SSSSS*
SSSS*S*
SSS*SSS*
SS*SSSSS*
S*SSSSSSS*
*SSSSSSSSS*

 층은 홀수개
 (처음)
 앞 공백은 1개씩 늘어남
 가운데는 2개씩 줄어듦
 마지막 별은 항상 끝에 출력됨


 11은 6 13은 7 15는 8
*/
