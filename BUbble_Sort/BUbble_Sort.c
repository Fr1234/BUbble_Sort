#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/// <summary>
/// 製造亂數放入陣列中
/// </summary>
/// <param name="array"></param>
/// <param name="array_length"></param>
void PutRandomNumberInArray(int* array, int* array_length) {
	//srand(time(NULL));
	for (int i = 0; i < *array_length; i++) {
		array[i] = rand() % *array_length + 1;
		//for (int j = 0; j < i; j++) {
		//	if (array[i] == array[j])  //比較值是否已經存在
		//	{
		//		/*i--;
		//		break;*/
		//		j = 0;
		//		array[i] = rand() % *array_length + 1;
		//	}
		////	/*while (array[i] == array[j])
		////	{
		////		j = 0;
		////		array[i] = rand() % *array_length + 1;
		////	}*/
		//}
	}


}
/// <summary>
/// 印出陣列裡的數字
/// </summary>
/// <param name="array"></param>
/// <param name="array_length"></param>
void Print(int* array, int* array_length) {

	for (int i = 0; i < *array_length; i++) {
		printf("%d ", *(array + i));
	}
	printf("\n");
}
/// <summary>
/// 交換兩個位置的值
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/// <summary>
/// Bubble Sort
/// </summary>
/// <param name="array"></param>
/// <param name="array_length"></param>
void Bubble_Sort(int* array, int* array_length) {
	
	for (int i = 0; i < (*array_length ); i++) {
		
		for (int j = 0; j < *array_length-i-1; j++) {
			if (*(array + j+1) < *(array + j )) {
				Swap(&array[j], &array[j+1]);//為了不要自己跟自己還要swap一次
			}

		}
	}
}
/// <summary>
/// 主程式
/// </summary>
/// <returns></returns>
int main() {
	//int a = 10, b = 20;
	int A[] = { 0,10,40,5,16,1 };

	int B[100000];
	int  array_lengthB = sizeof(B) / sizeof(B[0]);
	int  array_length = sizeof(A) / sizeof(A[0]);
	clock_t start_time, end_time;
	printf("array_length=%d\n", array_length);
	Print(&A, &array_length);
	Bubble_Sort(&A, &array_length);
	Print(&A, &array_length);
	PutRandomNumberInArray(&B, &array_lengthB);
	Print(&B, &array_lengthB);
	printf("\n印完");
	start_time = clock(); /* mircosecond */
	Bubble_Sort(&B, &array_lengthB);
	end_time = clock();
	printf("\n start to print out results\n");
	//Print(&B, &array_lengthB); //印出結果B陣列
	/* CLOCKS_PER_SEC is defined at time.h */ 
	float total_time = (float)(end_time - start_time) / CLOCKS_PER_SEC; //總共時間

	printf("Time : %f sec \n", total_time);
	
}