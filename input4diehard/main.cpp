#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	FILE *fp_in, *fp_out;
	unsigned int i, j;
	unsigned char ch, temp, data;
	
	unsigned long int pos;

	fp_in = fopen(argv[1], "r");
	if (!fp_in)
		exit(1);
	fp_out = fopen(argv[2], "wb+");
	if (!fp_out)
		exit(1);

	fseek(fp_in, 0L, SEEK_END);
	unsigned long int num_of_input_bits = ftell(fp_in);
	fseek(fp_in, 0L, SEEK_SET);
	printf("number of bits = %d", num_of_input_bits);
	unsigned long int iterations = num_of_input_bits / 8;  // 8 bits into a character

	for (i = 0; i<iterations; ++i)
	{
		data = 0;
		for (j = 0; j<8; ++j)
		{
			fscanf(fp_in, "%c", &ch);
			pos = ftell(fp_in);
			temp = (char)(ch - '0');
			temp <<= (7 - j);
			data |= temp;
		}
		fprintf(fp_out, "%c", data);		
	}
	
	fclose(fp_in);
	fclose(fp_out);


	return 0;
}