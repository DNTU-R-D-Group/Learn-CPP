#include <iostream>
#include <vector>        // Thư viện vector (mảng động)
#include <string>        // Thư viện chuỗi
#include <fstream>       // Thư viện đọc/ghi file
#include <memory>   // BẮT BUỘC cho smart pointers
using namespace std;

void thay_doi_tham_chieu(int& x) {  // Truyền tham chiếu - thay đổi biến gốc
    x = 100;
}

/*
================================================================================
                    5. CON TRỎ VÀ THAM CHIẾU
================================================================================
*/

//Con trỏ (pointer) là biến dùng để lưu địa chỉ bộ nhớ của một biến khác.
int x = 10;
int* ptr = &x;

// x → dữ liệu
// &x → địa chỉ của x
// ptr → giữ địa chỉ đó
// *ptr → truy cập dữ liệu tại địa chỉ (dereference)

// Vì sao cần con trỏ?
// C++ cho phép:
// Quản lý bộ nhớ cấp thấp
// Làm việc với mảng, cấu trúc dữ liệu động
// Truyền dữ liệu hiệu quả hơn copy
// Giao tiếp với hardware / OS / API C

// Syntax quan trọng
// int x = 10;
// int* p;      // Khai báo con trỏ
// p = &x;      // Gán địa chỉ
// *p = 20;     // Thay đổi giá trị gốc

// Ứng dụng thực tế
// Thao tác buffer
// Driver / hệ thống nhúng
// C API
// Game engine (quản lý object)

// 5.1. CON TRỎ CƠ BẢN
void con_tro_co_ban() {
    cout << "\n=== CON TRỎ CƠ BẢN ===" << endl;
    
    int x = 10;
    int* ptr = &x;  // Con trỏ trỏ đến địa chỉ của x
    
    cout << "Giá trị x: " << x << endl;
    cout << "Địa chỉ x: " << &x << endl;
    cout << "Giá trị ptr (địa chỉ x): " << ptr << endl;
    cout << "Giá trị mà ptr trỏ tới: " << *ptr << endl;  // Dereference
    
    // Thay đổi giá trị qua con trỏ
    *ptr = 20;
    cout << "Giá trị x sau khi thay đổi qua ptr: " << x << endl;
    
    // // Con trỏ NULL
    // int* null_ptr = nullptr;  // C++11
    // if (null_ptr == nullptr) {
    //     cout << "Con trỏ NULL" << endl;
    // }
}

// 5.2. CON TRỎ VÀ MẢNG
void con_tro_va_mang() {
    cout << "\n=== CON TRỎ VÀ MẢNG ===" << endl;
    
    int arr[] = {10, 20, 30, 40, 50};
    int* p = arr;  // Tên mảng chính là con trỏ đến phần tử đầu
    
    cout << "Các phần tử qua con trỏ:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << *(p + i) << endl;
    }
    
    // Duyệt mảng bằng con trỏ
    cout << "Duyệt bằng con trỏ: ";
    for (int* ptr = arr; ptr < arr + 5; ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
}

// 5.3. CẤP PHÁT ĐỘNG
void cap_phat_dong() {
    cout << "\n=== CẤP PHÁT ĐỘNG ===" << endl;
    
    // Cấp phát cho 1 biến
    int* p = new int;
    *p = 42;
    cout << "Giá trị cấp phát động: " << *p << endl;
    delete p;  // Giải phóng bộ nhớ
    
    // Cấp phát cho mảng
    int n = 5;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }
    
    cout << "Mảng động: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;  // Giải phóng mảng
}

// 5.4. SMART POINTERS (C++11)
void smart_pointers() {
    cout << "\n=== SMART POINTERS ===" << endl;
    
    // unique_ptr - chỉ một con trỏ sở hữu
    unique_ptr<int> uptr(new int(42));
    cout << "unique_ptr: " << *uptr << endl;
    // Tự động giải phóng khi ra khỏi scope
    
    // shared_ptr - nhiều con trỏ có thể chia sẻ
    shared_ptr<int> sptr1 = make_shared<int>(100);
    shared_ptr<int> sptr2 = sptr1;  // Cùng trỏ đến một vùng nhớ
    cout << "shared_ptr count: " << sptr1.use_count() << endl;
    cout << "shared_ptr: " << *sptr1 << endl;
    
    // weak_ptr - tham chiếu yếu, không tăng reference count
    weak_ptr<int> wptr = sptr1;
    cout << "weak_ptr expired? " << (wptr.expired() ? "Yes" : "No") << endl;
}

// 5.5. THAM CHIẾU
void tham_chieu() {
    cout << "\n=== THAM CHIẾU ===" << endl;
    
    int x = 10;
    int& ref = x;  // ref là tham chiếu đến x
    
    cout << "x: " << x << endl;
    cout << "ref: " << ref << endl;
    
    // Thay đổi qua tham chiếu
    ref = 20;
    cout << "x sau khi thay đổi ref: " << x << endl;
    
    // Tham chiếu trong hàm
    int a = 5;
    thay_doi_tham_chieu(a);
    cout << "a sau khi gọi hàm: " << a << endl;
}


/*
================================================================================
        7. FILE I/O (ĐỌC / GHI FILE)
================================================================================
*/

void file_io() {
    cout << "\n=== FILE I/O ===" << endl;

    // Ghi file
    ofstream out("data.txt");
    if (!out) {
        cout << "Không thể mở file để ghi!" << endl;
        return;
    }
    out << "Hello C++ File\n";
    out << "Tuổi: 25\n";
    out.close();

    // Đọc file
    ifstream in("data.txt");
    if (!in) {
        cout << "Không thể mở file để đọc!" << endl;
        return;
    }

    string line;
    cout << "Nội dung file:" << endl;
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();
}

/*
================================================================================
        8. ERROR HANDLING – EXCEPTION
================================================================================
*/

void exception_handling() {
    cout << "\n=== EXCEPTION HANDLING ===" << endl;

    try {
        string s = "abc";
        int x = stoi(s);  // Lỗi
        cout << x << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Lỗi invalid_argument: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Lỗi khác: " << e.what() << endl;
    }
}

int main() {
    con_tro_co_ban();
    con_tro_va_mang();
    cap_phat_dong();
    smart_pointers();
    tham_chieu();
    file_io();
    exception_handling();
}

