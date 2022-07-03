#include <iostream>
#include <cstring>


// Allows us to move instead of copying in situations where we
// would otherwise be forced to create a copy, injuring performance.


//  WE HAVE AVOIDED THE COPY BY MOVING!



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
        String(const String& other) // COPY CONSTRUCTOR
        {
            printf("Copied\n");
            m_Size = other.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);
                
        }
        String(String&& other) noexcept // MOVE CONSTRUCTOR
        {
            printf("Moved\n");
            m_Size = other.m_Size;
            m_Data = other.m_Data; // steals the pointer to the other object. Takes control of its memory

            // Turn old String into "Hollow object". When it calls the destructor
            // it will only delete a null pointer.
            other.m_Size = 0;
            other.m_Data = nullptr;
            // Can be thought of as a shallow copy.
        }
        ~String() {
            printf("Destroyed\n");
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
        Entity(String&& name) : m_Name((String&&)name) // only accepts rvalue temporary.
        {
            // should be done like this : m_Name(std::move(name)) which basically does the same thing.
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
    int x;
    std::cin >> x;
    return 0;
}