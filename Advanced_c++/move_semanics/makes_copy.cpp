#include <iostream>
#include <cstring>


// Allows us to move instead of copying in situations where we
// would otherwise be forced to create a copy, injuring performance.





class String
{
    public:
        String() = default;
        String(const char* string)
        {
            printf("Created\n");
            m_Size = strlen(string); // length of string.
            m_Data = new char[m_Size]; // create the length of memory.
            memcpy(m_Data, string, m_Size); // copy the data into the memory.
        }
        String(const String& other)
        {
            printf("Copied\n");
            m_Size = other.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);
                
        }
        ~String() {
            delete m_Data;
        }
        void Print()
        {
            for (uint32_t i = 0; i < m_Size; i++)
                printf("%c", m_Data[i]);
            printf("\n");
        }
    private:
        char* m_Data;
        uint32_t m_Size;

};

class Entity {
    public:
        Entity(const String& name) : m_Name(name) // uses String class' copy constructor.
        {

        }
        void PrintName() {
            m_Name.Print();
        }
    private:
        String m_Name;
};


int main() {

    Entity entity("Ryan");
    entity.PrintName();
    return 0;
}