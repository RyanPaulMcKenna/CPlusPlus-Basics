#include <iostream>
#include <cstring>

// WORKS IN ONLINE COMPILER, SOMETHING WRONG WITH LOCAL COMPILER MAY REQUIRE SPECIFIC ARGUMENTS
// LIKE -std=c++11 BUT NOT SURE.

// READ ME!
// std::move() and the MOVE ASSIGNMENT OPERATOR!

// ILLUSTRATIVE EXAMPLE.
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
        String& operator=(String&& other)  noexcept { // move assignment operator.
            printf("Moved\n");

            if (this != &other) // only do the move if they're different objects.
            { // even if the data is the same, if they are different objects the move must still be done.
                delete[] m_Data; // Make sure to clean out the existing data before assigning the new data.

                m_Size = other.m_Size;
                m_Data = other.m_Data;

                other.m_Size = 0;
                other.m_Data = nullptr;
            }
            return *this;
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
        Entity(String&& name) : m_Name(std::move(name)) // only accepts rvalue temporary.
        {
        }
        void PrintName() {
            m_Name.Print();
        }
    private:
        String m_Name;
};


int main() {

    // Entity entity("Ryan");
    // entity.PrintName();

    // String string = "Hello";
    // String dest = (String&&)string; // only accepts rvalue temporary. So we use the move constructor.
    // String dest2 = std::move(string); // More elegantly and safer.

    // // The assignment operator only gets called when we assign a variable between to locations
    // // that already exist. NOT AN INITALIZATION.
    // dest = std::move(string);


    String apple = "Apple";
    String dest;
    
    std::cout << "apple: ";
    apple.Print();
    std::cout << "dest: ";
    dest.Print();

    dest = std::move(apple); // move assignment operator.
    
    std::cout << "apple: ";
    apple.Print();
    std::cout << "dest: ";
    dest.Print();

    std::cin.get();
    return 0;
}