g++ main.cpp app.cpp libgtest.a -lpthread -std=c++14 -I /home/runner/TDDdemo/demo_app/include -o main_gtest
if [ $? == 0 ]; then
  ./main_gtest
fi