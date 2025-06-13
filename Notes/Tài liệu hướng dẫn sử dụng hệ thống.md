
# 📘 HƯỚNG DẪN SỬ DỤNG HỆ THỐNG SINH TEST `test_generator.cpp`

---

## 🎯 MỤC TIÊU

- Tự động sinh **input** và **output** cho bài toán lập trình.
- Hỗ trợ stress test để kiểm tra tính đúng đắn giữa 2 lời giải.
- Tổ chức file test một cách có hệ thống.
- Có thể sử dụng dễ dàng và tuỳ chỉnh linh hoạt.

---

## 🧱 1. CẤU TRÚC CHÍNH CỦA FILE

```cpp
void funcInput(ofstream& inp);        // Bạn viết code sinh input ở đây
const string FILENAME = "BAI2";       // Tên bài/toàn bộ test
const int TEST_START = 1;
const int TEST_END = 20;
const function<void(ofstream&)> FUNC_INPUT = funcInput;  // Hàm dùng để sinh input
```

---

## ✍️ 2. CÁCH VIẾT CODE SINH INPUT

Bạn viết mã sinh test trong hàm `funcInput(...)`. Đây là nơi bạn quy định logic tạo dữ liệu cho mỗi test.

Ví dụ:
```cpp
void funcInput(ofstream& inp) {
    int n = randNum(1, 100);
    inp << n << '\n';
    for (int i = 0; i < n; ++i)
        inp << randNum(1, 1e9) << ' ';
}
```

Hàm `randNum(l, r)` hỗ trợ sinh số nguyên ngẫu nhiên từ `l` đến `r`.

---

## ⚙️ 3. CẤU HÌNH CÁC TÙY CHỌN

| Tên biến | Ý nghĩa | Giá trị gợi ý |
|----------|---------|---------------|
| `FILENAME` | Tên thư mục chứa test | "BAI1", "SUM", ... |
| `TEST_START`, `TEST_END` | Khoảng số test | `1 → 20`, `1 → 100` |
| `GENERATE_OUTPUT` | Có chạy file lời giải để sinh output không? | `true` |
| `SEPERATE_EACH_TEST` | Có tạo thư mục riêng cho từng test không? | `true` |
| `PREVENT_IDENTICAL_TESTS` | Tránh sinh trùng test | `false` (vì chậm) |
| `OVERWRITE_OLD_TESTS` | Ghi đè test cũ nếu trùng tên | `true` |
| `CLEAN_ROOT_FOLDER` | Xoá toàn bộ thư mục FILENAME trước khi sinh | `false` |

---

## 🧪 4. CHẾ ĐỘ STRESS TEST (SO SÁNH 2 LỜI GIẢI)

Bạn có thể kiểm tra xem hai chương trình `.exe` có cho ra output giống nhau hay không.

| Biến | Ý nghĩa |
|------|--------|
| `STRESS_TEST` | Bật chế độ stress test |
| `STRESS_TEST_REPEAT_UNTIL_WA` | Lặp vô hạn đến khi tìm thấy test sai |
| `STRESS_TEST_FORCE_STOP` | Dừng ngay khi phát hiện test sai |
| `STRESS_TEST_WRITE_REPORT` | Ghi log `AC/WA` vào `stress_test_log.txt` |
| `STRESS_TEST_MOVE_WA_OUTPUT_TO_DIRECTORY` | Lưu output bị sai vào thư mục test |
| `STRESS_TEST_KEEP_WA_TEST_ONLY` | Chỉ lưu test gây sai |

> 🎯 Cần có 2 file `.exe` cùng thư mục:
> - `BAI2.exe` – lời giải chính
> - `BAI2_test.exe` – lời giải phụ

---

## 🗂️ 5. CẤU TRÚC THƯ MỤC SAU KHI SINH TEST

Nếu `SEPERATE_EACH_TEST = true`, chương trình sẽ tạo thư mục như sau:

```
BAI2/
├── test1/
│   ├── BAI2.inp
│   └── BAI2.out
├── test2/
│   ├── BAI2.inp
│   └── BAI2.out
...
```

Nếu sai ở bước nào đó, log lỗi sẽ được ghi vào **`LOG.txt`**.

---

## 🧼 6. CÁC TÍNH NĂNG BỔ TRỢ

| Tính năng | Mô tả |
|----------|------|
| `fileExist(name)` | Kiểm tra file tồn tại |
| `logError(test, msg)` | Ghi log lỗi cụ thể cho test |
| `fc` (file compare) | So sánh output từ 2 lời giải |
| `system()` | Chạy `.exe` từ chương trình |

---

## 🚀 7. CÁCH CHẠY HỆ THỐNG

1. Viết hàm `funcInput` đúng bài cần sinh test.
2. Đặt tên lời giải đúng (`BAI2.exe`, `BAI2_test.exe` nếu dùng stress test).
3. Biên dịch và chạy `test_generator.cpp`.
4. Kiểm tra thư mục output hoặc `LOG.txt` nếu có lỗi.

---

## 💬 8. GỢI Ý SỬ DỤNG

- **Sinh test cho một bài toán mới**:
  - Thay `FILENAME`
  - Viết lại `funcInput(...)`
  - Chạy và thu output

- **Kiểm tra lời giải của học sinh**:
  - Bật `STRESS_TEST`
  - So sánh với `BAI2_test.exe` (lời giải học sinh)

- **Tạo bộ đề chấm CMS**:
  - Dùng `SEPERATE_EACH_TEST = true`
  - Export thành `.zip`

---

## 📌 GHI NHỚ

- Cần có file `.exe` tương ứng để sinh output.
- Nên để `SHOW_COMPARE_ON_CMD = true` để debug dễ hơn.
- Nên tắt `PREVENT_IDENTICAL_TESTS` nếu số test lớn để tăng tốc.
