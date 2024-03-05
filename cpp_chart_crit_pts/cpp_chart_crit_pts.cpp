#include <iostream>
#include <vector>

double calcFunction(double x)
{
	//return 30.0f * sin(x*3.14/180.0f);
	return 30.0f * sin(10*x*3.14 / 180.0f) * exp(-0.001*x);
}

int main()
{
    std::cout << "Input x1, x2, n\n";
	double x1 = 0, x2 = 0;
	int n = 100;
	std::cin >> x1 >> x2 >> n;

	double dx = (x2 - x1) / (double)n;
	//std::cout << "dx=" << dx << "\n";

	std::vector<double> dataSet = {};
	std::vector<double> dataSetX = {};
	
	//fill data vector
	for (int i = 0; i < n; i++)
	{
		dataSetX.push_back(x1 + dx * i);
		dataSet.push_back(calcFunction(dataSetX[i]));
		//std::cout << i << "] " << dataSet[i] << "\n";
	}

	//analyze vector
	std::vector<double> critPoints = {};
	std::vector<double> critPointsX = {};

	for (int i = 1; i < (n - 1); i++)
	{
		double v_curr = dataSet[i];
		double v_prev = dataSet[i - 1];
		double v_next = dataSet[i + 1];

		double x_curr = dataSetX[i];
		double x_prev = dataSetX[i - 1];
		double x_next = dataSetX[i + 1];

		if (((v_next >= v_curr) && (v_prev >= v_curr)) ||
			((v_next <= v_curr) && (v_prev <= v_curr)))
		{
			critPointsX.push_back((x_curr + x_prev + x_next) / 3.0f);
			critPoints.push_back((v_curr + v_prev + v_next) / 3.0f);
		}
	}

	int cp = 0;
	for(int i=0;i<critPoints.size();i++)
	{
		cp++;
		std::cout << cp << ") " << critPointsX[i] << "; " << critPoints[i] <<"\n";	
	}

	system("pause");
}