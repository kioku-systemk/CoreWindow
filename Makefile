INCS=
LIBS=-lGL

DEFINES = -g `gtk-config --cflags --libs`

CXX=g++

all:
	$(CXX) $(INCS) $(DEFINES) test.cpp Core/CoreWindow_x11.cpp $(LIBS) -o Test
