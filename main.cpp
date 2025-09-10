#define FMT_HEADER_ONLY
#include <iostream>
#include <vector>
#include <string>

#include "fmt/core.h"       // สำหรับการจัดรูปแบบข้อความ
#include "fmt/color.h"      // สำหรับเพิ่มสีสันใน Terminal
#include "nlohmann/json.hpp" // สำหรับจัดการข้อมูล JSON

using json = nlohmann::json;

int main() {
    // 1. สร้างข้อมูล JSON สำหรับผู้ใช้หลายคน
    json users = {
        {{"id", 1}, {"name", "Alice"}, {"score", 85.5}, {"active", true}},
        {{"id", 2}, {"name", "Bob"}, {"score", 42.0}, {"active", false}},
        {{"id", 3}, {"name", "Charlie"}, {"score", 92.3}, {"active", true}}
    };

    fmt::print(fg(fmt::color::cyan), "--- User Report ---\n\n");

    // 2. วนลูปอ่านข้อมูลและแสดงผลด้วยการจัดรูปแบบที่สวยงาม
    for (const auto& user : users) {
        std::string name = user["name"];
        double score = user["score"];
        bool is_active = user["active"];

        // ใช้ fmt ในการจัดการช่องว่าง (Padding) และทศนิยม
        // {:10} คือจองที่ 10 ตัวอักษร, {:>6.2f} คือชิดขวา 6 ช่อง ทศนิยม 2 ตำแหน่ง
        fmt::print("ID: {} | Name: {:10} | Score: {:>6.2f} | Status: ", 
                   user["id"].get<int>(), name, score);

        // แสดงสถานะพร้อมสีสัน
        if (is_active) {
            fmt::print(fg(fmt::color::green), "Online\n");
        } else {
            fmt::print(fg(fmt::color::red), "Offline\n");
        }
    }

    // 3. ตัวอย่างการดึงข้อมูลกลับมาเป็น String เพื่อบันทึกหรือส่งต่อ
    std::string exported_data = users.dump(4); // Indent 4 spaces
    fmt::print("\nRaw JSON Export:\n{}\n", exported_data);

    return 0;
}