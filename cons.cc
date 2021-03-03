/* Console interface to mtools.cc
 * 28/3/2000
 */

#include "mtools.h"
#include <iostream.h>

void main(void) {
	GregDate*	Dates;
	Dates = new GregDate(28, 3, 2000);

	if (Dates->isValid()) {
		cout << "JDN:   " << Dates->Julian->Julian() << "\n\n";
		cout << "Bak:   " << Dates->Longcount->Bak() << "\n";
		cout << "Kat:   " << Dates->Longcount->Kat() << "\n";
		cout << "Tun:   " << Dates->Longcount->Tun() << "\n";
		cout << "Uin:   " << Dates->Longcount->Uin() << "\n";
		cout << "Kin:   " << Dates->Longcount->Kin() << "\n\n";
		cout << "Day:   " << Dates->Gregorian->Day() << "\n";
		cout << "Month: " << Dates->Gregorian->Month() << "\n";
		cout << "Year:  " << Dates->Gregorian->Year() << "\n";
	}

	delete Dates;

	return(0);
}
