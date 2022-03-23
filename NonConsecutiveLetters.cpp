#include <iostream>

void switchChar(char& aParam)
{
	switch (aParam)
	{
	case 'X':
	{
		aParam = 'O';
		break;
	}
	case 'O':
	default:
	{
		aParam = 'X';
		break;
	}
	}
};

class solution
{
private:
	int mXCount;
	int mOCount;
	std::string resultStr;

	void increaseCount(const char& aParam, int& countX, int& countO)
	{
		switch (aParam)
		{
		case 'X':
			countX++;
			break;
		case 'O':
			countO++;
			break;
		}
	};

	bool canSwitchChar(const char& aParam, const int& countX, const int& countO)
	{
		switch (aParam)
		{
		case 'X':
			return countO <= mOCount;
		case 'O':
			return countX <= mXCount;
		}
	};

public:
	solution(int aXCount, int aOCount) : mXCount(aXCount), mOCount(aOCount)
	{};

	std::string getResult()
	{
		std::string result;
		char aggChar = 'X';
		int xCount = 0;
		int oCount = 0;
		bool changeChar = false;
		auto count = 0;
		for (auto i = 0; i < (mOCount + mXCount); i++)
		{
			if (count > 2)
			{
				changeChar = true;
			}
			else if (aggChar == 'X')
			{
				if (xCount >= mXCount || ((mOCount - oCount) % 3 == 0))
				{
					changeChar = true;
				}
			}
			else if (aggChar == 'O')
			{
				if (oCount >= mOCount || ((mXCount - xCount) % 3 == 0))
				{
					changeChar = true;
				}
			}

			if (changeChar && canSwitchChar(aggChar, xCount + 1, oCount + 1))
			{
				count = 0;
				changeChar = false;
				switchChar(aggChar);
			}

			count++;
			increaseCount(aggChar, xCount, oCount);
			result += aggChar;
		}

		return result;
	}

};
int main()
{
	solution s(9,2);
	std::cout << s.getResult();
}