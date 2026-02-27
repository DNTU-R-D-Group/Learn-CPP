/*
================================================================================
                    HƯỚNG DẪN C++ TOÀN DIỆN
                 Từ Cơ Bản Đến Nâng Cao
================================================================================
*/

#include <iostream>      // Thư viện nhập xuất chuẩn
#include <string>        // Thư viện chuỗi
#include <vector>        // Thư viện vector (mảng động)
#include <array>         // Thư viện array (mảng tĩnh)
#include <algorithm>     // Thư viện thuật toán
#include <memory>        // Thư viện quản lý bộ nhớ thông minh
#include <fstream>       // Thư viện đọc/ghi file
#include <sstream>       // Thư viện xử lý chuỗi
#include <map>           // Thư viện map (từ điển)
#include <set>           // Thư viện set (tập hợp)
#include <queue>         // Thư viện hàng đợi
#include <stack>         // Thư viện ngăn xếp
#include <cmath>         // Thư viện toán học

using namespace std;     // Sử dụng namespace std để không phải viết std::

/*
================================================================================
                        1. CƠ BẢN VỀ C++
================================================================================
*/

// 1.1. KIỂU DỮ LIỆU Cơ BẢN
void kieu_du_lieu_co_ban() {
    cout << "\n=== KIỂU DỮ LIỆU CƠ BẢN ===" << endl;
    
    // Số nguyên
    int so_nguyen = 42;                    // 4 bytes, -2^31 đến 2^31-1
    short so_ngan = 100;                   // 2 bytes
    long so_dai = 1000000L;                // 4 bytes (hoặc 8)
    long long so_rat_dai = 1000000000LL;   // 8 bytes
    unsigned int so_khong_am = 100u;       // Chỉ số dương
    
    // Số thực
    float so_thuc_don = 3.14f;             // 4 bytes, độ chính xác ~7 chữ số
    double so_thuc_kep = 3.14159265359;    // 8 bytes, độ chính xác ~15 chữ số
    long double so_thuc_dai = 3.14159265359L; // 12-16 bytes
    
    // Ký tự và chuỗi
    char ky_tu = 'A';                      // 1 byte
    char chuoi_c[] = "Hello";              // Chuỗi kiểu C
    string chuoi_cpp = "Hello C++";        // Chuỗi kiểu C++
    
    // Boolean
    bool dung_sai = true;                  // true hoặc false
    
    // In ra màn hình
    cout << "Số nguyên: " << so_nguyen << endl;
    cout << "Số thực: " << so_thuc_kep << endl;
    cout << "Ký tự: " << ky_tu << endl;
    cout << "Chuỗi: " << chuoi_cpp << endl;
    cout << "Boolean: " << dung_sai << endl;
    
    // Kích thước của kiểu dữ liệu
    cout << "Kích thước int: " << sizeof(int) << " bytes" << endl;
    cout << "Kích thước double: " << sizeof(double) << " bytes" << endl;
}

// 1.2. BIẾN VÀ HẰNG SỐ
void bien_va_hang_so() {
    cout << "\n=== BIẾN VÀ HẰNG SỐ ===" << endl;
    
    // Khai báo biến
    int tuoi = 25;                         // Biến có thể thay đổi
    double chieu_cao = 1.75;
    
    // Hằng số - không thể thay đổi sau khi khởi tạo
    const double PI = 3.14159;
    const int SO_NGAY_TRONG_TUAN = 7;
    
    // Auto - tự động suy luận kiểu
    auto bien_auto = 10;                   // Tự động là int
    auto bien_auto2 = 3.14;                // Tự động là double
    
    // Decltype - lấy kiểu của biểu thức
    decltype(tuoi) bien_cung_kieu = 30;    // Cùng kiểu với tuoi (int)
    
    cout << "Tuổi: " << tuoi << endl;
    cout << "PI: " << PI << endl;
    cout << "Auto int: " << bien_auto << endl;
}

// 1.3. TOÁN TỬ
void toan_tu() {
    cout << "\n=== TOÁN TỬ ===" << endl;
    
    int a = 10, b = 3;
    
    // Toán tử số học
    cout << "Cộng: " << (a + b) << endl;          // 13
    cout << "Trừ: " << (a - b) << endl;           // 7
    cout << "Nhân: " << (a * b) << endl;          // 30
    cout << "Chia: " << (a / b) << endl;          // 3 (chia nguyên)
    cout << "Chia lấy dư: " << (a % b) << endl;   // 1
    
    // Toán tử so sánh
    cout << "a > b: " << (a > b) << endl;         // 1 (true)
    cout << "a < b: " << (a < b) << endl;         // 0 (false)
    cout << "a == b: " << (a == b) << endl;       // 0 (false)
    cout << "a != b: " << (a != b) << endl;       // 1 (true)
    
    // Toán tử logic
    bool x = true, y = false;
    cout << "x && y: " << (x && y) << endl;       // AND - 0
    cout << "x || y: " << (x || y) << endl;       // OR - 1
    cout << "!x: " << (!x) << endl;               // NOT - 0
    
    // Toán tử tăng/giảm
    int c = 5;
    cout << "c++: " << c++ << endl;               // In 5, sau đó c = 6
    cout << "++c: " << ++c << endl;               // c = 7, sau đó in 7
    cout << "c--: " << c-- << endl;               // In 7, sau đó c = 6
    cout << "--c: " << --c << endl;               // c = 5, sau đó in 5
    
    // Toán tử gán phức hợp
    int d = 10;
    d += 5;   // d = d + 5
    d -= 3;   // d = d - 3
    d *= 2;   // d = d * 2
    d /= 4;   // d = d / 4
    cout << "Kết quả d: " << d << endl;
}

/*
================================================================================
                    2. CẤU TRÚC ĐIỀU KHIỂN
================================================================================
*/

// 2.1. CÂU LỆNH IF-ELSE
void cau_lenh_if_else() {
    cout << "\n=== CÂU LỆNH IF-ELSE ===" << endl;
    
    int diem = 85;
    
    // If đơn giản
    if (diem >= 50) {
        cout << "Đậu" << endl;
    }
    
    // If-else
    if (diem >= 90) {
        cout << "Xuất sắc" << endl;
    } else if (diem >= 80) {
        cout << "Giỏi" << endl;
    } else if (diem >= 70) {
        cout << "Khá" << endl;
    } else if (diem >= 50) {
        cout << "Trung bình" << endl;
    } else {
        cout << "Yếu" << endl;
    }
    
    // Toán tử 3 ngôi (ternary operator)
    string ket_qua = (diem >= 50) ? "Đậu" : "Rớt";
    cout << "Kết quả: " << ket_qua << endl;
}

// 2.2. CÂU LỆNH SWITCH
void cau_lenh_switch() {
    cout << "\n=== CÂU LỆNH SWITCH ===" << endl;
    
    int ngay = 3;
    
    switch (ngay) {
        case 1:
            cout << "Thứ Hai" << endl;
            break;  // Break để thoát khỏi switch
        case 2:
            cout << "Thứ Ba" << endl;
            break;
        case 3:
            cout << "Thứ Tư" << endl;
            break;
        case 4:
            cout << "Thứ Năm" << endl;
            break;
        case 5:
            cout << "Thứ Sáu" << endl;
            break;
        case 6:
            cout << "Thứ Bảy" << endl;
            break;
        case 7:
            cout << "Chủ Nhật" << endl;
            break;
        default:
            cout << "Ngày không hợp lệ" << endl;
    }
}

// 2.3. VÒNG LẶP FOR
void vong_lap_for() {
    cout << "\n=== VÒNG LẶP FOR ===" << endl;
    
    // For cơ bản
    cout << "Đếm từ 1 đến 5: ";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    // For với mảng
    int mang[] = {10, 20, 30, 40, 50};
    cout << "Các phần tử trong mảng: ";
    for (int i = 0; i < 5; i++) {
        cout << mang[i] << " ";
    }
    cout << endl;
    
    // Range-based for (C++11)
    cout << "Duyệt mảng với range-based for: ";
    for (int phan_tu : mang) {
        cout << phan_tu << " ";
    }
    cout << endl;
    
    // For lồng nhau (in bảng cửu chương)
    cout << "Bảng cửu chương 2:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << "2 x " << i << " = " << (2 * i) << endl;
    }
}

// 2.4. VÒNG LẶP WHILE VÀ DO-WHILE
void vong_lap_while() {
    cout << "\n=== VÒNG LẶP WHILE ===" << endl;
    
    // While - kiểm tra điều kiện trước
    int i = 1;
    cout << "While đếm từ 1 đến 5: ";
    while (i <= 5) {
        cout << i << " ";
        i++;
    }
    cout << endl;
    
    // Do-While - thực hiện trước, kiểm tra sau
    int j = 1;
    cout << "Do-While đếm từ 1 đến 5: ";
    do {
        cout << j << " ";
        j++;
    } while (j <= 5);
    cout << endl;
}

// 2.5. BREAK VÀ CONTINUE
void break_va_continue() {
    cout << "\n=== BREAK VÀ CONTINUE ===" << endl;
    
    // Break - thoát khỏi vòng lặp
    cout << "Break khi gặp 5: ";
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            break;  // Thoát vòng lặp
        }
        cout << i << " ";
    }
    cout << endl;
    
    // Continue - bỏ qua lần lặp hiện tại
    cout << "Skip số chẵn: ";
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // Bỏ qua số chẵn
        }
        cout << i << " ";
    }
    cout << endl;
}

/*
================================================================================
                        3. HÀM (FUNCTIONS)
================================================================================
*/

// 3.1. HÀM CƠ BẢN
// Hàm không có tham số, không trả về
void chao_mung() {
    cout << "Xin chào!" << endl;
}

// Hàm có tham số
void chao_ten(string ten) {
    cout << "Xin chào, " << ten << "!" << endl;
}

// Hàm trả về giá trị
int tong(int a, int b) {
    return a + b;
}

// Hàm với giá trị mặc định
int nhan(int a, int b = 2) {
    return a * b;
}

// 3.2. THAM CHIẾU VÀ THAM TRỊ
void thay_doi_gia_tri(int x) {  // Truyền tham trị - không thay đổi biến gốc
    x = 100;
}

void thay_doi_tham_chieu(int& x) {  // Truyền tham chiếu - thay đổi biến gốc
    x = 100;
}

// 3.3. OVERLOADING - NẠP CHỒNG HÀM
int cong(int a, int b) {
    return a + b;
}

double cong(double a, double b) {
    return a + b;
}

string cong(string a, string b) {
    return a + b;
}

// 3.4. HÀM ĐỆ QUY
int giai_thua(int n) {
    if (n <= 1) {
        return 1;  // Điều kiện dừng
    }
    return n * giai_thua(n - 1);  // Gọi đệ quy
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 3.5. LAMBDA FUNCTIONS (C++11)
void lambda_functions() {
    cout << "\n=== LAMBDA FUNCTIONS ===" << endl;
    
    // Lambda cơ bản
    auto chao = []() {
        cout << "Lambda chào bạn!" << endl;
    };
    chao();
    
    // Lambda với tham số
    auto tong_lambda = [](int a, int b) {
        return a + b;
    };
    cout << "Tổng 5 + 3 = " << tong_lambda(5, 3) << endl;
    
    // Lambda capture biến
    int x = 10;
    auto nhan_x = [x](int y) {  // Capture x by value
        return x * y;
    };
    cout << "10 * 5 = " << nhan_x(5) << endl;
    
    // Lambda capture by reference
    int dem = 0;
    auto tang_dem = [&dem]() {  // Capture dem by reference
        dem++;
    };
    tang_dem();
    tang_dem();
    cout << "Đếm: " << dem << endl;
}

/*
================================================================================
                        4. MẢNG VÀ CHUỖI
================================================================================
*/

// 4.1. MẢNG TĨNH
void mang_tinh() {
    cout << "\n=== MẢNG TĨNH ===" << endl;
    
    // Khai báo và khởi tạo
    int mang1[5] = {1, 2, 3, 4, 5};
    int mang2[] = {10, 20, 30};  // Tự động xác định kích thước
    
    // Truy cập phần tử
    cout << "Phần tử đầu tiên: " << mang1[0] << endl;
    cout << "Phần tử thứ 3: " << mang1[2] << endl;
    
    // Duyệt mảng
    cout << "Các phần tử: ";
    for (int i = 0; i < 5; i++) {
        cout << mang1[i] << " ";
    }
    cout << endl;
    
    // Mảng 2 chiều
    int ma_tran[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Ma trận 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ma_tran[i][j] << " ";
        }
        cout << endl;
    }
}

// 4.2. VECTOR - MẢNG ĐỘNG
void vector_mang_dong() {
    cout << "\n=== VECTOR - MẢNG ĐỘNG ===" << endl;
    
    // Khởi tạo vector
    vector<int> v1;                    // Vector rỗng
    vector<int> v2(5);                 // Vector 5 phần tử, mặc định = 0
    vector<int> v3(5, 10);             // Vector 5 phần tử, giá trị = 10
    vector<int> v4 = {1, 2, 3, 4, 5};  // Khởi tạo với danh sách
    
    // Thêm phần tử
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    
    // Truy cập phần tử
    cout << "Phần tử đầu: " << v1.front() << endl;
    cout << "Phần tử cuối: " << v1.back() << endl;
    cout << "Phần tử thứ 2: " << v1[1] << endl;
    cout << "Phần tử thứ 2 (at): " << v1.at(1) << endl;  // Kiểm tra bounds
    
    // Kích thước
    cout << "Kích thước: " << v1.size() << endl;
    cout << "Dung lượng: " << v1.capacity() << endl;
    
    // Duyệt vector
    cout << "Các phần tử: ";
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;
    
    // Xóa phần tử cuối
    v1.pop_back();
    
    // Xóa tất cả
    v1.clear();
    
    // Kiểm tra rỗng
    cout << "Vector rỗng? " << (v1.empty() ? "Có" : "Không") << endl;
}

// 4.3. CHUỖI STRING
void xu_ly_chuoi() {
    cout << "\n=== XỬ LÝ CHUỖI ===" << endl;
    
    // Khởi tạo
    string s1 = "Hello";
    string s2("World");
    string s3 = s1 + " " + s2;  // Nối chuỗi
    
    cout << "Chuỗi: " << s3 << endl;
    
    // Độ dài
    cout << "Độ dài: " << s3.length() << endl;
    cout << "Độ dài: " << s3.size() << endl;
    
    // Truy cập ký tự
    cout << "Ký tự đầu: " << s3[0] << endl;
    cout << "Ký tự cuối: " << s3[s3.length() - 1] << endl;
    
    // Chuỗi con
    string sub = s3.substr(0, 5);  // Từ vị trí 0, lấy 5 ký tự
    cout << "Chuỗi con: " << sub << endl;
    
    // Tìm kiếm
    size_t pos = s3.find("World");
    if (pos != string::npos) {
        cout << "Tìm thấy 'World' tại vị trí: " << pos << endl;
    }
    
    // Thay thế
    string s4 = s3;
    s4.replace(6, 5, "C++");  // Thay thế từ vị trí 6, 5 ký tự
    cout << "Sau khi thay thế: " << s4 << endl;
    
    // So sánh
    string a = "abc", b = "abd";
    cout << "So sánh: " << a.compare(b) << endl;  // < 0 nếu a < b
    
    // Chuyển đổi
    string so = "123";
    int num = stoi(so);  // String to int
    cout << "Số: " << num << endl;
    
    string from_num = to_string(456);  // Int to string
    cout << "Từ số: " << from_num << endl;
}

/*
================================================================================
                    5. CON TRỎ VÀ THAM CHIẾU
================================================================================
*/

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
    
    // Con trỏ NULL
    int* null_ptr = nullptr;  // C++11
    if (null_ptr == nullptr) {
        cout << "Con trỏ NULL" << endl;
    }
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

/*
================================================================================
        9. CONST CORRECTNESS
================================================================================
*/

// const reference - không cho sửa dữ liệu
void in_vector(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

void const_correctness() {
    cout << "\n=== CONST CORRECTNESS ===" << endl;

    const int a = 10;
    // a = 20; // ❌ lỗi

    int x = 5;
    const int* p1 = &x;   // Con trỏ tới const
    int* const p2 = &x;   // Con trỏ const

    cout << "Giá trị qua p1: " << *p1 << endl;
}

/*
================================================================================
        10. PREPROCESSOR & COMPILE-TIME
================================================================================
*/

#define PI_DEFINE 3.14159

constexpr int MAX_SIZE = 100;

void preprocessor_demo() {
    cout << "\n=== PREPROCESSOR & COMPILE-TIME ===" << endl;
    cout << "PI_DEFINE: " << PI_DEFINE << endl;
    cout << "MAX_SIZE: " << MAX_SIZE << endl;
}

/*
================================================================================
        11. ENUM & TYPE ALIAS
================================================================================
*/

enum class TrangThai {
    Idle,
    Running,
    Finished
};

using ll = long long;
typedef unsigned int uint;

void enum_type_alias() {
    cout << "\n=== ENUM & TYPE ALIAS ===" << endl;

    TrangThai st = TrangThai::Running;
    if (st == TrangThai::Running) {
        cout << "Chương trình đang chạy" << endl;
    }

    ll so_lon = 10000000000LL;
    uint so_duong = 100;

    cout << "ll: " << so_lon << ", uint: " << so_duong << endl;
}

/*
================================================================================
        12. STL QUAN TRỌNG KHÁC (MAP, SET, STACK, QUEUE, ALGORITHM)
================================================================================
*/

void stl_khac() {
    cout << "\n=== STL QUAN TRỌNG KHÁC ===" << endl;

    // map
    map<string, int> diem;
    diem["An"] = 8;
    diem["Binh"] = 9;
    for (auto& p : diem) {
        cout << p.first << ": " << p.second << endl;
    }

    // set
    set<int> s = {1, 2, 2, 3};
    cout << "Set: ";
    for (int x : s) cout << x << " ";
    cout << endl;

    // stack
    stack<int> st;
    st.push(1);
    st.push(2);
    cout << "Stack top: " << st.top() << endl;

    // queue
    queue<int> q;
    q.push(10);
    q.push(20);
    cout << "Queue front: " << q.front() << endl;

    // algorithm
    vector<int> v = {5, 1, 4, 2};
    sort(v.begin(), v.end());
    cout << "Sau sort: ";
    in_vector(v);
}

/*
================================================================================
        13. STRUCT & POD (KHÔNG PHẢI OOP)
================================================================================
*/

struct Student {
    string name;
    int age;
    double gpa;
};

void struct_pod() {
    cout << "\n=== STRUCT & POD ===" << endl;

    Student s1 = {"Tuấn", 20, 3.5};
    cout << "Tên: " << s1.name
         << ", Tuổi: " << s1.age
         << ", GPA: " << s1.gpa << endl;
}

/*
================================================================================
        HÀM MAIN
================================================================================
*/

int main() {
    kieu_du_lieu_co_ban();
    bien_va_hang_so();
    toan_tu();

    cau_lenh_if_else();
    cau_lenh_switch();
    vong_lap_for();
    vong_lap_while();
    break_va_continue();

    chao_mung();
    chao_ten("C++");
    cout << "Tổng: " << tong(3, 4) << endl;

    lambda_functions();

    mang_tinh();
    vector_mang_dong();
    xu_ly_chuoi();

    con_tro_co_ban();
    con_tro_va_mang();
    cap_phat_dong();
    smart_pointers();
    tham_chieu();
    file_io();
    exception_handling();
    const_correctness();
    preprocessor_demo();
    enum_type_alias();
    stl_khac();
    struct_pod();

    return 0;
}
