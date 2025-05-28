#include <string>

using namespace std;

typedef unsigned int level_t;

class Pokemon {
    private:
        const string name;
        level_t experience;
    public:
        Pokemon(const string& _name);
        Pokemon(const string& _name, const level_t _experience);
        ~Pokemon() = default;

        string getName() const;
        level_t getLevel() const;

        void setName();
        void setLevel();

        friend ostream& operator<<(ostream& os, const Pokemon& pokemon);
};