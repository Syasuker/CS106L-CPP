//
// Created by zhuda on 2023/9/11.
//

using namespace std;

class ConstStaticClass {
public:
    void constFn() const;

private:
    static int staticData;
};

int ConstStaticClass::staticData = 0;

void ConstStaticClass::constFn() const {
    ++staticData;
}