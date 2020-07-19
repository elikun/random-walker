# Compile Commander subsystem
qmake -o Makefile_Commander main.pro CONFIG+=config_commander
make -f Makefile_Commander

# Compile Environment subsystem
qmake -o Makefile_Environment main.pro CONFIG+=config_environment
make -f Makefile_Environment

# Copy in /app/exe/ directory
cp -f ./SS_Commander/commander /app/exe/commander
cp -f ./SS_Environment/environment /app/exe/environment
