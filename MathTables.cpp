/* MathTables.cpp
// Daniel Salazar
// 7/21/17 10:28pm
//
// Refer to THE HAND BOOK OF MATHEMATICAL TABLES by
// Selby, Weast, Shankland, and Hodgman
//
// The logarithm of a number is the exponent of that power to which another number,
// the base, must be raised to give the number first named. Any positive number
// greater than 1 might serve as a base.
// Two bases are used:
// 1) Base e (2.718281...) {natural, Naperian, or Hyperbolic}
// 2) Base 10 {common or Briggsian}
//
// The common logs of all numbers expressed by the
// same figures in the same order with the decimal
// point in different positions have different
// characteristics (left of the radix) but the same mantissa
// (right of the radix).
*/
#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include<string>
#include<iomanip>

// Logarithm
#define BASE2 M_E
#define BASE10 10
// Trigonometry
#define PI M_PI
#define MINUTE 60


// Logarithm
double_t log_x(int base, double_t x)
{
	switch (base)
	{
	case 2: return log(x);
		break;
	case 10: return log10(x);
		break;
	default: return (log(x) / log(base));
	}
}
double antilog_x(int base, double_t x)
{
	if (base == 2) return exp(x);
	else return pow(base, x);
}
double colog_x(int base, double_t x)
{
	return log_x(base, (1 / x));
}
double_t n_mult(int base, double_t x, double_t y)
{
	// cout << n_mult(BASE10, 52600, 0.00381);
	return antilog_x(base, (log_x(base, x) + log_x(base, y)));
}
double_t n_div(int base, double_t x, double_t y)
{
	// cout << n_div(BASE10, 0.00123, 52.7);
	return antilog_x(base, (log_x(base, x) - log_x(base, y)));
}
double_t n_root(int base, double_t x, double_t n)
{
	// cout << n_root(BASE10, 492, 5);
	return antilog_x(base, log_x(base, x) / n);
}
double_t n_power(int base, double_t x, double_t n)
{
	// cout << n_power(BASE10, 0.000372, (-1.32));
	return antilog_x(base, (colog_x(base, x) * abs(n)));
}
void fractionalLog10()
{
	std::cout << "N" << std::endl;
	int space = 0;
	for (double_t i = 0.1; i <= 0.9; i += 0.1)
	{
		for (double_t j = 0.00; j <= 0.09; j += 0.01)
		{
			double_t ij = i + j;
			std::cout << std::fixed << std::setprecision(2) << ij << "\t";
			std::cout << std::setprecision(4) << log_x(BASE10, ij) << "\t";
			std::cout << std::endl;
			if ((++space % 5) == 0)
			{
				std::cout << "N" << std::endl;
			}
		}
	}
}
void fractionalLog2()
{
	std::cout << "N";
	int space = 0;
	for (double_t i = 0.00; i <= 0.90; i += 0.10)
	{
		for (double_t j = 0.00; j <= 0.09; j += 0.01)
		{
			double_t ij = i + j;
			std::cout << std::fixed << std::setprecision(2) << ij << "\t";
			std::cout << std::setprecision(4) << log_x(BASE2, ij) << "\t";
			std::cout << std::endl;
			if ((++space % 5) == 0)
			{
				std::cout << "N" << std::endl;
			}
		}
	}
}
void decimalLog10()
{
	std::cout << "N\t";
	int space = 0;
	for (int i = 10; i <= 1190; i += 10)
	{
		for (int j = 0; j <= 9; ++j)
		{
			int ij = i + j;
			std::cout << ij << "\t";
			std::cout << std::fixed << std::setprecision(5) << log_x(BASE10, ij) << "\t";
			std::cout << std::endl;
			if ((++space % 5) == 0)
			{
				std::cout << "N" << std::endl;
			}
		}
	}
}
void decimalLog2()
{
	std::cout << "N";
	std::cout << std::endl;
	int space = 0;
	for (int i = 0; i <= 990; i += 10)
	{
		for (int j = 0; j <= 9; ++j)
		{
			int ij = i + j;
			std::cout << ij << "\t";
			std::cout << std::fixed << std::setprecision(5) << log_x(BASE2, ij) << "\t";
			std::cout << std::endl;
			if ((++space % 5) == 0)
			{
				std::cout << "N" << std::endl;
			}
		}
	}
}
void antiLog()
{
	std::cout << "N";
	std::cout << std::endl;
	int space = 0;
	for (double_t i = 0.0; i <= 0.9; i += 0.1)
	{
		for (double_t j = 0.00; j <= 0.09; j += 0.01)
		{
			double_t ij = i + j;
			std::cout << std::fixed << std::setprecision(2) << ij << "\t";
			std::cout << std::setprecision(4) << antilog_x(BASE10, ij) << "\t";
			std::cout << std::endl;
			if ((++space % 5) == 0)
			{
				std::cout << "N" << std::endl;
			}
		}
	}
}
void exponential()
{
	std::cout << "x\te^x\tlog(e^x)   e^(-x)" << std::endl;
	int space = 0;
	for (double_t i = 0.0; i <= 9.0; i += 1.0)
	{
		for (double_t j = 0.00; j <= 0.99; j += 0.05)
		{
			double_t ij = i + j;
			std::cout << std::fixed << std::setprecision(2) << ij << "\t";
			std::cout << std::setprecision(1) << antilog_x(BASE2, ij) << "\t";
			std::cout << std::setprecision(5) << log_x(BASE10, antilog_x(BASE2, ij)) << "\t   ";
			std::cout << std::setprecision(7) << antilog_x(BASE2, -1.0 * ij) << "\t";
			std::cout << std::endl;
			if ((++space % 5) == 0)
			{
				std::cout << std::endl << "x\te^x\tlog(e^x)   e^(-x)" << std::endl;
			}
		}
	}
}
std::string radianCircle(double_t ij)
{
	switch (int(ij * 100))
	{
	case 0: return "0.00";
		break;
	case 26: return "PI/12";
		break;
	case 52: return "PI/6";
		break;
	case 78: return "PI/4";
		break;
	case 104: return "PI/3";
		break;
	case 130: return "5PI/12";
		break;
	case 157: return "PI/2";
		break;
	case 183: return "7PI/12";
		break;
	case 209: return "2PI/3";
		break;
	case 235: return "3PI/4";
		break;
	case 261: return "5PI/6";
		break;
	case 287: return "11PI/12";
		break;
	case 314: return "PI";
		break;
	case 340: return "13PI/12";
		break;
	case 366: return "7PI/6";
		break;
	case 392: return "5PI/4";
		break;
	case 418: return "4PI/3";
		break;
	case 445: return "17PI/12";
		break;
	case 471: return "3PI/2";
		break;
	case 497: return "19PI/12";
		break;
	case 523: return "5PI/3";
		break;
	case 549: return "7PI/4";
		break;
	case 575: return "11PI/6";
		break;
	case 602: return "23PI/12";
		break;
	case 628: return "2PI";
		break;
	default: return  std::to_string(ij).substr(0, 4);
	}
}
void printRow(int type, double_t i, double_t j)
{
	double_t ij = i + j, sine = sin(ij),
		cosine = cos(ij), tangent = tan(ij),
		sinSqr = sine*sine, cosSqr = cosine * cosine;
	std::cout << std::fixed << std::setprecision(2) << radianCircle(ij) << "\t";

	switch (type)
	{
	case 0: std::cout << std::setprecision(2) << sine << "\t" << cosine <<
		"\t" << tangent << "\t" << 1 / sine << "\t"  << 1 / cosine <<
		"\t" << 1 / tangent << "\t" << std::endl;
		break;
	case 1: std::cout << std::setprecision(2) << log_x(BASE10, abs(sine)) <<
		"\t"<< log_x(BASE10, abs(cosine)) << "\t" <<
		log_x(BASE10, abs(tangent)) << "\t" <<
		log_x(BASE10, abs((1 / sine))) << "\t" <<
		log_x(BASE10, abs((1 / cosine))) << "\t" <<
		log_x(BASE10, abs((1 / tangent))) << "\t" << std::endl;
		break;
	case 2: std::cout << std::setprecision(2) << sinSqr << "\t" <<
		sine * cosine << "\t" << cosSqr << "\t" << sinSqr * cosSqr <<
		"\t" << std::endl;
		break;
	default: std::cout << "Error" << std::endl;
	}
}
void trig()
{
	std::cout << "Rad.\tSin\tCos\tTan\tCsc\tSec\tCot" << std::endl;
	int space = 0;
	for (double_t i = 0.0; i <= 6.0; i += 1.0)
	{
		for (double_t j = 0.00; j <= 0.99; j += 0.01)
		{
			if ((i + j) > 6.28) return;
			printRow(0, i, j);
			if ((++space % 5) == 0)
			{
				std::cout << std::endl << "Rad.\tSin\tCos\tTan\tCsc\tSec\tCot" << std::endl;
			}
		}
	}
}
void trigLog()
{
	std::cout << "Rad.\tL.Sin\tL.Cos\tL.Tan\tL.Csc\tL.Sec\tL.Cot" << std::endl;
	int space = 0;
	for (double_t i = 0.0; i <= 6.0; i += 1.0)
	{
		for (double_t j = 0.00; j <= 0.99; j += 0.01)
		{
			if ((i + j) > 6.28) return;
			printRow(1, i, j);
			if ((++space % 5) == 0)
			{
				std::cout << std::endl << "Rad.\tSin\tCos\tTan\tCsc\tSec\tCot" << std::endl;
			}
		}
	}
}
void trigSquare()
{
	std::cout << "Rad.\tsin^2\tSin*Cos\tCos^2\t(sinx)^2 * (cosx)^2" << std::endl;
	int space = 0;
	for (double_t i = 0.0; i <= 6.0; i += 1.0)
	{
		for (double_t j = 0.00; j <= 0.99; j += 0.01)
		{
			if ((i + j) > 6.28) return;
			printRow(2, i, j);
			if ((++space % 5) == 0)
			{
				std::cout << "Rad.\tsin^2\tSin*Cos\tCos^2\t(sinx)^2 * (cosx)^2" << std::endl;
			}
		}
	}
}

void printTable(int choice)
{
	switch (choice)
	{
	case 1: fractionalLog10();
		break;
	case 2: fractionalLog2();
		break;
	case 3: decimalLog10();
		break;
	case 4: decimalLog2();
		break;
	case 5: antiLog();
		break;
	case 6: exponential();
		break;
	case 7: trig();
		break;
	case 8: trigLog();
		break;
	case 9: trigSquare();
		break;
	default: system("cls");
	}
}
int main()
{
	int choice = 0;
	do
	{
		system("cls");
		std::cout << "Select option 1-7:\n";
		std::cout << "1)fractionalLog10\n2)fractionalLog2\n";
		std::cout << "3)decimalLog10\n4)decimalLog2\n";
		std::cout << "5)antiLog\n6)compare exp to log\n";
		std::cout << "7)trig\n8)trigLog\n9)trigSquare\n";
		std::cin >> choice;
		if (choice > 0 && choice < 10)
		{
			printTable(choice);
			system("pause");
		}
	} while (choice > 0 && choice < 10);
	return 0;
}
