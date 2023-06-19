// 顶点数组对象：Vertex Array Object，VAO
// 顶点缓冲对象：Vertex Buffer Object，VBO
// 元素缓冲对象：Element Buffer Object，EBO
//            或 Index Buffer Object， IBO
// 3D坐标（在OpenGL，所有事物都是在3D空间中）转为2D坐标的处理过程是由OpenGL的图形渲染管线实现的
// Step.1 3D坐标转换为2D坐标
// Step.2 2D坐标转变为实际有颜色的像素
// 完整过程：顶点数据--顶点着色器--形状（图元）装配--几何着色器--光栅化--片段着色器--测试与混合
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// 顶点着色器，GLSL（OpenGL Shading Language）
// OpenGL在过程中动态编译
const char* vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main() \n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";
// 片段着色器：红色、绿色、蓝色和透明度（alpha）分量，RGBA
const char* fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                   "}\n\0";

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if(window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // 创建一个顶点着色器对象，并用ID引用
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // 着色器源码附加到着色器对象上，并编译
    // glShaderSource第一个参数：要编译的着色器对象，第二个参数：传递的源码字符串数量
    // 第三个参数：顶点着色器真正的源码，第四个参数：先暂定为NULL
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // 检测是否编译成功
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        // 获取错误信息
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // 创建一个片段着色器对象，并编译
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // 创建一个着色器程序，并返回新创建程序对象的ID引用
    unsigned int shaderProgram = glCreateProgram();
    // 将之前的着色器附加到程序上，并链接
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // 检测链接着色器程序是否失败
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKED_FAILED\n" << infoLog << std::endl;
    }
    // 将着色器对象链接到程序对象以后，删除着色器对象
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // 顶点输入
    // 当且仅当3D坐标在3个轴（x、y和z）上-1.0到1.0的范围内时才处理，标准化设备坐标（Normalized Device Coordinates，NDC）
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    };

    // 创建一个VAO和一个VBO
    unsigned int VBO, VAO;
    // OpenGL的核心模式要求使用VAO，如果绑定失败，则拒绝绘制任何东西
    glGenVertexArrays(1, &VAO);
    // 利用glGenBuffers函数和一个缓冲ID生成一个VBO对象
    glGenBuffers(1, &VBO);

    // 绑定VAO
    glBindVertexArray(VAO);
    // GL_ARRAY_BUFFER顶点缓冲对象类型，使用glBindBuffer函数将新创建的缓冲绑定到GL_ARRAY_BUFFER目标上
    // 此后使用GL_ARRAY_BUFFER目标上的缓冲调用都会用来配置当前绑定的缓冲VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // 将之前定义的顶点数据复制到缓冲的内存中
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // OpenGL解析顶点数据
    // 第一个参数：对应顶点着色器layout（location=0）定义position顶点属性，设置为0
    // 第二个参数：vec3
    // 第三个参数：数据类型，浮点数
    // 第四个参数：是否标准化（Normalize）到【0，1】之间
    // 第五个参数：步长，连续顶点属性组之间的间隔
    // 第六个参数：在缓冲中起始位置的偏移量
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    // 以顶点属性位置值作为参数，启用顶点属性，顶点属性默认是禁用的
    glEnableVertexAttribArray(0);

    // 解绑VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // 解绑VAO
    glBindVertexArray(0);

    while(!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 将着色器程序作为参数，激活程序对象
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}