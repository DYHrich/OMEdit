#!/usr/bin/env python3
"""
Python环境检测脚本 - 用于验证OMEdit所需的Python环境
"""

import sys
import os
import subprocess

def test_python_basic():
    """测试基本Python环境"""
    print("=== Python基本环境检测 ===")
    print(f"Python版本: {sys.version}")
    print(f"Python路径: {sys.executable}")
    print(f"Python库路径: {sys.path}")
    return True

def test_pybind11():
    """测试pybind11模块"""
    print("\n=== pybind11检测 ===")
    try:
        import pybind11
        print(f"✓ pybind11版本: {pybind11.__version__}")
        print(f"✓ pybind11路径: {pybind11.__file__}")
        return True
    except ImportError as e:
        print(f"✗ pybind11导入失败: {e}")
        return False

def test_ompython():
    """测试OMPython模块"""
    print("\n=== OMPython检测 ===")
    try:
        import OMPython
        print(f"✓ OMPython模块导入成功")
        print(f"✓ OMPython路径: {OMPython.__file__}")

        # 测试OMCSessionZMQ
        from OMPython import OMCSessionZMQ
        print(f"✓ OMCSessionZMQ类导入成功")

        # 尝试创建实例
        try:
            omc = OMCSessionZMQ()
            print(f"✓ OMCSessionZMQ实例创建成功")

            # 测试基本命令
            version = omc.sendExpression("getVersion()")
            print(f"✓ OpenModelica版本: {version}")
            return True
        except Exception as e:
            print(f"✗ OMCSessionZMQ实例创建失败: {e}")
            return False

    except ImportError as e:
        print(f"✗ OMPython导入失败: {e}")
        return False

def test_zmq():
    """测试ZeroMQ"""
    print("\n=== ZeroMQ检测 ===")
    try:
        import zmq
        print(f"✓ ZeroMQ版本: {zmq.zmq_version()}")
        print(f"✓ PyZMQ版本: {zmq.pyzmq_version()}")
        return True
    except ImportError as e:
        print(f"✗ ZeroMQ导入失败: {e}")
        return False

def test_openmodelica_env():
    """测试OpenModelica环境变量"""
    print("\n=== OpenModelica环境变量检测 ===")

    omhome = os.environ.get('OPENMODELICAHOME')
    if omhome:
        print(f"✓ OPENMODELICAHOME: {omhome}")
    else:
        print("✗ OPENMODELICAHOME环境变量未设置")

    # 检查omc可执行文件
    try:
        result = subprocess.run(['omc', '--version'],
                              capture_output=True, text=True, timeout=10)
        if result.returncode == 0:
            print(f"✓ omc可执行文件: {result.stdout.strip()}")
            return True
        else:
            print(f"✗ omc执行失败: {result.stderr}")
            return False
    except (subprocess.TimeoutExpired, FileNotFoundError) as e:
        print(f"✗ omc命令不可用: {e}")
        return False

def main():
    """主测试函数"""
    print("OpenModelica Python环境检测工具")
    print("=" * 50)

    results = []
    results.append(("Python基本环境", test_python_basic()))
    results.append(("pybind11", test_pybind11()))
    results.append(("ZeroMQ", test_zmq()))
    results.append(("OpenModelica环境", test_openmodelica_env()))
    results.append(("OMPython", test_ompython()))

    print("\n" + "=" * 50)
    print("检测结果汇总:")

    all_passed = True
    for name, passed in results:
        status = "✓ 通过" if passed else "✗ 失败"
        print(f"{name:20}: {status}")
        if not passed:
            all_passed = False

    print("\n" + "=" * 50)
    if all_passed:
        print("🎉 所有检测通过！Python环境配置正确。")
        return 0
    else:
        print("❌ 部分检测失败，请根据上述信息修复环境。")
        return 1

if __name__ == "__main__":
    sys.exit(main())