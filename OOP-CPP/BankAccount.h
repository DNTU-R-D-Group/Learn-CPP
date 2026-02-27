// ============================================================================
//                          BankAccount.h
//                    (VÍ DỤ VỀ ENCAPSULATION)
// ============================================================================
/*
ENCAPSULATION (Đóng gói):
- Ẩn dữ liệu bên trong class (private)
- Chỉ truy cập qua public methods
- Bảo vệ tính toàn vẹn của dữ liệu
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

namespace MyProject {

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;
    std::string pin;  // Mật khẩu - hoàn toàn private
    
    // Private helper method
    bool validatePin(const std::string& inputPin) const;
    
public:
    // Constructor
    BankAccount(const std::string& accountNumber, 
                const std::string& accountHolder,
                const std::string& pin);
    
    // Public methods để tương tác với dữ liệu private
    bool deposit(double amount, const std::string& pin);
    bool withdraw(double amount, const std::string& pin);
    bool transfer(BankAccount& toAccount, double amount, const std::string& pin);
    
    // Getter (không cho phép thay đổi trực tiếp)
    double getBalance(const std::string& pin) const;
    std::string getAccountNumber() const;
    std::string getAccountHolder() const;
    
    // Setter có validation
    bool changePin(const std::string& oldPin, const std::string& newPin);
    
    void displayInfo() const;
};

} // namespace MyProject

#endif // BANKACCOUNT_H