#include "PythonEnv.h"
#include <iostream>

PythonEnv::PythonEnv() {
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
    } catch (const py::error_already_set& e) {
        std::cerr << "init failed：" << e.what() << std::endl;
        initialized = false;
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
