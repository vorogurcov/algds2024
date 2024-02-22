#include "Header.h"

long long** CreateMatrix(int const n, int const k)
{
	long long** NewMatrix = (long long**)malloc((n + 1) * sizeof(long long*));
	for (size_t i = 0; i < n + 1; i++)
	{
		NewMatrix[i] = (long long*)malloc((k + 1)*sizeof(long long));
		for (size_t j = 0; j < k + 1; j++)
			NewMatrix[i][j] = -1;
	}
	return NewMatrix;
}

void ShowMatrix(long long** matr,int n, int k)
{
	for (size_t i = 0; i < n+1; i++)
	{
		for (size_t j = 0; j < k+1; j++)
		{
			printf("%d ", matr[i][j]);
		}
		putchar('\n');
	}
}

int IsInMemo(int const n, int const remainder, memo const Memo)
{
	if (Memo.n == n && Memo.remainder == remainder)
		return 1;
	else
		return 0;
}

FullMemo* InitFullMemo()
{
	FullMemo* NewMemo = (FullMemo*)malloc(sizeof(FullMemo));
	NewMemo->MemoArray = (memo*)malloc(sizeof(memo));
	NewMemo->MemoSize = 0;
	return NewMemo;
}
//
//memo* Finder(int const n, int const remainder)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		for (size_t j = 0; j < remainder; j++)
//		{
//			
//		}
//	}
//}

void AddToMemo(int const n, int const remainder, int const Amount, FullMemo* Memo)
{
	Memo->MemoArray = (memo*)realloc(Memo->MemoArray, (++Memo->MemoSize)*sizeof(memo));

	Memo->MemoArray[Memo->MemoSize - 1].Amount = Amount;
	Memo->MemoArray[Memo->MemoSize - 1].remainder = remainder;
	Memo->MemoArray[Memo->MemoSize - 1].n = n;
}

void ZeroFill(long long* const arr, int const Size)
{
	for (size_t i = 0; i < Size; i++)
		arr[i] = 0;
}

long long GetSum(long long* const arr, int const Size)
{
	long long summ = 0;
	for (size_t i = 0; i < Size; i++)
		summ += arr[i];
	return summ;
}

long long FindAmount(int const n, int const k, long long** HelperMatrix)
{
	

	if (k == 0)
	{
		return 1;
	}
	else if (k < 0)
		return 0;
	else if (k > 0 && n == 0)
		return 0;

	if (HelperMatrix[n][k] != -1)
		return HelperMatrix[n][k];

	long long Amount[10];
	ZeroFill(Amount, 10);
	for (size_t num = 0; num < 10; num++)
	{
		int remainder = k - num;
		if (remainder > 9 * (n - 1))
		{
			HelperMatrix[n - 1][remainder] = 0;
			continue;
		}
		
		Amount[num] = FindAmount(n - 1, remainder, HelperMatrix);
		if (Amount[num])
			HelperMatrix[n - 1][remainder] = Amount[num];
		
	}
	return GetSum(Amount,10);
}

