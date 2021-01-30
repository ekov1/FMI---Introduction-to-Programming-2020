//�������� �������� dictionary, ����� �� ������������� �������� ������
//�� ���� � �������� ��������� �� ����������� ����� ����� �� ����������
//���� �� �������� � �������.
//
//������:
//
//const char* dictionary[] = { �cats�, �dogs� };
//����: it�s raining cats and dogs
//����� : 2

#include <iostream>


using namespace std;

int main()
{
	const unsigned int MAX_INPUT = 1024;

	const char* dic[] = { "cats","dogs","animals" };

	char input[MAX_INPUT];

	cin.getline(input, MAX_INPUT);

	char* curWord = strtok(input, " ");

	while (curWord != nullptr) {
		cout << curWord << " " << endl;
		curWord = strtok(nullptr, " ");
	}
}

bool DicContains(const char* dic[], const char* word, const int dicSize) {
	for (int i = 0; i < dicSize; ++i)
	{
		if (strcmp(word,dic[i]))
		{
			return true;
		}
	}
	return false;
}
