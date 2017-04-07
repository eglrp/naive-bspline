# naive-bspline

A naive implementation of B-spline by c++

## Description
- Naive implementation of B-spline function
- Translation of [scipy.interpolate.BSpline Examples](https://docs.scipy.org/doc/scipy/reference/generated/scipy.interpolate.BSpline.html#scipy.interpolate.BSpline) into c++

## Requirement
- c++11

## NaiveBSpline class
```
const int k = 2;                                       // spline degree
const std::vector<double> t = { 0, 1, 2, 3, 4, 5, 6 }; // knot vector
const std::vector<double> c = { -1, 2, 0, -1 };        // spline coefficients

NaiveBSpline bspline(t, c, k);

// Evaluate a spline function
const double x = 2.5;
const double y = bspline(x);
```

## Sample code
### How to build
```
$ git clone https://github.com/gishi523/naive-bspline.git
$ cd naive-bspline
$ mkdir build
$ cd build
$ cmake ../
$ make
```

### How to run
```
./bspline
```

## Author
gishi523
