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

#include <cmath>
#include <iostream>

#include "../main.hpp"

using namespace std;

void hc2_3_1a(double n_o = 1.658, double n_e = 1.486, double lambda0 = 400,
		double theta = 60, double e_0 = 10);
void hc2_3_1b(double n_o = 1.658, double n_e = 1.486, double theta = 60);

void hc2_3_1() {
	char defaults;

	cout << "\n3)\nUse default values? (Y/N): ";
	cin >> defaults;

	if (defaults != 'Y' && defaults != 'y') {
		double n_o, n_e, lambda0, theta, e_0;

		cout << "Ordinary refractive index n_O: ";
		cin >> n_o;

		cout << "Extraordinary refractive index n_E: ";
		cin >> n_e;

		cout << "Wavelength lambda_0 (nm): ";
		cin >> lambda0;

		cout << "Angle of wavevector theta (degrees): ";
		cin >> theta;

		cout << "Amplitude of electric field E_0 (kV / m): ";
		cin >> e_0;

		hc2_3_1a(n_o, n_e, lambda0, theta, e_0);
		hc2_3_1b(n_o, n_e, theta);
	} else {
		hc2_3_1a();
		hc2_3_1b();
	}
}

void hc2_3_1a(double n_o, double n_e, double lambda0, double theta,
		double e_0) {
	double k_hat[2];
	k_hat[0] = sin(deg2rad(theta));
	k_hat[1] = cos(deg2rad(theta));
	double n = n_e * n_o
			/ sqrt(pow(k_hat[0] * n_o, 2) + pow(k_hat[1] * n_e, 2));
	double k0 = 2 * M_PI / lambda0;
	double k[2];
	k[0] = k0 * n * k_hat[0];
	k[1] = k0 * n * k_hat[1];
	double e0[2];
	e0[0] = e_0 * pow(n_e, 2) * k_hat[1]
			/ sqrt(
					pow(n_o, 4) * pow(k_hat[0], 2)
							+ pow(n_e, 4) * pow(k_hat[1], 2));
	e0[1] = -e_0 * pow(n_o, 2) * k_hat[0]
			/ sqrt(
					pow(n_o, 4) * pow(k_hat[0], 2)
							+ pow(n_e, 4) * pow(k_hat[1], 2));

	// Solutions have 10^-7 on the k-vector instead of 10^7
	cout << "\na)\n\nComplex harmonic electric field: E(r) = (";
	cout << e0[0];
	if (e0[1] > 0)
		cout << " x_hat + ";
	else
		cout << " x_hat - ";
	cout << abs(e0[1]);
	cout << " z_hat) * exp[(";
	cout << k[0] * pow(10, 9);
	if (k[1] > 0)
		cout << "x + ";
	else
		cout << "x - ";
	cout << abs(k[1]) * pow(10, 9);
	cout << "z) m^-1] kV/m\n";
}

void hc2_3_1b(double n_o, double n_e, double theta) {
	double k_hat[2];
	k_hat[0] = sin(deg2rad(theta));
	k_hat[1] = cos(deg2rad(theta));
	double n = n_e * n_o
			/ sqrt(pow(k_hat[0] * n_o, 2) + pow(k_hat[1] * n_e, 2));
	cout << "\nb)\n\nEffective refractive index: ";
	cout << n;
	cout << "\n";
}
