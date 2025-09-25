# import OMPython
# from OMPython import OMCSessionZMQ
# import os

# def smart_split_commands(line):
#     """
#     智能分割命令，正确处理字符串内的分号
#     """
#     commands = []
#     current_command = ""
#     in_string = False
#     escape_next = False
    
#     i = 0
#     while i < len(line):
#         char = line[i]
        
#         if escape_next:
#             current_command += char
#             escape_next = False
#         elif char == '\\' and in_string:
#             current_command += char
#             escape_next = True
#         elif char == '"':
#             current_command += char
#             in_string = not in_string
#         elif char == ';' and not in_string:
#             # 只有在字符串外的分号才作为分隔符
#             if current_command.strip():
#                 commands.append(current_command.strip())
#             current_command = ""
#         else:
#             current_command += char
        
#         i += 1
    
#     # 添加最后一个命令
#     if current_command.strip():
#         commands.append(current_command.strip())
    
#     return commands

# def main():
#     # 初始化OMPython会话
#     omc = OMCSessionZMQ()
    
#     # 获取mos.txt文件路径
#     mos_file_path = "/home/yuhangdai/OpenModelica/OMEdit/OMEditLIB/OMC/mos.txt"
    
#     # 输出文件路径
#     output_file_path = "/home/yuhangdai/OpenModelica/OMEdit/OMEditLIB/OMC/output.txt"
    
#     # 检查文件是否存在
#     if not os.path.exists(mos_file_path):
#         print(f"错误：文件 {mos_file_path} 不存在")
#         return
    
#     # 统计信息
#     total_lines = 0
#     total_commands = 0
#     successful_commands = 0
#     failed_commands = 0
    
#     try:
#         # 打开输出文件
#         with open(output_file_path, 'w', encoding='utf-8') as output_file:
#             # 读取mos.txt文件
#             # 在处理文件的循环中，替换原来的分割逻辑：
#             with open(mos_file_path, 'r', encoding='utf-8') as file:
#                 for line_num, line in enumerate(file, 1):
#                     line = line.strip()
#                     if not line:  # 跳过空行
#                         continue
                    
#                     total_lines += 1
                    
#                     # 使用智能分割函数替换简单的split(';')
#                     commands = smart_split_commands(line)
                    
#                     for command in commands:
#                         total_commands += 1
                        
#                         try:
#                             # 执行命令
#                             result = omc.sendExpression(command, False)
#                             successful_commands += 1
                            
#                             # 格式化输出：命令：输出；
#                             output_line = f"命令：{command}：{result}；"
#                             print(output_line)  # 同时在控制台显示
#                             output_file.write(output_line + "\n")  # 写入文件
                            
#                         except Exception as e:
#                             failed_commands += 1
#                             error_line = f"命令：{command}：错误 - {str(e)}；"
#                             print(error_line)  # 同时在控制台显示
#                             output_file.write(error_line + "\n")  # 写入文件
                    
#                     # 每处理100行显示进度
#                     if line_num % 100 == 0:
#                         progress_info = f"\n--- 已处理 {line_num} 行 ---\n成功命令: {successful_commands}, 失败命令: {failed_commands}\n"
#                         print(progress_info)
#                         output_file.write(progress_info)
        
#         # 输出最终统计信息
#         final_stats = f"""
# === 执行完成 ===
# 总行数: {total_lines}
# 总命令数: {total_commands}
# 成功命令: {successful_commands}
# 失败命令: {failed_commands}
# 输出文件: {output_file_path}
# """
#         print(final_stats)
        
#         # 将统计信息也写入文件
#         with open(output_file_path, 'a', encoding='utf-8') as output_file:
#             output_file.write(final_stats)
    
#     except FileNotFoundError:
#         error_msg = f"错误：无法找到文件 {mos_file_path}"
#         print(error_msg)
#     except IOError as e:
#         error_msg = f"文件写入错误：{str(e)}"
#         print(error_msg)
#     except Exception as e:
#         error_msg = f"读取文件时发生错误：{str(e)}"
#         print(error_msg)
    
#     finally:
#         # 关闭OMC会话
#         try:
#             omc.__del__()
#         except:
#             pass

# if __name__ == "__main__":
#     main()

import OMPython
from OMPython import OMCSessionZMQ
import os

omc = OMCSessionZMQ()
S = 'parseFile("/home/yuhangdai/test.mo","UTF-8")'

result = omc.sendExpression("system(\"initGarbageCollector\")" , False)
print(type(result))
print(result)
