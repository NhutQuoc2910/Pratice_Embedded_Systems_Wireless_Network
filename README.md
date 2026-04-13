# 🌐 Mạng Không Dây và Hệ Thống Nhúng

[![Ubuntu](https://img.shields.io/badge/Ubuntu-20.04-orange.svg)](https://ubuntu.com/)
[![NS-3](https://img.shields.io/badge/NS--3-3.33-blue.svg)](https://www.nsnam.org/) 

Chào mừng bạn đến với repository chứa các bài thực hành môn **Mạng Truyền Thông Không Dây và Hệ Thống Nhúng**. Dự án này tập trung vào việc mô phỏng và phân tích các mạng không dây, giao thức định tuyến MANET, và cấu hình hệ thống mạng trên Linux.

## 📋 Mục Lục
- [Giới Thiệu](#-giới-thiệu)
- [Cấu Trúc Thư Mục](#-cấu-trúc-thư-mục)
- [Chi Tiết Các Bài Lab](#-chi-tiết-các-bài-lab)
- [Yêu Cầu Hệ Thống](#-yêu-cầu-hệ-thống)
- [Hướng Dẫn Cài Đặt và Sử Dụng](#-hướng-dẫn-cài-đặt-và-sử-dụng)
- [Nhóm Thực Hiện](#-nhóm-thực-hiện)

## 📖 Giới Thiệu
Repository này lưu trữ mã nguồn, kết quả mô phỏng và báo cáo cho các chủ đề chính:
- **Mô phỏng mạng WLAN 802.11** sử dụng NS-3
- **Phân tích giao thức định tuyến MANET** (AODV, OLSR, v.v.)
- **Cấu hình Netfilter & Iptables** trên Linux kernel

Mỗi lab được tổ chức rõ ràng với mã nguồn, file phân tích và báo cáo chi tiết.

## 🏗 Cấu Trúc Thư Mục
```
.
├── README.md                    # Tài liệu hướng dẫn
├── LAB01/                       # Lab 1: WLAN 802.11 với NS-3
│   ├── cau12.txt               # Báo cáo câu 12
│   ├── cau13.txt               # Báo cáo câu 13
│   ├── lab1-student.cc         # Mã nguồn NS-3
│   ├── task2.txt               # Task 2
│   ├── task2full.txt           # Task 2 đầy đủ
│   └── TH1.03-Lab1_24521485_24521486_24521541/
│       ├── lab1-task1-code.cc  # Code task 1
│       ├── lab1-task1-ap-0-1.pcap    # PCAP từ AP
│       ├── lab1-task1-client-1-0.pcap # PCAP từ Client
│       ├── lab1-task1-server-4-0.pcap # PCAP từ Server
│       └── Nhom03-Lab01-task2.pcapng  # PCAP task 2
├── LAB02/                       # Lab 2: MANET Routing Protocols
│   ├── Đình Quốc/
│   │   ├── lab2-aodv-dev0-0-0.pcap  # AODV PCAP
│   │   ├── lab2-aodv-dev1-1-0.pcap
│   │   ├── lab2-aodv-dev2-2-0.pcap
│   │   ├── lab2-aodv-dev3-3-0.pcap
│   │   ├── lab2-olsr-3-0.txt   # OLSR log
│   │   └── lab2-olsr.cc        # OLSR code
│   ├── Sử/
│   │   ├── lab2-olsr-0-0.pcap  # OLSR PCAP
│   │   ├── lab2-olsr-1-0.pcap
│   │   ├── lab2-olsr-2-0.pcap
│   │   └── lab2-olsr-3-0.pcap
│   └── src/
│       ├── lab2-aodv.cc        # AODV code
│       ├── lab2-olsr.cc        # OLSR code
│       └── myapp.h             # Header file
├── LAB03/                       # Lab 3: Netfilter & Iptables
│   └── src/
│       ├── Makefile            # Build script
│       ├── nkmod_Cau1.c        # Kernel module câu 1
│       ├── nkmod_Cau2.c        # Kernel module câu 2
│       ├── nkmod_Cau3.c        # Kernel module câu 3
│       ├── nkmod_Cau4.c        # Kernel module câu 4
│       └── nkmod_Cau5.c        # Kernel module câu 5
├── LAB04/                       # Lab 4: (Chưa có nội dung)
├── LAB05/                       # Lab 5: (Chưa có nội dung)
└── LAB06/                       # Lab 6: (Chưa có nội dung)
```

## 🔬 Chi Tiết Các Bài Lab

### 🌐 [LAB01] Giới Thiệu WLAN 802.11
**Công cụ:** NS-3 Simulator  
**Mục tiêu:** Thiết lập và mô phỏng mạng WiFi với Access Point và Station, sử dụng mô hình di động và ứng dụng UDP Echo.  
**Nội dung:**
- Phân tích gói tin WLAN
- Mô phỏng kịch bản mạng
- Phân tích hiệu năng

**File chính:**
- `lab1-student.cc`: Script mô phỏng NS-3
- Các file `.pcap`: Gói tin thu thập được

### 🚀 [LAB02] Giao Thức Định Tuyến MANET
**Mục tiêu:** So sánh và phân tích các giao thức định tuyến trong mạng ad-hoc (AODV, OLSR).  
**Nội dung:**
- Triển khai AODV và OLSR
- Phân tích hiệu năng mạng
- Thu thập và phân tích gói tin

**File chính:**
- `lab2-aodv.cc`: Code AODV
- `lab2-olsr.cc`: Code OLSR
- Các file `.pcap`: Dữ liệu mạng

### 🛡️ [LAB03] Netfilter & Iptables
**Công cụ:** Linux Kernel, Iptables  
**Mục tiêu:** Cấu hình firewall, NAT và quản lý lưu lượng mạng.  
**Nội dung:**
- Viết kernel modules
- Cấu hình Netfilter rules
- Thực hành forwarding và filtering

**File chính:**
- `nkmod_Cau1.c` đến `nkmod_Cau5.c`: Kernel modules
- `Makefile`: Script build

### 🔄 [LAB04-06] Các Lab Sắp Tới
Các lab này chưa có nội dung cụ thể. Sẽ được cập nhật trong tương lai.

## 💻 Yêu Cầu Hệ Thống
- **Hệ điều hành:** Linux (Ubuntu 20.04 khuyến nghị)
- **Trình mô phỏng:** [NS-3](https://www.nsnam.org/) (phiên bản 3.33+)
- **Công cụ phân tích:** Wireshark (đọc file .pcap/.pcapng)
- **Công cụ build:** GCC, Make (cho kernel modules)
- **Phần mềm khác:** Git, Github (nếu cần)

## 🚀 Hướng Dẫn Cài Đặt và Sử Dụng

### 1. Cài Đặt NS-3
```bash
# Tải và cài đặt NS-3
wget https://www.nsnam.org/releases/ns-allinone-3.36.tar.bz2
tar xjf ns-allinone-3.36.tar.bz2
cd ns-allinone-3.36
./build.py --enable-examples --enable-tests
```

### 2. Chạy Mô Phỏng NS-3 (Ví dụ Lab 1)
```bash
# Copy code vào thư mục scratch của NS-3
cp LAB01/lab1-student.cc path/to/ns-3/scratch/

# Chạy mô phỏng
cd path/to/ns-3
./ns3 run scratch/lab1-student

# Xem kết quả PCAP
wireshark LAB01/TH1.03-Lab1_24521485_24521486_24521541/lab1-task1-ap-0-1.pcap
```

### 3. Build Kernel Modules (Lab 3)
```bash
cd LAB03/src
make
sudo insmod nkmod_Cau1.ko  # Ví dụ load module
```

### 4. Phân Tích Dữ Liệu
- Sử dụng Wireshark để mở file .pcap
- Đọc báo cáo trong các file .txt

## 👥 Nhóm Thực Hiện
- **24521485**: Nguyễn Đình Quốc
- **24521486**: Nguyễn Nhựt Quốc
- **24521541**: Châu Lê Quốc Sử

---

*📚 Tài liệu này phục vụ mục đích học tập và nghiên cứu. Đóng góp và phản hồi được chào đón!*