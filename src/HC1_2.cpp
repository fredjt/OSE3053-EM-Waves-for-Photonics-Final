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

void hc1_2a(double lambda0 = 600, double n_f = 2.0, double theta_b = 20);

void hc1_2() {
	char defaults;

	cout << "2)\nUse default values? (Y/N): ";
	cin >> defaults;

	if (defaults != 'Y' && defaults != 'y') {
		double lambda0, n_f, theta_b;

		cout << "Wavelength (nm): ";
		cin >> lambda0;

		cout << "Film refractive index n_f: ";
		cin >> n_f;

		cout << "Brewster's angle theta_B (deg): ";
		cin >> theta_b;

		hc1_2a(lambda0, n_f, theta_b);
	} else {
		hc1_2a();
	}
}

void hc1_2a(double lambda0, double n_f, double theta_b) {
	double d = lambda0
			/ (4 * sqrt(pow(n_f, 2) - pow(sin(theta_b * M_PI / 180), 2)));
	cout << "\na)\n\nMinimum film thickness for 100% transmission: ";
	cout << d;
	cout << " nm\n";
}
