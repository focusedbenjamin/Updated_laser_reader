#include <ros/ros.h>

using std::string;

int main(int argc, char **argv) {
  ros::init(argc, argv, "lambda_basics_node");
  ros::NodeHandle _n("lambda_basics_ns");

  // We define the Lambda function merge_words
  auto merge_words = [](std::string a, std::string b) -> string {
    return a + "-" + b;
  };

  auto result = merge_words("Adventure", "Time");

  std::cout << "Result Merge: " << result << std::endl;
  auto dummy_positive = []() -> bool { return false; };

  bool dummy_x = dummy_positive();
  printf(dummy_x ? "true" : "false");
  printf("\n");

  // Capture list example
  std::string w1 = "Finn";
  std::string w2 = "Jacke";
  
  auto best_pals = [w1, &w2] {
  w2 = "IceKing";
  return w1 + " friend of " + w2;
  };
  auto result2 = best_pals();
  std::cout << "Result best_pals: " << result2 << std::endl;
  std::cout << "final value of w1: " << w1 << std::endl;
  std::cout << "final value of w2: " << w2 << std::endl;

  // Mutable example
  std::string MutableName = "Prismo";
  int MutableId = 1;
  
  auto mutable_lambda = [=]() mutable {
  MutableId += 1;
  MutableName = "Prismo-" + std::to_string(MutableId);
  std::cout << "MutableName Inside Lambda =" << MutableName << std::endl;
  std::cout << "MutableId Inside Lambda =" << MutableId << std::endl;
  return;
  };
  mutable_lambda();
  std::cout << "MutableName Outside Lambda =" << MutableName << std::endl;
  std::cout << "MutableId Outside Lambda =" << MutableId << std::endl;
  
  mutable_lambda();
  std::cout << "MutableName Outside Lambda =" << MutableName << std::endl;
  std::cout << "MutableId Outside Lambda =" << MutableId << std::endl;
  
  return 0;
}