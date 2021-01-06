int fib(int n, int memoization[])
{
	if (n == 0) return 1;
	if (n == 1) return 1;

	if (memoization[n] != -1)
	{
		return memoization[n];
	}

	int r = fib(n - 1, memoization) + fib(n - 2, memoization);
	memoization[n] = r;
	return r;
}

int fib(int n)
{
	int* mem = new int[n + 1];
	for (int i = 0; i < n + 1; ++i)
	{
		mem[i] = -1;
	}
	int r = fib(n, mem);

	delete[]mem;

	return r;
}


int fib2(int n, int a = 0, int b = 1)
{
	if (n == 0) return b;
	return fib2(n - 1, b, a + b);
}


int main()
{
	for (int i = 0; i < 20; ++i)
		std::cout << fib(i) << " " << fib2(i) << std::endl;

	return 0;
}