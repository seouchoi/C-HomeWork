/*
#include <stdio.h>

int main_diamond(void) {
	printf("ũ�⸦ ���ϼ���(Ȧ���� ����) : ");
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
		for (int i = renum; i > 0; i--) { // i�� 5,4,3,2,1
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
		printf("Ȧ���� �ƴϹǷ� �Ұ����մϴ�.");
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

 ���� Ȧ����
 (ó��)
 �� ������ 1���� �þ
 ����� 2���� �پ��
 ������ ���� �׻� ���� ��µ�


 11�� 6 13�� 7 15�� 8
*/
