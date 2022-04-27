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
	} else {
		hc2_3_2a();
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
