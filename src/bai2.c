#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
int thanhToanHoaDon(float *soDuVi, float tongTien, float tyLeHoan, float *tienHoan);

#ifndef UNIT_TEST
int main() {
    float soDu = 500000.0;
    float hoaDon, tyLe;
    float tienDuocHoan = 0.0;

    printf("So du vi hien tai: %.2f VND\n", soDu);
    printf("Nhap so tien hoa don: ");
    scanf("%f", &hoaDon);
    printf("Nhap ty le cashback (%%): ");
    scanf("%f", &tyLe);

    int trangThai = thanhToanHoaDon(&soDu, hoaDon, tyLe, &tienDuocHoan);

    if (trangThai == 1) {
        printf("\n>> Giao dich THANH CONG!");
        printf("\nTien cashback nhan ve: %.2f VND", tienDuocHoan);
        printf("\nSo du vi sau cung: %.2f VND\n", soDu);
    } else {
        printf("\n>> Giao dich THAT BAI (So du khong du)!");
        printf("\nSo du giu nguyen: %.2f VND\n", soDu);
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
int thanhToanHoaDon(float *soDuVi, float tongTien, float tyLeHoan, float *tienHoan) {
    // 1. Kiểm tra nếu số dư không đủ để thanh toán
    if (*soDuVi < tongTien) {
        return 0; // Thất bại (không đủ tiền)
    }

    // 2. Tính số tiền được hoàn (cashback)
    *tienHoan = tongTien * (tyLeHoan / 100.0f);

    // 3. Cập nhật số dư ví: Trừ tiền hóa đơn và Cộng lại tiền cashback
    *soDuVi = *soDuVi - tongTien + *tienHoan;

    return 1; // Thành công
}