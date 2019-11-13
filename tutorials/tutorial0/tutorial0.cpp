#include <iostream>
#include <libcellml>

#include "../../utilities/tutorial_utilities.h"

int main()
{
  std::cout << "Hello libCellML user!" << std::endl;
  std::cout << " The version number is "<<libcellml.version.versionHeading()<<std::endl;
}