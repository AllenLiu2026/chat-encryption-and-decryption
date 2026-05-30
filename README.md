# chat-encryption-and-decryption

![License](https://img.shields.io/github/license/AllenLiu2026/chat-encryption-and-decryption)
![Last Commit](https://img.shields.io/github/last-commit/AllenLiu2026/chat-encryption-and-decryption)
![Stars](https://img.shields.io/github/stars/AllenLiu2026/chat-encryption-and-decryption?style=social)

## 项目简介
- 一个使用 C++ 实现的简单聊天加密解密工具
- 支持多行加密
- 换行+ Ctrl Z +换行结束

## 功能特性
- 支持 **加密/解密** 多行文本
- 易于扩展和修改
- Beginner-friendly，新手友好

## 使用示例
```
===== 聊天加密解密工具 =====
输入秘钥：ALlen刘123

请选择你要做的事：
1.加密
2.解密
0.退出
你的选择：1
输入要加密的信息（多行可粘贴，回车+Ctrl+Z +回车结束）
text测试123
^Z
加密后：
NQkUEdwjP+UDAXJm
已自动复制到剪贴板！

请选择你要做的事：
1.加密
2.解密
0.退出
你的选择：2
输入密文（回车+Ctrl+Z+回车结束）：
NQkUEdwjP+UDAXJm
^Z
解密后：
text测试123

已自动复制到剪贴板！

请选择你要做的事：
1.加密
2.解密
0.退出
你的选择：θ
已关闭。

————————————————————————————————
```

## 编译参数
编译时加入以下参数:
```
-lurlmon
```
在链接时加入以下参数：
```
-static-libstdc++ -static-libgcc
```

## 贡献说明
欢迎大家提交PR或者Issue！

## License
MIT
