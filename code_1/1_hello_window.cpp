// 包含GLFW的头文件之前包含了GLAD的头文件
// 需要在其他依赖于OpenGL的头文件之前包含GLAD
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

// 注册一个回调函数，当用户改变窗口大小的时候，及时调整视口
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    // 实例化GLFW窗口
    // 初始化GLFW
    glfwInit();
    // 配置GLFW的主版本号（MAJOR）和次版本号（MINOR）
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // 使用核心模式
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // 创建窗口对象，创建完窗口可以通知窗口的上下文设置为当前线程的主上下文
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if(window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // 注册函数，通知GLFW及时改变视口
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // GLAD是用来管理OpenGL的函数指针的
    // 在调用任何OpenGL的函数之前初始话GLAD
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // 循环渲染（Render Loop）
    // 每次循环开始前检查一次GLFW是否被要求退出
    while(!glfwWindowShouldClose(window)) {
        // 输入函数，一个窗口以及一个按键作为输入
        processInput(window);

        // 渲染
        // 设置清空屏幕所用的颜色，设置为0.2 0.3 0.3的颜色
        // 清空屏幕的颜色缓冲，接受一个缓冲位（Buffer Bit）来指定要清空的缓冲
        // glClearColor函数是一个状态设置函数
        // glClear函数则是一个状态使用函数，使用了当前状态来获取应该清除为的颜色
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 交换颜色缓冲（一个存储着GLFW窗口每一个像素颜色值的大缓冲）
        // 在该次循环中被用来绘制，并且将会作为输出显示在屏幕上
        glfwSwapBuffers(window);
        // 检查是否触发事件、更新窗口状态，并调用对应的回调函数
        glfwPollEvents();
    }

    // 正确释放/删除之前的分配的所有资源
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // 设置视口
    glViewport(0, 0, width, height);
}