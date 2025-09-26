# # This is a sample Python script.
#
# # Press Shift+F10 to execute it or replace it with your code.
# # Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
#
#
# def print_hi(name):
#     # Use a breakpoint in the code line below to debug your script.
#     print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.
#
#
# # Press the green button in the gutter to run the script.
# if __name__ == '__main__':
#     print_hi('PyCharm')
#
# # See PyCharm help at https://www.jetbrains.com/help/pycharm/
# from OMPython import OMCSessionZMQ
# omc = OMCSessionZMQ()
# errors = omc.sendExpression("getErrorString()")
# if errors:
#     # 处理错误信息
#     print(f"Errors/Warnings: {errors}")
# cmds = [
#   'loadFile(getInstallationDirectoryPath() + "/share/doc/omc/testmodels/BouncingBall.mo")',
#   "simulate(BouncingBall)",
#   "plot(h)"
#   ]
# for cmd in cmds:
#   answer = omc.sendExpression(cmd)
#   print("\n{}:\n{}".format(cmd, answer))
from pyparsing import (
    Combine,
    Dict,
    Forward,
    Group,
    Keyword,
    Optional,
    QuotedString,
    StringEnd,
    Suppress,
    Word,
    alphanums,
    alphas,
    delimitedList,
    nums,
    replaceWith,
    infixNotation,
    opAssoc,
)
# tmp = "戴敔航"
# tmp = tmp.replace("敔航", "雨杭")
# print(tmp)

import re
import os
import sys
from typing import List, Tuple


class CppFunctionStubber:
    def __init__(self):
        # 修改正则表达式以完整捕获函数签名
        self.function_pattern = re.compile(
            r'((?:static\s+|virtual\s+|inline\s+)*)'  # 修饰符
            r'([a-zA-Z_][a-zA-Z0-9_]*(?:\s*<[^>]*>)?(?:\s*\*)*(?:\s*&)?)'  # 返回类型
            r'\s+'
            r'([a-zA-Z_][a-zA-Z0-9_]*(?:::[a-zA-Z_][a-zA-Z0-9_]*)*)'  # 函数名
            r'\s*'
            r'(\([^)]*\))'  # 参数列表
            r'(\s*const)?'  # 捕获const关键字
            r'(\s*override)?'  # 捕获override关键字
            r'\s*'
            r'(\{)',  # 开始的大括号
            re.MULTILINE | re.DOTALL
        )

    def find_matching_brace(self, content: str, start_pos: int) -> int:
        """找到匹配的右大括号位置"""
        brace_count = 1
        pos = start_pos + 1

        while pos < len(content) and brace_count > 0:
            if content[pos] == '{':
                brace_count += 1
            elif content[pos] == '}':
                brace_count -= 1
            pos += 1

        return pos - 1 if brace_count == 0 else -1

    def get_default_return_value(self, return_type):
        """根据返回类型生成默认返回值"""
        return_type = return_type.strip()

        # 移除static, virtual, inline等修饰符
        return_type = re.sub(r'\b(static|virtual|inline)\s+', '', return_type)
        return_type = return_type.strip()

        if return_type == 'void':
            return ''
        elif return_type == 'bool':
            return 'return false;'
        elif return_type in ['int', 'long', 'short', 'char', 'size_t', 'qint64', 'DWORD']:
            return 'return 0;'
        elif return_type in ['float', 'double']:
            return 'return 0.0;'
        elif return_type == 'String':
            return 'return "";'
        elif return_type == 'QString':
            return 'return QString();'
        elif return_type == 'QByteArray':
            return 'return QByteArray();'
        elif return_type == 'QModelIndex':
            return 'return QModelIndex();'
        elif return_type == 'QVariant':
            return 'return QVariant();'
        elif return_type.startswith('QList<'):
            return f'return {return_type}();'
        elif return_type.endswith('*'):
            # 指针类型返回空指针
            return 'return nullptr;'
        elif return_type.endswith('&'):
            # 引用类型需要特殊处理
            base_type = return_type[:-1].strip()
            if base_type == 'QString':
                return 'static QString dummy; return dummy;'
            else:
                return f'static {base_type} dummy; return dummy;'
        elif '::' in return_type:
            # 枚举或嵌套类型
            if 'ItemFlags' in return_type:
                return 'return Qt::ItemFlags();'
            else:
                return f'return {return_type}();'
        else:
            # 默认构造函数调用
            return f'return {return_type}();'

    def create_stub_function(self, modifiers: str, return_type: str, function_name: str,
                             parameters: str, const_modifier: str = '', override_modifier: str = '') -> str:
        """创建stub函数，保持完整的函数签名"""
        # 构建完整的函数签名
        signature_parts = []
        if modifiers.strip():
            signature_parts.append(modifiers.strip())
        signature_parts.append(return_type.strip())
        signature_parts.append(function_name.strip() + parameters)
        if const_modifier.strip():
            signature_parts.append(const_modifier.strip())
        if override_modifier.strip():
            signature_parts.append(override_modifier.strip())

        full_signature = ' '.join(signature_parts)
        print_statement = f'std::cout << "{full_signature}" << std::endl;'

        # 生成返回语句
        return_statement = self.get_default_return_value(return_type)

        # 构建新的函数体
        new_body = "{\n    " + print_statement + "\n"
        if return_statement:
            new_body += f"    {return_statement}\n"
        new_body += "}"

        return f"{full_signature} {new_body}"

    def process_file(self, file_path: str, output_path: str = None) -> bool:
        """处理单个C++文件"""
        try:
            with open(file_path, 'r', encoding='utf-8') as f:
                content = f.read()
        except Exception as e:
            print(f"Error reading file {file_path}: {e}")
            return False

        # 检查是否需要添加iostream头文件
        needs_iostream = '#include <iostream>' not in content and '#include<iostream>' not in content

        # 找到所有函数定义
        matches = list(self.function_pattern.finditer(content))

        if not matches:
            print(f"No function definitions found in {file_path}")
            return True

        # 从后往前处理，避免位置偏移问题
        matches.reverse()

        new_content = content

        for match in matches:
            modifiers = match.group(1) if match.group(1) else ''
            return_type = match.group(2).strip()
            function_name = match.group(3).strip()
            parameters = match.group(4).strip()
            const_modifier = match.group(5) if match.group(5) else ''
            override_modifier = match.group(6) if match.group(6) else ''

            # 找到函数体的开始和结束位置
            brace_start = match.end() - 1  # 开始大括号的位置
            brace_end = self.find_matching_brace(new_content, brace_start)

            if brace_end == -1:
                print(f"Warning: Could not find matching brace for function {function_name}")
                continue

            # 创建新的函数定义
            new_function = self.create_stub_function(modifiers, return_type, function_name,
                                                     parameters, const_modifier, override_modifier)

            # 替换原函数
            function_start = match.start()
            new_content = new_content[:function_start] + new_function + new_content[brace_end + 1:]

            print(f"Processed function: {function_name}")

        # 添加iostream头文件（如果需要）
        if needs_iostream and matches:
            # 找到第一个#include的位置
            include_pattern = re.compile(r'#include\s*[<"][^>"]*[>"]')
            include_match = include_pattern.search(new_content)

            if include_match:
                # 在第一个include之后添加
                insert_pos = include_match.end()
                new_content = new_content[:insert_pos] + '\n#include <iostream>' + new_content[insert_pos:]
            else:
                # 如果没有找到include，在文件开头添加
                new_content = '#include <iostream>\n' + new_content

        # 写入输出文件
        output_file = output_path if output_path else file_path
        try:
            with open(output_file, 'w', encoding='utf-8') as f:
                f.write(new_content)
            print(f"Successfully processed {file_path}")
            return True
        except Exception as e:
            print(f"Error writing file {output_file}: {e}")
            return False

    def process_directory(self, directory_path: str, output_dir: str = None,
                          file_extensions: List[str] = None) -> None:
        """处理目录中的所有C++文件"""
        if file_extensions is None:
            file_extensions = ['.cpp', '.cc', '.cxx']

        if output_dir and not os.path.exists(output_dir):
            os.makedirs(output_dir)

        for root, dirs, files in os.walk(directory_path):
            for file in files:
                if any(file.endswith(ext) for ext in file_extensions):
                    file_path = os.path.join(root, file)

                    if output_dir:
                        # 保持目录结构
                        rel_path = os.path.relpath(file_path, directory_path)
                        output_file = os.path.join(output_dir, rel_path)
                        output_file_dir = os.path.dirname(output_file)
                        if not os.path.exists(output_file_dir):
                            os.makedirs(output_file_dir)
                    else:
                        output_file = None

                    self.process_file(file_path, output_file)


def main():
    """主函数"""
    stubber = CppFunctionStubber()

    if len(sys.argv) < 2:
        print("Usage: python cleanCPP.py <file_or_directory> [output_directory]")
        print("Examples:")
        print("  python cleanCPP.py file.cpp")
        print("  python cleanCPP.py /path/to/cpp/files")
        print("  python cleanCPP.py /path/to/cpp/files /path/to/output")
        return

    input_path = sys.argv[1]
    output_path = sys.argv[2] if len(sys.argv) > 2 else None

    if os.path.isfile(input_path):
        # 处理单个文件
        stubber.process_file(input_path, output_path)
    elif os.path.isdir(input_path):
        # 处理目录
        stubber.process_directory(input_path, output_path)
    else:
        print(f"Error: {input_path} is not a valid file or directory")


if __name__ == "__main__":
    main()