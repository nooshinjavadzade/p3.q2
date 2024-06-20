#include <iostream>

struct MyStruct {
    int data;
    // اگر دیگر فیلد‌ها نیاز دارید، آن‌ها را اضافه کنید
};

void shiftArray(MyStruct arr[], int size, int index) {
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = {}; // خالی کردن آخرین خانه
}

int main() {
    const int size = 10;
    MyStruct arr[size] = {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}}; // آرایه مثالی از ساختارها
    
    int indexToRemove = 3; // شماره خانه‌ای که می‌خواهیم حذف کنیم
    
    shiftArray(arr, size, indexToRemove);
    
    // چاپ آرایه پس از جابجایی
    for (int i = 0; i < size; i++) {
        std::cout << arr[i].data << " ";
    }
    
    return 0;
}
