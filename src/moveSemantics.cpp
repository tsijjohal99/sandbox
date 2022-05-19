#include <iostream>
#include <vector>

// class foo {};

// void goo(foo&& x){foo my_foo = std::move(x)};

// void myf(int x);
// void myf(const char* p);
// void my(foo f);

// int main() {
//     myf(4);
//     myf("Hi");
//     myf(foo());

//     foo f;
//     std::cout << &f << std::endl;

//     // foo g = foo();
//     // std::cout << &g << std::endl;

//     foo g = foo();

//     goo(std::move(f));
//     std::cout << &f << std::endl;

//     goo(foo());
//     std::cout << &g << std::endl;

//     std::vector<std::string>
//         v1 = {
//             "First really long string that will avoid SSO",
//             "Second really long string that will avoid SSO"};

//     std::cout << "v1[0] = " << &v1[0] << " = " << v1[0] << std::endl;
//     std::cout << "v1[1] = " << &v1[1] << " = " << v1[1] << std::endl;

//     std::vector<std::string> v2;
//     v2 = std::move(v1);

//     std::cout << "=====================================" << std::endl;

//     // std::cout << "v1[0] = " << &v1[0] << " = " << v1[0] << std::endl;
//     // std::cout << "v1[1] = " << &v1[1] << " = " << v1[1] << std::endl;
//     std::cout << "v2[0] = " << &v2[0] << " = " << v2[0] << std::endl;
//     std::cout << "v2[1] = " << &v2[1] << " = " << v2[1] << std::endl;
// }

/*

void foo(std::string& arg) {
    std::cout << arg << std::endl;

    std::string s = arg;

    std::string s2 = std::move(arg);

    arg = "yo";
}

void foo(const std::string& arg);  // const lvalue reference

void foo(std::string& arg);  // lvalue reference

void foo(std::string&& arg);  // rvalue reference

void foo(const std::string&& arg);  // const rvalue reference

int main() {
    // foo("Hello");

    std::string cs = "NON_CONST";
    foo(cs);

    std::cout << cs << std::endl;
}*/

class foo {
   public:
    void getValue() & { std::cout << "yea" << std::endl; }
    void getValue() && { std::cout << "no" << std::endl; }
    void getValue() const& { std::cout << "const yea" << std::endl; }
    void getValue() const&& { std::cout << "const no" << std::endl; }
};

int main() {
    foo f;
    f.getValue();
    std::move(f).getValue();

    const foo g;
    g.getValue();
    std::move(g).getValue();
}