#ifndef PYTHON_ENV_H
#define PYTHON_ENV_H

#include <pybind11/embed.h>
#include <memory>
#include <string>

// Suppress visibility warnings for pybind11 types
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"

namespace py = pybind11;

class PythonEnv {
public:
    static PythonEnv& get_instance();

    PythonEnv(const PythonEnv&) = delete;
    PythonEnv& operator=(const PythonEnv&) = delete;
    PythonEnv(PythonEnv&&) = delete;
    PythonEnv& operator=(PythonEnv&&) = delete;

    // 发送表达式并返回字符串结果
    std::string send_expression(const std::string& expr);

    // 发送表达式并返回原始py::object（用于处理未知类型）
    py::object send_expression_object(const std::string& expr, bool parsed = true);

    bool is_ready() const { return initialized && omc_session.ptr() != nullptr; }

private:
    PythonEnv();
    ~PythonEnv();

    std::unique_ptr<py::scoped_interpreter> interpreter;
    py::object omc_session;
    bool initialized = false;
    FILE* error_log_file = nullptr;
};

#pragma GCC diagnostic pop

#endif // PYTHON_ENV_H
