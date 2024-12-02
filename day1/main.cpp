#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <print>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

using std::stringstream;

const std::filesystem::path input1_file = "input1.txt";
const std::filesystem::path input2_file = "input2.txt";
const std::filesystem::path test_file   = "test.txt";

std::optional<int> part1()
{
  std::fstream file{input1_file};
  if (!file.is_open())
  {
    std::println("Could not open file");
    return std::nullopt;
  }

  std::vector<int> left;
  std::vector<int> right;
  stringstream     ss;
  int              left_num{};
  int              right_num{};
  for (std::string line; std::getline(file, line);)
  {
    ss << line;
    ss >> left_num >> right_num;
    left.insert(std::ranges::upper_bound(left, left_num), left_num);
    right.insert(std::ranges::upper_bound(right, right_num), right_num);
    ss.clear();
  }
  file.close();

  int sum{0};
  for (int i = 0; i < left.size(); ++i)
  {
    sum += std::abs(left[i] - right[i]);
  }
  return sum;
}

int main(int argc, char* argv[])
{
  const auto result1 = part1();

  if (!result1.has_value())
  {
    return EXIT_FAILURE;
  }
  std::println("Part 1: {}", result1.value());
  return EXIT_SUCCESS;
}
