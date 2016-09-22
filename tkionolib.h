#include <string>
#include <vector>

/**
* Library for various ionospheric functions
*
* @author  Tom Kane
* @version 1.0
* @since   2016-09-22
*/

/**
* Get hourly NmF2 for a radar FoV
* <p>
* Get hourly values of NmF2 for each range/beam cell of a specified radar for a specified day
*
* @param strday String value of the day in question
* @param radar The radar in question
* @param aIono vector for storing NmF2 values (passed as reference)
*/
int getRadarIri(::std::string strday, ::std::string radar, ::std::vector< ::std::vector< ::std::vector<double> > > &aIono);
