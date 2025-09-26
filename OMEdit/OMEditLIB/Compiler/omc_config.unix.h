/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF AGPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.8.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THE OSMC PUBLIC LICENSE OR THE GNU AGPL
 * VERSION 3, ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the OSMC (Open Source Modelica Consortium)
 * Public License (OSMC-PL) are obtained from OSMC, either from the above
 * address, from the URLs:
 * http://www.openmodelica.org or
 * https://github.com/OpenModelica/ or
 * http://www.ida.liu.se/projects/OpenModelica,
 * and in the OpenModelica distribution.
 *
 * GNU AGPL version 3 is obtained from:
 * https://www.gnu.org/licenses/licenses.html#GPL
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */

/*  */
#define CONFIGURE_COMMANDLINE "Configured  using arguments: ''"
#define CONFIG_DLL_EXT ".so"
#define CONFIG_MODELICA_SPEC_PLATFORM "linux64"
#define CONFIG_OPENMODELICA_SPEC_PLATFORM "x86_64-linux"
#define CONFIG_OPENMODELICA_SPEC_PLATFORM_ALTERNATIVE ""
#define CONFIG_TRIPLE "x86_64-linux-gnu"

#define DEFAULT_CC "/usr/bin/cc"
#define DEFAULT_CXX "/usr/bin/c++"
#define DEFAULT_OMPCC "/usr/bin/cc -fopenmp"

#if defined(__sparc__)
  #define DEFAULT_LINKER "/usr/bin/cc -G"
#elif defined(__APPLE_CC__)
  #define DEFAULT_LINKER "/usr/bin/cc -single_module -dynamiclib -flat_namespace"
#elif defined(__x86_64__)
  /* -fPIC needed on x86_64! */
  #define DEFAULT_LINKER "/usr/bin/cc -shared"
#else
  #define DEFAULT_LINKER "/usr/bin/cc -shared"
#endif

#define DEFAULT_CFLAGS "-DOM_HAVE_PTHREADS -fPIC -DOM_HAVE_PTHREADS "

/* Define as HAVE_LAPACK if we have lapack support*/
#define HAVE_LAPACK
/* Define as HAVE_LAPACK_DEPRECATED if we have deprecated lapack functions (v < 3.6)*/
#define HAVE_LAPACK_DEPRECATED



#define CONFIG_DEFAULT_OPENMODELICAHOME ""
#define CONFIG_REVISION "v1.26.0-dev-287-gcef2838d45-cmake"
#define CONFIG_WITH_OPENMP 1

/* Skip compiling against some stuff for the JavaScript runtime */
#if !defined(OMC_EMCC) && !defined(OMC_MINIMAL_RUNTIME)
#define WITH_SUNDIALS
/* OMC_HAVE_IPOPT Not needed for CMake build. Availability and use of ipopt is handled by the CMakefiles.*/
#define WITH_SUITESPARSE
#define WITH_HWLOC 0
#define WITH_LIBUUID 1
#endif
#if !defined(OMC_MINIMAL_RUNTIME)
#define WITH_DASSL
#endif

#define USE_GRAPH 0
#if USE_GRAPH
#define USE_PATOH 
#define USE_METIS 
#endif

