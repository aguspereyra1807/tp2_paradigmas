// Esto también incesario


// #pragma once

// #include <unordered_map>

// using namespace std;

// using id_t = unsigned int;

// class Zone {
//     private:
//         const id_t id;
//     public:
//         Zone();
//         ~Zone() = default;

//         id_t getId() const;
// };

// namespace std {
//     template<>
//     struct hash<Zone> {
//         size_t operator() (const Zone& zone) const {
//             return hash<id_t>()(zone.getId());
//         }
//     };
// }