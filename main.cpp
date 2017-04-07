#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

class NaiveBSpline
{
public:

	static double B(double x, int k, int i, const std::vector<double>& t)
	{
		if (k == 0)
			return x >= t[i] && x < t[i + 1] ? 1 : 0;
		const double c1 = t[i + k] != t[i] ? (x - t[i]) / (t[i + k] - t[i]) * B(x, k - 1, i, t) : 0;
		const double c2 = t[i + k + 1] != t[i + 1] ? (t[i + k + 1] - x) / (t[i + k + 1] - t[i + 1]) * B(x, k - 1, i + 1, t) : 0;
		return c1 + c2;
	}

	NaiveBSpline(const std::vector<double>& t, const std::vector<double>& c, int k)
		: _t(t), _c(c), _k(k)
	{
	}

	double operator()(double x)
	{
		const size_t n = _t.size() - _k - 1;
		assert(n >= (size_t)_k + 1 && _c.size() >= n);
		double y = 0;
		for (size_t i = 0; i < n; i++)
			y += _c[i] * B(x, _k, i, _t);
		return y;
	}

private:

	std::vector<double> _t;
	std::vector<double> _c;
	int _k;
};

int main()
{

	const int k = 2;
	const std::vector<double> t = { 0, 1, 2, 3, 4, 5, 6 };
	const std::vector<double> c = { -1, 2, 0, -1 };

	NaiveBSpline bspline(t, c, k);
	
	std::ofstream ofs("spline.txt");

	const int n = 50;
	const double xb = 1.5;
	const double xe = 4.5;
	const double step = (xe - xb) / (n - 1);

	for (int i = 0; i < n; i++)
	{
		const double x = step * i + xb;
		const double y = bspline(x);
		ofs << x << " " << y << std::endl;
	}

	return 0;
}
