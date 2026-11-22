Bài tập Lý thuyết mật mã: DES và AES-128
1. Nội dung bài tập
Cài đặt hai thuật toán mã hóa DES và AES-128 bằng ngôn ngữ C.

Chương trình in các giá trị trung gian trong quá trình mã hóa để có thể đối chiếu với các bước tính trên lớp. Các phép biến đổi được viết trực tiếp trong mã nguồn, không dùng thư viện mã hóa có sẵn.
2. Các file trong bài
- des.c: Chương trình mã hóa DES.
- aes128.c: Chương trình mã hóa AES-128.
- des_output.txt: Kết quả chạy DES, gồm các khóa con và giá trị ở 16 vòng.
- aes_output.txt: Kết quả chạy AES-128 với ví dụ trên lớp, gồm các ma trận trạng thái.
- tests/test_vectors.txt: Dữ liệu dùng để kiểm tra chương trình.
- tests/aes_standard_output.txt: Kết quả chạy AES-128 với bộ dữ liệu kiểm thử chuẩn.
3. Thuật toán DES
DES mã hóa một khối dữ liệu 64 bit qua 16 vòng Feistel.

Các bước chính:
1. Hoán vị ban đầu IP, tách thành hai nửa L0 và R0.
2. Từ khóa đầu vào, dùng PC-1, dịch vòng và PC-2 để tạo 16 khóa con.
3. Thực hiện 16 vòng: mở rộng E, XOR khóa con, thay thế S-box, hoán vị P và cập nhật L, R.
4. Đổi vị trí hai nửa, thực hiện hoán vị cuối FP để nhận bản mã.
Chương trình in giá trị IP, L0, R0, khóa con K1 đến K16, E(R), kết quả XOR, F và L/R sau mỗi vòng.
4. Thuật toán AES-128
AES-128 mã hóa một khối 128 bit với khóa 128 bit, gồm bước cộng khóa ban đầu và 10 vòng.

Trong các vòng 1 đến 9 có bốn phép biến đổi: SubBytes, ShiftRows, MixColumns, AddRoundKey. Vòng 10 không thực hiện MixColumns.

Chương trình in khóa con từng vòng và ma trận trạng thái 4 x 4 sau mỗi phép biến đổi. Các byte của trạng thái được sắp xếp theo cột như quy ước AES.
