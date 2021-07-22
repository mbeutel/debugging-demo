
#include <vector>
#include <string>       // for stod()
#include <numeric>      // for partial_sum()
#include <iostream>     // for cout, cerr
#include <stdexcept>    // for runtime_error
#include <string_view>


// NOTE: this code has bugs.

std::vector<double>
integrate(std::vector<double> const& src)
{
    auto dst = std::vector<double>(src.size());
    auto it = dst.begin();
    *it++ = 0;
    std::partial_sum(src.begin(), src.end(), it);
    return dst;
}


int
main(int argc, char* argv[])
try
{
    if (argc < 2 || std::string_view(argv[1]) == "-h")
    {
        static constexpr std::string_view helpString =
R"raw(Usage:
  scan <numbers>...

Computes the scan of the given sequence of numbers.
)raw";

        std::cout << helpString;
        return 0;
    }

    // We can assume `argc > 1` henceforth.
    
    int n = argc - 1;
    auto numbers = std::vector<double>(static_cast<std::size_t>(n));
    for (int i = 0; i < n; ++i)
    {
        numbers[i] = std::stod(argv[1 + i]);
    }
    auto integratedNumbers = integrate(numbers);
    for (auto number : integratedNumbers)
    {
        std::cout << number << ' ';
    }
    std::cout << '\n';
}
catch (std::runtime_error const& e)
{
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
}
