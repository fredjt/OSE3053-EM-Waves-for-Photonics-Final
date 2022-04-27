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

void hc2_3_2a(double theta_i = 45, double n_o = 1.658, double n_e = 1.486);
void hc2_3_2b(double theta_i = 45, double n_o = 1.658, double n_e = 1.486);

void hc2_3_2() {
	char defaults;

	cout << "\n2)\nUse default values? (Y/N): ";
	cin >> defaults;

	if (defaults != 'Y' && defaults != 'y') {
		double theta_i, n_o, n_e;

		cout << "Incidence angle theta_i (degrees): ";
		cin >> theta_i;

		cout << "Ordinary refractive index n_O: ";
		cin >> n_o;

		cout << "Extraordinary refractive index n_E: ";
		cin >> n_e;

		hc2_3_2a(theta_i, n_o, n_e);
		hc2_3_2b(theta_i, n_o, n_e);
	} else {
		hc2_3_2a();
		hc2_3_2b();
	}
}

void hc2_3_2a(double theta_i, double n_o, double n_e) {
	double theta_e = rad2deg(asin(sin(deg2rad(theta_i)) / n_e));
	double theta_o = rad2deg(asin(sin(deg2rad(theta_i)) / n_o));

	cout << "\na\n\nOrdinary angle of refraction theta_O: ";
	cout << theta_o;
	cout << "°\nExtraordinary angle of refraction theta_E: ";
	cout << theta_e;
	cout << "°\n";
}

void hc2_3_2b(double theta_i, double n_o, double n_e) {
	double theta_ko = rad2deg(asin(sin(deg2rad(theta_i)) / n_o));
	double k_pa = sin(deg2rad(theta_i));
	double k_pe = n_e * sqrt(1 - 1 / (2 * pow(n_o, 2)));
	double theta_ke = rad2deg(atan(k_pa / k_pe));

	cout << "\na\n\nOrdinary angle of propagation theta_O: ";
	cout << theta_ko;
	cout << "°\nExtraordinary angle of propagation theta_E: ";
	cout << theta_ke;
	cout << "°\n";
}
