#include <iostream>
#include <tuple>

template<typename T1, typename T2> class MyClass
{
    T1 value1;
    T2 value2;
public:

    MyClass() = default;

    MyClass(const T1& val1, const T2& val2)
    {
        value1 = val1;
        value2 = val2;
    }

    MyClass(const MyClass& other)
    {
        value1 = other.value1;
        value2 = other.value2;
    }


    MyClass& operator=(const MyClass& other)
    {
        value1 = other.value1;
        value2 = other.value2;
        return *this;
    }

    void set(const T1& val1, const T2& val2)
    {
        value1 = val1;
        value2 = val2;
    }

    std::pair<T1, T2> get() const noexcept
    {
        return std::pair<T1, T2> (value1, value2);
    }

    T1 get_left_value() const noexcept
    {
        return value1;
    }

    T2 get_right_value() const noexcept
    {
        return value2;
    }

    ~MyClass() = default;
};

int main()
{
    std::tuple<MyClass<int, int>, int> arr(MyClass<int, int> (1, 1), 5);
}