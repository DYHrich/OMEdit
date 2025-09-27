#!/usr/bin/env python3
import os
import subprocess
import shutil

print("=== OPENMODELICAHOME 环境变量变化测试 ===\n")

# 1. 显示当前环境变量
print("1. 当前环境变量状态：")
print(f"   OPENMODELICAHOME: {os.environ.get('OPENMODELICAHOME', '未设置')}")

# 2. 检查系统 PATH 中的 omc
print("\n2. 系统 PATH 中的 omc：")
omc_path = shutil.which("omc")
if omc_path:
    print(f"   omc 路径: {omc_path}")
    # 推断安装目录
    inferred_home = os.path.dirname(os.path.dirname(omc_path))
    print(f"   推断的安装目录: {inferred_home}")
else:
    print("   未在 PATH 中找到 omc")

# 3. 测试 OMPython 初始化前后的变化
print("\n3. OMPython 初始化测试：")
print("   初始化前:")
print(f"     OPENMODELICAHOME: {os.environ.get('OPENMODELICAHOME', '未设置')}")

try:
    from OMPython import OMCSessionZMQ
    print("   正在初始化 OMCSessionZMQ...")
    omc = OMCSessionZMQ()

    print("   初始化后:")
    print(f"     OPENMODELICAHOME: {os.environ.get('OPENMODELICAHOME', '未设置')}")

    # 4. 获取 OMC 报告的安装目录
    print("\n4. OMC 报告的信息：")
    try:
        installation_dir = omc.sendExpression("getInstallationDirectoryPath()")
        print(f"   OMC 安装目录: {installation_dir}")

        version = omc.sendExpression("getVersion()")
        print(f"   OMC 版本: {version}")
    except Exception as e:
        print(f"   获取 OMC 信息失败: {e}")

except ImportError:
    print("   OMPython 未安装")
except Exception as e:
    print(f"   OMPython 初始化失败: {e}")

print("\n=== 测试完成 ===")