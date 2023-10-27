#include <iostream>
#include <string>
using std::string;

class person {
    private:

        char gender;
    public:

        string name;
        int age;
        float height;
        string city;

        person(string aName, char aGender, int aAge, float aHeight, string aCity) {

            name = aName;
            setGender(aGender);
            age = aAge;
            height = aHeight;
            city = aCity;

        }
        void setGender(char aGender) {
            if (aGender == 'M' || aGender == 'F') {
                gender = aGender;
            } else { 
                exit(1);
            }
        }
        char getGender() {
            return gender;
        }
};

int main(int argc, char *argv[]) {

    return 0;
}