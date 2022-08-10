#include <iostream>


//Templating lets us declare the size and type of the array when we create it.
//because this is a stack memory array, the compiler needs to know the required memory allocation at compile time, so we cannot declare an array dynamically.
//templating is what allows us to create the array without having a single set size requirement.
template<typename T, size_t S>
class Array
{
//this is a class constructer.
public:
	//size is not stored, when the array is first created, every templated S and T is replaced by the actual value.
	//so in this case this function literally just returns a set integer, rather than a stored variable.
	constexpr size_t Size() const { return S; }

	T& operator[](size_t index) 
	{
		if (!(index < S))
		{
			__debugbreak();
		}
		return m_Data[index];
	}
	const T& operator[](size_t index) const 
	{
		if (!(index < S))
		{
			__debugbreak();
		}
		return m_Data[index]; 
	}

	T* Data() { return m_Data; }
	const T* Data() const { return m_Data; }


//this is class data.
private:
	T m_Data[S];
};


int main()
{
	Array<int, 5> data;

	const auto& arrayReference = data;
	for (size_t i = 0; i < data.Size(); i++)
	{
		std::cout << data[i] << std::endl;
	}

	std::cin.get();

}