#include "PythonEnv.h"
#include <iostream>
#include <string>
#include <chrono>

int main() {
    std::cout << "=== Python环境测试程序 ===" << std::endl;
    std::cout << "开始测试Python环境初始化..." << std::endl;

    auto start_time = std::chrono::high_resolution_clock::now();

    try {
        // 获取PythonEnv单例实例
        std::cout << "\n1. 获取PythonEnv实例..." << std::endl;
        PythonEnv& pythonEnv = PythonEnv::get_instance();

        // 检查初始化状态
        std::cout << "\n2. 检查Python环境状态..." << std::endl;
        if (pythonEnv.is_ready()) {
            std::cout << "✓ Python环境初始化成功！" << std::endl;
        } else {
            std::cout << "✗ Python环境初始化失败！" << std::endl;
            return 1;
        }

        // 测试基本的Python表达式
        std::cout << "\n3. 测试基本Python表达式..." << std::endl;

        // 测试简单数学运算
        std::string result1 = pythonEnv.send_expression("1 + 1");
        std::cout << "1 + 1 = " << result1 << std::endl;

        // 测试字符串操作
        std::string result2 = pythonEnv.send_expression("'Hello' + ' ' + 'World'");
        std::cout << "字符串拼接: " << result2 << std::endl;

        // 测试Python版本信息
        std::cout << "\n4. 获取Python环境信息..." << std::endl;
        py::object version_obj = pythonEnv.send_expression_object("import sys; sys.version");
        std::string version = py::str(version_obj);
        std::cout << "Python版本: " << version << std::endl;

        py::object executable_obj = pythonEnv.send_expression_object("import sys; sys.executable");
        std::string executable = py::str(executable_obj);
        std::cout << "Python可执行文件路径: " << executable << std::endl;

        // 测试OMPython相关功能
        std::cout << "\n5. 测试OMPython功能..." << std::endl;

        // 测试OMC版本
        try {
            py::object omc_version_obj = pythonEnv.send_expression_object("getVersion()");
            std::string omc_version = py::str(omc_version_obj);
            std::cout << "OMC版本: " << omc_version << std::endl;
        } catch (const std::exception& e) {
            std::cout << "获取OMC版本失败: " << e.what() << std::endl;
        }

        // // 测试简单的OMC命令
        // try {
        //     py::object model_path_obj = pythonEnv.send_expression_object("getModelicaPath()");
        //     std::string model_path = py::str(model_path_obj);
        //     std::cout << "Modelica路径: " << model_path << std::endl;
        // } catch (const std::exception& e) {
        //     std::cout << "获取Modelica路径失败: " << e.what() << std::endl;
        // }

        // // 测试工作目录
        // try {
        //     py::object pwd_obj = pythonEnv.send_expression_object("cd()");
        //     std::string pwd = py::str(pwd_obj);
        //     std::cout << "当前工作目录: " << pwd << std::endl;
        // } catch (const std::exception& e) {
        //     std::cout << "获取工作目录失败: " << e.what() << std::endl;
        // }

        // // 测试环境变量
        // std::cout << "\n6. 测试环境变量..." << std::endl;
        // try {
        //     py::object env_obj = pythonEnv.send_expression_object("import os; os.environ.get('OPENMODELICAHOME', 'Not set')");
        //     std::string openmodelica_home = py::str(env_obj);
        //     std::cout << "OPENMODELICAHOME: " << openmodelica_home << std::endl;
        // } catch (const std::exception& e) {
        //     std::cout << "获取OPENMODELICAHOME失败: " << e.what() << std::endl;
        // }

        // // 测试Python模块路径
        // std::cout << "\n7. 测试Python模块路径..." << std::endl;
        // try {
        //     py::object sys_path_obj = pythonEnv.send_expression_object("import sys; str(sys.path)");
        //     std::string sys_path = py::str(sys_path_obj);
        //     std::cout << "Python sys.path: " << sys_path << std::endl;
        // } catch (const std::exception& e) {
        //     std::cout << "获取sys.path失败: " << e.what() << std::endl;
        // }

        // // 测试OMPython模块信息
        // std::cout << "\n8. 测试OMPython模块信息..." << std::endl;
        // try {
        //     py::object ompython_path_obj = pythonEnv.send_expression_object("import OMPython; OMPython.__file__");
        //     std::string ompython_path = py::str(ompython_path_obj);
        //     std::cout << "OMPython模块路径: " << ompython_path << std::endl;
        // } catch (const std::exception& e) {
        //     std::cout << "获取OMPython模块路径失败: " << e.what() << std::endl;
        // }

        // // 计算总耗时
        // auto end_time = std::chrono::high_resolution_clock::now();
        // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        // std::cout << "\n=== 测试完成 ===" << std::endl;
        // std::cout << "总耗时: " << duration.count() << " 毫秒" << std::endl;
        // std::cout << "✓ Python环境测试成功！" << std::endl;

        return 0;

    } catch (const std::exception& e) {
        std::cout << "✗ 测试过程中发生错误: " << e.what() << std::endl;
        return 1;
    }
}