#include <iostream>

using namespace std;

int tasksCount;
int minutesNeeded;
int minutesLeft;

int* tasksIndex;
double* tasksTime;
double* tasksPoints;
long double* coefficients;
int* indexes;
int* bestIndexes;
int bestSum = 0;
int bestTime = 0;

void ReadInput();
void SortByCoefficient();
void Swap(double* xp, double* yp);
void Swap(int* xp, int* yp);
void Swap(long double* xp, long double* yp);
void CheckWhichTasksCanBeCompleted();
void InitializeCoefficients();
void SubsetSums(int l, int r, int sum = 0, int time = 0);
void PrintIndexes(int* x);

int* CopyArr(int* arr);

bool DefinitelyGreaterThan(float a, float b, float epsilon)
{
	return (a - b) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

int main()
{
	ReadInput();
	
	InitializeCoefficients();
	SortByCoefficient();

	CheckWhichTasksCanBeCompleted();

	// free memory
	delete[]tasksIndex;
	delete[]tasksTime;
	delete[]tasksPoints;
	delete[]indexes;
	delete[]coefficients;
	delete[]bestIndexes;

}

void CheckWhichTasksCanBeCompleted() {
	// check if all tasks can be done
	if (minutesNeeded <= minutesLeft)
	{
		cout << "Tasks: ";

		int taskCanBeDoneCount = 0;
		int testTime = minutesLeft;
		for (int i = 0; i < tasksCount; i++)
		{
			int taskTimeNeeded = tasksTime[i];
			if (taskTimeNeeded <= testTime)
			{
				// do task
				testTime -= taskTimeNeeded;
				++taskCanBeDoneCount;
			}
		}

		for (int i = 0; i < tasksCount; i++)
		{
			int taskTimeNeeded = tasksTime[i];
			if (taskTimeNeeded <= minutesLeft)
			{
				// do task
				minutesLeft -= taskTimeNeeded;
				if (taskCanBeDoneCount > 1)
				{
					cout << tasksIndex[i] << ", ";
				}
				else {
					cout << tasksIndex[i];
				}
				--taskCanBeDoneCount;
			}
		}

		int hours = minutesLeft / 60;
		minutesLeft %= 60;
		cout << endl;
		cout << "Time remaining: " << hours << ':' << minutesLeft;
	}
	else {
		SubsetSums(0, tasksCount - 1);

		PrintIndexes(bestIndexes);
	}
}

void PrintIndexes(int* x) {
	int countIndexes = 0;
	for (int i = 0; i < tasksCount; i++)
	{
		if (x[i] >= 0)
		{
			++countIndexes;
		}
	}

	cout << "Tasks: ";
	for (int i = 0; i < tasksCount; i++)
	{
		if (x[i] >= 0)
		{
			if (countIndexes > 1)
			{
				cout << x[i] << ", ";
			}
			else {
				cout << x[i];
			}
			--countIndexes;
		}
	}
	cout << endl;

	bestTime = minutesLeft - bestTime;
	int hours = bestTime / 60;
	bestTime %= 60;
	cout << "Time remaining: " << hours << ':' << bestTime;
}

int* CopyArr(int* arr) {
	int* temp = new int[tasksCount];
	for (int i = 0; i < tasksCount; i++)
	{
		temp[i] = arr[i];
	}
	return temp;
}

// get sums of all subsets of arr[l..r] 
void SubsetSums(int l, int r, int sum, int time)
{
	// Print current subset 
	if (l > r)
	{
		if (time <= minutesLeft) {

			if (sum > bestSum)
			{
				bestSum = sum;
				bestTime = time;
				bestIndexes = CopyArr(indexes);
			}
		}
		return;
	}

	indexes[l] = tasksIndex[l];

	// Subset including arr[l] 
	SubsetSums(l + 1, r, sum + tasksPoints[l], time + tasksTime[l]);
	indexes[l] = -1;
	// Subset excluding arr[l] 
	SubsetSums(l + 1, r, sum, time);

	indexes[l] = -1;
}

void ReadInput() {
	// read tasks count
	cin >> tasksCount;

	// intitialize lists
	tasksIndex = new int[tasksCount];
	tasksPoints = new double[tasksCount];
	tasksTime = new double[tasksCount];
	indexes = new int[tasksCount];

	// read tasks
	int index, taskPoints, taskTime;
	for (int i = 0; i < tasksCount; i++)
	{
		cin >> index >> taskTime >> taskPoints;
		tasksIndex[i] = index;
		tasksPoints[i] = taskPoints;
		tasksTime[i] = taskTime;
		minutesNeeded += taskTime;
	}

	// read days left
	int daysLeft;
	cin >> daysLeft;
	int minutesLeftPerDay;
	for (int i = 0; i < daysLeft; i++)
	{
		cin >> minutesLeftPerDay;
		minutesLeft += minutesLeftPerDay;
	}
}

//sorts task lists by coefficients
void SortByCoefficient() {
	int i, j;
	bool swapped;
	for (i = 0; i < tasksCount - 1; i++)
	{
		swapped = false;
		for (j = 0; j < tasksCount - i - 1; j++)
		{
			if (DefinitelyGreaterThan(coefficients[j + 1], coefficients[j], DBL_EPSILON))
			{
				Swap(&tasksPoints[j], &tasksPoints[j + 1]);
				Swap(&tasksIndex[j], &tasksIndex[j + 1]);
				Swap(&tasksTime[j], &tasksTime[j + 1]);
				Swap(&coefficients[j], &coefficients[j + 1]);

				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break 
		if (swapped == false)
			break;
	}
}

// sort tasks list by time
// needs tasks to be sorted by points first
//void SortByTime() {
//	int i, j;
//	bool swapped;
//	for (i = 0; i < tasksCount - 1; i++)
//	{
//		swapped = false;
//		for (j = 0; j < tasksCount - i - 1; j++)
//		{
//			if (tasksPoints[j] == tasksPoints[j + 1])
//			{
//				if (tasksTime[j] > tasksTime[j + 1])
//				{
//					Swap(&tasksPoints[j], &tasksPoints[j + 1]);
//					Swap(&tasksIndex[j], &tasksIndex[j + 1]);
//					Swap(&tasksTime[j], &tasksTime[j + 1]);
//
//					swapped = true;
//				}
//			}
//
//		}
//
//		// IF no two elements were swapped by inner loop, then break 
//		if (swapped == false)
//			break;
//	}
//}
void Swap(long double* xp, long double* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void Swap(double* xp, double* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void Swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void InitializeCoefficients() {
	coefficients = new long double[tasksCount];

	for (int i = 0; i < tasksCount; ++i)
	{
		long double coefficient = (tasksPoints[i] / tasksTime[i]) * 10000;
		coefficients[i] = coefficient;
	}
}










