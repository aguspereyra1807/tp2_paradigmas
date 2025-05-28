#include <string>
#include <vector>

using namespace std;

class PokemonInfo {
    private:
        const string type;
        const string description;
        const unordered_map<string, unsigned int> attacksByLevel;
        const vector<unsigned int> nextLevelExperience;
    public:
        PokemonInfo(const string& _type, const string& _description, const unordered_map<string, unsigned int> _attacksByLevel, const vector<unsigned int> _nextLevelExperience);
        ~PokemonInfo() = default;

        string getType() const;
        string getDescription() const;
};
