#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace foundation {
namespace graphics {
    
#define MAX_KEYS 512
#define MAX_MOUSE_BTNS 512

    class Window
    {
    private:
        const char *m_title;
        int m_width, m_height;

        GLFWwindow *m_window;

        bool m_keysPressed[MAX_KEYS] = {0};
        bool m_mouseBtnsPressed[MAX_MOUSE_BTNS] = {0};
        double m_mx, m_my;

    public:
        Window(const char *name, int width, int height);
        ~Window();

        bool isClosed() const;

        void update();
        void clear() const;

        bool isKeyPressed(int key);
        bool isMouseButtonPressed(int button);

    private:
        bool init();

        friend static void windowResize(GLFWwindow* window, int width, int height);
        friend static void keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);
        friend static void mouseButtonCallback(GLFWwindow* window, int button, int action, int modes);
        friend static void cursorPosCallback(GLFWwindow* window, double xPos, double yPos);
    };
} 
}