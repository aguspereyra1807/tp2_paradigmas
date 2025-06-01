#pragma once

using id_t = unsigned int;

class Dron {
    private:
        const id_t id;
        bool overTenMts;
    public:
        Dron();
        ~Dron();

        bool isOverTenMts() const;

        void toggleOverTenMts();
};