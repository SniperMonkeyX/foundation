#include "src/graphics/window.h"
#include "src/math/vec2.h"

int main()
{
    using namespace foundation;
    using namespace graphics;

    Window window("Foundation", 800, 600);
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    auto vec = math::vec2(3.0f, 5.0f);
    auto org = vec;
    vec += org;
    std::cout << vec << std::endl;
    vec -= org;
    std::cout << vec << std::endl;
    vec *= org;
    std::cout << vec << std::endl;
    vec /= org;
    std::cout << vec << std::endl;

    float xOffset = 0.0f;
    float yOffset = 0.0f;
    while (!window.isClosed())
    {
        window.clear();
#if 1
        if (window.isKeyPressed(GLFW_KEY_RIGHT)) {
            xOffset += 0.001f;
        }
        if (window.isKeyPressed(GLFW_KEY_LEFT)) {
            xOffset -= 0.001f;
        }
        if (window.isKeyPressed(GLFW_KEY_UP)) {
            yOffset += 0.001f;
        }
        if (window.isKeyPressed(GLFW_KEY_DOWN)) {
            yOffset -= 0.001f;
        }

        if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_1)) {
            xOffset = 0.0f;
            yOffset = 0.0f;
        }

        glBegin(GL_POLYGON);
        glVertex2f(0.2f + xOffset, 0.8f + yOffset);
        glVertex2f(0.2f + xOffset, -0.5f + yOffset);
        glVertex2f(-0.2f + xOffset, -0.5f + yOffset);
        glVertex2f(-0.2f + xOffset, 0.8f + yOffset);
        glEnd();
#else
        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
        window.update();
    }

    return 0;
}