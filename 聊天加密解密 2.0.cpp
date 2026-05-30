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

int main() {
    setlocale(LC_ALL, "zh_CN.GBK");
    cout << "===== 聊天加密解密工具 =====" << endl;
    cout << "输入秘钥: ";
    string key;
    getline(cin, key);
    try {
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
                break;
            } else if (choice == 1) {
                cout << "输入要加密的信息（多行可粘贴，回车+ Ctrl+Z +回车结束）：\n";
                string msg, line;
                while (getline(cin, line)) {
                    msg += line + '\n';
                }
                cin.clear();
                string cipherText = cipherTool.encrypt(msg);
                cout << "加密后:\n" << cipherText << endl;
                copyToClipboard(cipherText);
                cout << "已自动复制到剪贴板！" << endl;
            } else if (choice == 2) {
                cout << "输入密文（Ctrl+Z回车结束）：\n";
                string cipherText, line;
                while (getline(cin, line)) {
                    cipherText += line;
                }
                cin.clear();
                string msg = cipherTool.decrypt(cipherText);
                cout << "解密后:\n" << msg << endl;
                copyToClipboard(msg);
                cout << "已自动复制到剪贴板！" << endl;
            } else {
                cout << "【错误】请输入0，1或者2" << endl;
            }
        }
    } catch (const exception& e) {
        cerr << "【错误】: " << e.what() << endl;
        return 1;
    }
    return 0;
} 
