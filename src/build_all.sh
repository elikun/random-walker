# Compile Commander subsystem
## qmake operating mode  : makefile
## qmake output makefile : Makefile_Commander
## qmake project file    : main.pro
## section in .pro file  : config_commander
## debug level           : DEBUG 3 (-d -d -d)
qmake -makefile -o Makefile_Commander main.pro CONFIG+=config_commander -d -d -d
make -f Makefile_Commander

# Compile Environment subsystem
## qmake operating mode  : makefile
## qmake output makefile : Makefile_Environment
## qmake project file    : main.pro
## section in .pro file  : config_environment
## debug level           : DEBUG 3 (-d -d -d)
qmake -makefile -o Makefile_Environment main.pro CONFIG+=config_environment -d -d -d
make -f Makefile_Environment

# Deploy in /app/exe/ directory
cp -f ./SS_Commander/commander /app/exe/commander
cp -f ./SS_Environment/environment /app/exe/environment
