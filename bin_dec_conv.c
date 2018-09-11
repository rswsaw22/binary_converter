#include <stdio.h>
#include <math.h>
#include "bin_to_dec.h"

void dec_to_bin(int dec){
	int bin[8];
	int sum = dec;
	for(int i = 0; i < 8; i++)
	{
		if((sum % 2) != 0)
		{
			bin[i] = 1;
		}
		else
		{
			bin[i] = 0;
		}
		sum = sum/2;
	}

	printf("The binary representation of %d is ", dec);
	for(int i = 7; i >= 0; i--)
	{
		printf("%d",bin[i]);
	}
	printf("\n");
	return;
}

void bin_to_dec(int bin[8])
{
	int dec;
	int sum = 0;
	for(int i = 7; i >= 0; i--)
	{
		sum = (bin[i]*pow(2,i)) + sum;
	}
	dec = sum;
	for(int k = 7; k >= 0; k--)
	{
		printf("%d",bin[k]);
	}
	printf(" is %d in decimal\n", dec);
	return;
}

void two_comp(int bin[8])
{
	int count = 0;
	int cout = 0;
	int run_complement = 1;
	printf("You put in ");
	for(int k = 7; k >= 0; k--)
	{
		printf("%d", bin[k]);
	}
	for(int i = 0; i < 8; i++)
	{
		bin[i] ^= 0b1;
	}
	while(run_complement)
	{
		if((cout = bin[count] + 1) == 2)
		{
			bin[count] = 0;
			count++;
		}
		else
		{
			bin[count] += 1;
			run_complement = 0;
		}
	}
	printf(" The two's complement is ");
	for(int i = 7; i >= 0; i--)
	{
		printf("%d",bin[i]);
	}
	printf("\n");
}

void bin_to_hex(int bin[8])
{
	int sum1 = 0;
	int sum2 = 0;

	for(int i = 0; i < 4; i++)
	{
		sum1 = (bin[i]*pow(2,i)) + sum1;
		sum2 = (bin[i+4]*pow(2,(i))) + sum2;
	}

	for(int i = 7; i >= 0; i--)
	{
		printf("%d",bin[i]);
	}
	printf(" is 0x%c%c in hexadecimal\n", hex_val[sum2], hex_val[sum1]);
}

int main(void)
{
	int choice;
	int bin_operations;
	int decimal;
	int binval;
	int binary[8];

	printf("Choose if you want to convert binary[0] or decimal[1]?");
	scanf("%d", &choice);

	if(choice == 0)
	{
		printf("Would you like to also perform two_comp and hexadecimal conversion?[0|1]\n");
		scanf("%d",&bin_operations);
		printf("Give your eightbit binary value: \n");
		for(int i = 7; i >= 0; i--)
		{
			printf("Bit %d \n",(i+1));
			scanf("%d",&binval);
			binary[i] = binval;
		}
		bin_to_dec(binary);
		if(bin_operations)
		{
			bin_to_hex(binary);
			two_comp(binary);
		}
	}
	else
	{
		printf("Give a decimal value: \n");
		scanf("%d", &decimal);
		while(decimal > 255)
		{
			printf("This is only for a byte, choose a value 255 or less\n");
			scanf("%d",&decimal);
		}
		dec_to_bin(decimal);
	}

	return 0;
}