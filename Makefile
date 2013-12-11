
# for Linux if NO, don't depend on GTK
USE_GTK_FILEDIALOG = YES

UNAME=$(shell uname)
ifeq ($(UNAME),Linux)
  LIBS=-lGL
  ifeq ($(USE_GTK_FILEDIALOG),YES)
    GTK=`pkg-config gtk+-2.0 --libs --cflags` -DUSE_GTK
  endif
  DEFINES = -O2 $(GTK)
  CXX=g++
  SRC=test.cpp
  COREWIN=Core/CoreWindow_x11.cpp
else # MacOSX
  LIBS=-framework OpenGL -framework Cocoa
  DEFINES = -O2
  CXX=clang++
  SRC=test.cpp
  COREWIN=Core/CoreWindow_mac.mm
endif


all:
	$(CXX) $(DEFINES) $(SRC) $(COREWIN) $(LIBS) -o Test
