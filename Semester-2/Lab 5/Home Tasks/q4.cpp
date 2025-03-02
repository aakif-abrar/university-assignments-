#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Blend {
public:
    void blendJuice() { for (int i = 0; i < 5; i++) { cout << "Blending..." << endl; this_thread::sleep_for(chrono::seconds(1)); } }
};

class Grind {
public:
    void grindJuice() { cout << "Grinding..." << endl; this_thread::sleep_for(chrono::seconds(5)); }
};

class JuiceMaker {
    Blend blender;
    Grind grinder;
public:
    void makeJuice() { blender.blendJuice(); grinder.grindJuice(); cout << "Juice is ready!" << endl; }
};

int main() {
    JuiceMaker jm;
    jm.makeJuice();
    return 0;
}