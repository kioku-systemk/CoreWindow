//
//  test.cpp
//  CoreWindowTest
//
//  Created by kioku on 12/07/07.
//  Copyright (c) 2012 System K. All rights reserved.
//

#include "Core/CoreWindow.h"

// GL Headers
#if defined(__EMSCRIPTEN__)
#include <GLES2/gl2.h>
#elif defined(__APPLE__)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <stdio.h>

class MainWindow : public CoreWindow
{
public:
	MainWindow(int x, int y, int width, int height)
	: CoreWindow(x, y, width, height, "CoreWindow Test")
	{
	}
	~MainWindow()
    {
    }
	
	void MouseLeftDown(int x, int y)
	{
        printf("MouseLeftDown(%d,%d)\n", x,y);
	}
	void MouseLeftUp(int x, int y)
	{
        printf("MouseLeftUp(%d,%d)\n", x,y);
	}
    void MouseRightDown(int x, int y)
	{
        printf("MouseRightDown(%d,%d)\n", x,y);
	}
	void MouseRightUp(int x, int y)
	{
        printf("MouseRightUp(%d,%d)\n", x,y);
	}

	void MouseMove(int x, int y)
	{
        printf("MouseMove(%d,%d)\n", x,y);
	}
	void Wheel(float dx, float dy, float dz)
	{
        printf("Wheel(%f,%f,%f)\n", dx,dy,dz);
	}
	void KeyDown(int key)
	{
        printf("KeyDown=%d\n", key);
	}
	void KeyUp(int key)
	{
        printf("KeyUp=%d\n", key);
	}
	
	void Magnify(float z)
	{
		printf("Magnify=%f\n", z);
	}
	void Swipe(float dx, float dy, float dz)
	{
		printf("Swipe(%f,%f,%f)\n", dx,dy,dz);
	}
	void Rotate(float r)
	{
		printf("Rotate=%f\n", r);
	}
    void Draw()
    {
        glClearColor(0.5,0.5,0.5,0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // own graphics code.
        
        SwapBuffer();
    }
     
	void Idle(void)
	{
        Draw();
	}
	
	void Resize(int w, int h)
	{
        glViewport(0, 0, w, h);
        Draw();
	}
    
private:
    int m_mode;
};

int main(int argc, char *argv[])
{
    MainWindow win(32, 32, 720, 480);
    CoreWindow::MainLoop();
    return 0;
}
