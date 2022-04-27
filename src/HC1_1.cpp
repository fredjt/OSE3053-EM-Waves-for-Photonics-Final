////////////////////////////////////////////////////////////////////////////////////
// MIT License                                                                    //
//                                                                                //
// Copyright (c) 2022 fredjt                                                      //
//                                                                                //
// Permission is hereby granted, free of charge, to any person obtaining a copy   //
// of this software and associated documentation files (the "Software"), to deal  //
// in the Software without restriction, including without limitation the rights   //
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      //
// copies of the Software, and to permit persons to whom the Software is          //
// furnished to do so, subject to the following conditions:                       //
//                                                                                //
// The above copyright notice and this permission notice shall be included in all //
// copies or substantial portions of the Software.                                //
//                                                                                //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     //
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       //
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    //
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         //
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  //
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  //
// SOFTWARE.                                                                      //
////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

void hc1_1a(double t = 100, double n_m = 1.4, int l_min = 20, int l_max = 100);
void hc1_1b(double t = 100, double n_m = 1.4, double z_min = -100,
		double z_max = 200, int k_max = 4);
void hc1_1c(double t = 100, double n_m = 1.4, double z_min = -100,
		double z_max = 200, int k_max = 4);

void hc1_1() {
	char defaults;
	cout << "1)\nUse default values? (Y/N): ";
	cin >> defaults;

	if (defaults != 'Y' && defaults != 'y') {
		double t, n_m, e_iy0, z_min, z_max;
		int l_min, l_max, k_max;

		cout << "Question 1\n\nEnter membrane thickness (nm): ";
		cin >> t;

		cout << "Refractive index of membrane n_m: ";
		cin >> n_m;

		cout << "Initial electric field in y-direction E_i,y,0 (V/m): ";
		cin >> e_iy0;

		cout << "Minimum wavelength (nm): ";
		cin >> l_min;

		cout << "Maximum wavelength (nm): ";
		cin >> l_max;

		cout << "\nb)\n\nMinimum z position (nm): ";
		cin >> z_min;

		cout << "Maximum z position (nm): ";
		cin >> z_max;

		cout << "Maximum for E-field plot: ";
		cin >> k_max;

		hc1_1a(t, n_m, l_min, l_max);
		hc1_1b(t, n_m, z_min, z_max, k_max);
	} else {
		hc1_1a();
		hc1_1b();
		hc1_1c();
	}
}

void hc1_1a(double t, double n_m, int l_min, int l_max) {
	cout << "\na)\nOpen HC1_1a.m in MATLAB and execute to plot transmission\n";
	FILE *file = fopen("data1.txt", "w"), *matlab_file = fopen("HC1_1a.m", "w");

	double r_if = (1 - n_m) / (1 + n_m);
	double r_fs = (n_m - 1) / (1 + n_m);
	double t_if = 2 / (1 + n_m);
	double t_fs = 2 * n_m / (1 + n_m);

	for (float i = l_max; i >= l_min; i -= 0.1) {
		fprintf(file, "%lf %lf\n", 2 * M_PI / i,
				pow(t_fs, 2) * pow(t_if, 2)
						/ (2 * cos(2 * t * n_m * 2 * M_PI / i) * r_fs * r_if
								+ pow(r_fs, 2) * pow(r_if, 2) + 1));
	}

	fprintf(matlab_file,
			"clear\nclc\nfigure\ndata1 = importdata(\"data1.txt\");\nplot(data1(:, 1), data1(:, 2))\nylim([0, 1])\ntitle(\"Transmission vs. Wavenumber\")\nylabel(\"Transmission\")\nxlabel(\"k_0 (\\mum^{-1})\")");
}

void hc1_1b(double t, double n_m, double z_min, double z_max, int k_max) {
	cout
			<< "\nb)\nOpen HC1_1b.m in MATLAB and execute to plot electric field\n";
	FILE *file = fopen("data2.txt", "w"), *matlab_file = fopen("HC1_1b.m", "w");

	double t_fp = (n_m + 1) / (2 * n_m);
	double t_fm = (n_m - 1) / (2 * n_m);
	double k0 = k_max * M_PI / (n_m * t);
	for (double i = z_min; i < min(z_max, 0.); i++)
		fprintf(file, "%lf %lf 1\n", i, cos(k0 * i));
	if (z_max > 0)
		for (double i = 0; i < min(z_max, t); i++)
			fprintf(file, "%lf %lf 2\n", i, (t_fm + t_fp) * cos(n_m * k0 * i));
	for (double i = t; i < z_max; i++)
		fprintf(file, "%lf %lf 3\n", i, cos(k0 * i - t * k0));

	fprintf(matlab_file,
			"clear\nclc\nfigure\ndata2 = importdata(\"data2.txt\");\nplot(data2(:, 1), data2(:, 2))\nxline(0)\nxline(%lf)\ntitle(\"Electric Field Amplitude at t=0\")\nylabel(\"E (V/m)\")\nxlabel(\"z (nm)\")",
			t);
}

void hc1_1c(double t, double n_m, double z_min, double z_max, int k_max) {
	cout
			<< "\nc)\nOpen HC1_1c.m in MATLAB and execute to plot electric field\n";
	FILE *file = fopen("data3.txt", "w"), *matlab_file = fopen("HC1_1c.m", "w");

	double k0 = (k_max + 0.5) * M_PI / (n_m * t);
	double r = -(pow(n_m, 2) - 1) / (pow(n_m, 2) + 1);
	double t_s_i = -1 / (2 * (pow(n_m, 2) + 1));
	double t_fp = (r - t_s_i + 1) / 2;
	double t_fm = (r + t_s_i + 1) / 2;

	for (double i = z_min; i < min(z_max, 0.); i++)
		fprintf(file, "%lf %lf 1\n", i, (r + 1) * cos(k0 * i));
	if (z_max > 0)
		for (double i = 0; i < t; i++)
			fprintf(file, "%lf %lf 2\n", i, (t_fm + t_fp) * cos(n_m * k0 * i));
	// TODO: Amplitude seems off
	for (double i = t; i < z_max; i++)
		fprintf(file, "%lf %lf 3\n", i, (-sin(k0 * i - t * k0)) / n_m);

	fprintf(matlab_file,
			"clear\nclc\nfigure\ndata3 = importdata(\"data3.txt\");\nplot(data3(:, 1), data3(:, 2))\nxline(0)\nxline(%lf)\ntitle(\"Electric Field Amplitude at t=0\")\nylabel(\"E (V/m)\")\nxlabel(\"z (nm)\")",
			t);
}
