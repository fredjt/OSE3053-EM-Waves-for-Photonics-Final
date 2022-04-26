#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

void hc1_1();
void hc1_2();

int main() {
	hc1_1();
	return (0);
}

void hc1_1a(double t = 100, double n_m = 1.4, int l_min = 20, int l_max = 100);
void hc1_1b(double n_m = 1.4, double z_min = -200, double z_max = 100,
		double k0 = M_PI / 70);
void hc1_1c();

void hc1_1() {
	double t, n_m, e_iy0, z_min, z_max, k0;
	int l_min;
	int l_max;

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

	cout << "Actual wavenumber for E-field plot (1/nm): ";
	cin >> k0;

	hc1_1a(t, n_m, l_min, l_max);
//	hc1_1a();

	hc1_1b(n_m, z_min, z_max, k0);
//	hc1_1b();
}

void hc1_1a(double t, double n_m, int l_min, int l_max) {
	cout << "\na)\n";
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
			"clear\nclc\nfigure\ndata = importdata(\"data1.txt\");\nplot(data(:, 1), data(:, 2),'DisplayName','data')\nylim([0, 1])\ntitle(\"Transmission vs. Wavenumber\")\nylabel(\"Transmission\")\nxlabel(\"k_0 (\\mum^{-1})\")");
	cout << "Open HC1_1.m in MATLAB and execute to plot transmission\n";
}

void hc1_1b(double n_m, double z_min, double z_max, double k0) {
	FILE *file = fopen("data2.txt", "w"), *matlab_file = fopen("HC1_1b.m", "w");

	double t_fp = (n_m + 1) / (2 * n_m);
	double t_fm = (n_m - 1) / (2 * n_m);
	for (int i = z_min; i < z_max; i++) {
		fprintf(file, "%lf %ls\n");
	}
}

void hc1_1c() {
	cout << "";
}

void hc1_2() {
	cout << "";
}
