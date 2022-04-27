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

using namespace std;

void hc2_3_4a(double lambda0 = 600, double d = 5, double n = 1.33);
void hc2_3_4b(double lambda0 = 600, double d = 5, double n = 1.33);

void hc2_3_4() {
	char defaults;

	cout << "\n4)\nUse default values? (Y/N): ";
	cin >> defaults;

	if (defaults != 'Y' && defaults != 'y') {
		double lambda0, d, n;

		cout << "Wavelength lambda_0 (nm): ";
		cin >> lambda0;

		cout << "Waveguide width d (µm): ";
		cin >> d;

		cout << "Waveguide refractive index n: ";
		cin >> n;

		hc2_3_4a(lambda0, d, n);
		hc2_3_4b(lambda0, d, n);
	} else {
		hc2_3_4a();
		hc2_3_4b();
	}
}

void hc2_3_4a(double lambda0, double d, double n) {
	int m = 2000 * n * d / lambda0;

	cout << "\na)\n\nNumber of TE and TM modes m: ";
	cout << m;
	cout << "\n";
}

void hc2_3_4b(double lambda0, double d, double n) {
	int m = 2000 * n * d / lambda0;
	double v_g1 = 1 / n * sqrt(1 - pow(lambda0 / (2000 * n * d), 2));
	double v_g22 = 1 / n * sqrt(1 - pow(m * lambda0 / (2000 * n * d), 2));

	cout << "\nb)\n\nFastest group velocity: ";
	cout << v_g1;
	cout << "c\nSlowest group velocity: ";
	cout << v_g22;
	cout << "c\n";
}
