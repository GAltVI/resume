#ifndef H_BIGNUM
#define H_BIGNUM

#define LEN 100
#define TEN 10

int input_bignum(int *buffer, int *length);

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sum_by_shift(int *buffMAX, int lenMAX, int *buffMIN, int lenMIN, int *result, int *result_length);

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub_by_shift(int *buffMAX, int lenMAX, int *buffMIN, int lenMIN, int *result, int *result_length);

int get_lager_buffer(int len1, int len2);
void delete_unsign_zero(int *buff, int *len);

#endif
