
# Bank Management System (C++)

This project is a console-based Bank Management System written in C++.  
Originally, it supported only one admin user, but **a new feature has been added**:  
👉 **Multiple Admin/User Accounts with Permissions**.

This system allows admins to manage clients, perform transactions, and control user permissions.

---

## 🔥 New Feature Added (Update)

### ✅ **✔ Multi-User System**
You can now create **multiple users/admins**, each with their own:
- Username  
- Password  
- Permissions (full or limited)

### ✅ **✔ User Permissions**
Each user can be assigned permissions such as:
- Show client list  
- Add new clients  
- Delete clients  
- Update client info  
- Search for clients  
- Perform transactions  
- Manage other users  

Permissions use bitwise flags to give very flexible access control.

### File Added / Updated
- `Users.txt` – Stores all system users
- New functions:
  - `ManageUsersMenu`
  - `CheckAccessPermission`
  - `ShowManageUsersMenuScreen()`
  - `ReadUser() / AddUserToFile()`
  - And more…

---

## 📌 Features
### 🔐 **User Management**
- Create new admin/user  
- Delete users  
- Assign permissions  
- Login system with username/password  

---

