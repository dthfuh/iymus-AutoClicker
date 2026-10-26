#include <iostream>
#include <windows.h>
#include <limits>
using namespace std;

bool leftActive = false;
bool rightActive = false;
int clickDelay = 40;
int leftToggleKey = 'X'; 
int rightToggleKey = 'C'; 

void RapidClick(bool isLeft) {
    INPUT inputs[2] = {};
    inputs[0].type = INPUT_MOUSE;
    inputs[1].type = INPUT_MOUSE;

    if (isLeft) {
        inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTUP;
        inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    } else {
        inputs[0].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
        inputs[1].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    }
    SendInput(2, inputs, sizeof(INPUT));
}

void ShowMenu() {
    system("cls");
    cout << "========================================" << endl;
    cout << "         IYMUS     CLICKER - V1         " << endl;
    cout << "========================================" << endl;
    cout << " [ AYARLAR ]" << endl;
    cout << " -> Hiz: " << clickDelay << " ms" << endl;
    cout << " -> Sol Tik (" << (char)leftToggleKey << "): " << (leftActive ? "[AKTIF]" : "[KAPALI]") << endl;
    cout << " -> Sag Tik (" << (char)rightToggleKey << "): " << (rightActive ? "[AKTIF]" : "[KAPALI]") << endl;
    cout << "----------------------------------------" << endl;
    cout << " [ F10 ]  : AYARLAR MENU" << endl;
    cout << " [ ESC ] : PROGRAMI KAPAT" << endl;
    cout << "----------------------------------------" << endl;
}

void OpenSettings() {
    leftActive = false; 
    rightActive = false;
    
    system("cls");
    cout << "========== AYARLAR SEKMESI ==========" << endl;
    cout << "1 - Hiz Degistir (ms)" << endl;
    cout << "2 - Sol Tik Tusunu Degistir" << endl;
    cout << "3 - Sag Tik Tusunu Degistir" << endl;
    cout << "4 - VARSAYILANLARA DON (X, C, 40ms)" << endl;
    cout << "0 - Iptal ve Geri Don" << endl;
    cout << "=====================================" << endl;
    cout << "Seciminizi yapip Enter'a basin: ";

    int choice;
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    if (choice == 1) {
        cout << "Yeni MS Degeri (Orn: 30): ";
        cin >> clickDelay;
    } else if (choice == 2) {
        cout << "Yeni Sol Tik Tusu (Tek Harf): ";
        char k; cin >> k; leftToggleKey = toupper(k);
    } else if (choice == 3) {
        cout << "Yeni Sag Tik Tusu (Tek Harf): ";
        char k; cin >> k; rightToggleKey = toupper(k);
    } else if (choice == 4) {
        clickDelay = 40; leftToggleKey = 'X'; rightToggleKey = 'C';
        cout << "\nAyarlar Sifirlandi!";
        Sleep(1000);
    }

    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    cout << "\nAna menuye donuluyor..." << endl;
    Sleep(800);
}

int main() {
    ShowMenu();

    while (true) {
        // F10 Menü Girişi
        if (GetAsyncKeyState(VK_F10) & 0x01) {
            OpenSettings();
            ShowMenu();
        }

        // Sol Tik Modunu Ac/Kapat
        if (GetAsyncKeyState(leftToggleKey) & 0x01) {
            leftActive = !leftActive;
            ShowMenu();
        }

        // Sag Tik Modunu Ac/Kapat
        if (GetAsyncKeyState(rightToggleKey) & 0x01) {
            rightActive = !rightActive;
            ShowMenu();
        }

        // Tıklama İşlemleri (basılı tutuluyorsa)
        if (leftActive && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
            RapidClick(true);
            Sleep(clickDelay);
        }

        if (rightActive && (GetAsyncKeyState(VK_RBUTTON) & 0x8000)) {
            RapidClick(false);
            Sleep(clickDelay);
        }

        // Çıkış
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;

        Sleep(1);
    }

    return 0;
}