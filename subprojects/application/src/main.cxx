#include <iostream>

#include <p5/experiments/cmake/framework_with_dedicated_components/a.hpp>
#include <p5/experiments/cmake/framework_with_dedicated_components/b.hpp>


int main(int, char **) {
    ::std::clog << ::p5::experiments::cmake::framework_with_dedicated_components::a::message() << ::std::endl << ::std::flush;
    ::std::clog << ::p5::experiments::cmake::framework_with_dedicated_components::b::message() << ::std::endl << ::std::flush;
    return 0;
}
