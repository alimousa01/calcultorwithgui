# 1. Set the OBJECTS variable. It should contain all the
#    object files needed to generate an executable separated
#    by spaces. If you for example have two C source files,
#    file1.c and file2.c, you should enter:
#      SOURCES = file1.c file2.c
#

SOURCES = calc.c functioncalc.c functioncalc.h

# 2. Set the TARGET variable to the name of the executable.
#    This is the program generated by make, and the name you
#    enter at the Unix prompt to run it.
#

TARGET  = calc

# 3. Type make at the Unix prompt and press return.
#
# Hints:
#  * A few additional flags (such as compiler, optimisation, ...)
#    can be set by modifying the variables below.
#  * Enter 'make clean' at the Unix prompt to clean up the
#    directory. The command removes the executable and object
#    files generated by make.
#
# Please refer to the make manual for additional information.
# The manual for GNU Make is avaliable at http://www.gnu.org
#
# Martin Horauer (horauer@technikum-wien.at)
#-------------------------------------------------------------

#-------------------------------------------------------------
# CXX       - C compiler to use, e.g. gcc
# CXXFLAGS  - compiler flags
# CPPFLAGS  - preprocessor flags, e.g. -I. to look for include
#             files in the current directory
# LDFLAGS   - linker flags, e.g. -lm to link with the math library

CXX      = gcc
CXXFLAGS = `pkg-config --cflags --libs gtk+-3.0` -Wall -g
CPPFLAGS = -I.
LDFLAGS  = -lm

#-------------------------------------------------------------
# Make rules
#
$(TARGET): $(SOURCES)
	$(CXX) $(SOURCES) $(LDFLAGS) $(CXXFLAGS) -o $(TARGET)

.PHONY: clean
clean:
	@rm -rf $(OBJECTS) $(TARGET) core *~

