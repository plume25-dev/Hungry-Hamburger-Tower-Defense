#include "Map.h"
#include <iostream>

// Constructor : สร้างแผนที่ 30x30 และกำหนดทางเดิน + ฐาน
Map::Map() {
    rows = 30;
    cols = 30;

    // ล้างกระดาน
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            grid[i][j] = 0;

    int topLane = rows / 4;        // 30/4 = 7
    int middleRow = rows / 2;      // 15
    int bottomLane = rows - 5;     // 25
    int rightCol = cols - 6;       // 24

    // ===== เลนบน =====
    for (int j = 0; j < rightCol; j++)
        grid[topLane][j] = 1;

    // ลงกลาง
    for (int i = topLane; i < middleRow; i++)
        grid[i][rightCol] = 1;

    // กลับซ้าย
    for (int j = rightCol; j >= 5; j--)
        grid[middleRow][j] = 1;

    // ลงล่าง
    for (int i = middleRow; i < bottomLane; i++)
        grid[i][5] = 1;

    // ไปขวาเข้าฐาน
    for (int j = 5; j < cols - 1; j++)
        grid[bottomLane][j] = 1;

    // ฐาน
    grid[bottomLane][cols - 1] = 2;
}


// แสดงผลแผนที่บนหน้าจอ
// . = พื้นว่าง, # = ทางเดิน, H = ฐาน
void Map::draw() {
    std::cout << "---- Tower Defense Map ----\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (grid[i][j] == 0)
                std::cout << ". ";
            else if (grid[i][j] == 1)
                std::cout << "# ";
            else if (grid[i][j] == 2)
                std::cout << "H ";
        }
        std::cout << std::endl;
    }
}


// เช็คว่าตำแหน่งเป็นทางเดินหรือไม่
bool Map::isPath(int r, int c) {
    // ป้องกัน index หลุด
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return false;

    return grid[r][c] == 1;
}


// เช็คว่าสามารถวาง Tower ได้หรือไม่
// ต้องเป็นช่องว่าง (0) และอยู่ในขอบเขต
bool Map::canPlace(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return false;

    return grid[r][c] == 0;
}


// เช็คว่า Enemy ถึงฐานแล้วหรือยัง
bool Map::reachedBase(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return false;

    return grid[r][c] == 2;
}