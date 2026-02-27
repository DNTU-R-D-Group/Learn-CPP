// ============================================================================
//                          BankAccount.cpp
// ============================================================================
#include "BankAccount.h"

#include <iostream>

namespace MyProject {

BankAccount::BankAccount(const std::string& accountNumber,
                         const std::string& accountHolder,
                         const std::string& pin)
    : accountNumber(accountNumber), accountHolder(accountHolder), 
      balance(0.0), pin(pin) {
    std::cout << "[BankAccount] Tạo tài khoản: " << accountNumber << "\n";
}

// Private method - chỉ dùng trong class
bool BankAccount::validatePin(const std::string& inputPin) const {
    return (pin == inputPin);
}

// Gửi tiền
bool BankAccount::deposit(double amount, const std::string& pin) {
    if (!validatePin(pin)) {
        std::cout << "PIN không đúng!\n";
        return false;
    }
    
    if (amount <= 0) {
        std::cout << "Số tiền không hợp lệ!\n";
        return false;
    }
    
    balance += amount;
    std::cout << "Gửi tiền thành công: " << amount << " VNĐ\n";
    return true;
}

// Rút tiền
bool BankAccount::withdraw(double amount, const std::string& pin) {
    if (!validatePin(pin)) {
        std::cout << "PIN không đúng!\n";
        return false;
    }
    
    if (amount <= 0) {
        std::cout << "Số tiền không hợp lệ!\n";
        return false;
    }
    
    if (amount > balance) {
        std::cout << "Số dư không đủ!\n";
        return false;
    }
    
    balance -= amount;
    std::cout << "Rút tiền thành công: " << amount << " VNĐ\n";
    return true;
}

// Chuyển khoản
bool BankAccount::transfer(BankAccount& toAccount, double amount, 
                           const std::string& pin) {
    if (withdraw(amount, pin)) {
        // Tạm thời dùng PIN giả để deposit
        toAccount.balance += amount;
        std::cout << "Chuyển khoản thành công đến: " 
                  << toAccount.accountNumber << "\n";
        return true;
    }
    return false;
}

// Xem số dư
double BankAccount::getBalance(const std::string& pin) const {
    if (!validatePin(pin)) {
        std::cout << "PIN không đúng!\n";
        return -1.0;
    }
    return balance;
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

std::string BankAccount::getAccountHolder() const {
    return accountHolder;
}

// Đổi PIN
bool BankAccount::changePin(const std::string& oldPin, 
                            const std::string& newPin) {
    if (!validatePin(oldPin)) {
        std::cout << "PIN cũ không đúng!\n";
        return false;
    }
    
    if (newPin.length() < 4) {
        std::cout << "PIN mới phải có ít nhất 4 ký tự!\n";
        return false;
    }
    
    this->pin = newPin;
    std::cout << "Đổi PIN thành công!\n";
    return true;
}

void BankAccount::displayInfo() const {
    std::cout << "=== THÔNG TIN TÀI KHOẢN ===\n";
    std::cout << "Số TK: " << accountNumber << "\n";
    std::cout << "Chủ TK: " << accountHolder << "\n";
    std::cout << "Số dư: ****** (cần PIN để xem)\n";
}

} // namespace MyProject