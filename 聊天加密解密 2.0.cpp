#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

const string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";
             
string base64_encode(const string &in) {
    string out;
    int val = 0, valb = -6;
    for (unsigned char c : in) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            out.push_back(base64_chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) out.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
    while (out.size() % 4) out.push_back('=');
    return out;
}

string base64_decode(const string &in) {
    string out;
    vector<int> T(256, -1);
    for (int i = 0; i < 64; i++) T[base64_chars[i]] = i;
    int val = 0, valb = -8;
    for (unsigned char c : in) {
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            out.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return out;
}
void copyToClipboard(const string &s) {
    OpenClipboard(NULL);
    EmptyClipboard();
    HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
    char *p = (char*)GlobalLock(h);
    strcpy(p, s.c_str());
    GlobalUnlock(h);
    SetClipboardData(CF_TEXT, h);
    CloseClipboard();
}

class ChatCipher {
private:
    string key;
public:
    ChatCipher(const string& customKey) : key(customKey) {
        if (key.empty()) throw invalid_argument("密钥不能为空！");
    }
    string encrypt(const string& str) {
        string cipher;
        int key_len = key.length();
        for (size_t i = 0; i < str.length(); i++) {
            cipher += str[i] ^ key[i % key_len];
        }
        return base64_encode(cipher);
    }
    string decrypt(const string& base64_str) {
        string cipher = base64_decode(base64_str);
        string plain;
        int key_len = key.length();
        for (size_t i = 0; i < cipher.length(); i++) {
            plain += cipher[i] ^ key[i % key_len];
        }
        return plain;
    }
};

() {
    setlocale(LC_ALL, "zh_CN.GBK");
    cout << "===== 聊天加密解密工具 =====" << endl;
    cout << "输入秘钥: ";
    字符串 键;
    getline(cin, key);
    尝试 {
        ChatCipher cipherTool(key);
        int choice;
        while (true) {
            cout << "\n请选择你要做的事:" << endl;
            cout << "1.加密" << endl;
            cout << "2.解密" << endl;
            cout << "0.退出" << endl;
            cout << "你的选择: ";
            cin >> choice;
            cin.ignore();
            if (choice == 0) {
                cout << "已关闭。" << endl;
                中断;
}选择 == 1) {
                cout << "输入要加密的信息（多行可粘贴，回车+ Ctrl+Z +回车结束）：\n";
                字符串 消息, 行;
                < a i=0>当< a i=1>(< a i=2>读取行< a i=3>(< a i=4>cin, line< a i=5>)< a i=6>)< a i=7>{  
                    msg += line + '\n';
                输入：}
                cin.清除();
                字符串 密文 = 加密工具.加密(消息)
                cout << "加密后:\n" << cipherText << endl;
                复制到剪贴板);
                cout << "已自动复制到剪贴板！" << endl;
            } 否则 如果 (选择 == 2) {
                cout << "输入密文（Ctrl+Z回车结束）：\n";
                字符串 密文，行;
                < a i=0>当< a i=1>(< a i=2>读取行< a i=3>(< a i=4>cin, line< a i=5>)< a i=6>)< a i=7>{  
                    密文 += line;
                输入：}
                cin.清除()
                字符串 msg = 密码工具.解密);
                cout << "解密后:\n" << msg << endl;
                复制到剪贴板(消息);
                cout << "已自动复制到剪贴板！" << endl;
            } 否则 {
                cout << "【错误】请输入0，1或者2" << endl;
            输入：}
        输入：}
    } 捕获 (常量 异常& e) {
        cerr << "【错误】: " << e.what() << endl;
        返回 ;
    输入：
0;
输入：} 
