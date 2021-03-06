// Stack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include"Stack.h"
int getPriority(char opt)
{
	switch (opt) {
	case '#': return 0;
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 2;
	default: throw 2;
	}
}
int compare(char optA, char optB)
{
	return getPriority(optA) - getPriority(optB);
}
double calculate(double v1, double v2, char opt)
{
	switch (opt) {
	case '+': return v1 + v2;
	case '-': return v1 - v2;
	case '*': return v1 * v2;
	case '/': return v1 / v2;

	}
}
double evaluate(const char *expression)
{
	Stack<float> values;
	Stack<char> operators;
	int i = 0;
	char ch;
	while ((ch = expression[i]) != '\0')
	{
		i++;
		if (ch >= '0'&& ch <= '9')
		{
			values.push(ch-48);
		}
		else
		{
			while (operators.top > 0 && compare(ch, operators.peek()) <= 0)
			{
				float f2 = values.pop();
				float f1 = values.pop();
				char c = operators.pop();
				values.push(calculate( f1, f2, c));
			}
			operators.push(ch);
		}
	}
	return values.pop();
}
int main()
{
	cout << evaluate("3-4+5#")<<endl;
	cout << evaluate("3-4*2+5#") << endl;
	cout << evaluate("5/4#") << endl;
	cout << evaluate("6-4/5+2*6#") << endl;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
