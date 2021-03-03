/* Console interface to mtools.cc
 * 28/3/2000
 */

#include "mtools.h"
#include <iostream>

int main(void) {
	GregDate*	Dates;
	Dates = new GregDate(3, 3, 2021);

	if (Dates->isValid()) {
        std::cout << "JDN:   " << std::to_string(Dates->Julian->Julian()) << "\n\n";
        std::cout << "Bak:   " << Dates->Longcount->Bak() << "\n";
        std::cout << "Kat:   " << Dates->Longcount->Kat() << "\n";
        std::cout << "Tun:   " << Dates->Longcount->Tun() << "\n";
        std::cout << "Uin:   " << Dates->Longcount->Uin() << "\n";
        std::cout << "Kin:   " << Dates->Longcount->Kin() << "\n\n";
        std::cout << "Day:   " << Dates->Gregorian->Day() << "\n";
        std::cout << "Month: " << Dates->Gregorian->Month() << "\n";
        std::cout << "Year:  " << Dates->Gregorian->Year() << "\n";
	}

	delete Dates;

	return(0);
}
