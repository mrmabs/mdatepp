/* mtools.cc date converter routines
 * by Marcus Berglund
 * 20/03/2000
 * Copyright under the GPL.
 *
 * 28/03/2000 - finished and cleaned up code a littl
 */

#include <math.h>
#include "mtools.h"

#define JD_CORRELATION 584285.0L

// Convert to Gregorian date
Greg::Greg(double jdn) {
	int		day, month, year;
	int		jalpha, ja, jb, jc, jd, je;

	jalpha = (int)(((jdn - 1867216) - 0.25) / 36524.25);
	ja = (int)(jdn + 1 + jalpha - ((int)((0.25 * jalpha))));
	jb = (int)(ja + 1524);
	jc = (int)(6680.0 + ((jb - 2439870.0) - 122.1) / 365.25);
	jd = (int)(365.0 * jc + (0.25 * jc));
	je = (int)((jb - jd) / 30.6001);

	day = (jb - jd - ((int)( 30.6001 * je ) ));
	while (day < 0)
		day = day + 7;
	
	month = je - 1;
	if ( month > 12 )
		month = month - 12;
	while (month < 0)
		month = month + 12;

	year = jc - 4715;
	if (month > 2 )
		year = year - 1;
	
	this->day = day;
	this->month = month;
	this->year = year;

	return;
}

// Convert to longcount -- optimised, no need for my_mod -- yet...
LongC::LongC(double jdn) {
	double	longcount, rem;

	longcount = jdn - JD_CORRELATION; // XXX: if's not required here???

	this->bak = (int)floor(longcount / 144000);
	rem = longcount - ((double)this->bak * 144000);
	this->kat = (int)floor(rem / 7200);
	rem = rem - ((double)this->kat * 7200);
	this->tun = (int)floor(rem / 360);
	rem = rem - ((double)this->tun * 360);
	this->uin = (int)floor(rem / 20);
	rem = rem - ((double)this->uin * 20);
	this->kin = (int)floor(rem);

	return;
}

// Check gregorian date & convert to jdn
GregDate::GregDate(int day, int month, int year) {
	// Check to see if date is valid
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	daysInMonth[1] = isGregLeapYear(year) ? 29 : 28;

	if (month < 1 || month > 12)
		return; // valid is already 0, so it should be ok...
	
	if (day < 1 || day > daysInMonth[month - 1])
	    return; // as above...
	
	this->valid = 1;

	// Now convert to jdn.
	int		jm;
	double	jul, ja;
	
	if (month > 2) {
		jm = month + 1;
	} else {
		year = year - 1;
		jm = month + 13;
	}
	
	// XXX: I will have to look at the below code in more detail later,
	// I am a bit iffy about how it all works....
	jul = (int) (floor(365.25 * year)) + (floor((30.6001 * jm) +
			(day + 1720995.0)));
	ja = (int)(0.01 * year);
	jul = (int)(jul + (2 - ja + ((int)(0.25 * ja))));

	this->jdn = jul;
	this->doCals();
	return;
}

// Check if year is leap year
bool GregDate::isGregLeapYear(int year) {
	return !(year % 100 ? year % 4 : year % 400);
}

// check to see if the given jdn is valid
JDNDate::JDNDate(double jdn) {
	if (jdn < JD_CORRELATION)
		return;
	this->valid = 1;
	this->doCals();
	return;
}

LongcountDate::LongcountDate(int bak, int kat, int tun, int uin, int kin) {
	double  semijdn;

	// validate longcount XXX: check if these are valid date ranges
	if (bak <= 0 || bak >= 20 )
		return;
	if (kat <= 0 || kat >= 20 )
		return;
	if (tun <= 0 || tun >= 20 )
		return;
	if (uin <= 0 || uin >= 18 )
		return;
	if (kin <= 0 || kin >= 20 )
		return;

	this->valid = 1;
	
	semijdn = (double)((bak * 144000.0) + (kat * 7200.0) +
				(tun * 360.0) + (uin * 20.0) + kin);
	
	this->jdn = semijdn + JD_CORRELATION;
	this->doCals();
	return;
}

// do calender generation
void Date::doCals() {
	Gregorian = new Greg(this->jdn);
	Julian = new JDN(this->jdn);
	Longcount = new LongC(this->jdn);
}

Date::Date() {
	this->valid = 0;
}

Date::~Date() {
	delete Gregorian;
	delete Julian;
	delete Longcount;
}
