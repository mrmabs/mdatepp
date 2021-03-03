/* mtools.h date converter declarations
 * by Marcus Berglund
 * 20/03/2000
 * Copyright under the GPL.
 *
 * 28/03/2000 - minor fixes
 */

//@{
/** Gregorian Date convertor class.<br>
 * This class, which is inside the Date classes turns a jdn into
 * gregorian (everyday) date format.
 *
 * @author Marcus Berglund
 * @version 2000.03.20
 */

class Greg {
	public:
		/** Constructor
		 * @param jdn Julian Day Number
		 */
					Greg(double jdn);
		/** Day
		 * @return Day of month 1 - 31
		 */
		int			Day()   { return(this->day); }
		/** Month
		 * @return Month of year 1 - 12
		 */
		int			Month() { return(this->month); }
		/** Year
		 * @return Gregorian Year
		 */
		int			Year()  { return(this->year); }
	private:
		int			day;
		int			month;
		int			year;
};
//@}

//@{
/** Julian Date convertor class.<br>
 * Currently has no major code, because all date fromats are generated
 * from the JDN.
 *
 * @author Marcus Berglund
 * @version 2000.03.20
 */

class JDN {
	public:
		/** Constructor
		 * @param jdn Julian Day Number
		 */
					JDN(double jdn) { this->jdn = jdn; }
		/** Julian
		 * @return Julian Day Number
		 */
		double		Julian() { return(this->jdn); }
	private:
		double		jdn;
};
//@}

//@{
/** Longcount Date convertor class.<br>
 * Converts a jdn into Longcount for the Date classes.
 *
 * @author Marcus Berglund
 * @version 2000.03.20
 */

class LongC {
	public:
		/** Constructor
		 * @param jdn Julian Day Number
		 */
					LongC(double jdn);
		/** Bak
		 * @return Longcount Bak
		 */
		int			Bak() { return(this->bak); }
		/** Kat
		 * @return Longcount Kat
		 */
		int			Kat() { return(this->kat); }
		/** Tun
		 * @return Longcount Tun
		 */
		int			Tun() { return(this->tun); }
		/** Uin
		 * @return Longcount Uin
		 */
		int			Uin() { return(this->uin); }
		/** Kin
		 * @return Longcount Kin
		 */
		int			Kin() { return(this->kin); }
	private:
		int			bak;
		int			kat;
		int			tun;
		int			uin;
		int			kin;
};
//@}

//@{
/** Date class.<br>
 * This is the base date class.
 *
 * @author Marcus Berglund
 * @version 2000.03.20
 */

class Date {
	public:
		/// Constructor
					Date();
					~Date();
		Greg*		Gregorian;
		JDN*		Julian;
		LongC*		Longcount;

		/** used to see if if the constructor was sucessful
		 * @return boolean True/False value
		 */
		bool		isValid() { return(this->valid); } // check to see if data
													  // was valid
	protected:
		double		jdn; // this is just to make life easier for now...
		bool		valid;
		void		doCals(); // FIXME ugly hack :(
};
//@}

//@{
/** Gregorian Date class.<br>
 * This is the class that we use if we start with a Gregorian Date.
 *
 * @author Marcus Berglund
 * @version 2000.03.20
 */

class GregDate : public Date {
	public:
			/// Checks Gregorian date
					GregDate(int day, int month, int year);
	private:
			/// Check if year is leap year
			bool	isGregLeapYear(int year);
};
//@}

//@{
/** Julian Day Number Date class.<br>
 * This is the class we use if we start with a JDN.
 *
 * @author Marcus Berglund
 * @version 2000.03.20
 */

class JDNDate : public Date {
	public:
			/// Checks JDN
					JDNDate(double jdn);
};
//@}

//@{
/** Longcount Date class.<br>
 * This is the class we use if we start with a Longcount.
 *
 * @author Marcus Berglund
 * @version 2000.03.20
 */

class LongcountDate : public Date {
	public:
			/// Check Longcount
					LongcountDate(int bak, int kat, int tun, int uin, int kin);
};
//@}
