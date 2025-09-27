#include "PythonEnv.h"
#include <iostream>

PythonEnv::PythonEnv() {
    error_log_file = fopen("python_env_error.log", "a");
    if (!error_log_file) {
        std::cerr << "Warning: Could not open error log file" << std::endl;
    }
    try {
        // 初始化Python解释器
        interpreter = std::make_unique<py::scoped_interpreter>();
        std::cout << "Python interpreter init success" << std::endl;

        // 导入OMPython中的OMCSessionZMQ
        py::module_ ompython = py::module_::import("OMPython");
        py::object OMCSessionZMQ = ompython.attr("OMCSessionZMQ");

        // 创建OMCSessionZMQ实例
        omc_session = OMCSessionZMQ();
        std::cout << "OMCSessionZMQ create success" << std::endl;

        initialized = true;
    } catch (const std::runtime_error& e) {
            // 使用文件指针将异常输出到文件
        if (error_log_file) {
            // 获取当前时间
            time_t now = time(0);
            char* time_str = ctime(&now);
            // 移除换行符
            if (time_str && time_str[strlen(time_str) - 1] == '\n') {
                time_str[strlen(time_str) - 1] = '\0';
            }

            fprintf(error_log_file, "[%s] PythonEnv init failed: %s\n",
                    time_str ? time_str : "Unknown time", e.what());
            fflush(error_log_file);  // 立即刷新到文件
        }
        std::cout << "init failed：" << e.what() << std::endl;
        initialized = false;
    }
}

PythonEnv::~PythonEnv() {
    // 关闭错误日志文件
    if (error_log_file) {
        fclose(error_log_file);
        error_log_file = nullptr;
    }
}

PythonEnv& PythonEnv::get_instance() {
    static PythonEnv instance;
    return instance;
}

std::string PythonEnv::send_expression(const std::string& expr) {
    try {
        py::str result = omc_session.attr("sendExpression")(expr);
        return static_cast<std::string>(result);
    } catch (const py::error_already_set& e) {
        std::cerr << "send expression failed：" << e.what() << std::endl;
        return "";
    }
}

// 新增：返回原始py::object用于处理未知类型
py::object PythonEnv::send_expression_object(const std::string& expr, bool parsed) {
    try {
        return omc_session.attr("sendExpression")(expr, parsed);
    } catch (const py::error_already_set& e) {
        std::cerr << "send expression object failed：" << e.what() << std::endl;
        return py::none();
    }
}
