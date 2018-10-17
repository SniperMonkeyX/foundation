#include "window.h"

namespace foundation {
namespace graphics {

    // Callbacks
    void windowResize(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key < 0) return;

        auto fWindow = (Window*)glfwGetWindowUserPointer(window);
        fWindow->m_keysPressed[key] = (action != GLFW_RELEASE);
    }

    void mouseButtonCallback(GLFWwindow* window, int button, int action, int modes)
    {
        if (button < 0) return;

        auto fWindow = (Window*)glfwGetWindowUserPointer(window);
        fWindow->m_mouseBtnsPressed[button] = (action != GLFW_RELEASE);
    }

    void cursorPosCallback(GLFWwindow* window, double xPos, double yPos)
    {
        auto fWindow = (Window*)glfwGetWindowUserPointer(window);
        fWindow->m_mx = xPos;
        fWindow->m_my = yPos;
    }

    // Window
    Window::Window(const char *tile, int width, int height)
    {
        m_title = tile;
        m_width = width;
        m_height = height;

        if (!init())
        {
            glfwTerminate();
        }
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    bool Window::init()
    {
        if (!glfwInit()) 
        {
            std::cout << "Failed to init glfw :(" << std::endl;
            return false;
        }

        m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
        if (!m_window)
        {
            std::cout << "Failed to create GLFW window :(" << std::endl;
            return false;
        }

        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, this);
        glfwSetWindowSizeCallback(m_window, windowResize);
        glfwSetKeyCallback(m_window, keyCallback);
        glfwSetMouseButtonCallback(m_window, mouseButtonCallback);
        glfwSetCursorPosCallback(m_window, cursorPosCallback);

        if (glewInit() != GLEW_OK) {
            std::cout << "Could not init glew :(" << std::endl;
            return false;
        }

        std::cout << glGetString(GL_VERSION) << std::endl;
        
        return true;
    }

    bool Window::isClosed() const
    {
        return glfwWindowShouldClose(m_window);
    }

    void Window::update()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    void Window::clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    bool Window::isKeyPressed(int key) {
        return m_keysPressed[key];
    }

    bool Window::isMouseButtonPressed(int button) {
        return m_mouseBtnsPressed[button];
    }
} }