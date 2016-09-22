#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>


#include "tkionolib.h"


::std::string getSciencePath();


int getRadarIri(::std::string strday, ::std::string radar, ::std::vector< ::std::vector< ::std::vector<double> > > &aIono)
{
  ::std::string path = getSciencePath() + "/iono/iri-" + radar + "/" + strday + "." + radar + ".dat";
  ::std::ifstream infile (path.c_str(), ::std::ifstream::in);
  ::std::string line;

  while (std::getline(infile, line))
  {
    // Format:
    // 0        9  12 15        25        35   ... etc (24 values)
    // |        |  |  |         |         |         |         |         |
    // 20100101 15 00    356959    357988    351689    342460    337082    341266 .... etc
    int bm = atoi(line.substr(9, 2).c_str());
    int rg = atoi(line.substr(12, 2).c_str());
    for (int i = 0; i < 24; i++)
      aIono[bm][rg][i] = atof(line.substr(15 + (10 * i), 9).c_str());
  }
  infile.close();
  return 0;
}






::std::string getSciencePath()
{
  ::std::string envName = "SCIENCEPATH";
  ::std::string envValue;
  char* cEnvValue;
  cEnvValue = ::std::getenv(envName.c_str());
  if (!cEnvValue)
    throw ::std::runtime_error("Environmental variable SCIENCEPATH not defined");
  envValue = ::std::string(cEnvValue);
  return envValue;
}
