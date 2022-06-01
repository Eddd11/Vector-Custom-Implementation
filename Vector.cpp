#include <iostream>

template <typename T>
class Vector
{
    public:
    Vector()
        : m_size{0}, m_cap{2}, m_buff{new T[m_cap]}
    {
    }
    ~Vector()
    {
        delete [] m_buff;
        m_buff = nullptr;
    }
    bool empty() const
    {
            if(m_size == 0)
            {
                std::cout << "Container is empty " << std::endl;
                return true;
            }
            std::cout << "Container is not empty " << std::endl;
            return false;
    }
    void size()const
    {
            std::cout <<"The size is " << m_size << std::endl; 
    }
    void capacity() const
    {
            std::cout << "The capacity is " << m_cap << std::endl;
    }
    void push_back(T value = 0)
    {
        if(m_size == m_cap)
        {
            T* m_tmp = m_buff;
            m_buff = new T[2 * m_cap];
            for(int i = 0; i < m_size; ++i)
            {
                m_buff[i] = m_tmp[i];
            }
            delete [] m_tmp;
            m_cap *= 2;
            m_tmp = nullptr;
            std::cout << "new array created " << std::endl;
        }
            m_buff[m_size] = value;
            m_size++;
            std::cout << "push_back is done " << std::endl;
    }
    void pop_back()
    {
        if(m_size == 0)
        {
            std::cout << "Container is empty - program is terminated " << std::endl;
            return;
        }
            T* m_tmp = m_buff;
            m_buff = new T[m_cap - 1];
            for(int i = 0; i < m_size - 1; ++i)
            {
            m_buff[i] = m_tmp[i];
            }
            m_size--;
            std::cout << "pop_back is done " << std::endl;
    }
    void clear()
    {
        delete [] this-> m_buff;
        m_buff = new T[m_cap];
        m_size = 0;
    }
    Vector(const Vector & other)
    {
        this -> m_size = other.m_size;
        this -> m_cap = other.m_cap;
        this -> m_buff = new T[m_cap];
        for(int i = 0; i < m_size; ++i)
            {
                this-> m_buff[i] = other.m_buff[i];
            }
    }
    auto& operator[](int index)
    {
        return this -> m_buff[index];
    }
    auto& At(int index)
    {
        if(index < 0 || index > m_size)
        {
                std::cout << "No matching index " << std::endl;
        }
        return this->m_buff[index];
    }
    auto& Front()
    {
        return m_buff[0];
    }
    auto& Back()
    {
        return m_buff[m_size - 1];
    }
    Vector& operator=(const Vector & other)
    {
        this -> m_size = other.m_size;
        this -> m_cap = other.m_cap;
        T* m_tmp = new T[other.m_cap];
        for(int i = 0; i < other.m_size; ++i)
        {
            m_tmp[i] = other.m_buff[i];
        }
        delete [] this -> m_buff;
        m_buff = m_tmp;
        return *this;
    }
    void reserve(int value)
    {
        std::cout << "Reserve called for " << value << " capacity ";
        if(this -> m_size < value)
        {
            T* m_tmp = new T[value];
            for(int i = 0; i < this -> m_size; ++i)
            {
                m_tmp[i] = this-> m_buff[i];
            }
            this -> m_cap = value;
            delete [] this-> m_buff;
            m_buff = m_tmp;
        }
        else{
            std::cout << "The reserved value is lower than size of container " << std::endl;
        }
        return;
    }

    void resize(int count, T value = 0)
    {
        if(count >= this -> m_cap)
        {
            reserve(2*count);
        
            for(int i = 0; i < count; ++i)
            {
                if(i > m_size)
                {
                    this -> m_buff[i] = value;
                }
                    std::cout << m_buff[i] << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            T*m_tmp = new T[count];
            for(int i = 0; i < count; ++i)
            {
                m_tmp[i] = this-> m_buff[i];
                std::cout << m_buff[i] << " ";
            }
            delete [] this-> m_buff;
            this -> m_buff = m_tmp;
            m_cap = count;
            m_size = count;
        }
    }
    T* data()const
    {
        return this-> m_buff;
    }
    void shrink_to_fit()
    {
        std::cout << "Shrink to fit call " << std::endl;
        if(m_size < m_cap)
        {
            T* m_tmp = new T[m_size];
            for(int i = 0; i < m_size; ++i)
            {
                m_tmp[i] = this-> m_buff[i];
            }
            delete [] this-> m_buff;
            m_buff = m_tmp;
            m_cap = m_size;
        }
    }

    void Showall() const
    {
        for(int i = 0; i < m_cap; ++i)
        {
            std::cout << m_buff[i] << " ";
        }
        std::cout << std::endl;
    }
    void Show() const
    {
        for(int i = 0; i < m_size; ++i)
        {
            std::cout << m_buff[i] << " ";
        }
        std::cout << std::endl;
    }
    void Erase(int index)
    {
        if(index < 0 || index > m_size)
        {
            std::cout << "Erase - index is out of range " << std::endl;
                return;
        }
        for(int i = index; i < m_size - 1; ++i)
        {
            m_buff[i] = m_buff[i + 1];
        }
        --m_size;
    }
    void Insert(int index, int value)
    {
        if((index < 0) || (index >= m_size))
        {
            std::cout << "Insert - index out of range " << std::endl;
        }
        if(m_size != m_cap)
        {
            for(int i = m_size -1; i >= index; --i)
            {
                m_buff[i + 1] = m_buff[i];
            }
            m_buff[index] = value;
            ++m_size;
        }
        else
        {
            m_cap *= 2;
            T* m_tmp = new T[m_cap];
            for(int i = 0; i < m_size; ++i)
            {
                m_tmp[i] = m_buff[i];
            }
            delete[] m_buff;
            m_buff = m_tmp;
            Insert(index, value);
        }

    }
    private:
    int m_size{};
    int m_cap{};
    T* m_buff{};
};


int main()
{
  {
    std::cout << "Creating a vectors A and C " << std::endl;
    Vector <int> C;
    Vector <int> A;
    Vector <char>D;
    std::cout << "Push_backs for D vector " << std::endl;
    D.push_back('A');
    D.push_back('B');
    D.push_back('C');
    D.push_back('D');
    D.push_back('E');
    D.push_back('A');
    D.resize(28);
    D.capacity();
    D.Showall();
    std::cout << D.Front() << std::endl;
    std::cout << "Push_backs for C vector " << std::endl;
    C.push_back(1);
    C.push_back(2);
    C.push_back(3);
    C.push_back(4);
    C.push_back(5);
    C.push_back(4);
    C.push_back(4);
    C.push_back(5);
    C.push_back(8);
    std::cout << "Push_backs for A vector " << std::endl;
    A.push_back();
    A.push_back();
    A.push_back();
    A.push_back();
    std::cout << "Vector A : ";
    A.size();
    A.capacity();
    A.pop_back();
    A.size();
    std::cout << "Copy constructor : Vector A to new created S " << std::endl;
    Vector S(A);
    std::cout << "Copy Assignment A = C" << std::endl;
    A = C;
    std::cout << "After some changes " << std::endl;
    A.capacity();
    std::cout << "Reserving new space for A" << std::endl;
    A.reserve(4);
    A.capacity();
    std::cout << "Resizing an A to 20 " << std::endl;
    A.resize(20);
    A.capacity();
    A.size();
    std::cout << "Doing Shrink to fit process " << std::endl;
    A.shrink_to_fit();
    A.size();
    A.capacity();
    std::cout << "Doing operator [] process - chaecking value in index [4] : " << std::endl;
    std::cout << A[4] << std::endl;
    std::cout << "Doing Front() process " << std::endl;
    std::cout << A.Front() << std::endl;
    std::cout << "Doing Back() process " << std::endl;
    std::cout << A.Back() << std::endl;
    std::cout << "Doing At() process " << std::endl;
    std::cout << A.At(2) << std::endl;
    std::cout << "Doing Data() process " << std::endl;
    std::cout << A.data() << std::endl;
    std::cout << "Doing Erase() process - 4th element " << std::endl;
    A.Show();
    A.Erase(4);
    A.Show();
    std::cout << "Doing Insert() process - 4th element's index chancge to 9 " << std::endl;
    A.Show();
    A.Insert(4,9);
    A.Show();
  }
  return 0;
}
